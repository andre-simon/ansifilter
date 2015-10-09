/*
 * tclansifilter.c -- a minimal Tcl wrapper for ansifilter -fL
 *
 * TODO: allow for multiple generators / options / ...
 */
#include <tcl.h>
#include <memory>
#include "../codegenerator.h"

// Tcl namespace
#define NS "ansifilter"

// ansifilter requires C++ compiler
extern "C" {

static int 
TeXEscape_Cmd(ClientData cdata, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
{
    int i;
    // XXX this creates and destroys new instances for every call!
    auto_ptr<ansifilter::CodeGenerator> generator(ansifilter::CodeGenerator::getInstance(ansifilter::LATEX)); // -L
    generator->setFragmentCode(1);                                                                            // -f
    for (i = 1; i < objc; i++) {
        Tcl_AppendResult(interp, generator->generateString(Tcl_GetString(objv[i])).c_str(), NULL);
    }
    return TCL_OK;
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
    if (Tcl_PkgProvide(interp, "ansifilter", "0.1") == TCL_ERROR) {
        return TCL_ERROR;
    }
    // create command
    Tcl_CreateObjCommand(interp, NS "::tex_escape", TeXEscape_Cmd, NULL, NULL);
    return TCL_OK;
}

} // extern "C"
