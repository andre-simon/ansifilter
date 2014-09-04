/***************************************************************************
                     pangogenerator.cpp  -  description
                             -------------------

    copyright            : (C) 2014 by Dominik Schmidt

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

#include <fstream>
#include <iostream>
#include <sstream>

#include "pangogenerator.h"
#include "version.h"

using namespace std;

namespace ansifilter {

PangoGenerator::PangoGenerator ():
  CodeGenerator(PANGO),
  fileSuffix(".pango")
{
  newLineTag="\n";
  styleCommentOpen="";
  styleCommentClose="";
}

string PangoGenerator::getOpenTag() 
{
	ostringstream os;
	os<< "<span";

	if (elementStyle.isBold()) {
		os<< " font-weight=\"bold\"";
	}
	if (elementStyle.isItalic()) {
		os<< " font-style=\"italic\"";
	}
	if (elementStyle.isUnderline()) {
		os<< " underline=\"single\"";
	}

	if (elementStyle.isFgColorSet()){
		os << " fgcolor=\"#"
		<< elementStyle.getFgColour().getRed(HTML)
		<< elementStyle.getFgColour().getGreen(HTML)
		<< elementStyle.getFgColour().getBlue(HTML)
		<< "\"";
	}
	if (elementStyle.isBgColorSet()){
	    os <<" bgcolor=\"#"
	    << elementStyle.getBgColour().getRed(HTML) 
	    << elementStyle.getBgColour().getGreen(HTML)
	    << elementStyle.getBgColour().getBlue(HTML)
	    <<"\"";
	}

	os<<">";
	return os.str();
}

string PangoGenerator::getCloseTag()  {
  return "</span>";
}

string PangoGenerator::getHeader()
{

  int fontSizePango=0;
  StringTools::str2num<int>(fontSizePango, fontSize, std::dec);
  
  ostringstream os;
  os << "<span";
  os << " font_family=\""<<font << "\"";
  os << " font_size=\""<<((fontSizePango)? fontSizePango*1024: 1024*10) << "\"";
  os << ">";
  return os.str();
}

string PangoGenerator::getFooter()
{
  return "</span>";
}

void PangoGenerator::printBody()
{
  processRootState();
}

string PangoGenerator::maskCharacter(unsigned char c)
{
  switch (c) {
    case '<' :
      return "&lt;";
      break;
    case '>' :
      return "&gt;";
      break;
    case '&' :
      return "&amp;";
      break;
	  
    default :
       if (c>0x1f ){ // printable?
        return string( 1, c );
      } else {
        return "";
     }
    }
}
}
