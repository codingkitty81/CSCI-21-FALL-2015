# Makefile for Program Project #2
# 
# CSCI 21, Fall 2015
# 
# Programmer: Katherine Jouzapaitis
# 
# Targets for Programming Project #2
# Date completed: 10/9/2015

project2: boxprizetest.o prize.o box.o CinReader.o
	g++ -o project2 boxprizetest.o prize.o box.o CinReader.o
	
boxtest: boxprizetest.cpp
	g++ -c boxprizetest.cpp
	
prize: prize.cpp
	g++ -c prize.cpp
	
box: box.cpp
	g++ -c box.cpp
	
CinReader: CinReader.cpp
	g++ -c CinReader.cpp
	
clean: 
	rm boxprizetest.o prize.o box.o CinReader.o
	
cleanall:  
	rm boxprizetest.o prize.o box.o CinReader.o project2