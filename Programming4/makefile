#Programming Assignment 4
#Evan Heaton
#yolo

COMPILER=g++
CFLAGS=-c -Wall -g
LFLAGS=-Wall -g
all: CS216PA4

#LFLAGS is linking flags
CS216PA4: main.o EStack.o ETreeNodeStack.o EIntegerNode.o EStringNode.o EStringNode.o EIntegerNode.o ETree.o
	$(COMPILER) $(LFLAGS) -o CS216PA4 main.o EStack.o ETreeNodeStack.o EIntegerNode.o EStringNode.o ETree.o

#CFLAGS is compiling flags
main.o: main.cpp
	$(COMPILER) $(CFLAGS) main.cpp

EStack.o: EStack.cpp EStack.h
	$(COMPILER) $(CFLAGS) EStack.cpp

ETreeNodeStack.o: EStack.cpp EStack.h
	$(COMPILER) $(CFLAGS) ETreeNodeStack.cpp

EStringNode.o: EStringNode.cpp EStringNode.h ETreeNode.h
	$(COMPILER) $(CFLAGS) EStringNode.cpp

EIntegerNode.o: EIntegerNode.cpp EIntegerNode.h ETreeNode.h
	$(COMPILER) $(CFLAGS) EIntegerNode.cpp

ETree.o: ETree.cpp ETree.h
	$(COMPILER) $(CFLAGS) ETree.cpp

clean:
	rm *.o
