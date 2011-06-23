/***************************************************************************
                          codegenerator.h  -  description
                             -------------------
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

#ifndef CODEPARSER_H
#define CODEPARSER_H

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

// Avoid problems with isspace and UTF-8 characters, use iswspace instead
//#include <cctype>
#include <wctype.h>

#include "elementstyle.h"

#include "enums.h"
#include "stringtools.h"

/// The ansifilter namespace contains all classes and data structures needed for parsing input data.

namespace ansifilter {

class ReGroup;

/** \brief Base class for escape sequence parsing.

    The virtual class provides source code parsing functionality, based on
    information stored in language definitions.<br>
    The derived classes have to define the output format.<br>
    Codegenerator is a singleton class.

* @author Andre Simon
*/

class CodeGenerator
  {

  public:

    virtual ~CodeGenerator();

    /**
      Get appropriate Codegenerator instance
      \param type Output file type (TEXT, HTML, RTF, LATEX, TEX)
    */
    static CodeGenerator* getInstance(OutputType type);

    /**
      Delete Codegenerator instance (this is intended for SWIG integration,
      in normal C++ code the result should be saved in an auto_ptr)
      \param CodeGenerator* CodeGenerator instance
    */
    static void deleteInstance(CodeGenerator* inst) {if (inst) delete inst;}

    /**
     Generates output file
     \param inFileName Path of input file (if empty use stdin)
     \param outFileName Path of output file (if empty use stdout)
     \return ParseError
    */
    ParseError generateFile(const string &inFileName, const string &outFileName);

    /**
     Generates output string from input string
     \param input input code string
     \return formatted output code
    */
    string generateString(const string &input);

    /**
     Generates output string from input file
     \param inFileName file path
     \return formatted output code
    */
    string generateStringFromFile(const string &inFileName);

    /**
     Generates output file from input string
     \param sourceStr input string
     \param outFileName output file path
     \param title document title
     \return formatted output code
    */
    ParseError generateFileFromString (const string &sourceStr,
                                       const string &outFileName,
                                       const string &title);

    /** tell parser to omit document header and footer
       \param  flag true if output should be fragmented
    */
    void setFragmentCode(bool flag);

    /** \return fragment flag */
    bool getFragmentCode();

    /** tell parser to use this font as base font
    \param s the font name, e.g. "Courier New"
     */
    void setFont(const string& s);

    /** \return base font */
    const string getFont() const ;

    /** tell parser to use this size as base font size
    \param s the font size, e.g. "12"
     */
    void setFontSize(const string& s);

    /** \return base font size*/
    const string getFontSize();

    /** Set encloding
      \param encodingName encoding name
    */
    void setEncoding(const string& encodingName);

    /** \param title Document title */
    void setTitle(const string & title);

    /** \return Document title */
    string getTitle();
    
    /** \param path style sheet path*/
    void setStyleSheet(const string & path);

   void setPlainOutput(bool b) {ignoreFormatting=b;}

   void setContinueReading(bool b) {readAfterEOF=b;}

   bool getPlainOutput() {return ignoreFormatting;}

   bool getContinueReading() {return readAfterEOF;}

protected:

    /** \param type Output type */
    CodeGenerator(ansifilter::OutputType type);
    CodeGenerator() {};

    /** \param c Character to be masked
        \return Escape sequence of output format */
    virtual string maskCharacter(unsigned char c) = 0;

    /** Tag for inserting line feeds*/
    string newLineTag;

    /** file input*/
    istream *in;

    /** file output*/
    ostream *out;

    string styleCommentOpen,  ///< open comment delimiter
           styleCommentClose; ///< close comment delimiter

    /** Encoding name */
    string encoding;

    /** Encoding name */
    string docTitle;

    /** Test if header and footer should be omitted */
    bool fragmentOutput;

    /** The base font to use */
    string font ;

    /** The base font size to use */
    string fontSize ;
    
    string styleSheetPath;

    /** Processes origin state */
    void processRootState();

    /** \return true id encoding is defined */
    bool encodingDefined() {return StringTools::lowerCase(encoding)!="none";}

   ElementStyle elementStyle;

   static string ColorBlack;
   static string ColorRed;
   static string ColorGreen;
   static string ColorYellow;
   static string ColorBlue;
   static string ColorMagenta;
   static string ColorCyan;
   static string ColorWhite;
   static string ColorBrightRed;
   static string ColorBrightGreen;
   static string ColorBrightYellow;
   static string ColorBrightBlue;
   static string ColorBrightMagenta;
   static string ColorBrightCyan;
   static string ColorBrightWhite;

private:

    CodeGenerator(const CodeGenerator&){}

    CodeGenerator& operator=(CodeGenerator&){ return *this;}

    /** parses string to extract sequence information
        @param line text line
        @param begin starting position within line
        @param end ending position within line
        @return true if sequence was recognized */
    bool parseSequence(const string& line, size_t begin, size_t end);

    /** Prints document footer
        @return footer */
    virtual string getFooter() = 0;

    /** Prints document body*/
    virtual void printBody() = 0;

    /** Prints document header
        @return header
    */
    virtual string getHeader() = 0;

    /** Resets parser to origin state, call this after every file conversion */
    void reset();

    /** Output format type*/
    OutputType outputType;

    virtual string getOpenTag() = 0;  ///< returns opening formatting sequence
    virtual string getCloseTag() = 0; ///< returns closing formatting sequence

    bool ignoreFormatting; ///< ignore color and font face information
    bool readAfterEOF;     ///< continue reading after EOF occoured

    /** convert an xterm color value (0-253) to 3 unsigned chars rgb
        @param color xterm color
        @param rgb RGB destination string */
    void xterm2rgb(unsigned char color, unsigned char* rgb);

    /// the 6 value iterations in the xterm color cube
    static const unsigned char valuerange[] ;

    /// 16 basic colors
    static const unsigned char basic16[16][3];

  };

}

#endif
