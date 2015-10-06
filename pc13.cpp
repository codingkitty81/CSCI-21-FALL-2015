/*
 * Programming Challenge 13
 * This program dynamically handles a string, and will free up the memory previoudly used and
 * make the pointer for the string NULL. The total characters within the string will be counted,
 * separated out by alpha, digit, and other characters. A word can be found within the string, 
 * and replaced. If the string's pointer is set to NULL for any of these operations an
 * exception will be thrown.
 *
 * Katherine Jouzapaitis
 * Date created: 9/21/2015
 * Date last modified: 10/6/2015
 *
 * Resources:
 * http://www.cplusplus.com/doc/tutorial/pointers/
 * http://stackoverflow.com/questions/18090739/how-do-i-use-stringfind-to-find-a-word-in-file-using-c
 * http://www.cplusplus.com/forum/beginner/99785/
 * http://en.cppreference.com/w/cpp/language/operator_member_access
 */
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

/*
 * Allocate memory for a dynamic string with specified contents.
 * @param contents the desired contents of the dynamic string
 * @return a pointer to the newly allocated string
 */
string* makeDynoString (string contents);
	
/*
 * Free the memory associated with a dynamic string and NULL out its pointer.
 * @param theString a pointer (passed by reference) to a dynamic string
 */
void clearDynoString (string*& theString);

/*
 * Count the number of alphabetic and numeric characters in a string and return its length.
 * @param theString a pointer to the string in which characters will be counted
 * @param alpha an unsigned int (passed by reference) that will contain the count
 *        of alphabetic characters in the string on return
 * @param num an unsigned int (passed by reference) that will contain the count
 *        of numeric characters in the string on return
 * @return an unsigned integer containined the length of theString
 * @throw ArrayException with the message "NULL STRING REFERENCE" if theString is NULL
 */
unsigned int countChars (string* theString, unsigned int& alpha, unsigned int& num);

/*
 * Find a word inside of a string.
 * @param theString the string in which the search for a word will take place
 * @param theWord the word to look for inside of theString
 * @return true if theWord is found in theString, else false
 * @throw ArrayException with the message "NULL STRING REFERENCE" if theString is NULL
 */
bool findWord (string* theString, string theWord);

/*
 * Replace one word in a string with another word.
 * @param theString a pointer to the string that will have a word replaced
 * @param oldWord the word inside of theString being replaced
 * @param newWord the word that will be used to replace oldWord in theString
 * @return true if oldWord was found and replaced, else return false
 * @throw ArrayException with the message "NULL STRING REFERENCE" if theString is NULL
 */
bool replaceWord (string* theString, string oldWord, string newWord);

/* for unit testing -- do not alter */
struct ArrayException {
	ArrayException (string newMessage="error")
	: message(newMessage) {
	}
	
	string message;
};

template <typename X, typename A>
void btassert(A assertion);
void unittest ();

int main (int argc, char* argv[]) {
	unittest();
	
	return 0;
}

// CODE HERE -- FUNCTION DEFINITIONS

string* makeDynoString (string contents) {
	string* dynString = new string;
	*dynString = contents;
	return dynString;
}

void clearDynoString (string*& theString) {
	if (theString != NULL) {
		delete theString;
		theString = NULL;
	}
}

unsigned int countChars (string* theString, unsigned int& alpha, unsigned int& num) {
	alpha = 0;
	num = 0;
	int charCount = 0;
	int otherChar = 0;
	
	if (theString == NULL) {
		throw ArrayException("NULL STRING REFERENCE");
	} else {
		// theString->length() is the same as (*theString).length()
			for (int i = 0; i < theString->length(); i++) {
				if (isalpha ((*theString)[i])) {
					alpha++;
				}
				else if (isdigit ((*theString)[i])) {
					num++;
				} else {
					otherChar++;
				}
			}
	}
	
	charCount = alpha + num + otherChar;
	
	return charCount;
}

bool findWord (string* theString, string theWord) {
	
	if (theString == NULL) {
		throw ArrayException("NULL STRING REFERENCE");
	} else {
		string::size_type pos = theString->find(theWord);
			if (pos != string::npos){
				return true;
			} else {
				return false;
			}
	}
}

bool replaceWord (string* theString, string oldWord, string newWord) {
	
	if (theString == NULL) {
		throw ArrayException("NULL STRING REFERENCE");
	} else {
		string::size_type foundWord = theString->find(oldWord);
			if (foundWord != string::npos) {
				theString->replace(theString->find(oldWord), oldWord.length(), newWord);
				return true;
			} else {
				return false;
			}
	}
}
/*
 * Unit testing functions. Do not alter.
 */

void unittest () {

	unsigned short utCount = 12;
	unsigned short utPassed = 0;

	cout << "\nSTARTING UNIT TEST\n\n";
	
	string* myString = 0;
	unsigned int alpha, num;
	
	try {
		countChars(myString, alpha, num);
        btassert<bool>(false);
	} catch (ArrayException e) {
		try {
			btassert<bool>(e.message == "NULL STRING REFERENCE");
			cout << "Passed TEST 1: countChars EXCEPTION HANDLING (STRING*) () \n";
			++utPassed;
		} catch (bool b) {
			cout << "# FAILED TEST 1: countChars EXCEPTION HANDLING (STRING*) () #\n";
		}
	} catch (bool) {
		cout << "# FAILED TEST 1: countChars MISSING EXCEPTION #\n";
	}
	
	try {
		findWord(myString, "hello");
        btassert<bool>(false);
	} catch (ArrayException e) {
		try {
			btassert<bool>(e.message == "NULL STRING REFERENCE");
			cout << "Passed TEST 2: findWord EXCEPTION HANDLING (STRING*) () \n";
			++utPassed;
		} catch (bool b) {
			cout << "# FAILED TEST 2: findWord EXCEPTION HANDLING (STRING*) () #\n";
		}
	} catch (bool) {
		cout << "# FAILED TEST 2: findWord MISSING EXCEPTION #\n";
	}
	
	try {
		replaceWord(myString, "hello", "goodbye");
        btassert<bool>(false);
	} catch (ArrayException e) {
		try {
			btassert<bool>(e.message == "NULL STRING REFERENCE");
			cout << "Passed TEST 3: replaceWord EXCEPTION HANDLING (STRING*) () \n";
			++utPassed;
		} catch (bool b) {
			cout << "# FAILED TEST 3: replaceWord EXCEPTION HANDLING (STRING*) () #\n";
		}
	} catch (bool) {
		cout << "# FAILED TEST 3: replaceWord MISSING EXCEPTION #\n";
	}
	
	myString = makeDynoString("123, abc; 456: hello. 0!");
	
	try {
		btassert<bool>(myString != 0);
		cout << "Passed TEST 4: STRING INITIALIZATION () \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 4: STRING INITIALIZATION () #\n";
	}
	
	try {
		btassert<bool>(countChars(myString, alpha, num) == 24);
		cout << "Passed TEST 5: countChars (myString) \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 5: countChars (myString) #\n";
	}
	
	try {
		btassert<bool>(alpha == 8);
		cout << "Passed TEST 6: countChars (alphabetic) \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 6: countChars (alphabetic) #\n";
	}
	
	try {
		btassert<bool>(num == 7);
		cout << "Passed TEST 7: countChars (numeric) \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 7: countChars (numeric) #\n";
	}
	
	try {
		btassert<bool>(findWord(myString, "HELLO") == false);
		cout << "Passed TEST 8: findWord (\"HELLO\") \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 8: findWord (\"HELLO\") #\n";
	}
	
	try {
		btassert<bool>(findWord(myString, "abc") == true);
		cout << "Passed TEST 9: findWord (\"abc\") \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 9: findWord (\"abc\") #\n";
	}
	
	replaceWord(myString, "hello", "goodbye");
	try {
		btassert<bool>(*myString == "123, abc; 456: goodbye. 0!");
		cout << "Passed TEST 10: replaceWord (myString, \"hello\", \"goodbye\") \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 10: replaceWord (myString, \"hello\", \"goodbye\") #\n";
	}
	
	try {
		btassert<bool>(replaceWord(myString, "HELLO", "GOODBYE") == false);
		cout << "Passed TEST 11: replaceWord (myString, \"HELLO\", \"GOODBYE\") \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 11: replaceWord (myString, \"HELLO\", \"GOODBYE\") #\n";
	}
	
	clearDynoString(myString);
	
	try {
		btassert<bool>(myString == 0);
		cout << "Passed TEST 12: clearDynoString () \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 12: clearDynoString () #\n";
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
