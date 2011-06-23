/***************************************************************************
                          elementstyle.h  -  description
                             -------------------

    copyright            : (C) 2007-2011 by Andre Simon
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

#ifndef ELEMENTSTYLE_H
#define ELEMENTSTYLE_H

#include "stylecolour.h"

using namespace std;

namespace ansifilter {

/** \brief The class stores the basic text formatting properties.

* @author Andre Simon
*/

class ElementStyle {
  public:

    ElementStyle();

    ~ElementStyle();

   /** \return True if italic */
    bool isItalic() const;

  /** \return True if italic */
    bool isBlink() const;

   /** \return True if bold */
   bool isBold() const;

   /** \return True if underline */
   bool isUnderline() const;

   /** \return True if concealed */
   bool isConceal() const;
   
      /** \return True if background color should change */
   bool isBgColorSet() const;

   /** \param b set blink flag */
    void setBlink(bool b) {blink = b;}

   /** \param b set italic flag */
    void setItalic(bool b) {italic = b;}

   /** \param b set conceal flag */
    void setConceal(bool b) {conceal = b;}

   /** \param b set bold flag */
   void setBold(bool b) { bold = b; }

   /** \param b set underline flag */
   void setUnderline(bool b) {underline = b; }

   /** \return True if reset flag was set */
   bool isReset() const {return reset;}

   /** \param b reset formatting parameters to defaults */
   void setReset(bool b);

   /** \return Foreground colour */
   const StyleColour getFgColour() const;

   /** \return Background colour */
   const StyleColour getBgColour() const;

   /** Set Foreground colour
       \param col colour of this element */
   void setFgColour(const StyleColour& col) {fgColour = col;}

   /**   Set Background colour
         \param col colour of this element */
   void setBgColour(const StyleColour& col) {
     bgColour = col; 
     bgColorSet=true;
  }

   /** Set Foreground colour
       \param col colour of this element */
   void setFgColour(const string& rgbVal) {fgColour.setRGB(rgbVal);}

   /**   Set Background colour
         \param col colour of this element */
   void setBgColour(const string& rgbVal) {
     bgColour.setRGB(rgbVal);
     bgColorSet=true;
  }


   /** Set Foreground colour IF (RTF)
       \param col colour ID of this element */
   void setFgColourID(int id) {fgColID=id;}

   /**   Set Background colour ID (RTF)
         \param col colour ID of this element */
   void setBgColourID(int id) {bgColID=id;}


   /** Set Foreground colour IF (RTF)
       \param col colour ID of this element */
   int getFgColourID() {return fgColID;}

   /**   Set Background colour ID (RTF)
         \param col colour ID of this element */
   int getBgColourID() {return bgColID;}

   /** Swap background and foreground colors
       \param negative Set to true, to invert default colors, set to false, to invert them back to default*/
   void imageMode(bool negative=true);

 private:
    StyleColour fgColour;
    StyleColour bgColour;
    bool bold, italic, underline, blink;
    bool reset;
    bool isNegativeMode, conceal;
    bool bgColorSet;
    int fgColID;
    int bgColID;
  };

}

#endif
