/***************************************************************************
                          cmdlineoptions.cpp  -  description
                             -------------------
    begin                : Sun Oct 13 2007
    copyright            : (C) 2007-2011 by Andre Simon
    email                : andre.simon1@gmx.de
 ***************************************************************************/

/*
This file is part of ANSIFilter.

ANSIFilter is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ANSIFilter is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ANSIFilter.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <cstring>
#include <string>
#include <vector>

#include "arg_parser.h"
#include "cmdlineoptions.h"
#include "platform_fs.h"
#include "stringtools.h"

using namespace std;

CmdLineOptions::CmdLineOptions( const int argc, const char *argv[] ):
    outputType (ansifilter::TEXT),
    opt_help(false),
    opt_version(false),
    opt_fragment(false),
    opt_plain(false),
    opt_ignoreEOF(false),
    encodingName("ISO-8859-1"),
    font("Courier New"),
    fontSize("10pt"),
    wrapLineLen(0)
{

  const Arg_parser::Option options[] =
    {
    { 'd', "doc-title", Arg_parser::yes },
    { 'e', "encoding",  Arg_parser::yes },
    { 'f', "fragment",  Arg_parser::no  },
    { 'F', "font",      Arg_parser::yes },
    { 'h', "help",      Arg_parser::no  },
    { 'H', "html",      Arg_parser::no  },
    { 'i', "input",     Arg_parser::yes },
    { 'L', "latex",     Arg_parser::no  },
    { 'P', "tex",       Arg_parser::no  },
    { 'B', "bbcode",    Arg_parser::no  },
    { 'o', "output",    Arg_parser::yes },
    { 'O', "outdir",    Arg_parser::yes },
    { 'p', "plain",     Arg_parser::no  },
    { 'r', "style-ref", Arg_parser::yes },
    { 'R', "rtf",       Arg_parser::no  },
    { 's', "font-size", Arg_parser::yes },
    { 't', "tail",      Arg_parser::no  },
    { 'T', "text",      Arg_parser::no  },
    { 'w', "wrap",      Arg_parser::yes },
    { 'v', "version",   Arg_parser::no  },
    { 'V', "version",   Arg_parser::no  },
    {  0,  0,           Arg_parser::no  } };

  Arg_parser parser( argc, argv, options );
  if( parser.error().size() )				// bad option
    {
    cerr << "ansifilter: "<< parser.error()<<"\n";
    cerr << "Try 'ansifilter --help' for more information.\n";
    exit( 1 );
    }

  int argind = 0;
  for( ; argind < parser.arguments(); ++argind )
    {
    const int code = parser.code( argind );
    const std::string & arg = parser.argument( argind );
    if( !code ) break;					// no more options
    switch( code )
      {
       case 'B':
        outputType = ansifilter::BBCODE;
        break;
      case 'd':
        docTitle = arg;
        break;
      case 'e':
        encodingName = arg;
        break;
      case 'f':
        opt_fragment = true;
        break;
      case 'F':
        font = arg;
        break;
      case 'h':
        opt_help = true;
        break;
      case 'H':
        outputType = ansifilter::HTML;
        break;
      case 'i':
        inputFileNames.push_back( arg );
        break;
      case 'L':
        outputType = ansifilter::LATEX;
        break;
      case 'P':
        outputType = ansifilter::TEX;
        break;
      case 'o':
        outFilename = arg;
        break;
      case 'p':
	opt_plain = true;
        break;
      case 'r':
        styleSheetPath = arg;
        break;
      case 'R':
        outputType = ansifilter::RTF;
        break;
      case 's':
        fontSize = arg;
        break;
      case 't':
	opt_ignoreEOF = true;
        break;
      case 'T':
        outputType = ansifilter::TEXT;
        break;
      case 'v':
      case 'V':
        opt_version = true;
        break;
      case 'O':
        outDirectory = validateDirPath( arg );
        break;
      case 'w':
	wrapLineLen=atoi(arg.c_str())-1;
      default:
        cerr << "ansifilter: option parsing failed" << endl;
      }
    }

  if (argind < parser.arguments())   //still args left
    {
      if  (inputFileNames.empty()) {
        while (argind < parser.arguments()){
          inputFileNames.push_back( parser.argument( argind++ ) );
         }
      }
    } else if (inputFileNames.empty()) {
       inputFileNames.push_back("");
    }
}

CmdLineOptions::~CmdLineOptions(){}


string CmdLineOptions::validateDirPath(const string & path){
   return (path[path.length()-1] !=Platform::pathSeparator)?
              path+Platform::pathSeparator : path;
}

string CmdLineOptions::getSingleOutFilename()
  {
   if (!inputFileNames.empty() && !outDirectory.empty()) {
      if (outFilename.empty()) {
        outFilename = outDirectory;
        int delim = getSingleInFilename().find_last_of(Platform::pathSeparator)+1;
        outFilename += getSingleInFilename().substr((delim>-1)?delim:0)
                       + getOutFileSuffix();
      }
   }
   return outFilename;
  }

string CmdLineOptions::getSingleInFilename()  const
  {
  return inputFileNames[0];
  }

string CmdLineOptions::getOutDirectory()
  {
    if (!outFilename.empty() && !inputFileNames.size()){
      outDirectory=getDirName(outFilename);
    }
    return outDirectory;
  }

string CmdLineOptions::getDirName(const string & path) {
  size_t dirNameLength=path.rfind(Platform::pathSeparator);
  return (dirNameLength==string::npos)?string():path.substr(0, dirNameLength+1);
}

bool CmdLineOptions::printVersion()const
  {
    return opt_version;
  }

bool CmdLineOptions::printHelp()const
  {
    return opt_help;
  }

bool CmdLineOptions::fragmentOutput()const{
    return opt_fragment;
}

string CmdLineOptions::getOutFileSuffix()const{
    switch (outputType){
      case ansifilter::HTML: return ".html";
      case ansifilter::XHTML: return ".xhtml";
      case ansifilter::RTF:   return ".rtf";
      case ansifilter::TEX:
      case ansifilter::LATEX: return ".tex";
      case ansifilter::BBCODE: return ".bbcode";
      default:    return ".txt";
    }
}

string CmdLineOptions::getEncoding() const{
    return encodingName;
}

string CmdLineOptions::getFont() const {
    return font;
}

string CmdLineOptions::getFontSize() const{
    return fontSize;
}

bool CmdLineOptions::plainOutput() const {
  return opt_plain;
}

bool CmdLineOptions::ignoreInputEOF() const {
  return opt_ignoreEOF;
}

bool CmdLineOptions::omitEncoding() const{
    return StringTools::lowerCase(encodingName)=="none";
}

string CmdLineOptions::getDocumentTitle() const {
   return docTitle;
}

string CmdLineOptions::getStyleSheetPath() const
{
  return styleSheetPath;
}

const vector <string> & CmdLineOptions::getInputFileNames() const{
  return inputFileNames;
}

ansifilter::OutputType CmdLineOptions::getOutputType() const {
    return outputType;
}

int CmdLineOptions::getWrapLineLength() const {
    return wrapLineLen;
}
    