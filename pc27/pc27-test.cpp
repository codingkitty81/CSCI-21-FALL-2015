/*
 * Programming Challenge 27
 */
#include "BSTree.h"
#include "Utility.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>
#include <sstream>
using std::cout;
using std::ostringstream;
using std::streambuf;

TEST_CASE ("binary search tree traversals (in-order, reverse-order)/callback function") {
	BSTree tree;
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);

	streambuf* oldCout = cout.rdbuf();
	ostringstream captureCout;
	cout.rdbuf(captureCout.rdbuf());

	tree.inOrder(Utility::log);
	CHECK(captureCout.str() == "5 10 15 ");

	captureCout.str("");
	tree.reverseOrder(Utility::log);
	CHECK(captureCout.str() == "15 10 5 ");

	cout.rdbuf(oldCout);
}
