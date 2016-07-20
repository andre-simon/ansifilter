/***************************************************************************
                        mydialog.h  -  description
                             -------------------
    copyright            : (C) 2007-2016 by Andre Simon
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

#include <QtGlobal>

#if (QT_VERSION < QT_VERSION_CHECK(5,0,0))
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFileDialog>
#include <QScrollBar>
#else
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QScrollBar>
#endif

#include "../version.h"
#include <memory>
#include <QClipboard>
#include <QSettings>
#include <QUrl>
#include <QMimeData>
#include <QMimeData>
#include <QFileInfo>


MyDialog::MyDialog(QWidget * parent, Qt::WindowFlags f):QDialog(parent, f)
{
    dlg.setupUi(this);
    QSettings settings("andre-simon.de", "ansifilter-gui");
    settings.beginGroup("format");
    dlg.leTitle->setText(settings.value("title").toString());
    dlg.leColorMapPath->setText(settings.value("map").toString());
    dlg.cbFragment->setChecked(settings.value("fragment").toBool());
    dlg.cbIgnoreSequences->setChecked(settings.value("ignoreseq").toBool());
    dlg.cbParseAsciiArt->setChecked(settings.value("parseart").toBool());

    dlg.rbAsciiCP437->setChecked(settings.value("cp437").toBool());
    dlg.rbAsciiBin->setChecked(settings.value("asciibin").toBool());
    dlg.comboEncoding->setCurrentIndex(settings.value("encoding").toInt());
    dlg.comboFont->setCurrentIndex(settings.value("font").toInt());
    dlg.comboFormat->setCurrentIndex(settings.value("format").toInt());
    dlg.spinBoxWrap->setValue(settings.value("linewrap").toInt());
    dlg.sbWidth->setValue(settings.value("width").toInt());
    dlg.sbHeight->setValue(settings.value("height").toInt());
    settings.endGroup();
    settings.beginGroup("paths");
    inputFileName = settings.value("infile").toString();
    outputFileName = settings.value("outfile").toString();
    settings.endGroup();
    settings.beginGroup("window");
    resize(settings.value("size", QSize(400, 400)).toSize());
    move(settings.value("pos", QPoint(200, 200)).toPoint());
    settings.endGroup();

    this->setAcceptDrops(true);
    QObject::connect(&fileWatcher, SIGNAL(fileChanged(const QString &)), this, SLOT(onFileChanged(const QString &)));
    QObject::connect(dlg.comboFormat, SIGNAL(currentIndexChanged(int)), this, SLOT(plausibility()));

    if (!inputFileName.isEmpty()) {
        showFile();
        dlg.cbWatchFile->setEnabled(true);
    }
    plausibility();
}

void MyDialog::closeEvent(QCloseEvent *event)
{
    QSettings settings("andre-simon.de", "ansifilter-gui");
    settings.beginGroup("format");
    settings.setValue("title", dlg.leTitle->text());
    settings.setValue("map", dlg.leColorMapPath->text());
    settings.setValue("fragment", dlg.cbFragment->isChecked());
    settings.setValue("ignoreseq", dlg.cbIgnoreSequences->isChecked());
    settings.setValue("parseart", dlg.cbParseAsciiArt->isChecked());

    settings.setValue("cp437", dlg.rbAsciiCP437->isChecked());
    settings.setValue("asciibin", dlg.rbAsciiBin->isChecked());
    settings.setValue("encoding", dlg.comboEncoding->currentIndex());
    settings.setValue("format", dlg.comboFormat->currentIndex());
    settings.setValue("font", dlg.comboFont->currentIndex());
    settings.setValue("linewrap", dlg.spinBoxWrap->value());
    settings.setValue("width", dlg.sbWidth->value());
    settings.setValue("height", dlg.sbHeight->value());
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

void MyDialog::dragEnterEvent(QDragEnterEvent *event)
{
    if ( event->mimeData()->hasFormat("text/uri-list")
            && event->mimeData()->urls().count()==1
       ) {
        event->acceptProposedAction();
        dlg.lblDrop->setEnabled(true);
    }
}

void MyDialog::dragLeaveEvent(QDragLeaveEvent* event)
{
    dlg.lblDrop->setEnabled(false);
}

void MyDialog::dropEvent(QDropEvent* event)
{
    dlg.lblDrop->setEnabled(false);

    QList<QUrl> urls = event->mimeData()->urls();
    if (urls.isEmpty())
        return;

    QString fileName = urls.first().toLocalFile();
    if (!fileName.isEmpty()) {
        inputFileName=fileName;
        dlg.cbWatchFile->setEnabled(true);
        dlg.cbWatchFile->setChecked(false);
        showFile();
    }
}

void MyDialog::onFileChanged(const QString & path)
{
    inputFileName  = path;
    showFile();
    QScrollBar *sb = dlg.textEdit->verticalScrollBar();
    sb->setValue(sb->maximum());
}

void MyDialog::plausibility()
{
    int selIdx = dlg.comboFormat->currentIndex();
    dlg.cbIgnoreSequences->setEnabled(selIdx!=0);
    dlg.cbFragment->setEnabled(selIdx==1 || selIdx==3 || selIdx==4|| selIdx==6);
    dlg.cbParseAsciiArt->setEnabled(selIdx==1 || selIdx==2);

    dlg.lblEncoding->setEnabled(selIdx==1|| selIdx==2 || selIdx==3);
    dlg.comboEncoding->setEnabled(selIdx==1 || selIdx==2 ||selIdx==3);
    dlg.leTitle->setEnabled(selIdx==1||selIdx==3||selIdx==4);
    dlg.comboFont->setEnabled(selIdx==1||selIdx==2||selIdx==6);
    dlg.gbAsciiArt->setEnabled(dlg.cbParseAsciiArt->isEnabled() && dlg.cbParseAsciiArt->isChecked());
    dlg.artSizeFrame->setEnabled(dlg.cbParseAsciiArt->isEnabled() && dlg.cbParseAsciiArt->isChecked());
    dlg.lblHeight->setEnabled(dlg.gbAsciiArt->isEnabled());
    dlg.sbHeight->setEnabled(dlg.gbAsciiArt->isEnabled());
    dlg.lblWidth->setEnabled(dlg.gbAsciiArt->isEnabled());
    dlg.sbWidth->setEnabled(dlg.gbAsciiArt->isEnabled());
}

ansifilter::OutputType MyDialog::getOutputType()
{
    switch (dlg.comboFormat->currentIndex()) {

    case 1:
        return ansifilter::HTML;
    case 2:
        return ansifilter::RTF;
    case 3:
        return ansifilter::LATEX;
    case 4:
        return ansifilter::TEX;
    case 5:
        return ansifilter::BBCODE;
    case 6:
        return ansifilter::PANGO;
    }
    return ansifilter::TEXT;
}

QString MyDialog::getOutFileSuffix()
{
    switch (dlg.comboFormat->currentIndex()) {
    case 1:
        return ".html";
    case 2:
        return ".rtf";
    case 3:
        return ".latex";
    case 4:
        return ".tex";
    case 5:
        return ".bbcode";
    case 6:
        return ".pango";
    }
    return ".txt";
}

void MyDialog::on_pbSaveAs_clicked()
{
    if (inputFileName.isEmpty()) {
        QMessageBox::information(this, "Note", "Please select an input file.");
        return;
    }

    QFileInfo check_file(dlg.leColorMapPath->text());
    if (dlg.leColorMapPath->text().length() && (!check_file.exists() || !check_file.isFile())) {
        QMessageBox::information(this, "Note", "Please select a color map file.");
        dlg.leColorMapPath->setFocus();
        return;
    }


    QString outFileSuffix = getOutFileSuffix();

    QString outFileName =QFileDialog::getSaveFileName(this, tr("Save File"), outputFileName,
                         outFileSuffix.mid(1).toUpper() + " (*" + outFileSuffix+")" );

    unique_ptr<ansifilter::CodeGenerator> generator(ansifilter::CodeGenerator::getInstance(getOutputType()));
    generator->setTitle( (dlg.leTitle->text().isEmpty()? QFileInfo(outFileName).fileName() : dlg.leTitle->text()).toStdString());
    generator->setEncoding(dlg.comboEncoding->currentText().toStdString());
    generator->setFragmentCode(dlg.cbFragment->isChecked());
    generator->setPlainOutput(dlg.cbIgnoreSequences->isChecked());

    if (dlg.cbParseAsciiArt->isChecked()){
        generator->setParseCodePage437(dlg.rbAsciiCP437->isChecked());
        generator->setParseAsciiBin(dlg.rbAsciiBin->isChecked());
        generator->setAsciiArtSize(dlg.sbWidth->value(), dlg.sbHeight->value());
    }

    generator->setFont(dlg.comboFont->currentFont().family().toStdString());
    generator->setPreformatting ( ansifilter::WRAP_SIMPLE, dlg.spinBoxWrap->value());
    generator->setFontSize("10pt"); //TODO TeX?

    if (!dlg.leColorMapPath->text().isEmpty()) {
        if (!generator->setColorMap(dlg.leColorMapPath->text().toStdString())){
            QMessageBox::warning(this, "Color Mapping Error", "Could not read color map");
            return;
        }
    }

    this->setCursor(Qt::WaitCursor);
    ansifilter::ParseError result= generator->generateFile( inputFileName.toStdString (), outFileName.toStdString () ) ;
    if (result==ansifilter::BAD_OUTPUT) {
        QMessageBox::warning(this, "IO Error", "Could not write output file");
    } else if (result==ansifilter::BAD_INPUT) {
        QMessageBox::warning(this, "IO Error", "Could not read input file");
    } else {
        outputFileName = outFileName;
    }
    this->setCursor(Qt::ArrowCursor);

}


void MyDialog::on_pbClipboard_clicked()
{

    if (inputFileName.isEmpty()) {
        QMessageBox::information(this, "Note", "Please select an input file.");
        return;
    }
    
    unique_ptr<ansifilter::CodeGenerator> generator(ansifilter::CodeGenerator::getInstance(ansifilter::TEXT));
    generator->setPreformatting ( ansifilter::WRAP_SIMPLE, dlg.spinBoxWrap->value());
    QString outString = QString(generator->generateStringFromFile( inputFileName.toStdString ()).c_str() ) ;

    if(!outString.isEmpty()) {
        QClipboard *clipboard = QApplication::clipboard();
        clipboard->setText(outString);
    }
}

void MyDialog::on_pbSelectMapFile_clicked()
{
  QString openFile = QFileDialog::getOpenFileName(this, tr("Open Map File"), "/home", tr("Text files (*.*)"));
    if (!openFile.isEmpty()) {
        dlg.leColorMapPath->setText(openFile);
        showFile();
    }
}

void MyDialog::on_pbFileOpen_clicked()
{
    QString openFile = QFileDialog::getOpenFileName(this, tr("Open File"), inputFileName, tr("Text files (*.*)"));
    if (!openFile.isEmpty()) {
        inputFileName = openFile;
        dlg.cbWatchFile->setEnabled(true);
        dlg.cbWatchFile->setChecked(false);
        showFile();
    }
}

void MyDialog::showFile()
{
    if (inputFileName.isEmpty()) return;


    dlg.lblInFilePath->setText(inputFileName);

    unique_ptr<ansifilter::CodeGenerator> generator(ansifilter::CodeGenerator::getInstance(ansifilter::HTML));

    generator->setEncoding(dlg.comboEncoding->currentText().toStdString());
    generator->setFragmentCode(false);
    generator->setPlainOutput(dlg.cbIgnoreSequences->isChecked());

    if (dlg.cbParseAsciiArt->isChecked()){
        generator->setParseCodePage437(dlg.rbAsciiCP437->isChecked());
        generator->setParseAsciiBin(dlg.rbAsciiBin->isChecked());
        generator->setAsciiArtSize(dlg.sbWidth->value(), dlg.sbHeight->value());
    }

    generator->setFont(dlg.comboFont->currentFont().family().toStdString());
    generator->setPreformatting ( ansifilter::WRAP_SIMPLE, dlg.spinBoxWrap->value());
    generator->setFontSize("10pt");
    if (!dlg.leColorMapPath->text().isEmpty()) {
        if (!generator->setColorMap(dlg.leColorMapPath->text().toStdString())){
            QMessageBox::warning(this, "Color Mapping Error", "Could not read color map");
            return;
        }
    }

    this->setCursor(Qt::WaitCursor);

    string htmlStdString=generator->generateStringFromFile(inputFileName.toStdString ());
    QString htmlString( htmlStdString.c_str() );
    if (!htmlString.isEmpty()) {
        dlg.textEdit->setText(htmlString);
        this->setWindowTitle("ANSIFilter - " + inputFileName);
    }
    this->setCursor(Qt::ArrowCursor);
}

void MyDialog::on_pbAbout_clicked()
{
    QMessageBox::about(this,
                       "ANSIFilter Information", 
                       QString("ANSIFilter GUI %1\n" 
                       "(c) 2007-2016 Andre Simon\n\n"
                       "Built with Qt version %2\n\n"
                       "Released under the terms of the GNU GPL license.\n\n"
                       "andre dot simon1 at gmx dot de\n"
                       "See www.andre-simon.de for updates.").arg(ANSIFILTER_VERSION).arg(QString(qVersion ())) 
                      );
}

void MyDialog::on_cbIgnoreSequences_stateChanged()
{
    showFile();
}

void MyDialog::on_cbParseAsciiArt_clicked()
{
    plausibility();
    showFile();
}

void MyDialog::on_rbAsciiCP437_toggled()
{
    showFile();
}

void MyDialog::on_rbAsciiBin_toggled()
{
    showFile();
}

void MyDialog::on_sbWidth_valueChanged(int i)
{
    showFile();
}
void MyDialog::on_sbHeight_valueChanged(int i)
{
    showFile();
}
void MyDialog::on_comboFont_currentIndexChanged(int idx)
{
    showFile();
}
void MyDialog::on_comboEncoding_currentIndexChanged(int idx)
{
    showFile();
}

void MyDialog::on_cbWatchFile_stateChanged()
{
    if (dlg.cbWatchFile->isChecked() && !inputFileName.isEmpty())
        fileWatcher.addPath(inputFileName);
    else
        fileWatcher.removePath(inputFileName);
}

