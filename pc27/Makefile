# Makefile for Programming Challenge 27
# 
# CSCI 21, Fall 2015
# 
# Programmer: Katherine Jouzapaitis
# 
# Targets for Programming Challenge 27
# Date completed: 11/16/2015

FLAGS = -Wall -Wextra -pedantic

challenge-27: pc27-test.o BSTNode.o BSTree.o Utility.o
	g++ $(FLAGS) -o challenge-27 pc27-test.o BSTNode.o BSTree.o Utility.o
	
pc27-test.o: pc27-test.cpp
	g++ $(FLAGS) -c pc27-test.cpp
	
BSTNode.o: BSTNode.cpp
	g++ $(FLAGS) -c BSTNode.cpp
	
BSTree.o: BSTree.cpp
	g++ $(FLAGS) -c BSTree.cpp
	
Utility.o: Utility.cpp
	g++ $(FLAGS) -c Utility.cpp
	
clean:
	rm -f *.o
	
cleanall: clean
	rm -f challenge-27