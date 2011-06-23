/***************************************************************************
                          cmdlineoptions.h  -  description
                             -------------------
    begin                : Sun Oct 13 2007
    copyright            : (C) 2007 by Andre Simon
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

#ifndef CMDLINEOPTIONS_H
#define CMDLINEOPTIONS_H

#include <string>
#include <map>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include "enums.h"


using namespace std;

/// handle command line options

class CmdLineOptions
  {
  public:

    /**Constructor
     \param argc Argument count
     \param argv Argument strings
    */
    CmdLineOptions( const int argc, const char *argv[] );
    ~CmdLineOptions();

    /** \return Single output file name*/
     string getSingleOutFilename();

    /** \return Single input file name*/
     string getSingleInFilename() const;

    /** \return Output directory*/
     string getOutDirectory() ;

    /** \return Char set*/
     string getEncoding() const;

    /** \return Char set*/
     string getFont() const;

    /** \return Char set*/
     string getFontSize() const;

    /** \return True if version information should be printed*/
    bool printVersion() const;

   /** \return True if help information should be printed*/
    bool printHelp() const;

    /** \return True if output shluld be fragmented*/
    bool fragmentOutput() const;

    /** \return output file suffix */
    string getOutFileSuffix() const;

    /** \return Output file format */
    ansifilter::OutputType getOutputType() const;

    /** \return True if encoding specification should be omitted in output*/
    bool omitEncoding() const;

    /** \return True if formatting infotmation should not be outputted */
    bool plainOutput() const;

    /** \return True if input files should be raed after EOF occoured */
    bool ignoreInputEOF() const;

    /** \return Document title */
     string getDocumentTitle() const ;
     
         /** \return Document title */
     string getStyleSheetPath() const ;

    /** \return List of input file names*/
    const vector <string> & getInputFileNames() const;

  private:
    ansifilter::OutputType outputType;

    bool opt_help;
    bool opt_version ;
    bool opt_fragment;
    bool opt_plain;
    bool opt_ignoreEOF;

    // name of single output file
    string outFilename;
    string docTitle;
    string encodingName;
    string outDirectory;
    string font;
    string fontSize;
    string styleSheetPath;

    /** list of all input file names */
    vector <string> inputFileNames;

    /** \return Valid path name */
    string validateDirPath(const string & path);

    /** \return directory name of path */
    string getDirName( const string & path);
  };

#endif
