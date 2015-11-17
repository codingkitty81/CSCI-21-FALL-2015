# Makefile for Programming Challenge 25
# 
# CSCI 21, Fall 2015
# 
# Programmer: Katherine Jouzapaitis
# 
# Targets for Programming Challenge 25
# Date completed: 11/10/2015

FLAGS = -Wall -Wextra -pedantic

challenge-25: pc25-test.o BSTNode.o BSTree.o
	g++ $(FLAGS) -o challenge-25 pc25-test.o BSTNode.o BSTree.o
	
pc25-test.o: pc25-test.cpp
	g++ $(FLAGS) -c pc25-test.cpp
	
BSTNode.o: BSTNode.cpp
	g++ $(FLAGS) -c BSTNode.cpp
	
BSTree.o: BSTree.cpp
	g++ $(FLAGS) -c BSTree.cpp
	
clean:
	rm -f *.o
	
cleanall: clean
	rm -f challenge-25