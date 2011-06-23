/***************************************************************************
                          mydialog.h  -  description
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
 
#ifndef MYDIALOG
#define MYDIALOG

#include <QCloseEvent>
#include "ui_ansifilter.h"

class MyDialog : public QDialog
{
                Q_OBJECT
public:
                Ui::Dialog dlg;
                //The same constructor that we used last time with QDialog default parameters
                MyDialog(QWidget * parent = 0, Qt::WindowFlags f = 0);

				void setInputFileName(const char* fName) {
				   inputFileName=QString(fName);
				   showFile(inputFileName);
				}
				virtual ~MyDialog() {};
				
protected:
				void closeEvent(QCloseEvent *event);
				
private:
				QString inputFileName;
				QString outputFileName;

				void showFile(const QString & inputFileName);

public slots:
                //This is a slot like the ones we used in our last tutorial
                // The difference here that it gets automatically connect
                // If you use on_objectname_signalname it's like connect(pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()))
				void on_pbSaveAs_clicked();
				void on_pbFileOpen_clicked();
				void on_pbAbout_clicked();
				void on_pbClipboard_clicked();
				
				void on_cbIgnoreSequences_stateChanged();
				void on_comboFont_textChanged();
				void on_comboEncoding_textChanged();

};

#endif

