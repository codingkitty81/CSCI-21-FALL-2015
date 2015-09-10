/*
 * Programming Challenge 6
 * This program deals with arrays in a variety of ways. First it displays an
 * array with desired separators, it will check to see if there is a particular
 * value within the array. Also, it will display a value at a given index, sum
 * the either the entire or portions of the array, and it will swap values of
 * given indexes.
 *
 * Katherine Jouzapaitis
 * Date created: 9/1/2015
 * Date last modified: 9/2/2015
 *
 */
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/*
 * Create a string containing the contents of an array, each element 
 * separated by a specified character. For example, if the array contents
 * are {1, 2, 3} and the separator character is ':', the string returned
 * will be "1:2:3"
 * @param values an integer array
 * @param size the size of the integer array values
 * @param separator the character to use as the separator character in
 *        the returned string
 * @return a string containing the contents of values separated by the
 *         specified separator character
 */
string prepareForDisplay (int values[], int size, char separator = ',');

/*
 * Test to see if an array contains a specified value.
 * @param values an integer array
 * @param size the size of the integer array values
 * @param value the value to search for within the array values
 * @return true if value is found in values, else false
 */
bool hasValue (int values[], int size, int value);

/*
 * Return the value from an array at a specified index.
 * @param values an integer array
 * @param size the size of the integer array values
 * @param index the position in the array from which to return a value
 * @param error a bool flag that will be set to true if index
 *        is invalid for the array, else it will be set to false
 * @return an integer containing the value at the specified index in the
 *         array and error set to false; if index is invalid, returns 0 and 
 *         sets error to true
 */
int valueAt (int values[], int size, int index, bool& error);

/*
 * Return the sum of the values in an integer array.
 * @param values an integer array
 * @param size the size of the integer array values
 * @return an integer containing a sum of the values in the array
 */
int sum (int values[], int size);

/*
 * Swap the positions of two values in an integer array. This function 
 * does not check the validity of the two indices -- the function assumes 
 * the caller passes valid indices for the array.
 * @param values an integer array
 * @param index1 the position of the first value to be swapped
 * @param index2 the position of the second value to be swapped
 */
void swapValues (int values[], int index1, int index2);

/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest ();

int main (int argc, char* argv[]) {
	unittest();
	
	return 0;
}

// CODE HERE -- FUNCTION DEFINITIONS
string prepareForDisplay (int values[], int size, char separator) {
	
	stringstream valueStream;
	
	for (int i = 0; i < size; i++) {
		valueStream << values[i] << separator;
	}
	//substr(first argument is index of where you want to start keeping string, second argument is where what you want kept ends)
	return(valueStream.str().substr(0,valueStream.str().length() - 1));
}

bool hasValue (int values[], int size, int value) {
	
	bool check = false;
	
	for (int i = 0; i < size; i++) {
		if (values[i] == value) {
			check = true;
		}
	}
	
	return(check);
}

int valueAt (int values[], int size, int index, bool& error) {
	
	error = true;
	
	if (index < size) {
		error = false;
		return(values[index]);
	}
	else {
		return(0);
	}
}

int sum (int values[], int size) {
	
	int sumVal = 0;
	
	for (int i = 0; i < size; i++) {
		sumVal = sumVal + values[i];
	}
	
	return(sumVal);
}

void swapValues (int values[], int index1, int index2) {
	
	int tempVal = values[index1];
	values[index1] = values[index2];
	values[index2] = tempVal;
}

/*
 * Unit testing functions. Do not alter.
 */

void unittest () {

	unsigned short utCount = 15;
	unsigned short utPassed = 0;

	cout << "\nSTARTING UNIT TEST\n\n";
	
	int values[] = {3, 5, 7, 9, 11};
	int size = 5;
	
	try {
		btassert<bool>(prepareForDisplay(values, size) == "3,5,7,9,11");
		cout << "Passed TEST 1: prepareForDisplay(values, size)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 1 prepareForDisplay(values, size) #\n";
	}
	
	try {
		btassert<bool>(prepareForDisplay(values, size, ' ') == "3 5 7 9 11");
		cout << "Passed TEST 2: prepareForDisplay(values, size, ' ')\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 2 prepareForDisplay(values, size, ' ') #\n";
	}
	
	try {
		btassert<bool>(prepareForDisplay(values, size, ':') == "3:5:7:9:11");
		cout << "Passed TEST 3: prepareForDisplay(values, size, ':')\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 3 prepareForDisplay(values, size, ':') #\n";
	}
	
	try {
		btassert<bool>(hasValue(values, size, 0) == false);
		cout << "Passed TEST 4: hasValue(values, size, 0)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 4 hasValue(values, size, 0) #\n";
	}
	
	try {
		btassert<bool>(hasValue(values, size, 3) == true);
		cout << "Passed TEST 5: hasValue(values, size, 3)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 5 hasValue(values, size, 3) #\n";
	}
	
	try {
		btassert<bool>(hasValue(values, size, 11) == true);
		cout << "Passed TEST 6: hasValue(values, size, 11)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 6 hasValue(values, size, 11) #\n";
	}
	
	bool error = true;
	
	try {
		btassert<bool>(valueAt(values, size, 0, error) == 3 && error == false);
		cout << "Passed TEST 7: valueAt(values, size, 0, error)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 7 valueAt(values, size, 0, error) #\n";
	}
	
	try {
		btassert<bool>(valueAt(values, size, 5, error) == 0 && error == true);
		cout << "Passed TEST 8: valueAt(values, size, 5, error)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 8 valueAt(values, size, 5, error) #\n";
	}
	
	try {
		btassert<bool>(valueAt(values, size, 4, error) == 11 && error == false);
		cout << "Passed TEST 9: valueAt(values, size, 4, error)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 9 valueAt(values, size, 4, error) #\n";
	}
	
	try {
		btassert<bool>(sum(values, size) == 35);
		cout << "Passed TEST 10: sum(values, size)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 10 sum(values, size) #\n";
	}
	
	try {
		btassert<bool>(sum(values, 1) == 3);
		cout << "Passed TEST 11: sum(values, 1)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 11 sum(values, 1) #\n";
	}
	
	try {
		btassert<bool>(sum(values, 0) == 0);
		cout << "Passed TEST 12: sum(values, 0)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 12 sum(values, 0) #\n";
	}
	
	try {
		swapValues(values, 0, 4);
		btassert<bool>(values[0] == 11 && values[4] == 3);
		cout << "Passed TEST 13: swapValues(values, 0, 4)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 13 swapValues(values, 0, 4) #\n";
	}
	
	try {
		swapValues(values, 1, 3);
		btassert<bool>(values[1] == 9 && values[3] == 5);
		cout << "Passed TEST 14: swapValues(values, 1, 3)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 14 swapValues(values, 1, 3) #\n";
	}
	
	try {
		swapValues(values, 2, 2);
		btassert<bool>(values[2] == 7);
		cout << "Passed TEST 15: swapValues(values, 2, 2)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 15 swapValues(values, 2, 2) #\n";
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