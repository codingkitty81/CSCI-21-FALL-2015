/*
 * Programming Challenge 23 - UNIT TEST
 */
 
#include "recursive.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"



TEST_CASE("recursive factorial function") {
	CHECK(factorial(0) == 1);
	CHECK(factorial(1) == 1);
	CHECK(factorial(2) == 2);
	CHECK(factorial(5) == 120);
}

TEST_CASE("recursive fibonacci function") {
	CHECK(fibonacci(1) == 1);
	CHECK(fibonacci(2) == 1);
	CHECK(fibonacci(3) == 2);
	CHECK(fibonacci(15) == 610);
}

TEST_CASE("recursive wordIsPalindrome function") {
	CHECK(wordIsPalindrome("") == true);
	CHECK(wordIsPalindrome("a") == true);
	CHECK(wordIsPalindrome("sitonapotatopanotis") == true);
	CHECK(wordIsPalindrome("baseball") == false);
}

TEST_CASE("recursive array to string functions") {
	int numbers[5] = {5, 10, 15, 20, 25};

	SECTION("recursive array forwards as string function") {
		CHECK(arrayForwardsAsString(numbers, 0, 5) == "5 10 15 20 25 ");
		CHECK(arrayForwardsAsString(numbers, 3, 5) == "20 25 ");
	}

	SECTION("recursive array forwards as string function") {
		CHECK(arrayForwardsAsString(numbers, 5, 5) == "");
		CHECK(arrayBackwardsAsString(numbers, 4, 5) == "25 20 15 10 5 ");
		CHECK(arrayBackwardsAsString(numbers, 1, 5) == "10 5 ");
		CHECK(arrayBackwardsAsString(numbers, -1, 5) == "");
	}
}
