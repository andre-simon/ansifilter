/***************************************************************************
                         bbcdegenerator.h  -  description
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


#ifndef BBCodeGenerator_H
#define BBCodeGenerator_H

#include <string>

#include "codegenerator.h"

namespace ansifilter {

/**
   \brief This class generates HTML.

   It contains information about the resulting document structure (document
   header and footer), the colour system, white space handling and text
   formatting attributes.

* @author Andre Simon
*/

class BBCodeGenerator  : public ansifilter::CodeGenerator
  {
  public:

    BBCodeGenerator();

    virtual ~BBCodeGenerator() {};

  protected:

    string fileSuffix;   ///< filename extension

  private:

    string getOpenTag();
    string getCloseTag();

    /** Print document header
    */
    string getHeader();

    /** Print document body*/
    void printBody();

    /** Print document footer*/
    string getFooter();

    /** \return escaped character*/
    virtual string maskCharacter(unsigned char );
  };

}

#endif
