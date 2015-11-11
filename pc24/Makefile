# Makefile for Programming Challenge 24
# 
# CSCI 21, Fall 2015
# 
# Programmer: Katherine Jouzapaitis
# 
# Targets for Programming Challenge 24
# Date completed: 11/10/2015

FLAGS = -Wall -Wextra -pedantic

challenge-24: pc24-test.o BSTNode.o
	g++ $(FLAGS) -o challenge-24 pc24-test.o BSTNode.o
	
pc24-test.o: pc24-test.cpp
	g++ $(FLAGS) -c pc24-test.cpp
	
BSTNode.o: BSTNode.cpp
	g++ $(FLAGS) -c BSTNode.cpp
	
clean:
	rm -f *.o
	
cleanall: clean
	rm -f challenge-24