/*
 * Programming Challenge 8
 * This program takes input from the console, then compares it given values. If
 * there is a match then a function is called for that corresponding number and
 * a counter is activated. There is also a counter for any input that does not
 * match the desired values.
 *
 * Katherine Jouzapaitis
 * Date created: 9/3/2015
 * Date last modified: 9/10/2015
 *
 */
#include <cassert>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;

/*
 * Process the argv array (command-line arguments to the program). Ignore 
 * argv[0] as that is the program name. Perform the following operations on 
 * the input values:
 * <ul>
 * <li>10 -- invoke the function onTen</li>
 * <li>20 -- invoke the function onTwenty</li>
 * <li>30 -- invoke the function onThirty</li>
 * <li>40 -- invoke the function onForty</li>
 * <li>50 -- invoke the function onFifty</li>
 * <li>any other value -- invoke the function onError</li>
 * </ul>
 * @param argc an integer containing the number of arguments passed to the program
 *        on the command-line
 * @param argv an array containing the command-line arguments
 */
void processArguments (int argc, char* argv[]);

/* for unit testing -- do not alter */
map<int,int> counters;
bool checkArgs (int argc, char* argv[]);
void onTen ();
void onTwenty ();
void onThirty ();
void onForty ();
void onFifty ();
void onError ();

template <typename X, typename A>
void btassert(A assertion);
void unittest (int argc, char* argv[]);

int main (int argc, char* argv[]) {
	unittest(argc, argv);
	
	return 0;
}

// CODE HERE -- FUNCTION DEFINITIONS
void processArguments (int argc, char* argv[]) {
	
	stringstream valueStream;
	
	for (int i = 1; i < argc; i++) {
		valueStream.str("");
		valueStream << argv[i];
			if (valueStream.str() == "10") {
				onTen();
			}
			else if (valueStream.str() == "20") {
				onTwenty();
			}
			else if (valueStream.str() == "30") {
				onThirty();
			}
			else if (valueStream.str() == "40") {
				onForty();
			}
			else if (valueStream.str() == "50") {
				onFifty();
			}
			else {
				onError();
			}
	}
}
/*
 * Unit testing functions. Do not alter.
 */

void unittest (int argc, char* argv[]) {
	if (argc > 1 && strcmp(argv[1], "teacher") == 0 && checkArgs(argc, argv)) {

		unsigned short utCount = 6;
		unsigned short utPassed = 0;

		cout << "\nSTARTING UNIT TEST\n\n";
		
		counters[10] = 0, counters[20] = 0, counters[20] = 0, counters[40] = 0, counters[50] = 0;
		counters[99] = 0; // errors
	
		processArguments(argc, argv);
	
		try {
			btassert<bool>(counters[10] == 1);
			cout << "Passed TEST 1: counters[10]\n";
			++utPassed;
		} catch (bool b) {
			cout << "# FAILED TEST 1 counters[10] #\n";
		}
	
		try {
			btassert<bool>(counters[20] == 1);
			cout << "Passed TEST 2: counters[20]\n";
			++utPassed;
		} catch (bool b) {
			cout << "# FAILED TEST 2 counters[20] #\n";
		}
	
		try {
			btassert<bool>(counters[30] == 1);
			cout << "Passed TEST 3: counters[30]\n";
			++utPassed;
		} catch (bool b) {
			cout << "# FAILED TEST 3 counters[30] #\n";
		}
	
		try {
			btassert<bool>(counters[40] == 1);
			cout << "Passed TEST 4: counters[40]\n";
			++utPassed;
		} catch (bool b) {
			cout << "# FAILED TEST 4 counters[40] #\n";
		}
	
		try {
			btassert<bool>(counters[50] == 1);
			cout << "Passed TEST 5: counters[50]\n";
			++utPassed;
		} catch (bool b) {
			cout << "# FAILED TEST 5 counters[50] #\n";
		}
	
		try {
			btassert<bool>(counters[99] == 2); // teacher and 60 should be errors
			cout << "Passed TEST 6: counters[99]\n";
			++utPassed;
		} catch (bool b) {
			cout << "# FAILED TEST 6 counters[99] #\n";
		}
		
		cout << "\nUNIT TEST COMPLETE\n\n";

		cout << "PASSED " << utPassed << " OF " << utCount << " UNIT TEST";
		if (utCount > 1) {
			cout << "S";
		}
		cout << "\n\n";
	}
	else {
		cout << "\nRun program with the following argument list:\n";
		cout << "\n\t\"teacher 10 20 30 40 50 60\"\n";
	 	cout << "\nto run the UNIT TEST.\n\n";
	}
}

void onTen () {
	counters[10]++;
}

void onTwenty () {
	counters[20]++;
}

void onThirty () {
	counters[30]++;
}

void onForty () {
	counters[40]++;
}

void onFifty () {
	counters[50]++;
}

void onError () {
	counters[99]++;
}

bool checkArgs (int argc, char* argv[]) {
	if (argc == 8) {
		// convert the argv[2] to argv[7] contents to integers
		int* temps = new int[6];
		stringstream ss;
		for (int i=0, j=2; i<6; i++,j++) {
			ss.str(argv[j]);
			ss >> temps[i];
			ss.clear();
		}
		
		// check to see that argv[2] to argv[7] match the expected launch UNIT TEST values
		for (int i=0,j=10; i<6; i++,j+=10) {
			if (temps[i] != j)
				return false;
		}
		
		delete [] temps;
		
		return true;
	}
	return false;
}

template <typename X, typename A>
void btassert (A assertion) {
    if (!assertion)
		throw X();
}