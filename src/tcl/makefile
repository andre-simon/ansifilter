# Simple Makefile for tclansifilter
# This file will compile the tclansifilter shared object.

CC=g++

CFLAGS= -c -Wall -O2 -fPIC

LDFLAGS= -shared -fPIC

SOURCES=arg_parser.o stringtools.o cmdlineoptions.o main.o platform_fs.o\
codegenerator.o htmlgenerator.o pangogenerator.o texgenerator.o latexgenerator.o rtfgenerator.o\
plaintextgenerator.o bbcodegenerator.o elementstyle.o stylecolour.o preformatter.o\
tclansifilter.c

OBJECTS=$(SOURCES:.cpp=.o)
BINARY=tclansifilter.so

all: $(SOURCES) $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: ../%.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -f *.o
	@rm -f $(BINARY)
