#Lab11 yo

COMPILER=g++
CFLAGS=-c -Wall -g
LFLAGS=-Wall -g
all: Lab11

#LFLAGS is linking flags
Lab11: main.o parsetree.o
	$(COMPILER) $(LFLAGS) -o Lab11 main.o parsetree.o

#CFLAGS is compiling flags
main.o: main.cpp
	$(COMPILER) $(CFLAGS) main.cpp

parsetree.o: parsetree.cpp parsetree.h
	$(COMPILER) $(CFLAGS) parsetree.cpp parsetree.h

clean:
	rm *.o

