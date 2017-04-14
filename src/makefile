# Simple Makefile for ANSIFilter
# This file will compile the ansifilter binary.
# See INSTALL for instructions.

# afl-g++ for preparing fuzzing tests
CC=g++

# Added -std=c++11 because of auto_ptr to unique_ptr transition
CFLAGS= -Wall -O2 -DNDEBUG -std=c++11

LDFLAGS=

SOURCES=arg_parser.o stringtools.o cmdlineoptions.o main.o platform_fs.o\
codegenerator.o htmlgenerator.o pangogenerator.o texgenerator.o latexgenerator.o rtfgenerator.o\
plaintextgenerator.o bbcodegenerator.o elementstyle.o stylecolour.o preformatter.o

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ansifilter

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -f *.o
	@rm -f ./ansifilter
	@rm -f ./qt-gui/*.o
	@rm -f ./qt-gui/.qmake.stash
	@rm -f ./qt-gui/ansifilter-gui
	@rm -f ./.deps/*
