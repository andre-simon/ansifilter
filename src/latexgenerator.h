/***************************************************************************
                          texgenerator.h  -  description
                             -------------------

    copyright            : (C) 2008 by Hans Meine
    email                : hans_meine@gmx.net
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


#ifndef LATEXGENERATOR_H
#define LATEXGENERATOR_H

#include <string>

#include "codegenerator.h"

namespace ansifilter {

/**
   \brief This class generates LATEX.

   It contains information about the resulting document structure (document
   header and footer), the colour system, white space handling and text
   formatting attributes.

* @author Hans Meine
*/

class LaTeXGenerator  : public ansifilter::CodeGenerator
  {
  public:

    LaTeXGenerator();

    virtual ~LaTeXGenerator() {};

  protected:

    string fileSuffix;   ///< filename extension

    /** \return Comment with program information */
    string getGeneratorComment();

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
