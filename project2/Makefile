# Makefile for Program Project #2
# 
# CSCI 21, Fall 2015
# 
# Programmer: Katherine Jouzapaitis
# 
# Targets for Programming Project #2
# Date completed: 10/9/2015

FLAGS = -Wall -Wextra -pedantic

project2: boxprizetest.o prize.o box.o CinReader.o
	g++ $(FLAGS) -o project2 boxprizetest.o prize.o box.o CinReader.o
	
boxprizetest.o: boxprizetest.cpp
	g++ $(FLAGS) -c boxprizetest.cpp
	
prize.o: prize.cpp
	g++ $(FLAGS) -c prize.cpp
	
box.o: box.cpp
	g++ $(FLAGS) -c box.cpp
	
CinReader.o: CinReader.cpp
	g++ $(FLAGS) -c CinReader.cpp
	
clean: 
	rm -f *.o
	
cleanall: clean
	rm -f project2