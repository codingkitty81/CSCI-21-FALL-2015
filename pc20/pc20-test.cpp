/*
 * Programming Challenge 20 - UNIT TEST
 * 
 * Katherine Jouzapaitis
 * Date created: 10/22/2015
 * Date last modified:
 *
 * Resources:
 */

#include "SList.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/*
 * CATCH unit test
 */
 TEST_CASE ("singly-linked list functionality", "[slist]") {
 	SList list;

 	REQUIRE(list.getSize() == 0);
 	REQUIRE(list.toString() == "");

	list.insert(10);
	REQUIRE(list.getSize() == 1);
	REQUIRE(list.toString() == "10");

	list.insert(50);
	REQUIRE(list.getSize() == 2);
	REQUIRE(list.toString() == "10,50");

	list.insert(30);
	REQUIRE(list.getSize() == 3);
	REQUIRE(list.toString() == "10,30,50");

	list.insert(5);
	REQUIRE(list.getSize() == 4);
	REQUIRE(list.toString() == "5,10,30,50");

	list.insert(55);
	REQUIRE(list.getSize() == 5);
	REQUIRE(list.toString() == "5,10,30,50,55");

	list.insert(20);
	REQUIRE(list.getSize() == 6);
	REQUIRE(list.toString() == "5,10,20,30,50,55");

	list.insert(40);
	REQUIRE(list.getSize() == 7);
	REQUIRE(list.toString() == "5,10,20,30,40,50,55"); 

	list.insert(30);
	REQUIRE(list.getSize() == 8);
	REQUIRE(list.toString() == "5,10,20,30,30,40,50,55"); 

	list.insert(5);
	REQUIRE(list.getSize() == 9);
	REQUIRE(list.toString() == "5,5,10,20,30,30,40,50,55"); 		

	REQUIRE(list.removeFirst(1) == false);
	REQUIRE(list.getSize() == 9);
	REQUIRE(list.toString() == "5,5,10,20,30,30,40,50,55");

	REQUIRE(list.removeFirst(5) == true);
	REQUIRE(list.getSize() == 8);
	REQUIRE(list.toString() == "5,10,20,30,30,40,50,55");

	REQUIRE(list.removeFirst(30) == true);
	REQUIRE(list.getSize() == 7);
	REQUIRE(list.toString() == "5,10,20,30,40,50,55");

	REQUIRE(list.removeFirst(30) == true);
	REQUIRE(list.getSize() == 6);
	REQUIRE(list.toString() == "5,10,20,40,50,55");

	REQUIRE(list.removeFirst(55) == true);
	REQUIRE(list.getSize() == 5);
	REQUIRE(list.toString() == "5,10,20,40,50");

	REQUIRE(list.removeFirst(10) == true);
	REQUIRE(list.getSize() == 4);
	REQUIRE(list.toString() == "5,20,40,50");

	list.removeHead();
	REQUIRE(list.getSize() == 3);
	REQUIRE(list.toString() == "20,40,50");

	list.removeTail();
	REQUIRE(list.getSize() == 2);
	REQUIRE(list.toString() == "20,40");

	list.clear();
	REQUIRE(list.getSize() == 0);
	REQUIRE(list.toString() == "");
 }
