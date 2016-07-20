/***************************************************************************
                          rtfcode.cpp  -  description
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

#include <sstream>

#include "charcodes.h"
#include "version.h"
#include "rtfgenerator.h"
#include "stylecolour.h"

namespace ansifilter
{

string RtfGenerator::getAttributes( const StyleColour & col)
{
    stringstream s;
    s  << "\\red"<< col.getRed(RTF)
       << "\\green"<<col.getGreen(RTF)
       << "\\blue"<<col.getBlue(RTF)
       << ";";
    return s.str();
}

string  RtfGenerator::getOpenTag()
{
    ostringstream s;
    if (elementStyle.getFgColourID()>=0) {
    //  std::cerr <<"elementStyle.getFgColourID():"<<elementStyle.getFgColourID()<<"\n";
        s << "{\\cf"<<(elementStyle.getFgColourID()+ (parseCP437)? 9 : 1); // FIXME Bug?
    }
    if (elementStyle.getBgColourID()>=0) {
        s <<  "\\chcbpat"<<(elementStyle.getBgColourID()+1);
    }
    s <<"{";
    if (!parseCP437 &&  elementStyle.isBold()) s << "\\b ";
    if (elementStyle.isItalic()) s << "\\i ";
    if (elementStyle.isUnderline()) s << "\\ul ";
    return  s.str();
}

string  RtfGenerator::getCloseTag()
{
    ostringstream s;
    if (!parseCP437 && elementStyle.isBold()) s << "\\b0 ";
    if (elementStyle.isItalic()) s << "\\i0 ";
    if (elementStyle.isUnderline()) s << "\\ul0 ";
    s << "}}";
    return  s.str();
}

RtfGenerator::RtfGenerator()
    : CodeGenerator(RTF),
      pageSize("a4"), // Default: DIN A4
      isUtf8(false),
      utf16Char(0),
      utf8SeqLen(0)
{
    newLineTag = "\\line\n";
    spacer=" ";

    // Page dimensions
    psMap["a3"] = PageSize(16837,23811);
    psMap["a4"] = PageSize(11905,16837);
    psMap["a5"] = PageSize(8390,11905);

    psMap["b4"] = PageSize(14173,20012);
    psMap["b5"] = PageSize(9977,14173);
    psMap["b6"] = PageSize(7086,9977);

    psMap["letter"] = PageSize(12240,15840);
    psMap["legal"] = PageSize(12240,20163);
}

RtfGenerator::~RtfGenerator()
{}

string RtfGenerator::getHeader()
{
    return string();
}

void RtfGenerator::printBody()
{
    isUtf8 = encoding == "utf-8" || encoding == "UTF-8"; // FIXME
  
    *out << "{\\rtf1";
    
    if (parseCP437) 
      *out<< "\\cpg437"; // \\cpg437
    else 
      *out<< "\\ansi";
    
    *out <<" \\deff1"
         << "{\\fonttbl{\\f1\\fmodern\\fprq1\\fcharset0 " ;
    *out << font ;
    *out << ";}}"
         << "{\\colortbl;";

    for (int i=0;i<16;i++){
      *out << getAttributes(StyleColour(rgb2html(basic16[i])));
    }

    *out << "}\n";

    *out  << "\\paperw"<< psMap[pageSize].width <<"\\paperh"<< psMap[pageSize].height
          << "\\margl1134\\margr1134\\margt1134\\margb1134\\sectd" // page margins
          << "\\plain\\f1\\fs" ;  // Font formatting
    int fontSizeRTF=0;
    StringTools::str2num<int>(fontSizeRTF, fontSize, std::dec);
    *out << ((fontSizeRTF)? fontSizeRTF*2: 20);  // RTF needs double amount
    *out << "\n\\pard";
    if (parseCP437)
      *out << "\\cbpat1{";

    processInput();

    if (parseCP437)
      *out << "}";
    *out << "}"<<endl;
}

string RtfGenerator::getFooter()
{
    return string();
}

string RtfGenerator::maskCharacter(unsigned char c)
{
  if (isUtf8 && c > 0x7f  && utf8SeqLen==0){
    
    //http://stackoverflow.com/questions/7153935/how-to-convert-utf-8-stdstring-to-utf-16-stdwstring
    
    if (c <= 0xDF)
    {
      utf16Char = c&0x1F;
      utf8SeqLen = 1;
    }
    else if (c <= 0xEF)
    {
      utf16Char = c&0x0F;
      utf8SeqLen = 2;
    }
    else if (c <= 0xF7)
    {
      utf16Char = c&0x07;
      utf8SeqLen = 3;
    } else {
      utf8SeqLen = 0;
    }
    return "";
  }
  
  if (utf8SeqLen) {
    utf16Char <<= 6;
    utf16Char += c & 0x3f;   
    --utf8SeqLen;
    
    if (!utf8SeqLen){
      string m ( "\\u" );
      m += to_string(utf16Char);
      m += '?';
      utf16Char=0L;
      return m;
    } else {
      return "";
    }
  }
  
  switch (c) {
    case '}' :
    case '{' :
    case '\\' : {
        string m;
        m="\\";
        return m+=c;
    }
    break;
    case '\t' : // see deletion of nonprintable chars below
        return "\t";
        break;

    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9': {
        string m;
        m="{";
        m+=c;
        m+="}";
        return m;
    }
    break;

    case AUML_LC:
        return "\\'e4";
        break;
    case OUML_LC:
        return "\\'f6";
        break;
    case UUML_LC:
        return "\\'fc";
        break;
    case AUML_UC:
        return "\\'c4";
        break;
    case OUML_UC:
        return "\\'d6";
        break;
    case UUML_UC:
        return "\\'dc";
        break;

    case AACUTE_LC:
        return "\\'e1";
        break;
    case EACUTE_LC:
        return "\\'e9";
        break;
    case OACUTE_LC:
        return "\\'f3";
        break;
    case UACUTE_LC:
        return "\\'fa";
        break;

    case AGRAVE_LC:
        return "\\'e0";
        break;
    case EGRAVE_LC:
        return "\\'e8";
        break;
    case OGRAVE_LC:
        return "\\'f2";
        break;
    case UGRAVE_LC:
        return "\\'f9";
        break;

    case AACUTE_UC:
        return "\\'c1";
        break;
    case EACUTE_UC:
        return "\\'c9";
        break;
    case OACUTE_UC:
        return "\\'d3";
        break;
    case UACUTE_UC:
        return "\\'da";
        break;
    case AGRAVE_UC:
        return "\\'c0";
        break;
    case EGRAVE_UC:
        return "\\'c8";
        break;
    case OGRAVE_UC:
        return "\\'d2";
        break;
    case UGRAVE_UC:
        return "\\'d9";
        break;

    case SZLIG:
        return "\\'df";
        break;
        
        
    case 0xdb:
      return "\\u221e?";
      break;
    case 0xdc:
      return "\\u221e?";
      break;
    case 0xdd:
      return "\\u221e?";
      break;
    case 0xde:
      return "\\u221e?";
      break;      
    case 0xdf:
      return "\\u221e?";
      break;      

    default : {
        if (c>0x1f ) {
            return string( 1, c );
        } else {
            return "";
        }
    }
  }
}

string RtfGenerator::maskCP437Character(unsigned char c)
{
  
  switch (c) {
    case 0:
   // case ' ' :
      return " "; break;
      
    case '}' :
    case '{' :
    case '\\' : {
      string m;
      m="\\";
      return m+=c;
    }
    break;
    case '\t' : // see deletion of nonprintable chars below
      return "\t";
      break;
      
      
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9': {
      string m;
      m="{";
      m+=c;
      m+="}";
      return m;
    }
    break;
    
      //shades
    case 0xb0:   
      return "\\u9617?";
      break;
    case 0xb1:   
      return "\\u9618?";
      break;
    case 0xb2:   
      return "\\u9619?";
      break;
      
      //box drawings
    case 0xb3:   
      return "\\u9474?";
      break;
    case 0xb4:   
      return "\\u9508?";
      break;
    case 0xb5:   
      return "\\u9569?";
      break;
    case 0xb6:   
      return "\\u9570?";
      break;
    case 0xb7:   
      return "\\u9558?";
      break;
    case 0xb8:   
      return "\\u9557?";
      break;
    case 0xb9:   
      return "\\u9571?";
      break;
    case 0xba:   
      return "\\u9553?";
      break;
    case 0xbb:   
      return "\\u9559?";
      break;
    case 0xbc:   
      return "\\u9565?";
      break;
    case 0xbd:   
      return "\\u9564?";
      break;
    case 0xbe:   
      return "\\u9563?";
      break;
    case 0xbf:   
      return "\\u9488?";
      break;
      
    case 0xc0:   
      return "\\u9492?";
      break;
    case 0xc1:   
      return "\\u9524?";
      break;
    case 0xc2:   
      return "\\u9516?";
      break;
    case 0xc3:   
      return "\\u9500?";
      break;
    case 0xc4:   
      return "\\u9472?";
      break;
    case 0xc5:   
      return "\\u9532?";
      break;
    case 0xc6:   
      return "\\u9566?";
      break;
    case 0xc7:   
      return "\\u9567?";
      break;
    case 0xc8:   
      return "\\u9562?";
      break;
    case 0xc9:   
      return "\\u9556?";
      break;
    case 0xca:   
      return "\\u9577?";
      break;
    case 0xcb:   
      return "\\u9574?";
      break;
    case 0xcc:   
      return "\\u9568?";
      break;
    case 0xcd:   
      return "\\u9552?";
      break;
    case 0xce:   
      return "\\u9580?";
      break;
    case 0xcf:   
      return "\\u9575?";
      break;
  
    case 0xd0:   
      return "\\u9576?";
      break;
    case 0xd1:   
      return "\\u9572?";
      break;
    case 0xd2:   
      return "\\u9573?";
      break;
    case 0xd3:   
      return "\\u9561?";
      break;
    case 0xd4:   
      return "\\u9560?";
      break;
    case 0xd5:   
      return "\\u9554?";
      break;
    case 0xd6:   
      return "\\u9555?";
      break;
    case 0xd7:   
      return "\\u9579?";
      break;
    case 0xd8:   
      return "\\u9578?";
      break;
    case 0xd9:   
      return "\\u9496?";
      break;
    case 0xda:   
      return "\\u9484?";
      break;
          
      //https://de.wikipedia.org/wiki/Unicodeblock_Blockelemente
    case 0xdb:
      return "\\u9608?";
      break;
    case 0xdc:
      return "\\u9604?";
      break;
    case 0xdd:
      return "\\u9612?";
      break;
    case 0xde:
      return "\\u9616?";
      break;      
    case 0xdf:
      return "\\u9600?";
      break;

    case 0xf9:
      return "\\u8729?";
      break;
    case 0xfa:
      return "\\u8729?";
      break;
      
      
      
    default : {
      if (c ) {
        return string( 1, c );
        //char hexVal[3]={ 0 };
        //sprintf(hexVal, "%02X", c);
        //return "\\'" + string(hexVal); 
      } else {
        return "";
      }
    }
  }
}


void RtfGenerator::setPageSize(const string & ps)
{
    if (psMap.count(ps)) pageSize = ps;
}


void RtfGenerator::insertLineNumber ()
{
    if ( showLineNumbers && !parseCP437 ) {

        ostringstream lnum;
        lnum << setw ( 5 ) << right;
        if( numberCurrentLine ) {
            lnum << lineNumber;
            *out <<lnum.str()<<spacer;
        } else {
            *out << lnum.str(); //for indentation
        }
    }
}

}
