# -------------------------------------------------
# Project created by QtCreator 2010-02-03T21:56:57
# -------------------------------------------------
QT -= core \
    gui
TARGET = ansifilter
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app

INCLUDEPATH += ..

win32:DESTDIR = ../../
win32:QMAKE_CXXFLAGS += -std=c++11

SOURCES += ../main.cpp ../cmdlineoptions.cpp ../arg_parser.cpp
SOURCES += ../elementstyle.cpp ../plaintextgenerator.cpp ../codegenerator.cpp
SOURCES += ../platform_fs.cpp ../rtfgenerator.cpp ../htmlgenerator.cpp ../texgenerator.cpp ../latexgenerator.cpp ../bbcodegenerator.cpp ../pangogenerator.cpp
SOURCES += ../stringtools.cpp ../stylecolour.cpp  ../preformatter.cpp

win32:QMAKE_POST_LINK = D:\Devel\upx391w\upx.exe --best ../../ansifilter.exe
