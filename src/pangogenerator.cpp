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

namespace ansifilter
{

PangoGenerator::PangoGenerator ():
    CodeGenerator(PANGO),
    fileSuffix(".pango")
{
    newLineTag="\n";
    styleCommentOpen="";
    styleCommentClose="";
    spacer=" ";
}

string PangoGenerator::getOpenTag()
{
    ostringstream fmtStream;


    if (elementStyle.isBold()) {
        fmtStream<< " font-weight=\"bold\"";
    }
    if (elementStyle.isItalic()) {
        fmtStream<< " font-style=\"italic\"";
    }
    if (elementStyle.isUnderline()) {
        fmtStream<< " underline=\"single\"";
    }

    if (elementStyle.isFgColorSet()) {
        fmtStream << " fgcolor=\"#"
           << elementStyle.getFgColour().getRed(HTML)
           << elementStyle.getFgColour().getGreen(HTML)
           << elementStyle.getFgColour().getBlue(HTML)
           << "\"";
    }
    if (elementStyle.isBgColorSet()) {
        fmtStream <<" bgcolor=\"#"
           << elementStyle.getBgColour().getRed(HTML)
           << elementStyle.getBgColour().getGreen(HTML)
           << elementStyle.getBgColour().getBlue(HTML)
           << "\"";
    }  
    string fmt  = fmtStream.str();
    tagIsOpen = fmt.size()>0;
    if (tagIsOpen) {
        ostringstream spanTag;
        spanTag<< "<span "<<fmt<<">";
        return spanTag.str();
    }
    return "";
}

string PangoGenerator::getCloseTag()
{
    string retVal = tagIsOpen ? "</span>"  : "";
    tagIsOpen = false;
    return retVal;
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
    processInput();
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
    case '\t':
        return "\t";
        break;
	
    default :
        if (c>0x1f ) { // printable?
            return string( 1, c );
        } else {
            return "";
        }
    }
}
}
