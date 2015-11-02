FLAGS = -Wall -Wextra -pedantic

testNode: DLNode.o DLList.o test.o
	g++ $(FLAGS) -o testNode DLNode.o DLList.o test.o
	
DLNode.o: DLNode.cpp
	g++ $(FLAGS) -c DLNode.cpp
	
DLList.o: DLList.cpp
	g++ $(FLAGS) -c DLList.cpp
	
test.o: test.cpp
	g++ $(FLAGS) -c test.cpp
	
cleanall:
	rm -f *o testNode