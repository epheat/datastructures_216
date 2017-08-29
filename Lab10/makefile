#lab10

COMPILER=g++
CFLAGS=-c -Wall -g
LFLAGS=-Wall -g
all: Lab10

#LFLAGS is linking flags
Lab10: main.o Matrix.o
	$(COMPILER) $(LFLAGS) -o Lab10 main.o Matrix.o

#CFLAGS is compiling flags
main.o: main.cpp
	$(COMPILER) $(CFLAGS) main.cpp

Matrix.o: Matrix.cpp Matrix.h
	$(COMPILER) $(CFLAGS) Matrix.cpp Matrix.h

clean:
	rm *.o
