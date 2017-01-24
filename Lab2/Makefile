##############################################
# Makefile for CST320 lab 2
#
# Author: Russ Hurtado
# russell.hurtado@oit.edu
#
# Jan. 19, 2017
#

COPTS=-Wall -g -c  -O0
OBJS=main.o \
	 langlex.o \
	 parse.o \
	 utils.o

all: lang

clean:
	rm -f $(OBJS)
	rm -f langlex.c
	rm -f lang
	rm -f out

.c.o:
	g++ $(COPTS) $? -o $@

.cpp.o:
	g++ $(COPTS) $? -o $@

main.o: main.cpp langlex.c 
	g++ $(COPTS) main.cpp -o main.o 
	
parse.o: parse.cpp 
	g++ $(COPTS) parse.cpp -o parse.o

utils.o: utils.cpp 
	g++ $(COPTS) utils.cpp -o utils.o
	
langlex.c: lang.l
	flex -o langlex.c lang.l

langlex.o: langlex.c
	g++ $(COPTS) -Wno-sign-compare $? -o $@
lang: $(OBJS)
	g++ $(OBJS) -o lang

