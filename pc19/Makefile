# Makefile for Programming Challenge 19
# 
# CSCI 21, Fall 2015
# 
# Programmer: Katherine Jouzapaitis
# 
# Targets for Programming Challenge 19
# Date completed: 10/20/2015

FLAGS = -Wall -Wextra -pedantic

challenge-19: SList.o SLNode.o pc19-test.o
	g++ $(FLAGS) -o challenge-19 SList.o SLNode.o pc19-test.o
	
SList.o: SList.cpp
	g++ $(FLAGS) -c SList.cpp
	
SLNode.o: SLNode.cpp
	g++ $(FLAGS) -c SLNode.cpp
	
pc19-test.o: pc19-test.cpp
	g++ $(FLAGS) -c pc19-test.cpp
	
clean:
	rm -f *.o
	
cleanall: clean
	rm -f challenge-19