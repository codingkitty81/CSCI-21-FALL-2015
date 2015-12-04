# Makefile for Programming Project 4
# 
# CSCI 21, Fall 2015
# 
# Programmer: Katherine Jouzapaitis
# 
# Targets for Programming Project 4
# Date completed: 11/25/2015

FLAGS = -Wall -Wextra -pedantic -g

project4: word.o project4-test.o
	g++ $(FLAGS) -o project4 word.o project4-test.o
	
word.o: word.cpp
	g++ $(FLAGS) -c word.cpp
	
project4-test.o: project4-test.cpp
	g++ $(FLAGS) -c project4-test.cpp
	
clean:
	rm -f *.o
	
cleanall: clean
	rm -f project4