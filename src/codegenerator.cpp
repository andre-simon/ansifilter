/***************************************************************************
                      codegenerator.cpp  -  description
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

#include "codegenerator.h"

#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include <cstdlib> 
#include <cstring>
#include <fstream>
#include "version.h"

#include "pangogenerator.h"
#include "htmlgenerator.h"
#include "rtfgenerator.h"
#include "plaintextgenerator.h"
#include "texgenerator.h"
#include "latexgenerator.h"
#include "bbcodegenerator.h"

namespace ansifilter
{

CodeGenerator * CodeGenerator::getInstance(OutputType type)
{
    CodeGenerator* generator=NULL;
    switch (type) {
    case TEXT:
        generator = new PlaintextGenerator();
        break;
    case HTML:
        generator = new HtmlGenerator();
        break;
    case PANGO:
        generator = new PangoGenerator();
        break;
    case LATEX:
        generator = new LaTeXGenerator();
        break;
    case TEX:
        generator = new TeXGenerator();
        break;
    case RTF:
        generator = new RtfGenerator();
        break;
    case BBCODE:
        generator = new BBCodeGenerator();
        break;
    default:
        break;
    }
    return generator;
}

CodeGenerator::CodeGenerator(ansifilter::OutputType type)
    :in(NULL),
     out(NULL),
     tagIsOpen(false),
     encoding("none"),
     docTitle("Source file"),
     fragmentOutput(false),
     font("Courier New"),
     fontSize("10pt"),

     lineNumberWidth ( 5 ),
     lineNumber ( 0 ),
     showLineNumbers ( false ),
     
     numberWrappedLines ( true ), //TODO add option
     numberCurrentLine(false),
     addAnchors(false),
     parseCP437(false),
     parseAsciiBin(false),
     
     outputType(type),
     ignoreFormatting(false),
     readAfterEOF(false),
     termBuffer(NULL),
     curX(0),
     curY(0),
     memX(0),
     memY(0),
     maxY(0),
     asciiArtWidth(80),
     asciiArtHeight(150)
{
    elementStyle.setFgColour(rgb2html(workingPalette[0]));
}

CodeGenerator::~CodeGenerator()
{}


void CodeGenerator::setShowLineNumbers(bool flag)
{
    showLineNumbers=flag;
}

void CodeGenerator::setFragmentCode(bool flag)
{
    fragmentOutput=flag;
}

void CodeGenerator::setWrapNoNumbers(bool flag)
{
    numberWrappedLines = flag;
}

void CodeGenerator::setParseCodePage437(bool flag){
    parseCP437 = flag; 
}

void CodeGenerator::setParseAsciiBin(bool flag){
    parseAsciiBin = flag; 
}
void CodeGenerator::setAsciiArtSize(int width, int height){
    if (width>0) asciiArtWidth = width;
    if (height>0) asciiArtHeight = height;
}

bool CodeGenerator::getFragmentCode()
{
    return fragmentOutput;
}

void CodeGenerator::setFont(const string& s)
{
    font = s;
}

void CodeGenerator::setFontSize(const string& s)
{
    fontSize = s ;
}

void CodeGenerator::setTitle(const string & title)
{
    if (!title.empty())
        docTitle= title;
}

string CodeGenerator::getTitle()
{
    return docTitle;
}

void CodeGenerator::setEncoding(const string& encodingName)
{
    encoding = encodingName;
}

void CodeGenerator::setStyleSheet(const std::string& path)
{
    styleSheetPath=path;
}

void CodeGenerator::setPreformatting ( WrapMode lineWrappingStyle,
                                       unsigned int lineLength
                                     )
{
    if ( lineLength>0 ) {
        preFormatter.setWrap ( true );
        preFormatter.setWrapIndentBraces ( lineWrappingStyle==WRAP_DEFAULT );
        preFormatter.setWrapLineLength ( lineLength );
        preFormatter.setReplaceTabs ( false );
        //preFormatter.setNumberSpaces ( numberSpaces );
    }
}

ParseError CodeGenerator::generateFile (const string &inFileName,
                                        const string &outFileName)
{

    ParseError error=PARSE_OK;

    in = (inFileName.empty()? &cin :new ifstream (inFileName.c_str(), std::ios::binary));


    if (!in->fail() && error==PARSE_OK) {
        out = (outFileName.empty()? &cout :new ofstream (outFileName.c_str()));
        if ( out->fail()) {
            error=BAD_OUTPUT;
        }
    }

    if ( in->fail()) {
        error=BAD_INPUT;
    }

    if (error==PARSE_OK) {
        if (! fragmentOutput) {
            *out << getHeader();
        }

        printBody();

        if (! fragmentOutput) {
            *out << getFooter();
        }
    }

    if (!outFileName.empty()) {
        delete out;
        out=NULL;
    }
    if (!inFileName.empty()) {
        delete in;
        in=NULL;
    }
    return error;
}

string CodeGenerator::generateString(const string &input)
{
    in = new istringstream (input);
    out = new ostringstream ();

    if ( in->fail() || out->fail()) {
        return "";
    }

    if (! fragmentOutput) {
        *out << getHeader();
    }

    printBody();

    if (! fragmentOutput) {
        *out << getFooter();
    }

    string result = static_cast<ostringstream*>(out)->str();

    delete out;
    out=NULL;
    delete in;
    in=NULL;

    return result;
}

string CodeGenerator::generateStringFromFile(const string &inFileName)
{

    in = new ifstream (inFileName.c_str(), std::ios::binary);
    out = new ostringstream ();

    if ( in->fail() || out->fail()) {
        return "";
    }

    if (! fragmentOutput) {
        *out << getHeader();
    }

    printBody();

    if (! fragmentOutput) {
        *out << getFooter();
    }


    string result = static_cast<ostringstream*>(out)->str();

    delete out;
    out=NULL;
    delete in;
    in=NULL;

    return result;
}

ParseError CodeGenerator::generateFileFromString (const string &sourceStr,
        const string &outFileName,
        const string &title)
{
    ParseError error=PARSE_OK;

    in = new istringstream (sourceStr);
    if (!in->fail()) {
        out = (outFileName.empty()? &cout :new ofstream (outFileName.c_str()));
        if ( out->fail()) {
            error=BAD_OUTPUT;
        }
    }

    if ( in->fail()) {
        error=BAD_INPUT;
    }

    if (error==PARSE_OK) {

        if (! fragmentOutput) {
            *out << getHeader();
        }

        printBody();

        if (! fragmentOutput) {
            *out << getFooter();
        }
    }

    if (!outFileName.empty()) {
        delete out;
        out=NULL;
    }

    delete in;
    in=NULL;

    return error;
}
/*
  
 ESC[nL       Inserts n blank lines at cursor line.   (NANSI)
 ESC[nM       Deletes n lines including cursor line.  (NANSI)
 ESC[n@       Inserts n blank chars at cursor.        (NANSI)
 ESC[nP       Deletes n chars including cursor char.  (NANSI)
 ESC[n;ny     Output char translate                   (NANSI)
 */

bool CodeGenerator::parseSGRParameters(const string& line, size_t begin, size_t end)
{  
    if (line.empty() || begin==end) { // fix empty grep --color ending sequence
      elementStyle.setReset(true);
      return true;
    }
  
    int ansiCode=0;
    int colorCode=0;
    unsigned char colorValues[3]= {0};

    string codes=line.substr(begin, end-begin);
    vector<string> codeVector = StringTools::splitString(codes, ';');
    
    vector<string>::iterator itVectorData = codeVector.begin();
    while( itVectorData != codeVector.end()) {
        StringTools::str2num<int>(ansiCode, *(itVectorData), std::dec);
        elementStyle.setReset(false);

        switch (ansiCode) {
        case 0:
          elementStyle.setReset(true);
            break;   
        case 1:
            elementStyle.setBold(true);
            elementStyle.setFgColour(rgb2html(workingPalette[8]));
            break;
        case 2: //Faint
            break;

        case 3:
            elementStyle.setItalic(true);
            break;

        case 5: //Blink
        case 6: //Blink fast
            elementStyle.setBlink(true);
            break;

        case 7:
            elementStyle.imageMode(true);
            break;

        case 8:
            elementStyle.setConceal(true);
            break;

        case 4:// Underline Single
        case 21: // Underline double
            elementStyle.setUnderline(true);
            break;

        case 22:
            elementStyle.setBold(false);
            break;

        case 24:
            elementStyle.setUnderline(false);
            break;

        case 25:
            elementStyle.setBlink(false);
            break;

        case 27:
            elementStyle.imageMode(false);
            break;

        case 28:
            elementStyle.setConceal(false);
            break;

        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
            if (elementStyle.isBold()){              
              elementStyle.setFgColour(rgb2html(workingPalette[ansiCode-30+8]));
            } else
              elementStyle.setFgColour(rgb2html(workingPalette[ansiCode-30]));
            break;
            
        case 38: // xterm 256 foreground color mode \033[38;5;<color>

            itVectorData++;
            if (itVectorData == codeVector.end()) break;

            if(*(itVectorData)!="5") break;

            itVectorData++;
            if (itVectorData == codeVector.end()) break;

            StringTools::str2num<int>(colorCode, *(itVectorData), std::dec);
            xterm2rgb((unsigned char)colorCode, colorValues);
            elementStyle.setFgColour(rgb2html(colorValues));
            break;

        case 39:
          elementStyle.setReset(true);
            break;

        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
            elementStyle.setBgColour(rgb2html(workingPalette[ansiCode-40]));
            break;

        case 48:  // xterm 256 background color mode \033[48;5;<color>

            itVectorData++;
            if (itVectorData == codeVector.end()) break;

            if(*(itVectorData)!="5") break;

            itVectorData++;
            if (itVectorData == codeVector.end()) break;

            StringTools::str2num<int>(colorCode, *(itVectorData), std::dec);
            xterm2rgb((unsigned char)colorCode, colorValues);
            elementStyle.setBgColour(rgb2html(colorValues));
            break;

        case 49:
          elementStyle.setReset(true);
            break;

        /*aixterm codes*/
        case 90:
        case 91:
        case 92:
        case 93:
        case 94:
        case 95:
        case 96:
        case 97:
            elementStyle.setFgColour(rgb2html(workingPalette[ansiCode-90+8]));
            break;
    
        case 100:
        case 101:
        case 102:
        case 103:
        case 104:
        case 105:
        case 106:
        case 107:
            elementStyle.setBgColour(rgb2html(workingPalette[ansiCode-100+8]));
            break;

        }

        // Set RTF color index
        // 8 default colours followed by bright colors see rtfgenerator.cpp
        if (ansiCode>=30 and ansiCode <=37)
          elementStyle.setFgColourID(ansiCode-30 + (elementStyle.isBold()? 8 : 0) );
        else if (ansiCode>=90 and ansiCode <98)
            elementStyle.setFgColourID(ansiCode-90+8);

        else if (ansiCode>=40 and ansiCode <=47)
          elementStyle.setBgColourID(ansiCode-40 /*+ elementStyle.isBold()? 8 : 0 */);
        else if (ansiCode>=100 and ansiCode <108)
            elementStyle.setBgColourID(ansiCode-100+8);

        if (itVectorData != codeVector.end()) itVectorData++;
    }

    return true;
}


void CodeGenerator::parseCodePage437Seq(string line, size_t begin, size_t end){
    
  string codes=line.substr(begin, end-begin);
  vector<string> codeVector = StringTools::splitString(codes, ',');
  
  if (line[end]=='H'){
    codeVector = StringTools::splitString(codes, ';');
    
    curX = curY = 0;
    if (codeVector.size()==1) {
      curY = atoi(codeVector[0].c_str());
    } else  if (codeVector.size()==2){
     curY = atoi(codeVector[0].c_str());
     curX = atoi(codeVector[1].c_str()); 
    }     

    if (maxY<curY && curY<asciiArtHeight) maxY=curY;
  }
  
  if (line[end]=='A'){    
    if (codeVector.size()==1){
      curY -= atoi(codeVector[0].c_str());
     } else {
      curY--;
    }
  }
  
  if (line[end]=='B'){
    if (codeVector.size()==1){
      curY += atoi(codeVector[0].c_str());
    } else {
      curY++;
    }
    if (maxY<curY && curY<asciiArtHeight) maxY=curY;
  }
  
  if (line[end]=='C'){
    
    if (codeVector.size()==1){
      curX += atoi(codeVector[0].c_str());
    } else {
      curX++;
    }

    //handle coloumn overflow
    if (curX>asciiArtWidth && curY<asciiArtHeight){
      curX-=asciiArtWidth;
      curY++;
      if (maxY<curY && curY<asciiArtHeight) maxY=curY;
    }
  }
  
  if (line[end]=='D'){
    if (codeVector.size()==1){
      curX -= atoi(codeVector[0].c_str());
     } else {
      curX--;
    }
    if (curX<0) curX=0;    
  }
  
  if (line[end]=='J'){
 //   std::cerr<<"J!!!\n";
    /*
    if (codeVector.size()==1 && codeVector[0]=="2"){
      for (int i=0;i<100*100;i++) *termBuffer[i]->c =0;
    } 
    */
  }
  
  if (line[end]=='K'){
  //  std::cerr<<"K!!!\n";
    //    for (int i=curX;i<asciiArtWidth;i++) termBuffer[curY*asciiArtWidth + i]->c =0;
     
  }
  
  if (line[end]=='s'){
    memX = curX;
    memY = curY;
    memStyle = elementStyle;
  }
  if (line[end]=='u'){
    curX = memX;
    curY = memY;
    elementStyle=memStyle;
  }
 
}

void CodeGenerator::insertLineNumber ()
{
    if ( showLineNumbers && !parseCP437) {

        ostringstream lnum;
        lnum << setw ( 5 ) << right;
        if( numberCurrentLine ) {
            *out << getCloseTag();
            lnum << lineNumber;
            *out <<lnum.str()<<spacer;
            *out << getOpenTag();
        } else {
            *out << lnum.str(); //for indentation
        }
    }
}

void CodeGenerator::printTermBuffer() {

    
    for (int y=0;y<=maxY;y++) {

    for (int x=0;x<asciiArtWidth;x++) {
      if (termBuffer[x + y* asciiArtWidth].c=='\r') {
        break;
      }
      elementStyle = termBuffer[x + y* asciiArtWidth].style;
      
      //full block
      if (termBuffer[x + y* asciiArtWidth].c == 0xdb){
        elementStyle.setBgColour(elementStyle.getFgColour());
      }
      
      if (!elementStyle.isReset()) {
        *out <<getOpenTag();
      }
      
      *out << maskCP437Character(termBuffer[x + y* asciiArtWidth].c);
      
      if (!elementStyle.isReset()) {
        *out <<getCloseTag();
      }
    }
    *out<<newLineTag;  
  }
  out->flush();
  delete [] termBuffer;
}


void CodeGenerator::parseBinFile(){
  char * buffer = new char [2];
  int cur=0;
  int next=0;
  int count=0;
  allocateTermBuffer();
  while (in->read (buffer, 2)){
    
    cur = buffer[0]&0xff;
    next = buffer[1]&0xff;
    
    int colBg = (next & 240) >> 4;
    int colFg = (next & 15);
    
    if (colBg > 8)
    {
      colBg -= 8;
    }
    
    elementStyle.setFgColour(rgb2html(workingPalette[colFg]));
    elementStyle.setBgColour(rgb2html(workingPalette[colBg]));
    
    //FIXME:
    elementStyle.setBold(cur >= 0x20 && cur <= 0x7a);
    
    if (curX>=0 && curX<asciiArtWidth && curY>=0 && curY<asciiArtHeight){
      termBuffer[curX + curY*asciiArtWidth].c = cur;
      termBuffer[curX + curY*asciiArtWidth].style = elementStyle;
      curX++;
    } 
    if (count % asciiArtWidth == 0 ) {
      curY++;  
      if (maxY<curY && curY<asciiArtHeight) maxY=curY;
      curX=0;
    }
    count+=2; 
  } 
}

// the XBIN decoding function is based on AnsiLove:
// https://github.com/ansilove/
void CodeGenerator::parseXBinFile(){

    char header [11] = {0};
    char palette [48] = {0};

    if (in->read(header, 11)){
      
      asciiArtWidth = 0xff & ((header[ 6 ] << 8) + header[ 5 ]);
      asciiArtHeight = 0xff & ((header[ 8 ] << 8) + header[ 7 ]);
      int fontSize = header[ 9 ];
      int flags = header[ 10 ];
/*
      std::cerr<<"XBIN width:"<<asciiArtWidth<<"\n";
      std::cerr<<"XBIN height:"<<asciiArtHeight<<"\n";
      std::cerr<<"XBIN fontsize:"<<fontSize<<"\n";
      std::cerr<<"XBIN flags:"<<flags<<"\n";
*/
      allocateTermBuffer();
          
      if( (flags & 1) == 1 && in->read(palette, 48)) {
        int loop;
        int index;
        
        //override default palette
        for (loop = 0; loop < 16; loop++)
        {
          index = loop * 3;
          workingPalette[loop][0] = palette[index] << 2 | palette[index] >> 4;
          workingPalette[loop][1] = palette[index+1] << 2 | palette[index+1] >> 4;
          workingPalette[loop][2] = palette[index+2] << 2 | palette[index+2] >> 4;
        }
      }
      
      // skip font
      if( (flags & 2) == 2 ) {
        int numchars = ( flags & 0x10 ? 512 : 256 );      
        in->seekg ( fontSize * numchars, ios::cur);
      }
      
      // decode image
      if( (flags & 4) == 4) {
     //   std::cerr<<"DECODE--- starting at "<<in->tellg()<<"\n";
        int c=0;
        while( in && curY < asciiArtHeight)
        { 
          c = in->get();
          int compression = c & 0xC0;
          int cnt = ( c & 0x3F ) + 1;
          
          int cur = -1;
          int attr = -1;
          
          while( cnt-- ) {
            // none
            if( compression == 0 ) {
              cur = in->get();
              attr = in->get();
            }
            // char
            else if ( compression == 0x40 ) {
              if( cur == -1 ) {
                cur = in->get();
              }
              attr = in->get();
            }
            // attr
            else if ( compression == 0x80 ) {
              if( attr == -1 ) {
                attr = in->get();
              }
              cur = in->get();
            }
            // both
            else {
              if( cur == -1 ) {
                cur = in->get();
              }
              if( attr == -1 ) {
                attr = in->get();
              }
            }
            
            int colBg = (attr & 240) >> 4;
            int colFg = (attr & 15);
            
            if (colBg > 8)
            {
              colBg -= 8;
            }
            
            elementStyle.setFgColour(rgb2html(workingPalette[colFg]));
            elementStyle.setBgColour(rgb2html(workingPalette[colBg]));
            
            //FIXME:
            elementStyle.setBold(cur >= 0x20 && cur <= 0x7a);
            
            if (curX>=0 && curX<asciiArtWidth && curY>=0 && curY<asciiArtHeight){
              termBuffer[curX + curY*asciiArtWidth].c = cur;
              termBuffer[curX + curY*asciiArtWidth].style = elementStyle;
              curX++;
            }
          
            if (curX == asciiArtWidth)
            {
              curX = 0;
              curY++;
              if (maxY<curY && curY<asciiArtHeight) maxY=curY;
            }
          }
        }
    } else {
     // std::cerr<<"FLAT--- starting at "<<in->tellg()<<"\n";
      parseBinFile();
    } 
  }
}

void CodeGenerator::allocateTermBuffer(){
  
  if (termBuffer) delete [] termBuffer;
  
  termBuffer = new TDChar[asciiArtWidth*asciiArtHeight];
  for (int i=0; i<asciiArtWidth*asciiArtHeight; i++){
    termBuffer[i].c=0;
  }
}

bool CodeGenerator::streamIsXBIN() {
  bool isXBIN = false;
  char head[5] = {0};
  if (in->read (head, 4)) {
    isXBIN = string(head)=="XBIN";
    in->seekg (0, ios::beg);
  }
  return isXBIN;
}

////////////////////////////////////////////////////////////////////////////

void CodeGenerator::processInput()
{
  int cur=0;
  int next=0;
  
  if (parseCP437 || parseAsciiBin){
    elementStyle.setReset(false);
  }

  // deal with BIN/XBIN without file watching, reformatting and line numbering distractions
  if (parseAsciiBin){
    
    if (streamIsXBIN())
      parseXBinFile();
    else
      parseBinFile();

    printTermBuffer();
    return; 
  }
  
  // handle normal text files
  if (readAfterEOF && in!=&cin) {
    in->seekg (0, ios::end);
    // output the last few lines or the complete file if not too big
    if (in->tellg()>51200) {
      in->seekg (-512, ios::end);
      // output complete lines, ignore first line fragment
      in->ignore(512, '\n');
    } else {
      in->seekg (0, ios::beg); // output complete file
    }
  }
 
  if (streamIsXBIN()) {
   *out<<"Please apply --art-bin option for XBIN files.";
   return; 
  }
  
  string line;
  size_t i=0;
  bool tagOpen=false;
  bool isGrepOutput=false;
    
  if (parseCP437){
    allocateTermBuffer();
  }
  
  while (true) {
    
    bool eof=false;
    if ( preFormatter.isEnabled() ) {
      if ( !preFormatter.hasMoreLines() ) {
        eof=!getline(*in, line);
        preFormatter.setLine ( line );
        ++lineNumber;
        numberCurrentLine = true;
      } else {
        if(numberWrappedLines)
          ++lineNumber;
        numberCurrentLine = numberWrappedLines;
      }
      
      line = preFormatter.getNextLine();
    } else {
      eof=!getline(*in, line);
      ++lineNumber;
      numberCurrentLine = true;
    }
    
    if (eof) {
      // imitate tail bahaviour, continue to read after EOF
      if (readAfterEOF) {
        out->flush();
        in->clear();
        #ifdef WIN32
        Sleep(250);
        #else
        sleep(1);
        #endif
      } else {
        break;
      }
    } else {
      
      insertLineNumber();
      i=0;
      size_t seqEnd=string::npos;
      
      while (i <line.length() ) {
        // CSI ?
        cur = line[i]&0xff;
        
        if (parseCP437){

          if (cur==0x1b && line.length() - i > 2){
            next = line[i+1]&0xff;
            if (next==0x5b) {
              i+=2;
              seqEnd = i;
              //find sequence end
              while (   seqEnd<line.length() 
                && (line[seqEnd]<0x40 || line[seqEnd]>0x7e )) {
                ++seqEnd;
                }
                
                if ( line[seqEnd]=='m' ) {  
                  parseSGRParameters(line, i, seqEnd);
                } else {
                  parseCodePage437Seq(line, i, seqEnd);  
                }
                i=seqEnd+1;
            } else {
             ++i;
            }
          } else  if (cur==0x1a && line.length() - i > 6){
            // skip SAUCE info section
            while (line[i]==0x1a || !line[i]) ++i;
            if (line.substr(i, 5)=="SAUCE"){
              break; 
            }
          } else {
            if (curX>=0 && curX<asciiArtWidth && curY>=0 && curY<asciiArtHeight){
              termBuffer[curX + curY*asciiArtWidth].c = line[i];
              termBuffer[curX + curY*asciiArtWidth].style = elementStyle;
              curX++;
            } 
            
            if (curX==asciiArtWidth || line[i]=='\r' ) {
              curY++;  
              if (maxY<curY && curY<asciiArtHeight) maxY=curY;
              curX=0;
              if (line[i]=='\r') i=line.length();
            }
            
            
             /*if (line[i]=='\t'){
                curX += 8;
                std::cerr<<"tab\n";
             }*/
            
            ++i;
          }  
        } else {
          
          if (cur==0x1b || cur==0x9b || cur==0xc2) {
            if (line.length() - i > 2){
              
              next = line[i+1]&0xff;
              //move index behind CSI
              if ( (cur==0x1b && next==0x5b) || ( cur==0xc2 && next==0x9b) ) {
                ++i;
              }
              ++i;
              if (line[i-1]==0x5b || (line[i-1]&0xff)==0x9b){
                seqEnd=i;
                //find sequence end
                while (   seqEnd<line.length() 
                  && (line[seqEnd]<0x40 || line[seqEnd]>0x7e )) {
                  ++seqEnd;
                  }
                  
                  if (   line[seqEnd]=='m' && !ignoreFormatting ) {
                    if (!elementStyle.isReset()) {
                      *out <<getCloseTag();
                      tagOpen=false;
                    }
                    parseSGRParameters(line, i, seqEnd);
                    if (!elementStyle.isReset()) {
                      *out <<getOpenTag();
                      tagOpen=true;
                    }
                  }
                  
                  isGrepOutput = line[seqEnd]=='K' && line[seqEnd-3] == 'm';
                  // fix grep special K
                  if (   line[seqEnd]=='s' || line[seqEnd]=='u'
                    || (line[seqEnd]=='K' && !isGrepOutput) )
                    i=line.length();
                  else
                    i =   // ((line[seqEnd]=='m' || line[seqEnd]=='C'|| isGrepOutput) ?  1 : 0 )
                    1 + ((seqEnd!=line.length())?seqEnd:i);
              } else {
                cur= line[i-1]&0xff;
                next = line[i]&0xff;
                
                //ignore content of two and single byte sequences (no CSI)
                if (cur==0x1b && (  next==0x50 || next==0x5d || next==0x58
                  ||next==0x5e||next==0x5f) )
                {
                  seqEnd=i;
                  //find string end
                  while ( seqEnd<line.length() && (line[seqEnd]&0xff)!=0x9e 
                    && line[seqEnd]!=0x07 ) {
                    ++seqEnd;
                    }
                    i=seqEnd+1;
                }
              }
            }
          } else if (cur==0x90 || cur==0x9d || cur==0x98 || cur==0x9e ||cur==0x9f) {
            seqEnd=i;
            //find string end
            while (   seqEnd<line.length() && (line[seqEnd]&0xff)!=0x9e
              && line[seqEnd]!=0x07 ) {
              ++seqEnd;
              }
              i=seqEnd+1;
          } else {
            // output printable character
            *out << maskCharacter(line[i]);
            ++i;
          }
        }
      }
      if (!parseCP437) *out << newLineTag;
    }
  } // while (true)
  
  if (tagOpen) {
    *out <<getCloseTag();
  }
  
  if (parseCP437){
    printTermBuffer();
  }
  out->flush();
}

/* the following functions are based on Wolfgang Frischs xterm256 converter utility:
   http://frexx.de/xterm-256-notes/
*/
void CodeGenerator::xterm2rgb(unsigned char color, unsigned char* rgb)
{
    // 16 basic colors
    if(color<16) {
        rgb[0] = workingPalette[color][0];
        rgb[1] = workingPalette[color][1];
        rgb[2] = workingPalette[color][2];
    }

    // color cube color
    if(color>=16 && color<=232) {
        color-=16;
        rgb[0] = valuerange[(color/36)%6];
        rgb[1] = valuerange[(color/6)%6];
        rgb[2] = valuerange[color%6];
    }

    // gray tone
    if(color>232) {
        rgb[0]=rgb[1]=rgb[2] = 8+(color-232)*0x0a;
    }
}

string CodeGenerator::rgb2html(unsigned char* rgb){
  char colorString[10]= {0};
  sprintf(colorString, "#%02x%02x%02x", rgb[0], rgb[1], rgb[2]);
  return string(colorString);
}

const unsigned char CodeGenerator::valuerange[] = { 0x00, 0x5F, 0x87, 0xAF, 0xD7, 0xFF };

unsigned char CodeGenerator::defaultPalette[16][3] = {
  { 0x00, 0x00, 0x00 }, // 0 ColorBlack
  { 0xCD, 0x00, 0x00 }, // 1 ColorRed
  { 0x00, 0xCD, 0x00 }, // 2 ColorGreen
  { 0xCD, 0xCD, 0x00 }, // 3 ColorYellow
  { 0x00, 0x00, 0xEE }, // 4 ColorBlue
  { 0xCD, 0x00, 0xCD }, // 5 ColorMagenta
  { 0x00, 0xCD, 0xCD }, // 6 ColorCyan
  { 0xE5, 0xE5, 0xE5 }, // 7 ColorGray
  { 0x7F, 0x7F, 0x7F }, // 8 ColorDarkGray
  { 0xFF, 0x00, 0x00 }, // 9 ColorBrightRed
  { 0x00, 0xFF, 0x00 }, // 10 ColorBrightGreen
  { 0xFF, 0xFF, 0x00 }, // 11 ColorBrightYellow
  { 0x5C, 0x5C, 0xFF }, // 12 ColorBrightBlue
  { 0xFF, 0x00, 0xFF }, // 13 ColorBrightMagenta
  { 0x00, 0xFF, 0xFF }, // 14 ColorBrightCyan
  { 0xFF, 0xFF, 0xFF }  // 15 ColorBrightWhite
}; 

unsigned char CodeGenerator::workingPalette[16][3] = {
    { 0x00, 0x00, 0x00 }, // 0 ColorBlack
    { 0xCD, 0x00, 0x00 }, // 1 ColorRed
    { 0x00, 0xCD, 0x00 }, // 2 ColorGreen
    { 0xCD, 0xCD, 0x00 }, // 3 ColorYellow
    { 0x00, 0x00, 0xEE }, // 4 ColorBlue
    { 0xCD, 0x00, 0xCD }, // 5 ColorMagenta
    { 0x00, 0xCD, 0xCD }, // 6 ColorCyan
    { 0xE5, 0xE5, 0xE5 }, // 7 ColorGray
    { 0x7F, 0x7F, 0x7F }, // 8 ColorDarkGray
    { 0xFF, 0x00, 0x00 }, // 9 ColorBrightRed
    { 0x00, 0xFF, 0x00 }, // 10 ColorBrightGreen
    { 0xFF, 0xFF, 0x00 }, // 11 ColorBrightYellow
    { 0x5C, 0x5C, 0xFF }, // 12 ColorBrightBlue
    { 0xFF, 0x00, 0xFF }, // 13 ColorBrightMagenta
    { 0x00, 0xFF, 0xFF }, // 14 ColorBrightCyan
    { 0xFF, 0xFF, 0xFF }  // 15 ColorBrightWhite
}; 

bool CodeGenerator::setColorMap(const string& mapPath){
  
  //restore default colors
  if (mapPath.length()==0){
   memcpy(workingPalette, defaultPalette, sizeof defaultPalette);
   return true;
  }
  
  ifstream mapFile ( mapPath.c_str() );
  if ( mapFile ) {

      string line;
      
      unsigned int idx=0;
      char sep='\0';
          
      string colorCode;
      while ( getline ( mapFile, line ) ) {
        stringstream s(line);

        s>>idx;
        if (idx>15) return false;

        s>>sep;
        if (sep!='=') return false;

        s>>colorCode;
        if (colorCode.size()>=7 && colorCode[0]=='#' ) {  
          workingPalette[idx][0] = (char)std::strtol(colorCode.substr ( 1, 2 ).c_str(), NULL, 16);
          workingPalette[idx][1] = (char)std::strtol(colorCode.substr ( 3, 2 ).c_str(), NULL, 16);
          workingPalette[idx][2] = (char)std::strtol(colorCode.substr ( 5, 2 ).c_str(), NULL, 16);  
        } else {
          return false;
        }
      }
      mapFile.close();
  } else {
      return false;
  } 
  return true;
}

}
