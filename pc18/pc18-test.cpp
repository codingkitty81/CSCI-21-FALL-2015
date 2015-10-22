/*
 * Programming Challenge 18 - UNIT TEST
 * This program handles the construction and destruction of a linked list. The
 * ability to add and remove items at the head of the list is tested, and the
 * ability to display the list is presented here as well.
 * 
 * Katherine Jouzapaitis
 * Date created: 10/13/2015
 * Date last modified: 10/16/2015
 *
 * Resources:
 * http://stackoverflow.com/questions/20225775/inserting-at-the-head-of-the-linkedlist-c
 */

#include "SList.h"
#include "SLNode.h"

/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest ();

int main () {
	unittest();
	
	return 0;
}

/*
 * Unit testing functions. Do not alter.
 */
void unittest () {

    unsigned short utCount = 13;
    unsigned short utPassed = 0;

	cout << "\nSTARTING UNIT TEST\n\n";

	SList list;

	try {
		btassert<bool>(list.getSize() == 0);
		cout << "Passed TEST 1: default constructor (size) \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 1: default constructor (size) #\n";
	}

	try {
		btassert<bool>(list.toString() == "");
		cout << "Passed TEST 2: toString \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 2: toString #\n";
	}

	list.removeHead();
	try {
		btassert<bool>(list.getSize() == 0);
		cout << "Passed TEST 3: removeHead \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 3: removeHead #\n";
	}

	list.insertHead(1);
	try {
		btassert<bool>(list.getSize() == 1);
		cout << "Passed TEST 4: insertHead \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 4: insertHead #\n";
	}

	try {
		btassert<bool>(list.toString() == "1");
		cout << "Passed TEST 5: toString \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 5: toString #\n";
	}

	list.removeHead();
	try {
		btassert<bool>(list.getSize() == 0);
		cout << "Passed TEST 6: removeHead \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 6: removeHead #\n";
	}

	try {
		btassert<bool>(list.toString() == "");
		cout << "Passed TEST 7: toString \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 7: toString #\n";
	}

	list.insertHead(10);
	list.insertHead(20);
	try {
		btassert<bool>(list.toString() == "20,10" && list.getSize() == 2);
		cout << "Passed TEST 8: insertHead,insertHead,toString,getSize \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 8: insertHead,insertHead,toString,getSize #\n";
	}

	list.removeHead();
	try {
		btassert<bool>(list.toString() == "10" && list.getSize() == 1);
		cout << "Passed TEST 9: removeHead,toString,getSize \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 9: removeHead,toString,getSize #\n";
	}

	list.insertHead(5);
	try {
		btassert<bool>(list.toString() == "5,10" && list.getSize() == 2);
		cout << "Passed TEST 10: insertHead,toString,getSize \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 10: insertHead,toString,getSize #\n";
	}

	list.clear();
	try {
		btassert<bool>(list.toString() == "" && list.getSize() == 0);
		cout << "Passed TEST 11: clear,toString,getSize \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 11: clear,toString,getSize #\n";
	}

	for (unsigned int i=0; i<1000; i++)
		list.insertHead(i);
	try {
		btassert<bool>(list.getSize() == 1000);
		cout << "Passed TEST 12: insertHead high load \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 12: insertHead high load #\n";
	}

	for (unsigned int i=0; i<1000; i++)
		list.removeHead();
	try {
		btassert<bool>(list.getSize() == 0);
		cout << "Passed TEST 13: removeHead high load \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 13: removeHead high load #\n";
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
