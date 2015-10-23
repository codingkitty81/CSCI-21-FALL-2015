/*
 * Programming Challenge 19 - UNIT TEST
 * This program tests the construction and destruction of a linked list and
 * the insertion and removal of Nodes at the head and tail of a linked list, 
 * by checking the size of the list and testing the output from the toString() 
 * function.
 *
 * Katherine Jouzpaitis
 * Date created: 10/20/2015
 * Date last modified: 10/21/2015
 *
 * Resources:
 * http://stackoverflow.com/questions/20125477/linked-list-insert-at-the-end-c
 * http://stackoverflow.com/questions/19326017/deleting-the-back-element-in-a-linked-list
 */

#include "SList.h"

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

    unsigned short utCount = 21;
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
	
	list.removeTail();
	try {
		btassert<bool>(list.getSize() == 0);
		cout << "Passed TEST 4: removeTail \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 4: removeTail #\n";
	}
	
	list.insertHead(1);
	try {
		btassert<bool>(list.getSize() == 1);
		cout << "Passed TEST 5: insertHead \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 5: insertHead #\n";
	}
	
	try {
		btassert<bool>(list.toString() == "1");
		cout << "Passed TEST 6: toString \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 6: toString #\n";
	}
	
	list.removeHead();
	try {
		btassert<bool>(list.getSize() == 0);
		cout << "Passed TEST 7: removeHead \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 7: removeHead #\n";
	}
	
	list.insertTail(1);
	try {
		btassert<bool>(list.getSize() == 1);
		cout << "Passed TEST 8: insertTail \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 8: insertTail #\n";
	}
	
	try {
		btassert<bool>(list.toString() == "1");
		cout << "Passed TEST 9: toString \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 9: toString #\n";
	}
	
	list.removeTail();
	try {
		btassert<bool>(list.getSize() == 0);
		cout << "Passed TEST 10: removeTail \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 10: removeTail #\n";
	}
	
	list.insertHead(10);
	list.insertTail(20);
	try {
		btassert<bool>(list.toString() == "10,20" && list.getSize() == 2);
		cout << "Passed TEST 11: insertHead,insertTail,toString,getSize \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 11: insertHead,insertTail,toString,getSize #\n";
	}
	
	list.removeHead();
	try {
		btassert<bool>(list.toString() == "20" && list.getSize() == 1);
		cout << "Passed TEST 12: removeHead,toString,getSize \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 12: removeHead,toString,getSize #\n";
	}
	
	list.insertHead(10);
	list.removeTail();
	try {
		btassert<bool>(list.toString() == "10" && list.getSize() == 1);
		cout << "Passed TEST 13: insertHead,removeTail,toString,getSize \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 13: insertHead,removeTail,toString,getSize #\n";
	}
	
	list.clear();
	try {
		btassert<bool>(list.toString() == "" && list.getSize() == 0);
		cout << "Passed TEST 14: clear,toString,getSize \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 14: clear,toString,getSize #\n";
	}
	
	list.insertHead(10);
	list.insertHead(5);
	list.insertTail(20);
	list.insertTail(25);
	try {
		btassert<bool>(list.toString() == "5,10,20,25" && list.getSize() == 4);
		cout << "Passed TEST 15: insertHeadx2,insertTailx2,toString,getSize \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 15: insertHeadx2,insertTailx2,toString,getSize #\n";
	}
	
	list.removeHead();
	list.removeTail();
	list.removeHead();
	list.removeTail();
	list.clear();
	try {
		btassert<bool>(list.toString() == "" && list.getSize() == 0);
		cout << "Passed TEST 16: removeHeadx2,removeTailx2,toString,getSize \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 16: removeHeadx2,removeTailx2,toString,getSize #\n";
	}
	
	for (unsigned int i=0; i<1000; i++)
		list.insertHead(i);
	try {
		btassert<bool>(list.getSize() == 1000);
		cout << "Passed TEST 17: insertHead high load \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 17: insertHead high load #\n";
	}
	
	for (unsigned int i=0; i<1000; i++)
		list.removeHead();
	try {
		btassert<bool>(list.getSize() == 0);
		cout << "Passed TEST 18: removeHead high load \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 18: removeHead high load #\n";
	}
	
	for (unsigned int i=0; i<1000; i++)
		list.insertTail(i);
	try {
		btassert<bool>(list.getSize() == 1000);
		cout << "Passed TEST 19: insertTail high load \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 19: insertTail high load #\n";
	}
	
	for (unsigned int i=0; i<1000; i++)
		list.removeTail();
	try {
		btassert<bool>(list.getSize() == 0);
		cout << "Passed TEST 20: removeTail high load \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 20: removeTail high load #\n";
	}
	
	for (unsigned int i=0; i<1000; i++)
	{
		if (i%2)
			list.insertHead(i);
		else
			list.insertTail(i);
	}
	try {
		btassert<bool>(list.getSize() == 1000);
		cout << "Passed TEST 21: insertHead/insertTail high load \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 21: insertHead/insertTail high load #\n";
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