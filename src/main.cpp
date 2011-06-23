/***************************************************************************
                          main.cpp  -  description
                             -------------------

    copyright            : (C) 2007 by Andre Simon
    email                : andre.simon1@gmx.de

   Highlight is a universal source code to HTML converter. Syntax highlighting
   is formatted by Cascading Style Sheets. It's possible to easily enhance
   highlight's parsing database.

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

#include <memory>
#include "main.h"
#include "codegenerator.h"
#include "platform_fs.h"

using namespace std;

void ANSIFilterApp::printVersionInfo()
{
  cout << "\n ansifilter version "
       << ANSIFILTER_VERSION
       << "\n Copyright (C) 2007-2011 Andre Simon <andre.simon1 at gmx.de>"
       << "\n\n Argparser class"
       << "\n Copyright (C) 2006-2008 Antonio Diaz Diaz <ant_diaz at teleline.es>"
       << "\n\n This software is released under the terms of the GNU General "
       << "Public License."
       << "\n For more information about these matters, see the file named "
       << "COPYING.\n";
}

void ANSIFilterApp::printHelp()
{
    cout << "Invocation: ansifilter [OPTION]... [FILE]...\n\n";
    cout << "ansifilter handles text files containing ANSI terminal escape codes.\n";
    cout << "\nFile handling:\n";
    cout << "  -i, --input=<file>   name of single input file\n";
    cout << "  -o, --output=<file>  name of single output file\n";
    cout << "  -O, --outdir=<dir>   name of output directory\n";
    cout << "  -t, --tail           Continue reading after end-of-file (like tail -f)\n";
    cout << "                       Use system tail if available\n";
    cout << "\nOutput text formats:\n";
    cout << "  -T, --text (default) Output text\n";
    cout << "  -H, --html           Output HTML\n";
    cout << "  -L, --latex          Output LaTeX\n";
    cout << "  -P, --tex            Output Plain TeX\n";
    cout << "  -R, --rtf            Output RTF\n";
    cout << "  -B, --bbcode         Output BBCode\n";
    cout << "\nFormatted text options:\n";
    cout << "  -d, --doc-title      Set HTML/LaTeX document title\n";
    cout << "  -e, --encoding       Set HTML encoding (must match input file encoding)\n";
    cout << "  -f, --fragment       Omit HTML header and footer\n";
    cout << "  -F, --font=<font>    Set HTML/RTF font face\n";
    cout << "  -r, --style-ref=<rf> Set HTML/TeX/LaTeX stylesheet path\n";
    cout << "  -s, --font-size=<fs> Set HTML/RTF font size\n";
    cout << "  -p, --plain          Ignore ANSI formatting information\n";
    cout << "\nOther options:\n";
    cout << "  -h, --help           Print help\n";
    cout << "  -v, --version        Print version and license info\n";
    cout << "\nExamples:\n";
    cout << "ansifilter -i input.ansi -o output.txt\n";
    cout << "ansifilter *.txt\n";
    cout << "tail -f server.log | ansifilter\n";
    cout << "\nPlease report bugs to " ANSIFILTER_EMAIL "\n";
    cout << "For updates see " ANSIFILTER_URL "\n";
}

int ANSIFilterApp::run( const int argc, const char *argv[] ){

  CmdLineOptions options(argc, argv);

  if (options.printVersion()) {
    printVersionInfo();
    return EXIT_SUCCESS;
  }

  if  (options.printHelp())  {
    printHelp();
    return EXIT_SUCCESS;
  }

   const  vector <string> inFileList=options.getInputFileNames();
   auto_ptr<ansifilter::CodeGenerator> generator(ansifilter::CodeGenerator::getInstance(options.getOutputType()));

  string outDirectory = options.getOutDirectory();
/*
  if (!outDirectory.empty() && !options.quietMode() && !dirstr::directory_exists(outDirectory) ){
     cerr << "highlight: Output directory \""
          << outDirectory
	  << "\" does not exist.\n";
    // highlight::CodeGenerator::deleteInstance();
     return EXIT_FAILURE;
  }
*/
  unsigned int fileCount=inFileList.size(), i=0;
  string::size_type pos=0;
  string inFileName, outFilePath;
  bool failure=false;

  while (i < fileCount && !failure) {

    pos=(inFileList[i]).find_last_of(Platform::pathSeparator);
    inFileName = inFileList[i].substr(pos+1);

    if (fileCount>1){

      outFilePath = outDirectory;
      outFilePath += inFileName;
      outFilePath += options.getOutFileSuffix();
     } else {
        outFilePath = options.getSingleOutFilename();
     }

     generator->setTitle(options.getDocumentTitle().empty()?
                    inFileList[i]:options.getDocumentTitle());

     generator->setEncoding(options.getEncoding());
     generator->setFragmentCode(options.fragmentOutput());
     generator->setPlainOutput(options.plainOutput());
     generator->setContinueReading(options.ignoreInputEOF());
     generator->setFont(options.getFont());
     generator->setFontSize(options.getFontSize());
     generator->setStyleSheet(options.getStyleSheetPath());

     ansifilter::ParseError error = generator->generateFile(inFileList[i], outFilePath);

     if (error==ansifilter::BAD_INPUT){
       std::cerr <<"could not read input: "<<inFileList[i]<<"\n";
        failure=true;
     } else if (error==ansifilter::BAD_OUTPUT){
       std::cerr <<"could not write output: "<< outFilePath <<"\n";
       failure=true;
     }
     ++i;
   }
   return (failure)?EXIT_FAILURE:EXIT_SUCCESS;
}

int main( const int argc, const char *argv[] ) {

  ANSIFilterApp app;
  return app.run(argc, argv);
}
