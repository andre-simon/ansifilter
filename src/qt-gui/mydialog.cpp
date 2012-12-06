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

#include "mydialog.h"

#include <memory>
#include <QMessageBox>
#include <QFileDialog>
#include <QClipboard>
#include <QSettings>
#include "codegenerator.h"

MyDialog::MyDialog(QWidget * parent, Qt::WindowFlags f):QDialog(parent, f)
{
	dlg.setupUi(this);
	QSettings settings("andre-simon.de", "ansifilter-gui");

	settings.beginGroup("format");
	dlg.leTitle->setText(settings.value("title").toString());
	dlg.cbFragment->setChecked(settings.value("fragment").toBool());
	dlg.cbIgnoreSequences->setChecked(settings.value("ignoreseq").toBool());
	dlg.comboEncoding->setCurrentIndex(settings.value("encoding").toInt());
	dlg.comboFont->setCurrentIndex(settings.value("font").toInt());
    dlg.spinBoxWrap->setValue(settings.value("linewrap").toInt());
	settings.endGroup();
	settings.beginGroup("paths");
	inputFileName = settings.value("infile").toString();
	outputFileName = settings.value("outfile").toString();
	settings.endGroup();
	settings.beginGroup("window");
    resize(settings.value("size", QSize(400, 400)).toSize());
    move(settings.value("pos", QPoint(200, 200)).toPoint());
    settings.endGroup();
}

 void MyDialog::closeEvent(QCloseEvent *event)
 {
	QSettings settings("andre-simon.de", "ansifilter-gui");
	settings.beginGroup("format");
	settings.setValue("title", dlg.leTitle->text());
	settings.setValue("fragment", dlg.cbFragment->isChecked());
	settings.setValue("ignoreseq", dlg.cbIgnoreSequences->isChecked());
	settings.setValue("encoding", dlg.comboEncoding->currentIndex());
    settings.setValue("font", dlg.comboFont->currentIndex());
    settings.setValue("linewrap", dlg.spinBoxWrap->value());

	settings.endGroup();
	settings.beginGroup("paths");
	settings.setValue("infile", inputFileName);
	settings.setValue("outfile", outputFileName);
	settings.endGroup();
	settings.beginGroup("window");
        settings.setValue("size", size());
        settings.setValue("pos", pos());
        settings.endGroup();
 }

void MyDialog::on_pbSaveAs_clicked(){

    if (inputFileName.isEmpty()){
        QMessageBox::information(this, "Note", "Please select an input file.");
	return;
    }

    QString outFileName =
              QFileDialog::getSaveFileName(this, tr("Save File"), outputFileName,
                           tr("Text (*.txt);;HTML (*.html);;RTF (*.rtf);;LaTeX (*.latex);;TeX (*.tex);;BBCode (*.bbcode)"));

    ansifilter::OutputType outputType=ansifilter::TEXT;

    if (outFileName.endsWith(".html"))
        outputType=ansifilter::HTML;
    else if (outFileName.endsWith(".rtf"))
	outputType=ansifilter::RTF;
    else if (outFileName.endsWith(".tex"))
	outputType=ansifilter::TEX;
    else if (outFileName.endsWith(".latex"))
	outputType=ansifilter::LATEX;
    else if (outFileName.endsWith(".bbcode"))
	outputType=ansifilter::BBCODE;
    auto_ptr<ansifilter::CodeGenerator> generator(ansifilter::CodeGenerator::getInstance(outputType));
    generator->setTitle( (dlg.leTitle->text().isEmpty()? outFileName : dlg.leTitle->text()).toStdString());
    generator->setEncoding(dlg.comboEncoding->currentText().toStdString());
    generator->setFragmentCode(dlg.cbFragment->isChecked());
    generator->setPlainOutput(dlg.cbIgnoreSequences->isChecked());
    generator->setFont(dlg.comboFont->currentFont().family().toStdString());
    generator->setPreformatting ( ansifilter::WRAP_SIMPLE, dlg.spinBoxWrap->value());
    generator->setFontSize("10pt");

    ansifilter::ParseError result= generator->generateFile( inputFileName.toStdString (), outFileName.toStdString () ) ;
    if (result==ansifilter::BAD_OUTPUT){
      QMessageBox::warning(this, "IO Error", "Could not write output file");
    } else if (result==ansifilter::BAD_INPUT){
       QMessageBox::warning(this, "IO Error", "Could not read input file");
    } else {
       outputFileName = outFileName;
    }
}


void MyDialog::on_pbClipboard_clicked(){

    if (inputFileName.isEmpty()){
        QMessageBox::information(this, "Note",
      	"Please select an input file."
	   );
	   return;
    }
    auto_ptr<ansifilter::CodeGenerator> generator(ansifilter::CodeGenerator::getInstance(ansifilter::TEXT));
    generator->setPreformatting ( ansifilter::WRAP_SIMPLE, dlg.spinBoxWrap->value());

    QString outString = QString(generator->generateStringFromFile( inputFileName.toStdString ()).c_str() ) ;

    if(!outString.isEmpty()){
		QClipboard *clipboard = QApplication::clipboard();
		clipboard->setText(outString);
	}
}

void MyDialog::on_pbFileOpen_clicked(){

	QString openFile = QFileDialog::getOpenFileName(this, tr("Open File"), inputFileName, tr("Text files (*.*)"));
	if (!openFile.isEmpty()) {
		inputFileName = openFile;
		showFile(inputFileName);
	}
}

void MyDialog::showFile(const QString & inputFileName){
   if (inputFileName.isEmpty()) return;

    auto_ptr<ansifilter::CodeGenerator> generator(ansifilter::CodeGenerator::getInstance(ansifilter::HTML));
    generator->setEncoding(dlg.comboEncoding->currentText().toStdString());
    generator->setFragmentCode(false);
    generator->setPlainOutput(dlg.cbIgnoreSequences->isChecked());
    generator->setFont(dlg.comboFont->currentFont().family().toStdString());
    generator->setPreformatting ( ansifilter::WRAP_SIMPLE, dlg.spinBoxWrap->value());
    generator->setFontSize("10pt");

    QString htmlString = QString( generator->generateStringFromFile(inputFileName.toStdString ()).c_str() );
    if (!htmlString.isEmpty()) {
       dlg.textEdit->setText(htmlString);
       this->setWindowTitle("ANSIFilter - " + inputFileName);
    }
}

void MyDialog::on_pbAbout_clicked(){
    QMessageBox::information(this,
    "ANSIFilter Information", "ANSIFilter GUI Version 1.7\n"
    "(c) 2007-2012 Andre Simon\n\n"
	"Released under the terms of the GNU GPL license.\n\n"
	"andre dot simon1 at gmx dot de\n"
        "See www.andre-simon.de for updates."
	);
}

void MyDialog::on_cbIgnoreSequences_stateChanged(){
	showFile(inputFileName);
}
void MyDialog::on_comboFont_textChanged(){
	showFile(inputFileName);
}
void MyDialog::on_comboEncoding_textChanged(){
	showFile(inputFileName);
}

