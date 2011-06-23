/***************************************************************************
                     htmlgenerator.cpp  -  description
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

#include "plaintextgenerator.h"
#include "version.h"

using namespace std;

namespace ansifilter {

PlaintextGenerator::PlaintextGenerator ():
  CodeGenerator(TEXT),
  fileSuffix(".txt")
{
  newLineTag="\n";
  styleCommentOpen="";
  styleCommentClose="";
}


string PlaintextGenerator::getHeader()
{
  return "";
}

string PlaintextGenerator::getFooter()
{
  return "";
}

void PlaintextGenerator::printBody()
{
  processRootState();
}

string PlaintextGenerator::maskCharacter(unsigned char c)
{
       if (c>0x1f ){
        return string( 1, c );
      } else {
        return "";
     }
}

}
