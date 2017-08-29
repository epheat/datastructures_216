OBJECTS = main.o LinkedList.o
HEADERS = LinkedList.h

lab8: $(OBJECTS)
	g++ $^ -o lab8
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@
clean:
	rm -f *.o lab8
