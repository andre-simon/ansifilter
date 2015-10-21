# Simple Makefile for tclansifilter
# This file will compile the tclansifilter shared object.

CC=g++

CFLAGS= -c -Wall -O2 -fPIC

LDFLAGS= -shared -fPIC

SOURCES=stringtools.cpp platform_fs.cpp\
codegenerator.cpp htmlgenerator.cpp pangogenerator.cpp texgenerator.cpp latexgenerator.cpp rtfgenerator.cpp\
plaintextgenerator.cpp bbcodegenerator.cpp elementstyle.cpp stylecolour.cpp preformatter.cpp

OBJECTS=$(SOURCES:.cpp=.o) tclansifilter.o
BINARY=tclansifilter.so

all: $(OBJECTS) $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: ../%.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -f *.o
	@rm -f $(BINARY)
