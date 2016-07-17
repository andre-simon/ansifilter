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
     outputType(type),

     ignoreFormatting(false),
     readAfterEOF(false)
{
    elementStyle.setFgColour(rgb2html(basic16[0]));
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

    in = (inFileName.empty()? &cin :new ifstream (inFileName.c_str()));


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

    in = new ifstream (inFileName.c_str());
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
            elementStyle.setFgColour(rgb2html(basic16[8]));
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
              
              elementStyle.setFgColour(rgb2html(basic16[ansiCode-30+8]));
            } else
              elementStyle.setFgColour(rgb2html(basic16[ansiCode-30]));
            elementStyle.setBold(false);
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
          /*   if (elementStyle.isBold())
              elementStyle.setBgColour(rgb2html(basic16[ansiCode-40+8]));
            else */
              elementStyle.setBgColour(rgb2html(basic16[ansiCode-40]));
            /*elementStyle.setBold(false);*/
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
            elementStyle.setFgColour(rgb2html(basic16[ansiCode-90+8]));
            break;
    
        case 100:
        case 101:
        case 102:
        case 103:
        case 104:
        case 105:
        case 106:
        case 107:
            elementStyle.setBgColour(rgb2html(basic16[ansiCode-100+8]));
            break;

        }

        // Set RTF color index
        // 8 default colours followed by bright colors see rtfgenerator.cpp
        if (ansiCode>=30 and ansiCode <40)
            elementStyle.setFgColourID(ansiCode-30);
        else if (ansiCode>=90 and ansiCode <98)
            elementStyle.setFgColourID(ansiCode-90+8);

        else if (ansiCode>=40 and ansiCode <50)
            elementStyle.setBgColourID(ansiCode-40);
        else if (ansiCode>=100 and ansiCode <108)
            elementStyle.setBgColourID(ansiCode-100+8);

        if (itVectorData != codeVector.end()) itVectorData++;
    }

    return true;
}


void CodeGenerator::parseAnsiSysSeq(string line, size_t begin, size_t end, int& curX, int& curY){
  
  string codes=line.substr(begin, end-begin);
  vector<string> codeVector = StringTools::splitString(codes, ',');
  
  if (line[end]=='H'){
   if (codeVector.size()==2){
     curX = atoi(codeVector[0].c_str());
     curY = atoi(codeVector[1].c_str());
   } else {
     curX = curY = 0;
   }
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
  }
  
  if (line[end]=='C'){
    //std::cerr<<"C 1: "<<curX<<"\n";
    
    if (codeVector.size()==1){
      curX += atoi(codeVector[0].c_str());
    } else {
      curX++;
    }
  //  std::cerr<<"C 2: "<<curX<<"\n";
  }
  
  if (line[end]=='D'){
//    std::cerr<<"D 1: "<<curX<<"\n";
    if (codeVector.size()==1){
      curX -= atoi(codeVector[0].c_str());
    } else {
      curX--;
    }
    if (curX<0) curX=0;
  //  std::cerr<<"D 2: "<<curX<<"\n";
    
  }
  
  if (line[end]=='J'){
    std::cerr<<"J!!!\n";
    /*
    if (codeVector.size()==1 && codeVector[0]=="2"){
      for (int i=0;i<100*100;i++) *termBuffer[i]->c =0;
    } 
    */
  }
  
  if (line[end]=='K'){
    std::cerr<<"K!!!\n";
      //for (int i=*curX;i<80;i++) *termBuffer[i]->c =0;
     
  }
  if (line[end]=='S'){
    std::cerr<<"S!!!\n";
    //for (int i=*curX;i<80;i++) *termBuffer[i]->c =0;
    
  }
  if (line[end]=='M'){
    std::cerr<<"M!!!\n";
    //for (int i=*curX;i<80;i++) *termBuffer[i]->c =0;
    
  }
}

void CodeGenerator::insertLineNumber ()
{
    if ( showLineNumbers ) {

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

////////////////////////////////////////////////////////////////////////////

void CodeGenerator::processInput()
{

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

    string line;
    size_t i=0;
    bool tagOpen=false;
    bool isGrepOutput=false;
    
    bool parseTheDrawFile=false;
    
    
    TDChar termBuffer[80*100] = { 0 };
    int curX = 0, curY = 0;

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
            int cur=0;
            int next=0;
            
            
            while (i <line.length() ) {
              // CSI ?
              cur = line[i]&0xff;
             
              // http://www.syaross.org/thedraw/ : make this optional
              if (parseTheDrawFile){
                
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
                       parseAnsiSysSeq(line, i, seqEnd, curX, curY);
                       
                    }
                     
                     i=seqEnd+1;  
                  }
                } else {
                  if (curX>=0 && curX<80 && curY>=0 && curY<100){
                    termBuffer[curX + curY*80].c = line[i];
                    termBuffer[curX + curY*80].style = elementStyle;
                    curX++;
                  }
                  
                  if (line[i]=='\r') {
                    curY++;
                    curX=0;
                    i=line.length();
                   }
                  ++i;
                }
                
              }
              
              
              if (!parseTheDrawFile){
              
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
                } 
                else if (cur==0x90 || cur==0x9d || cur==0x98 || cur==0x9e ||cur==0x9f) {
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
            if (!parseTheDrawFile) *out << newLineTag;
        }
    }
    if (tagOpen) {
        *out <<getCloseTag();
    }
    
    if (parseTheDrawFile){
     for (int y=0;y<100;y++) {
       for (int x=0;x<80;x++) {
         if (termBuffer[x + y* 80].c=='\r') {
           *out<<"\n";
           break;
         }
         elementStyle = termBuffer[x + y* 80].style;
        
         if (!elementStyle.isReset()) {
           *out <<getOpenTag();
           tagOpen=true;
         }
         
         *out << maskCP437Character(termBuffer[x + y* 80].c);
         if (!elementStyle.isReset()) {
           *out <<getCloseTag();
           tagOpen=false;
         }
       }
     }
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
        rgb[0] = basic16[color][0];
        rgb[1] = basic16[color][1];
        rgb[2] = basic16[color][2];
    }

    // color cube color
    if(color>=16 && color<=232) {
        color-=16;
        rgb[0] = valuerange[(color/36)%6];
        rgb[1] = valuerange[(color/6)%6];
        rgb[2] = valuerange[color%6];
    }

    // gray tone
    if(color>232 /* && color<255*/) {
        rgb[0]=rgb[1]=rgb[2] = 8+(color-232)*0x0a;
    }
}

string CodeGenerator::rgb2html(unsigned char* rgb){
  char colorString[10]= {0};
  sprintf(colorString, "#%02x%02x%02x", rgb[0], rgb[1], rgb[2]);
  return string(colorString);
}

const unsigned char CodeGenerator::valuerange[] = { 0x00, 0x5F, 0x87, 0xAF, 0xD7, 0xFF };

unsigned char CodeGenerator::basic16[16][3] = {
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
          basic16[idx][0] = (char)std::strtol(colorCode.substr ( 1, 2 ).c_str(), NULL, 16);
          basic16[idx][1] = (char)std::strtol(colorCode.substr ( 3, 2 ).c_str(), NULL, 16);
          basic16[idx][2] = (char)std::strtol(colorCode.substr ( 5, 2 ).c_str(), NULL, 16);  
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
