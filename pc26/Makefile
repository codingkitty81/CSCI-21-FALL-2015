# Makefile for Programming Challenge 26
# 
# CSCI 21, Fall 2015
# 
# Programmer: Katherine Jouzapaitis
# 
# Targets for Programming Challenge 26
# Date completed: 11/16/2015

FLAGS = -Wall -Wextra -pedantic

challenge-26: pc26-test.o BSTNode.o BSTree.o
	g++ $(FLAGS) -o challenge-26 pc26-test.o BSTNode.o BSTree.o
	
pc26-test.o: pc26-test.cpp
	g++ $(FLAGS) -c pc26-test.cpp
	
BSTNode.o: BSTNode.cpp
	g++ $(FLAGS) -c BSTNode.cpp
	
BSTree.o: BSTree.cpp
	g++ $(FLAGS) -c BSTree.cpp
	
clean:
	rm -f *.o
	
cleanall: clean
	rm -f challenge-26