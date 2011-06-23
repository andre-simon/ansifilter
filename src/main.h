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

#ifndef ANSIFILTER_APP
#define ANSIFILTER_APP


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <cassert>

#include "cmdlineoptions.h"
//#include "codegenerator.h"
#include "version.h"
//#include "platform_fs.h"

/// Main application class of the command line interface

class ANSIFilterApp {

public:

   ANSIFilterApp(){};
   ~ANSIFilterApp(){};

   /** Start application
     \param argc Number of command line arguments
     \param argv values of command line arguments
     \return EXIT_SUCCESS or EXIT_FAILURE
   */
   int run( const int argc, const char *argv[] );

private:

  /** print version info*/
  void printVersionInfo();
  void printHelp();

};

#endif
