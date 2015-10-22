# Makefile for Programming Challenge 18
# 
# CSCI 21, Fall 2015
# 
# Programmer: Katherine Jouzapaitis
# 
# Targets for Programming Challenge 18
# Date completed:

FLAGS = -Wall -Wextra -pedantic

challenge-18: SList.o SLNode.o pc18-test.o
	g++ $(FLAGS) -o challenge-18 SList.o SLNode.o pc18-test.o
	
SList.o: SList.cpp
	g++ $(FLAGS) -c SList.cpp
	
SLNode.o: SLNode.cpp
	g++ $(FLAGS) -c SLNode.cpp
	
pc18-test.o: pc18-test.cpp
	g++ $(FLAGS) -c pc18-test.cpp
	
clean:
	rm -f *.o
	
cleanall: clean
	rm -f challenge-18