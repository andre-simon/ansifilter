/***************************************************************************
                    bbcodegenerator.cpp  -  description
                             -------------------

    copyright            : (C) 2011 by Andre Simon
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

#include <fstream>
#include <iostream>
#include <sstream>

#include "bbcodegenerator.h"
#include "version.h"

using namespace std;

namespace ansifilter {

BBCodeGenerator::BBCodeGenerator ():
  CodeGenerator(BBCODE),
  fileSuffix(".bbcode")
{
  newLineTag="\n";
}

string BBCodeGenerator::getOpenTag() 
{
	ostringstream s;

	s << "[color=#"
	   << elementStyle.getFgColour().getRed(HTML)
	<< elementStyle.getFgColour().getGreen(HTML)
	<< elementStyle.getFgColour().getBlue(HTML)
	   << "]";

	if ( elementStyle.isBold() ) s << "[b]";
	if ( elementStyle.isItalic() ) s << "[i]";
	if ( elementStyle.isUnderline() ) s << "[u]";
	
	return s.str();
}

string BBCodeGenerator::getCloseTag()  {
  	ostringstream s;

	if ( elementStyle.isUnderline() ) s << "[/u]";
	if ( elementStyle.isItalic() ) s << "[/i]";
	if ( elementStyle.isBold() ) s << "[/b]";
	s << "[/color]";
	return  s.str();
}


string BBCodeGenerator::getHeader()
{
  return "";
}

string BBCodeGenerator::getFooter()
{

  return "";
}

void BBCodeGenerator::printBody()
{
  processRootState();
}

string BBCodeGenerator::maskCharacter(unsigned char c)
{
  
    switch (c) {

    case '\t' : // see deletion of nonprintable chars below
      return "\t";
      break;
    default :
      if (c>0x1f ){ // printable?
	return string( 1, c );
      } else {
	return "";
      }
    }
      
    return ""; 
}

}
