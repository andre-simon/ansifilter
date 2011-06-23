/***************************************************************************
                          main.cpp  -  description
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
#include <QApplication>
#include <QDialog>
#include "mydialog.h"

int main(int argc, char *argv[])
{
     QApplication app(argc, argv);
     MyDialog d(0,  Qt::WindowTitleHint | Qt::WindowSystemMenuHint);
	 if (argc>1) d.setInputFileName(argv[1]);
     d.show();
     return app.exec();
}
