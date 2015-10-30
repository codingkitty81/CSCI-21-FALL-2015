# Makefile for Programming Challenge 21
# 
# CSCI 21, Fall 2015
# 
# Programmer: Katherine Jouzapaitis
# 
# Targets for Programming Challenge 21
# Date completed: 10/29/2015

FLAGS = -Wall -Wextra -pedantic

challenge-21: pc21-test.o 
	g++ $(FLAGS) -o challenge-21 pc21-test.o 
	
pc21-test.o: pc21-test.cpp
	g++ $(FLAGS) -c pc21-test.cpp

clean:
	rm -f *.o *.gch
	
cleanall: clean
	rm -f challenge-21