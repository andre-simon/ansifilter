# Simple Makefile for ANSIFilter
# This file will compile the ansifilter binary.
# See INSTALL for instructions.

CC=g++

CFLAGS= -c -Wall -O2

LDFLAGS=

SOURCES=arg_parser.o stringtools.o cmdlineoptions.o main.o platform_fs.o\
codegenerator.o htmlgenerator.o texgenerator.o latexgenerator.o rtfgenerator.o\
plaintextgenerator.o bbcodegenerator.o elementstyle.o stylecolour.o

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ansifilter

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -f *.o
	@rm -f ./ansifilter
	@rm -f ./ansifilter_gui
	@rm -f ./.deps/*
