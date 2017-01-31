#**************************************
# Makefile
#
# Makefile for lang compiler
#
# Author: Phil Howard 
# phil.howard@oit.edu
#
# Date: Jan. 12, 2016
#

COPTS=-Wall -g -c -O0 -std=c++11
OBJS=main.o \
	 langlex.o \
	 symtab.o

all: lang

clean:
	rm -f $(OBJS)
	rm -f *.o
	rm -f langlex.c
	rm -f lang
	rm -f out.xml
	rm -f out2.xml

.c.o:
	g++ $(COPTS) $? -o $@

.cpp.o:
	g++ $(COPTS) $? -o $@

main.o: main.cpp langlex.c symtab.cpp
	g++ $(COPTS) main.cpp -o main.o
	
symtab.o: symtab.cpp 
	g++ $(COPTS) symtab.cpp -o symtab.o

langlex.c: lang.l 
	flex -o langlex.c lang.l 

langlex.o: langlex.c
	g++ $(COPTS) -Wno-sign-compare $? -o $@

lang: $(OBJS) 
	g++ $(OBJS) -o lang

