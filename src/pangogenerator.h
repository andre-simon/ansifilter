/***************************************************************************
                          pangogenerator.h  -  description
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


#ifndef PANGOGENERATOR_H
#define PANGOGENERATOR_H

#include <string>

#include "codegenerator.h"

namespace ansifilter
{

/**
   \brief This class generates Pango Markup.

   It contains information about the resulting document structure (document
   header and footer), the colour system, white space handling and text
   formatting attributes.

* @author Dominik Schmidt
*/

class PangoGenerator  : public ansifilter::CodeGenerator
{
public:

    PangoGenerator();

    virtual ~PangoGenerator() {};

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
