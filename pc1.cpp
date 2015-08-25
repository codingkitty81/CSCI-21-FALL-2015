/*
 * Programming Challenge 1
 * This program prompts the user for their name and if they
 * have experience programming in C++.
 *
 * Katherine Jouzapaitis
 * Date created: 8/24/2015
 * Last date modified: 8/25/2015
 */
#include <cassert>
#include <iostream>
using namespace std;

string greet (string name);
string checkExperience (char hasExperience);

/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest (string s, char c);

int main (int argc, char* argv[]) {

	// 1 declare a string variable named userName
	
		string userName;
		
	// 2 declare a char variable named programmedBefore
	//   and initialize programmedBefore to the value 'z'
	
		char programmedBefore = 'z';
	
	// 3 display a welcome message to standard output
	// 4 prompt the user for a name
	
		cout << "Hello. Welcome to a new semester.\n"
				"Please enter you name: ";
			
	// 5 read in the name from standard input and store
	//   in the variable userName		
			
		getline(cin, userName);
		
	// 6 ask the user the yes/no question "Have you programmed 
	//   in C++ before?"		
	
		cout << "Have you programmed in C++ before?\n";
	
	// 7 read in the answer from standard input and store
	//   in the variable programmedBefore
	
		cin >> programmedBefore;
		
	unittest(userName, programmedBefore);
	
	return 0;
}

/*
 * Create a string greeting that is the concatenation of a message 
 * and a name.
 * @param name a string containing a user name
 * @return the string "Nice to meet you, NAME" where NAME contains 
 *         the parameter value
 */
string greet (string name) {
	return string("Nice to meet you, " + name);
}

/*
 * Create a string message based upon whether or not a user has C++ 
 * programming experience.
 * @param hasExperience a char ('Y'es or 'N'o) representing whether or 
 *        not a user has C++ programming experience
 * @return "Welcome back" when hasExperience is 'Y', else "Get ready to 
 *         have some fun"
 */
string checkExperience (char hasExperience) {
	
	if (toupper(hasExperience) == 'Y') {
		return string("Welcome back");
	}
	else {
		return string("Get ready to have some fun");
	}
	
}

/*
 * Unit test. Do not alter this function.
 */
void unittest (string s, char c) {

	unsigned short utCount = 2;
	unsigned short utPassed = 0;

	if (s == "fez") {
		cout << "\nSTARTING UNIT TEST\n\n";
		
		try {
			btassert<bool>(greet(s) == "Nice to meet you, fez");
			cout << "Passed TEST 1: greet\n";
			++utPassed;
		} catch (bool b) {
			cout << "# FAILED TEST 1 greet #\n";
		}
		
		if (toupper(c) == 'Y') {
			try {
				btassert<bool>(checkExperience(c) == "Welcome back");
				cout << "Passed TEST 2: checkExperience\n";
				++utPassed;
			} catch (bool b) {
				cout << "# FAILED TEST 2 checkExperience #\n";
			}
		}
		else if (toupper(c) == 'N') {
			try {
				btassert<bool>(checkExperience(c) == "Get ready to have some fun");
				cout << "Passed TEST 2: checkExperience\n";
				++utPassed;
			} catch (bool b) {
				cout << "# FAILED TEST 2 checkExperience #\n";
			}
		}
        else {
            cout << "# FAILED TEST 2 checkExperience #\n";
        }
		
		cout << "\nUNIT TEST COMPLETE\n\n";

		cout << "PASSED " << utPassed << " OF " << utCount << " UNIT TEST";
		if (utCount > 1) {
			cout << "S";
		}
		cout << "\n\n";
	}
	else {
		cout << "\nRun program and enter the name \"fez\" to see unit test output.\n";
	}
}

template <typename X, typename A>
void btassert (A assertion) {
    if (!assertion)
		throw X();
}
