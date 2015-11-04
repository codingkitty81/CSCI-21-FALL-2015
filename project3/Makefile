# Makefile for Program Project #3
# 
# CSCI 21, Fall 2015
# 
# Programmer: Katherine Jouzapaitis
# 
# Targets for Programming Project #3
# Date completed: 11/4/2015

FLAGS = -Wall -Wextra -pedantic

project3: DLNode.o DLList.o project3-test.o
	g++ $(FLAGS) -o project3 DLNode.o DLList.o project3-test.o
	
DLNode.o: DLNode.cpp
	g++ $(FLAGS) -c DLNode.cpp
	
DLList.o: DLList.cpp
	g++ $(FLAGS) -c DLList.cpp
	
project3-test.o: project3-test.cpp
	g++ $(FLAGS) -c project3-test.cpp
	
clean:
	rm -f *.o
	
cleanall: clean
	rm -f project3