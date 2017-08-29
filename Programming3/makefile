# Programming Assignment 3

COMPILER=g++
CFLAGS=-c -Wall -g
LFLAGS=-Wall -g
all: CS216PA3

#LFLAGS is linking flags
CS216PA3: main.o EStack.o
	$(COMPILER) $(LFLAGS) -o CS216PA3 main.o EStack.o

#CFLAGS is compiling flags
main.o: main.cpp
	$(COMPILER) $(CFLAGS) main.cpp

EStack.o: EStack.cpp EStack.h
	$(COMPILER) $(CFLAGS) EStack.cpp EStack.h

clean:
	rm *.o
