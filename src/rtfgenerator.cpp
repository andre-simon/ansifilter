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

using namespace std;

namespace ansifilter {

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
  s << "{\\cf"<<(elementStyle.getFgColourID()+1);
  if (elementStyle.getBgColourID()>=0){
   s <<  "\\chcbpat"<<(elementStyle.getBgColourID()+1);
   }
  s <<"{";
  if (elementStyle.isBold()) s << "\\b ";
  if (elementStyle.isItalic()) s << "\\i ";
  if (elementStyle.isUnderline()) s << "\\ul ";
  return  s.str();
}

string  RtfGenerator::getCloseTag()
{
  ostringstream s;
  if (elementStyle.isBold()) s << "\\b0 ";
  if (elementStyle.isItalic()) s << "\\i0 ";
  if (elementStyle.isUnderline()) s << "\\ul0 ";
  s << "}}";
  return  s.str();
}

RtfGenerator::RtfGenerator()
 : CodeGenerator(RTF),
   pageSize("a4") // Default: DIN A4
{
  newLineTag = "\\line\n";

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

 *out << "{\\rtf1\\ansi\\uc0 \\deff1"
       << "{\\fonttbl{\\f1\\fmodern\\fprq1\\fcharset0 " ;
 *out << font ;
 *out << ";}}"
      << "{\\colortbl;";

  *out << getAttributes(StyleColour(ColorBlack));
  *out << getAttributes(StyleColour(ColorRed));
  *out << getAttributes(StyleColour(ColorGreen));
  *out << getAttributes(StyleColour(ColorYellow));
  *out << getAttributes(StyleColour(ColorBlue));
  *out << getAttributes(StyleColour(ColorMagenta));
  *out << getAttributes(StyleColour(ColorCyan));
  *out << getAttributes(StyleColour(ColorWhite));
  
    *out << getAttributes(StyleColour(ColorBlack));
  *out << getAttributes(StyleColour(ColorBrightRed));
  *out << getAttributes(StyleColour(ColorBrightGreen));
  *out << getAttributes(StyleColour(ColorBrightYellow));
  *out << getAttributes(StyleColour(ColorBrightBlue));
  *out << getAttributes(StyleColour(ColorBrightMagenta));
  *out << getAttributes(StyleColour(ColorBrightCyan));
  *out << getAttributes(StyleColour(ColorBrightWhite));

  *out << "}\n";

  *out  << "\\paperw"<< psMap[pageSize].width <<"\\paperh"<< psMap[pageSize].height
        << "\\margl1134\\margr1134\\margt1134\\margb1134\\sectd" // page margins
        << "\\plain\\f1\\fs" ;  // Font formatting
  int fontSizeRTF=0;
  StringTools::str2num<int>(fontSizeRTF, fontSize, std::dec);
  *out << ((fontSizeRTF)? fontSizeRTF*2: 20);  // RTF needs double amount
  *out << "\n\\pard ";

  processRootState();

  *out << "}"<<endl;
}

string RtfGenerator::getFooter()
{
 return string();
}

string RtfGenerator::maskCharacter(unsigned char c)
{
  switch (c)
    {
    case '}' :
    case '{' :
    case '\\' :
      {
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
    case '9':
      {
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

    default :
      {
       if (c>0x1f ){
        return string( 1, c );
      } else {
        return "";
     }
      }
    }
}

void RtfGenerator::setPageSize(const string & ps){
    if (psMap.count(ps)) pageSize = ps;
}

}
