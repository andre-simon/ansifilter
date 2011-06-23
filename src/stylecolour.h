/***************************************************************************
                          stylecolour.h  -  description
                             -------------------
    begin                : Die Nov 5 2002
    copyright            : (C) 2002 by Andre Simon
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

#ifndef STYLECOLOUR_H
#define STYLECOLOUR_H

#include "enums.h"

#include <string>


using namespace std;

namespace ansifilter {

/**\brief Stores colours and returns red, green and blue values in different formats
* @author Andre Simon
 */

struct RGBVal {
  int iRed,    ///< Red value
      iGreen,  ///< Green value
      iBlue;   ///< Blue value
};

class StyleColour
  {
  public:
    /** Constructor
        \param red Red value in hex notation
        \param green Blue value in hex notation
        \param blue Green value in hex notation
    */
    StyleColour(const string & red, const string & green, const string & blue);

    /** Constructor
        \param styleColourString String with rgb values
    */
    StyleColour(const string & styleColourString);

    StyleColour();
    ~StyleColour(){};

   /** Sets red, green and blue values
     \param styleColourString String containing colour attributes
   */
   void setRGB(const string & styleColourString);


    /** Sets red value
        \param red New red value */
    void setRed(const string & red);

    /** Sets green value
        \param green New green value */
    void setGreen(const string & green);

    /** Sets blue value
        \param blue New blue value */
    void setBlue(const string & blue);

    /**  @param type Output type
         @return Red value in color representation according to output type */
    const string getRed(OutputType type) const;
    /**  @param type Output type
         @return Green value in color representation according to output type */
    const string getGreen(OutputType type) const;
    /**  @param type Output type
         @return Blue value in color representation according to output type */
    const string getBlue(OutputType type) const;

  private:
    RGBVal rgb;
    string int2str(int, std::ios_base& (*f)(std::ios_base&) ) const;
    string float2str(double) const;
  };

}

#endif
