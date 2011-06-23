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
#ifndef PLATFORM_FS__H__INCLUDED
#define PLATFORM_FS__H__INCLUDED

#include <string>


namespace Platform
{
	extern const char pathSeparator;
	//extern const std::string pathSeparatorStr;

	std::string getAppPath();
}
#endif
