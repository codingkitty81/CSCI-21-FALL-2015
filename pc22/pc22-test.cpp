/*
 * Programming Challenge 22 - UNIT TEST
 */

#include "SList.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>
using std::string;

TEST_CASE ("SList<int> full functionality") {
	SList<int> intList;

	REQUIRE(intList.getSize() == 0);
	REQUIRE(intList.toString() == "");

	intList.insert(10);
	REQUIRE(intList.getSize() == 1);
	REQUIRE(intList.toString() == "10");

	intList.insert(10);
	REQUIRE(intList.getSize() == 2);
	REQUIRE(intList.toString() == "10,10");

	intList.insert(30);
	REQUIRE(intList.getSize() == 3);
	REQUIRE(intList.toString() == "10,10,30");

	intList.insert(30);
	REQUIRE(intList.getSize() == 4);
	REQUIRE(intList.toString() == "10,10,30,30");

	intList.insert(15);
	REQUIRE(intList.getSize() == 5);
	REQUIRE(intList.toString() == "10,10,15,30,30");

	intList.insertHead(5);
	REQUIRE(intList.getSize() == 6);
	REQUIRE(intList.toString() == "5,10,10,15,30,30");

	intList.insert(50);
	REQUIRE(intList.getSize() == 7);
	REQUIRE(intList.toString() == "5,10,10,15,30,30,50");

	REQUIRE(intList.removeFirst(1) == false);
	REQUIRE(intList.removeAll(100) == false);

	REQUIRE(intList.removeFirst(10) == true);
	REQUIRE(intList.getSize() == 6);
	REQUIRE(intList.toString() == "5,10,15,30,30,50");

	REQUIRE(intList.removeAll(30) == true);
	REQUIRE(intList.getSize() == 4);
	REQUIRE(intList.toString() == "5,10,15,50");

	intList.removeHead();
	REQUIRE(intList.getSize() == 3);
	REQUIRE(intList.toString() == "10,15,50");

	intList.removeTail();
	REQUIRE(intList.getSize() == 2);
	REQUIRE(intList.toString() == "10,15");

	intList.clear();
	REQUIRE(intList.getSize() == 0);
	REQUIRE(intList.toString() == "");
}

TEST_CASE ("SList<string> full functionality") {
	SList<string> stringList;

	REQUIRE(stringList.getSize() == 0);
	REQUIRE(stringList.toString() == "");

	stringList.insert("hello");
	REQUIRE(stringList.getSize() == 1);
	REQUIRE(stringList.toString() == "hello");

	stringList.insert("hello");
	REQUIRE(stringList.getSize() == 2);
	REQUIRE(stringList.toString() == "hello,hello");

	stringList.insert("mellow");
	REQUIRE(stringList.getSize() == 3);
	REQUIRE(stringList.toString() == "hello,hello,mellow");

	stringList.insert("mellow");
	REQUIRE(stringList.getSize() == 4);
	REQUIRE(stringList.toString() == "hello,hello,mellow,mellow");

	stringList.insert("jello");
	REQUIRE(stringList.getSize() == 5);
	REQUIRE(stringList.toString() == "hello,hello,jello,mellow,mellow");

	stringList.insertHead("cello");
	REQUIRE(stringList.getSize() == 6);
	REQUIRE(stringList.toString() == "cello,hello,hello,jello,mellow,mellow");

	stringList.insert("yellow");
	REQUIRE(stringList.getSize() == 7);
	REQUIRE(stringList.toString() == "cello,hello,hello,jello,mellow,mellow,yellow");

	REQUIRE(stringList.removeFirst("fellow") == false);
	REQUIRE(stringList.removeAll("bellow") == false);

	REQUIRE(stringList.removeFirst("hello") == true);
	REQUIRE(stringList.getSize() == 6);
	REQUIRE(stringList.toString() == "cello,hello,jello,mellow,mellow,yellow");

	REQUIRE(stringList.removeAll("mellow") == true);
	REQUIRE(stringList.getSize() == 4);
	REQUIRE(stringList.toString() == "cello,hello,jello,yellow");

	stringList.removeHead();
	REQUIRE(stringList.getSize() == 3);
	REQUIRE(stringList.toString() == "hello,jello,yellow");

	stringList.removeTail();
	REQUIRE(stringList.getSize() == 2);
	REQUIRE(stringList.toString() == "hello,jello");

	stringList.clear();
	REQUIRE(stringList.getSize() == 0);
	REQUIRE(stringList.toString() == "");	
}
