/*
 * Programming Challenge 5
 * This program outputs a couple messages. It also finds the larger of two
 * values, will count the number of characters in a string and the number
 * of alphabetical character and numeric digits. Lastly it will take a message
 * and if allCaps is true, then the characters will be converted to uppercase,
 * if false the message will not be adjusted.
 *
 * Katherine Jouzapaitis
 * Date created: 8/31/2015
 * Last date modified: 9/1/2015
 *
 * Resources:
 * http://www.programiz.com/cpp-programming/default-argument
 */
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <streambuf>
using namespace std;

// CODE HERE -- FUNCTION DECLARATIONS/PROTOTYPES

/*
 * function name: hello
 * parameters: none
 * default arguments: n/a
 * return type: void
 * 
 * Display "Hello world!" to stdout (no newline character after)
 */
 
void hello();

/*
 * function name: printMessage
 * parameters: string message (call-by-value)
 * default arguments: none
 * return type: void
 * 
 * Display message to stdout (no newline character after)
 */
 
void printMessage(string message);

/*
 * function name: getAnswer
 * parameters: none
 * default arguments: n/a
 * return type: int
 * 
 * Return the value 42
 */
 
int getAnswer();

/*
 * function name: findLarger
 * parameters: int n1 (call-by-value), int n2 (call-by-value)
 * default arguments: none
 * return type: int
 * 
 * Return the larger of the two parameter values. Should work correctly
 * if the values are equivalent.
 */
 
int findLarger(int n1, int n2);

/*
 * function name: getStats
 * parameters: string s (call-by-value), int alphaCount (call-by-reference), int digitCount (call-by-reference)
 * default arguments: none
 * return type: int
 * 
 * Return the length of string s. On return alphaCount should contain a count of the number of alphabetic 
 * characters in s, digitCount should contain a count of the number of digits in s.
 */
 
int getStats(string s, int& alphaCount, int& digitCount);

/*
 * function name: buildMessage
 * parameters: string s (call-by-value), bool allCaps (call-by-value)
 * default arguments: s = "" (empty string), allCaps = false
 * return type: string
 * 
 * Return the string "Message: STRING", where STRING is replaced by the value of the parameter s. If allCaps is 
 * true, convert s to all uppercase letters before concatenating it with "Message: ". If s is empty string, 
 * return "Message: empty".
 */
 
string buildMessage(string s = "", bool allCaps = false);

/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest ();

int main (int argc, char* argv[]) {
	unittest();
	
	return 0;
}

// CODE HERE -- FUNCTION DEFINITIONS

void hello() {
	cout << "Hello world!";
}

void printMessage(string message) {
	cout << message;
}

int getAnswer() {
	return(42);
}

int findLarger(int n1, int n2) {
	if (n1 > n2) {
		return(n1);
	}
	else if (n2 > n1) {
		return(n2);
	}
	else {
		return(n1);
	}
}

int getStats(string s, int& alphaCount, int& digitCount) {
	alphaCount = 0;
	digitCount = 0;
	
	for (int i = 0; i < s.length(); i++) {
		if (isalpha (s[i])) {
			alphaCount++;
		}
		else if (isdigit (s[i])) {
			digitCount++;
		}
	}
	return(s.length());
}

string buildMessage(string s, bool allCaps) {
	if (s == "") {
		s = "empty";
	}	
	if (allCaps == true) {
		for(unsigned int i = 0; i < s.length(); ++i) {
			s[i] = toupper(s[i]);
		}
	}
	return("Message: " + s);
}

/*
 * Unit testing functions. Do not alter.
 */

void unittest () {

	unsigned short utCount = 15;
	unsigned short utPassed = 0;

	cout << "\nSTARTING UNIT TEST\n\n";
	
	streambuf* oldCout = cout.rdbuf();
	ostringstream captureCout;
	cout.rdbuf(captureCout.rdbuf());
	
	hello();
	cout.rdbuf(oldCout);
	try {
		btassert<bool>(captureCout.str() == "Hello world!");
		cout << "Passed TEST 1: hello()\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 1 hello() #\n";
	}
	
	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	printMessage("Hello again!");
	cout.rdbuf(oldCout);
	try {
		btassert<bool>(captureCout.str() == "Hello again!");
		cout << "Passed TEST 2: printMessage(\"Hello again!\")\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 2 printMessage(\"Hello again!\") #\n";
	}
	
	try {
		btassert<bool>(getAnswer() == 42);
		cout << "Passed TEST 3: getAnswer()\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 3 getAnswer() #\n";
	}
	
	try {
		btassert<bool>(findLarger(-1, 1) == 1);
		cout << "Passed TEST 4: findLarger(-1, 1)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 4 findLarger(-1, 1) #\n";
	}
	
	try {
		btassert<bool>(findLarger(1, -1) == 1);
		cout << "Passed TEST 5: findLarger(1, -1)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 5 findLarger(1, -1) #\n";
	}
	
	try {
		btassert<bool>(findLarger(1, 1) == 1);
		cout << "Passed TEST 6: findLarger(1, 1)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 6 findLarger(1, 1) #\n";
	}
	
	int alpha=0, digit=0;
	try {
		btassert<bool>(getStats("abc 123", alpha, digit) == 7 && alpha == 3 && digit == 3);
		cout << "Passed TEST 7: getStats(\"abc 123\", alpha, digit)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 7 getStats(\"abc 123\", alpha, digit) #\n";
	}
	
	try {
		btassert<bool>(getStats("abc", alpha, digit) == 3 && alpha == 3 && digit == 0);
		cout << "Passed TEST 8: getStats(\"abc\", alpha, digit)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 8 getStats(\"abc\", alpha, digit) #\n";
	}
	
	try {
		btassert<bool>(getStats("123", alpha, digit) == 3 && alpha == 0 && digit == 3);
		cout << "Passed TEST 9: getStats(\"123\", alpha, digit)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 9 getStats(\"123\", alpha, digit) #\n";
	}
	
	try {
		btassert<bool>(getStats("", alpha, digit) == 0 && alpha == 0 && digit == 0);
		cout << "Passed TEST 10: getStats(\"\", alpha, digit)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 10 getStats(\"\", alpha, digit) #\n";
	}
	
	try {
		btassert<bool>(buildMessage("hello") == "Message: hello");
		cout << "Passed TEST 11: buildMessage(\"hello\")\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 11 buildMessage(\"hello\") #\n";
	}
	
	try {
		btassert<bool>(buildMessage("hello", true) == "Message: HELLO");
		cout << "Passed TEST 12: buildMessage(\"hello\", true)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 12 buildMessage(\"hello\", true) #\n";
	}
	
	try {
		btassert<bool>(buildMessage("HELLO", false) == "Message: HELLO");
		cout << "Passed TEST 13: buildMessage(\"HELLO\", false)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 13 buildMessage(\"HELLO\", false) #\n";
	}
	
	try {
		btassert<bool>(buildMessage("HELLO", true) == "Message: HELLO");
		cout << "Passed TEST 14: buildMessage(\"HELLO\", true)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 14 buildMessage(\"HELLO\", true) #\n";
	}
	
	try {
		btassert<bool>(buildMessage() == "Message: empty");
		cout << "Passed TEST 15: buildMessage()\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 15 buildMessage() #\n";
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
