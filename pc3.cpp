/*
 * Programming Challenge 3
 * This program tells the sorry of Goldilocks based on the item and which
 * number of item chosen. Has a two player Rock, Scizzors, Paper game.
 * Will take a given character and return it's equivalent numerical value.
 * Converts strings all to lowercase letters, and another conversion to
 * uppercase letters. Lastly it will return the desired character of a 
 * string based on character index given.
 *
 * Katherine Jouzapaitis
 * Date created: 8/25/2015
 * Last modified date: 8/27/2015
 *
 * References: http://www.cplusplus.com/forum/beginner/25649/
 */
#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>
using namespace std;

string goldilocks (string item, int number);
int rockScissorPaper (char playerOne, char playerTwo);
int asciiValue (char c);
string toLower (string input);
string toUpper (string input);
char getCharacter (string input, int charIndex);

/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest ();

int main (int argc, char* argv[]) {
	unittest();
	
	return 0;
}

/*
 * Tell the story of Goldilocks. For example, 
 * if item is "bed" and number is 1, the story 
 * will say "This bed is too soft". "item" parameter must be passed 
 * in all lowercase characters -- the function is case-sensitive.
 * <ul>
 * <li>item: "porridge", number: 1, return "This porridge is too hot"</li>
 * <li>item: "porridge", number: 2, return "This porridge is too cold"</li>
 * <li>item: "porridge", number: 3, return "This porridge is just right"</li>
 * <li>item: "chair", number: 1, return "This chair is too big"</li>
 * <li>item: "chair", number: 2, return "This chair is too big"</li>
 * <li>item: "chair", number: 3, return "This chair is just right"</li>
 * <li>item: "bed", number: 1, return "This bed is too hard"</li>
 * <li>item: "bed", number: 2, return "This bed is too soft"</li>
 * <li>item: "bed", number: 3, return "This bed is just right"</li>
 * </ul>
 * @param item a string representing the item in the story ("porridge", "chair", and 
 *        "bed" are the only legal values -- will default to "bed" on invalid argument)
 * @param number which item (1, 2, and 3 are the only legal values -- will default to 3
 *        on invalid argument)
 * @return the output specified in the documentation above 
 */
string goldilocks (string item, int number) {
	if (item == "porridge") {
		if (number == 1) {
			return("This porridge is too hot");
		}
		else if (number == 2) {
			return("This porridge is too cold");
		}
		else
			return("This porridge is just right");
	}
	else if (item == "chair") {
		if (number == 1) {
			return("This chair is too big");
		}
		else if (number == 2) {
			return("This chair is too small");
		}
		else {
			return("This chair is just right");
		}
	}
	else {
		if (number == 1) {
			return("This bed is too hard");
		}
		else if (number == 2) {
			return("This bed is too soft");
		}
		else {
			return("This bed is just right");
		}
	}
}

/*
 * Compute the outcome of a round of a rock-scissor-paper game. Lowercase or uppercase
 * values for playerOne and playerTwo arguments are acceptable.
 * Possible inputs: 'R' rock, 'S' scissor, 'P' paper
 * <ul>
 * <li>rocks beats scissors</li>
 * <li>scissors beats paper</li>
 * <li>paper beats rock</li>
 * </ul>
 * @param playerOne a char representing player one's "play" ('R', 'S', or 'P')
 * @param playerTwo a char representing player two's "play" ('R', 'S', or 'P')
 * @return 1 if player one wins, 2 if player two wins, 3 on a draw, and 0 if a winner
 *           cannot be determined (which can happen if an invalid argument is passed in)
 */
int rockScissorPaper (char playerOne, char playerTwo) {
	
	switch (playerOne) {
		case 'R':
		case 'r':
			switch (playerTwo) {
				case 'S':
				case 's':
					return(1);
					break;
				case 'P':
				case 'p':
					return(2);
					break;
				case 'R':
				case 'r':
					return(3);
					break;
				default:
					return(0);
					break;
			}
		case 'S':
		case 's':
			switch (playerTwo) {
				case 'S':
				case 's':
					return(3);
					break;
				case 'P':
				case 'p':
					return(1);
					break;
				case 'R':
				case 'r':
					return(2);
					break;
				default:
					return(0);
					break;
			}
		case 'P':
		case 'p':
			switch (playerTwo) {
				case 'S':
				case 's':
					return(2);
					break;
				case 'P':
				case 'p':
					return(3);
					break;
				case 'R':
				case 'r':
					return(1);
					break;
				default:
					return(0);
					break;
			}
		default:
			return(0);
	}
}

/*
 * Return the ASCII integer value of a character.
 * @param c the char
 * @return an int containing the ASCII value of the character
 */
int asciiValue (char c) {
	return((int) c);
}

/*
 * Return the input string with all characters converted to lowercase.
 * @param input the string that will be converted to all lowercase characters.
 * @return a string containing the input string, converted to all lowercase characters.
 */
string toLower (string input) {
	string tempIn = input;
		for(unsigned int i = 0; i < tempIn.length(); ++i) {
			tempIn[i] = tolower(tempIn[i]);
		}
	return(tempIn);
}

/*
 * Return the input string with all characters converted to uppercase.
 * @param input the string that will be converted to all uppercase characters.
 * @return a string containing the input string, converted to all uppercase characters.
 */
string toUpper (string input) {
	string tempIn = input;
		for(unsigned int i = 0; i < tempIn.length(); ++i) {
			tempIn[i] = toupper(tempIn[i]);
		}
	return(tempIn);
}

/*
 * Return the character from the input string at index charIndex. This function does 
 * not check charIndex to ensure it is valid -- valid index must be ensured when 
 * the function is invoked.
 * @param input the string from which the character will be taken
 * @param charIndex an integer containing the zero-indexed position of the character
 *        to return
 * @return a char containing the character from the input string at charIndex position
 */
char getCharacter (string input, int charIndex) {
	string tempIn(input);
	return(tempIn[charIndex]);
}

/*
 * Unit testing functions. Do not alter.
 */
void unittest () {

	unsigned short utCount = 15;
	unsigned short utPassed = 0;

	cout << "\nSTARTING UNIT TEST\n\n";
	
	try {
		btassert<bool>(goldilocks("porridge", 2) == "This porridge is too cold");
		cout << "Passed TEST 1: goldilocks (porridge, 2)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 1 goldilocks (porridge, 2) #\n";
	}
	
	try {
		btassert<bool>(goldilocks("chair", 3) == "This chair is just right");
		cout << "Passed TEST 2: goldilocks (chair, 3)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 2 goldilocks (chair, 3) #\n";
	}
	
	try {
		btassert<bool>(goldilocks("bed", 1) == "This bed is too hard");
		cout << "Passed TEST 3: goldilocks (bed, 1)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 3 goldilocks (bed, 1) #\n";
	}
	
	try {
		btassert<bool>(rockScissorPaper('r', 'S') == 1);
		cout << "Passed TEST 4: rockScissorPaper (r, S)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 4 rockScissorPaper (r, S) #\n";
	}
	
	try {
		btassert<bool>(rockScissorPaper('R', 'p') == 2);
		cout << "Passed TEST 5: rockScissorPaper (R, p)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 5 rockScissorPaper (R, p) #\n";
	}
	
	try {
		btassert<bool>(rockScissorPaper('S', 'P') == 1);
		cout << "Passed TEST 6: rockScissorPaper (S, P)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 6 rockScissorPaper (S, P) #\n";
	}
	
	try {
		btassert<bool>(rockScissorPaper('r', 'r') == 3);
		cout << "Passed TEST 7: rockScissorPaper (r, r)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 7 rockScissorPaper (r, r) #\n";
	}
	
	try {
		btassert<bool>(asciiValue('Z') == 90);
		cout << "Passed TEST 8: asciiValue (Z)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 8 asciiValue (Z) #\n";
	}
	
	try {
		btassert<bool>(asciiValue('a') == 97);
		cout << "Passed TEST 9: asciiValue (a)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 9 asciiValue (a) #\n";
	}
	
	try {
		btassert<bool>(toLower("HELLO") == "hello");
		cout << "Passed TEST 10: toLower (HELLO)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 10 toLower (HELLO) #\n";
	}
	
	try {
		btassert<bool>(toLower("gOOdbYe") == "goodbye");
		cout << "Passed TEST 11: toLower (gOOdbYe)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 11 toLower (gOOdbYe) #\n";
	}
	
	try {
		btassert<bool>(toUpper("hello") == "HELLO");
		cout << "Passed TEST 12: toUpper (hello)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 12 toUpper (hello) #\n";
	}
	
	try {
		btassert<bool>(toUpper("gOOdbYe") == "GOODBYE");
		cout << "Passed TEST 13: toUpper (gOOdbYe)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 13 toUpper (gOOdbYe) #\n";
	}
	
	try {
		btassert<bool>(getCharacter("amazing", 3) == 'z');
		cout << "Passed TEST 14: getCharacter (amazing, 3)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 14 #\n";
	}
	
	try {
		btassert<bool>(getCharacter("hooray!", 6) == '!');
		cout << "Passed TEST 15: getCharacter (hooray, 6)\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 15 getCharacter (hooray, 6) #\n";
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
