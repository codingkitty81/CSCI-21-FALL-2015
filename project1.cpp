/*
 * Programming Project 1
 * This program tests some ways to count different aspects of a string
 * whether it is counting how many words, alphabetical characters, or numerical
 * characters are within the provided string. It also takes a string and
 * alternately converts the characters to either upper or lower case throughout
 * the string. Finally there is some arthimetic testing. First test is to
 * calculate the average of values in an array. The second test finds the
 * minimum value in an array and the final test finds the maximum value in an
 * array.
 *
 * Katherine Jouzapaitis
 * Date created: 9/3/2015
 * Date last modified: 9/21/2015
 *
 * Resources:
 * http://www.cplusplus.com/forum/general/30929/
 */
#include <cassert>
#include <climits>
#include <iostream>
#include <string>
using namespace std;

/**
 * Counts the number of alphabetical and numerical characters within a provided
 * string.
 * @param theString a string containing the characters to be counted.
 * @param alpha (call-by-reference) an integer keeping track of the number of alphabetical
 * 			characters in the string.
 * @param num (call-by-reference) an integer keeping track of the number of numerical
 * 			characters in the string.
 */
void countCharacters (string theString, int& alpha, int& num);

/**
 * Take characters from a provided string and will alternately change them to
 * uppercase or lowercase depending on whether their index is even or odd.
 * @param theString a string to be converted to uppercase and lowercase
 *			characters.
 * @return a string after being altered.
 */
string upAndDown (string theString);

/**
 * Counts the number of words in a provided string.
 * @param theString a string containing one or more words to be counted.
 * @return an integer of the number of words in the provided string.
 */
int countWords (string theString);

/**
 * Calculates the average of values within an array.
 * @param values an array of values used for calculating the average.
 * @param arraySize an integer dictating the number of values the array contains.
 * @return an integer that is the calculated average of the values of the array.
 */
int computeAverage (int values [], int arraySize);

/**
 * Finds the smallest value within an array of values.
 * @param values an array of values.
 * @param arraySize an integer dictating the number of values the array contains.
 * @return an integer that is the smallest value within the array.
 */
int findMinValue (int values [], int arraySize);

/**
 * Finds the largest value within an array of values.
 * @param values an array of values.
 * @param arraySize an integer dictating the number of values the array contains.
 * @return an interger that is the largest value within the array.
 */
int findMaxValue (int values [], int arraySize);

/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest ();

int main (int argc, char* argv[]) {
	unittest();
	
	return 0;
}

void countCharacters(string theString, int& alpha, int& num) {
	alpha = 0;
	num = 0;
	
	for (int i = 0; i < theString.length(); i++) {
		if (isalpha (theString[i])) {
			alpha++;
		}
		else if (isdigit (theString[i])) {
			num++;
		}
	}
}

string upAndDown (string theString) {
	for(int i = 0; i < theString.length(); i++) {
			theString[i] = toupper(theString[i]);
			i++;
		}
	for(int j = 1; j < theString.length(); j++) {
			theString[j] = tolower(theString[j]);
			j++;
	}
	return theString;
}

int countWords (string theString){
	int spaces = 1;
	
	if (theString == "") {
		spaces = 0;
	}
	else {
		for (int i = 0; i < theString.length(); i++) {
			if (isspace(theString[i])) {
				spaces++;
			}
		}
	}
	return spaces;
}

int computeAverage (int values [], int arraySize) {
	int sum = 0;
	
	for (int i = 0; i < arraySize; i++) {
		sum = sum + values[i];
	}
	
	int avg = sum / arraySize;
	
	return avg;
}

int findMinValue (int values [], int arraySize) {
	int tempMin = values[0];
	
	for (int i = 1; i < arraySize; i++) {
		if (values[i] < tempMin) {
			tempMin = values[i];
		}
	}
	
	return tempMin;
}

int findMaxValue (int values [], int arraySize) {
	int tempMax = values[0];
	
	for (int i = 1; i < arraySize; i++) {
		if (values[i] > tempMax) {
			tempMax = values[i];
		}
	}
	
	return tempMax;
}

/*
 * Unit testing functions. Do not alter.
 */
void unittest () {

	unsigned short utCount = 30;
	unsigned short utPassed = 0;

	cout << "\nSTARTING UNIT TEST\n\n";

	int n1=0, n2=0;

	try {
		countCharacters("", n1, n2);
		btassert<bool>((n1 == 0) && (n2 == 0));
		cout << "Passed TEST 1: countCharacters(empty string)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 1 #\n";
	}

	try {
		countCharacters("hello", n1, n2);
		btassert<bool>((n1 == 5) && (n2 == 0));
		cout << "Passed TEST 2: countCharacters(\"hello\")\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 2 #\n";
	}

	try {
		countCharacters("12345", n1, n2);
		btassert<bool>((n1 == 0) && (n2 == 5));
		cout << "Passed TEST 3: countCharacters(\"12345\")\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 3 #\n";
	}

	try {
		countCharacters("hello 12345", n1, n2);
		btassert<bool>((n1 == 5) && (n2 == 5));
		cout << "Passed TEST 4: countCharacters(\"hello 12345\")\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 4 #\n";
	}

	try {
		countCharacters("&,.", n1, n2);
		btassert<bool>((n1 == 0) && (n2 == 0));
		cout << "Passed TEST 5: countCharacters(\"&,.\")\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 5 #\n";
	}

	string s;

	try {
		s = upAndDown("hello");
		btassert<bool>(s == "HeLlO");
		cout << "Passed TEST 6: upAndDown(\"hello\")\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 6 #\n";
	}

	try {
		s = upAndDown("HeLlO");
		btassert<bool>(s == "HeLlO");
		cout << "Passed TEST 7: upAndDown(\"HeLlO\")\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 7 #\n";
	}

	try {
		s = upAndDown("hElLo");
		btassert<bool>(s == "HeLlO");
		cout << "Passed TEST 8: upAndDown(\"hElLo\")\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 8 #\n";
	}

	try {
		s = upAndDown("");
		btassert<bool>(s == "");
		cout << "Passed TEST 9: upAndDown(empty string)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 9 #\n";
	}

	try {
		s = upAndDown("a");
		btassert<bool>(s == "A");
		cout << "Passed TEST 10: upAndDown(\"a\")\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 10 #\n";
	}

	try {
		btassert<bool>(countWords("") == 0);
		cout << "Passed TEST 11: countWords(empty string)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 11 #\n";
	}

	try {
		btassert<bool>(countWords("hello") == 1);
		cout << "Passed TEST 12: countWords(\"hello\")\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 12 #\n";
	}

	try {
		btassert<bool>(countWords("hello,world") == 1);
		cout << "Passed TEST 13: countWords(\"hello world\")\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 13 #\n";
	}

	try {
		btassert<bool>(countWords("hello world") == 2);
		cout << "Passed TEST 14: countWords(\"hello world\")\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 14 #\n";
	}

	try {
		btassert<bool>(countWords("hello, world") == 2);
		cout << "Passed TEST 15: countWords(\"hello, world\")\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 15 #\n";
	}

	int values [] = {10, 20, 30};
	try {
		btassert<bool>(computeAverage(values, 3) == 20);
		cout << "Passed TEST 16: computeAverage([10,20,30])\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 16 #\n";
	}

	values[0] = 0, values[1] = 0, values[2] = 0;
	try {
		btassert<bool>(computeAverage(values, 3) == 0);
		cout << "Passed TEST 17: computeAverage([0,0,0])\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 17 #\n";
	}

	values[0] = 5, values[1] = 7, values[2] = 11;
	try {
		btassert<bool>(computeAverage(values, 3) == 7);
		cout << "Passed TEST 18: computeAverages([5,7,11])\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 18 #\n";
	}

	values[0] = -10, values[1] = -20, values[2] = -30;
	try {
		btassert<bool>(computeAverage(values, 3) == -20);
		cout << "Passed TEST 19: computeAverages([-10,-20,-30])\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 19 #\n";
	}

	values[0] = -5, values[1] = 0, values[2] = 5;
	try {
		btassert<bool>(computeAverage(values, 3) == 0);
		cout << "Passed TEST 20: computeAverages([-5,0,5])\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 20 #\n";
	}

	values[0] = -1, values[1] = 0, values[2] = 1;
	try {
		btassert<bool>(findMinValue(values, 3) == -1);
		cout << "Passed TEST 21: findMinValue([-1,0,1])\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 21 #\n";
	}

	values[0] = -3, values[1] = -2, values[2] = -1;
	try {
		btassert<bool>(findMinValue(values, 3) == -3);
		cout << "Passed TEST 22: findMinValue([-3,-2,-1])\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 22 #\n";
	}

	values[0] = 0, values[1] = 1, values[2] = 2;
	try {
		btassert<bool>(findMinValue(values, 3) == 0);
		cout << "Passed TEST 23: findMinValue([0,1,2])\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 23 #\n";
	}

	values[0] = 1, values[1] = 1, values[2] = 1;
	try {
		btassert<bool>(findMinValue(values, 3) == 1);
		cout << "Passed TEST 24: findMinValue([1,1,1])\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 24 #\n";
	}

	values[0] = INT_MAX, values[1] = INT_MAX, values[2] = INT_MAX;
	try {
		btassert<bool>(findMinValue(values, 3) == INT_MAX);
		cout << "Passed TEST 25: findMinValue([INT_MAX,INT_MAX,INT_MAX])\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 25 #\n";
	}

	values[0] = -1, values[1] = 0, values[2] = 1;
	try {
		btassert<bool>(findMaxValue(values, 3) == 1);
		cout << "Passed TEST 26: findMaxValue([-1,0,1])\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 26 #\n";
	}

	values[0] = -3, values[1] = -2, values[2] = -1;
	try {
		btassert<bool>(findMaxValue(values, 3) == -1);
		cout << "Passed TEST 27: findMaxValue([-3,-2,-1])\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 27 #\n";
	}

	values[0] = 0, values[1] = 1, values[2] = 2;
	try {
		btassert<bool>(findMaxValue(values, 3) == 2);
		cout << "Passed TEST 28: findMaxValue([0,1,2])\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 28 #\n";
	}

	values[0] = 1, values[1] = 1, values[2] = 1;
	try {
		btassert<bool>(findMaxValue(values, 3) == 1);
		cout << "Passed TEST 29: findMaxValue([1,1,1])\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 29 #\n";
	}

	values[0] = INT_MIN, values[1] = INT_MIN, values[2] = INT_MIN;
	try {
		btassert<bool>(findMaxValue(values, 3) == INT_MIN);
		cout << "Passed TEST 30: findMaxValue([INT_MIN,INT_MIN,INT_MIN])\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 30 #\n";
	}

	cout << "\nUNIT TEST COMPLETE\n\n";

	cout << "PASSED " << utPassed << " OF " << utCount << " UNIT TEST";
	if (utCount > 1) {
		cout << "S";
	}
	cout << "\n\n";
}

template <typename X, typename A>
void btassert (A assertion) {
	if (!assertion)
		throw X();
}
