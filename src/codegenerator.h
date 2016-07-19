/***************************************************************************
                          codegenerator.h  -  description
                             -------------------
    copyright            : (C) 2007-2016 by Andre Simon
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
#include "preformatter.h"

#include "enums.h"
#include "stringtools.h"

/// The ansifilter namespace contains all classes and data structures needed for parsing input data.

namespace ansifilter
{

  /** TheDraw output information of individual characters*/
  struct TDChar {
    unsigned char c;
    ElementStyle style;
  };
  
  
/** \brief Base class for escape sequence parsing.

    The virtual class provides escape sequence parsing functionality.<br>
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
      \param type Output file type (TEXT, PANGO, HTML, RTF, LATEX, TEX)
    */
    static CodeGenerator* getInstance(OutputType type);

    /**
      Delete Codegenerator instance (this is intended for SWIG integration,
      in normal C++ code the result should be saved in an auto_ptr)
      \param CodeGenerator* CodeGenerator instance
    */
    static void deleteInstance(CodeGenerator* inst)
    {
        if (inst) delete inst;
    }

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
    
    /**
     Overrides default colours by user defined values
     \param mapPath path of map file
     \return true if parsing was successfull
    */
    bool setColorMap(const string& mapPath);

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

    /** \param b set to true if text formatting should be stripped */
    void setPlainOutput(bool b)
    {
        ignoreFormatting=b;
    }

    /** \param b set to true if HTML anchors should be added to line numbers */
    void setAddAnchors(bool b)
    {
        addAnchors=b;
    }

    /** \param b set to true if the input stream is not closed after reaching EOF */
    void setContinueReading(bool b)
    {
        readAfterEOF=b;
    }

    /** \return plain outputting flag */
    bool getPlainOutput()
    {
        return ignoreFormatting;
    }

    /** \return continue reading from input stream flag */
    bool getContinueReading()
    {
        return readAfterEOF;
    }

    /** \param lineWrappingStyle wrapping style
        \param lineLength maximum length  per wrapped text line */
    void setPreformatting ( WrapMode lineWrappingStyle,unsigned int lineLength);

    /** \param b set to true if line numbers should be added */
    void setShowLineNumbers(bool flag);

    /** \param b set to true if line numbers of wrapped lines should be omitted */
    void setWrapNoNumbers(bool flag);

    /** \param b set to true if input is codepage 437 ASCII art  */
    void setCodePage437(bool flag);
    
    void setAsciiArtSize(int width, int height);
    
protected:

    /** \param type Output type */
    CodeGenerator(ansifilter::OutputType type);
    CodeGenerator() {};

    /** \param c Character to be masked
        \return Escape sequence of output format */
    virtual string maskCharacter(unsigned char c) = 0;

    virtual string maskCP437Character(unsigned char c) { return maskCharacter(c); };
    
    /** Tag for inserting line feeds*/
    string newLineTag;

    /** file input*/
    istream *in;

    /** file output*/
    ostream *out;

    bool tagIsOpen;

    string styleCommentOpen,  ///< open comment delimiter
           styleCommentClose; ///< close comment delimiter

    /** Encoding name */
    string encoding;

    /** Encoding name */
    string docTitle;

    string spacer;

    /** Test if header and footer should be omitted */
    bool fragmentOutput;

    /** The base font to use */
    string font ;

    /** The base font size to use */
    string fontSize ;

    /** Style sheet path */
    string styleSheetPath;

    /** Width of line numbers */
    unsigned int lineNumberWidth;

    /** Current line number */
    unsigned int lineNumber;
    bool showLineNumbers,      ///< show line numbers
         numberWrappedLines,  ///< also show number of wrapped lines
         numberCurrentLine,   ///< output number of current line
         addAnchors;          ///< add HTML anchor to line number

    bool parseCP437;
         
    /** Processes input data */
    void processInput();

    virtual void insertLineNumber ();

    /** \return true id encoding is defined */
    bool encodingDefined()
    {
        return StringTools::lowerCase(encoding)!="none";
    }
    
        /** convert a rgb triple to HTML color notation
        @param rgb RGB input values 
        @return HTML color string
        */
    string rgb2html(unsigned char* rgb);
    
        /// 16 basic colors
    static unsigned char basic16[16][3];

    ElementStyle elementStyle;

    /** Class for line wrapping and tab replacement*/
    PreFormatter preFormatter;


private:

    CodeGenerator(const CodeGenerator&) {}

    CodeGenerator& operator=(CodeGenerator&)
    {
        return *this;
    }

    /** parses string to extract sequence information
        @param line text line
        @param begin starting position within line
        @param end ending position within line
        @return true if sequence was recognized */
    bool parseSGRParameters(const string& line, size_t begin, size_t end);
    
    /** parses Codepage 437 sequence information
        @param line text line                     
        @param begin starting position within line
        @param end ending position within line
        
        */
    void parseCodePage437Seq(string line, size_t begin, size_t end);

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
    
    int curX, curY, memX, memY, maxY; ///< cursor position for Codepage 437 sequences
    int asciiArtWidth;
    int asciiArtHeight;
    
    ElementStyle memStyle;
    
    /** convert an xterm color value (0-253) to 3 unsigned chars rgb
        @param color xterm color
        @param rgb RGB output values */
    void xterm2rgb(unsigned char color, unsigned char* rgb);
    
    /// the 6 value iterations in the xterm color cube
    static const unsigned char valuerange[] ;
};


}

#endif
