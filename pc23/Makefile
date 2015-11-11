# Makefile for Programming Challenge 23
# 
# CSCI 21, Fall 2015
# 
# Programmer: Katherine Jouzapaitis
# 
# Targets for Programming Challenge 23
# Date completed: 11/10/2015

FLAGS = -Wall -Wextra -pedantic

challenge-23: recursive.o pc23-test.o
	g++ $(FLAGS) -o challenge-23 recursive.o pc23-test.o
	
recursive.o: recursive.cpp
	g++ $(FLAGS) -c recursive.cpp
	
pc23-test.o: pc23-test.cpp
	g++ $(FLAGS) -c pc23-test.cpp
	
clean:
	rm -f *.o

cleanall: clean
	rm -f challenge-23