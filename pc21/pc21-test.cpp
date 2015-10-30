/*
 * Programming Challenge 21 - UNIT TEST
 */

#include "box.h"

/*
 * Programming Challenge 21
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

 #include <iostream>
 using std::ostringstream;

TEST_CASE ("Box<int> class functionality", "[Box]") {
	Box<int> intBox(99);

	REQUIRE(intBox.getContents() == 99);

	intBox.setContents(42);
	REQUIRE(intBox.getContents() == 42);

	ostringstream ss;
	ss << intBox;
	REQUIRE(ss.str() == "42");
}

TEST_CASE ("Box<bool> class functionality", "[Box]") {
	Box<bool> boolBox(false);

	REQUIRE(boolBox.getContents() == false);

	boolBox.setContents(true);
	REQUIRE(boolBox.getContents() == true);

	ostringstream ss;
	ss << boolBox;
	REQUIRE(ss.str() == "1");
}

TEST_CASE ("Box<float> class functionality", "[Box]") {
	Box<float> floatBox(1.23f);

	REQUIRE(floatBox.getContents() == 1.23f);

	floatBox.setContents(3.21f);
	REQUIRE(floatBox.getContents() == 3.21f);

	ostringstream ss;
	ss << floatBox;
	REQUIRE(ss.str() == "3.21");
}

TEST_CASE ("Box<string> class functionality", "[Box]") {
	Box<string> stringBox("hello");

	REQUIRE(stringBox.getContents() == "hello");

	stringBox.setContents("goodbye");
	REQUIRE(stringBox.getContents() == "goodbye");

	ostringstream ss;
	ss << stringBox;
	REQUIRE(ss.str() == "goodbye");
}