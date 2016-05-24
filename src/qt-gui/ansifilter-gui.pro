TEMPLATE = app

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ansifilter-gui
DEPENDPATH += .
INCLUDEPATH += . ..
DEFINES += O2
QMAKE_CXXFLAGS += -std=c++11

# Input
HEADERS += mydialog.h
FORMS += ansifilter.ui
SOURCES += main.cpp mydialog.cpp 
SOURCES += ../elementstyle.cpp ../plaintextgenerator.cpp ../codegenerator.cpp 
SOURCES += ../platform_fs.cpp ../rtfgenerator.cpp ../htmlgenerator.cpp ../pangogenerator.cpp ../texgenerator.cpp ../latexgenerator.cpp ../bbcodegenerator.cpp
SOURCES += ../stringtools.cpp ../stylecolour.cpp ../preformatter.cpp

RESOURCES += ansifilter.qrc
win32 {
CONFIG += static
DEFINES += _WIN32
RC_FILE = icon.rc
DESTDIR = ../../
QMAKE_POST_LINK = D:\Devel\upx391w\upx.exe --best ../../ansifilter-gui.exe
}
