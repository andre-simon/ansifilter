/*
 * tclansifilter.c -- a minimal Tcl wrapper for ansifilter
 */
#include <tcl.h>
#include <memory>
#include "../codegenerator.h"

// Tcl namespace
#define NS "ansifilter"

// ansifilter requires C++ compiler
extern "C" {


static int
Execute_Escape_Cmd(ansifilter::OutputType type, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
{
    int i;
    // XXX this creates and destroys new instances for every call!
    auto_ptr<ansifilter::CodeGenerator> generator(ansifilter::CodeGenerator::getInstance(type));
    generator->setFragmentCode(1);     // -f
    generator->setPlainOutput(0);
    for (i = 1; i < objc; i++) {
        Tcl_AppendResult(interp, generator->generateString(Tcl_GetString(objv[i])).c_str(), NULL);
    }
    return TCL_OK;
}

static int
LaTeXEscape_Cmd(ClientData cdata, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
{
    return Execute_Escape_Cmd(ansifilter::LATEX, interp, objc, objv);
}

static int
TeXEscape_Cmd(ClientData cdata, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
{
    return Execute_Escape_Cmd(ansifilter::TEX, interp, objc, objv);
}

static int
HtmlEscape_Cmd(ClientData cdata, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
{
    return Execute_Escape_Cmd(ansifilter::HTML, interp, objc, objv);
}

static int
TextEscape_Cmd(ClientData cdata, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
{
    return Execute_Escape_Cmd(ansifilter::TEXT, interp, objc, objv);
}

static int
BBCodeEscape_Cmd(ClientData cdata, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
{
    return Execute_Escape_Cmd(ansifilter::BBCODE, interp, objc, objv);
}

static int
PangoEscape_Cmd(ClientData cdata, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
{
    return Execute_Escape_Cmd(ansifilter::PANGO, interp, objc, objv);
}
/*
 * Tclansifilter_Init -- Called when Tcl loads your extension.
 */
int DLLEXPORT
Tclansifilter_Init(Tcl_Interp *interp)
{
    if (Tcl_InitStubs(interp, TCL_VERSION, 0) == NULL) {
        return TCL_ERROR;
    }
    // provide package
    if (Tcl_PkgProvide(interp, "ansifilter", "0.2") == TCL_ERROR) {
        return TCL_ERROR;
    }
    // create command
    Tcl_CreateObjCommand(interp, NS "::tex", TeXEscape_Cmd, NULL, NULL);
    Tcl_CreateObjCommand(interp, NS "::latex", LaTeXEscape_Cmd, NULL, NULL);
    Tcl_CreateObjCommand(interp, NS "::html", HtmlEscape_Cmd, NULL, NULL);
    Tcl_CreateObjCommand(interp, NS "::text", TextEscape_Cmd, NULL, NULL);
    Tcl_CreateObjCommand(interp, NS "::bbcode", BBCodeEscape_Cmd, NULL, NULL);
    Tcl_CreateObjCommand(interp, NS "::pango", PangoEscape_Cmd, NULL, NULL);

    return TCL_OK;
}

} // extern "C"
