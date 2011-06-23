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

#include "platform_fs.h"

#include <iostream>

using namespace std;

namespace Platform {

#ifdef _WIN32
	#include <windows.h>

	const char pathSeparator = '\\';
	//const std::string pathSeparatorStr = "\\";

	std::string getAppPath()
	{
		char pathAndName[MAX_PATH], path[MAX_PATH], drive[3];
		GetModuleFileName(NULL, pathAndName, MAX_PATH);
		_splitpath(pathAndName, drive, path, 0, 0);
		return std::string(drive)+path;
	}

#else
       const char pathSeparator = '/';
      // const std::string pathSeparatorStr = "/";

	std::string getAppPath()
	{
		return "";
	}

#endif

}

