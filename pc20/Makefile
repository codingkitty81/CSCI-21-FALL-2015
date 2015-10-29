# Makefile for Programming Challenge 20
# 
# CSCI 21, Fall 2015
# 
# Programmer: Katherine Jouzapaitis
# 
# Targets for Programming Challenge 20
# Date completed: 10/22/2015

FLAGS = -Wall -Wextra -pedantic

challenge-20: SList.o SLNode.o catch.o pc20-test.o
	g++ $(FLAGS) -o challenge-20 SList.o SLNode.o pc20-test.o
	
SList.o: SList.cpp
	g++ $(FLAGS) -c SList.cpp
	
SLNode.o: SLNode.cpp
	g++ $(FLAGS) -c SLNode.cpp
	
catch.o: catch.hpp
	g++ $(FLAGS) -c catch.hpp
	
pc20-test.o: pc20-test.cpp
	g++ $(FLAGS) -c pc20-test.cpp
	
clean:
	rm -f *.o *.gch
	
cleanall: clean
	rm -f challenge-20