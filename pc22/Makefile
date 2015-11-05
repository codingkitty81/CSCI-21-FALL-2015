# Makefile for Programming Challenge 22
# 
# CSCI 21, Fall 2015
# 
# Programmer: Katherine Jouzapaitis
# 
# Targets for Programming Challenge 22
# Date completed: 11/4/2015

FLAGS = -Wall -Wextra -pedantic

challenge-22: pc22-test.o 
	g++ $(FLAGS) -o challenge-22 pc22-test.o 
	
pc22-test.o: pc22-test.cpp
	g++ $(FLAGS) -c pc22-test.cpp

clean:
	rm -f *.o *.gch
	
cleanall: clean
	rm -f challenge-22