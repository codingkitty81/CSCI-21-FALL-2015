# Makefile for Programming Challenge 28
# 
# CSCI 21, Fall 2015
# 
# Programmer: Katherine Jouzapaitis
# 
# Targets for Programming Challenge 28
# Date completed: 11/25/2015

FLAGS = -Wall -Wextra -pedantic

challenge-28: Item.o FoodItem.o MagicItem.o pc28-test.o
	g++ $(FLAGS) -o challenge-28 Item.o FoodItem.o MagicItem.o pc28-test.o
	
Item.o: Item.cpp
	g++ $(FLAGS) -c Item.cpp
	
FoodItem.o: FoodItem.cpp
	g++ $(FLAGS) -c FoodItem.cpp
	
MagicItem.o: MagicItem.cpp
	g++ $(FLAGS) -c MagicItem.cpp

pc28-test.o: pc28-test.cpp
	g++ $(FLAGS) -c pc28-test.cpp
	
clean:
	rm -f *.o
	
cleanall: clean
	rm -f challenge-28