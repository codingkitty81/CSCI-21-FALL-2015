# Makefile for Programming Challenge 29
# 
# CSCI 21, Fall 2015
# 
# Programmer: Katherine Jouzapaitis
# 
# Targets for Programming Challenge 29
# Date completed: 12/7/2015

FLAGS = -Wall -Wextra -pedantic -std=c++11

challenge-29: pc29-test.o
	g++ $(FLAGS) -o challenge-29 pc29-test.o
	
pc29-test.o: pc29-test.cpp
	g++ $(FLAGS) -c pc29-test.cpp
	
clean:
	rm -f *.o
	
cleanall: clean
	rm -f challenge-29