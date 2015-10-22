# Makefile for Programming Challenge 17
# 
# CSCI 21, Fall 2015
# 
# Programmer: Katherine Jouzapaitis
# 
# Targets for Programming Challenge 17
# Date completed: 10/13/2015

FLAGS = -Wall -Wextra -pedantic

challenge-17: SLNode.o pc17-test.o
	g++ $(FLAGS) -o challenge-17 SLNode.o pc17-test.o
	
SLNode.o: SLNode.cpp
	g++ $(FLAGS) -c SLNode.cpp
	
pc17-test.o: pc17-test.cpp
	g++ $(FLAGS) -c pc17-test.cpp
	
clean:
	rm -f *.o
	
cleanall: clean
	rm -f challenge-17