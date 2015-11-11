/*
 * recursive.h for Programming Challenge 23
 * This file provides the declarations for the functions used by recursive.cpp.
 * This program tests recursion in a variety of instances, by testing given values
 * for their factorial results, finding the value of the Fibonacci sequence at
 * a given index, testing words to see if they are palindromes, and printing
 * arrays both forwards and backwards.
 *
 * Katherine Jouzapaitis
 * Date created: 11/9/2015
 * Date last modified: 11/10/2015
 *
 * Resources:
 * http://www.cplusplus.com/forum/windows/39170/
 * http://stackoverflow.com/questions/22890946/finding-a-string-palindrome-with-a-recursive-function
 * http://www.cplusplus.com/forum/beginner/61934/
 */

#include <sstream>
#include <string>
using std::string;
using std::stringstream;

/*
 * Compute and return the factorial of a value, using a recursive algorithm. Zero factorial
 * will return 1.
 * @param value an unsigned integer containing the value for which the factorial will be computed
 * @return an unsigned integer containing the computed factorial of the value
*/
unsigned int factorial (unsigned int value);

/*
 * Return a specified value in a Fibonacci sequence, using a recursive algorithm. The lowest value requested in the sequence
 * must never be less than one.
 * @param fibValue an unsigned integer specifying which value in the Fibonacci sequence to return
 * @return an unsigned integer containing the requested value in the Fibonacci sequence
 */
unsigned int fibonacci (unsigned int fibValue);

/*
 * Test a single word to see if it is a palindrome, using a recursive algorithm. The word must be all in the same case 
 * (upper or lower) and cannot contain spaces, digits, or punctuation.
 * @param word a string containing the word to be tested
 * @return true of word is a palindrome, else false; empty string and single character strings
 *         are considered palindromes
 */
bool wordIsPalindrome (string word);

/*
 * Produce a string containing the contents of an array, separated by single spaces, 
 * starting at a specified index and going forward to the end of the array, using a recursive algorithm. The returned 
 * string will contain an extra space character after the last value added.
 * @param array an integer array containing the values to be added to the string
 * @param startIndex an unsigned integer containing the index of the first value in the array to be added
 *        to the output string
 * @param size an unsigned integer containing the number of elements in the array
 * @return a string containing the contents of the array, separated by spaces; returns empty string
 *         if the startIndex is >= the size of the array
 */
string arrayForwardsAsString (int array[], unsigned int startIndex, unsigned int size);

/*
 * Produce a string containing the contents of an array, separated by single spaces, 
 * starting at a specified index and going backward to the beginning of the array, using a recursive 
 * algorithm. The returned string will contain an extra space character after the last value added.
 * @param array an integer array containing the values to be added to the string
 * @param startIndex an integer containing the index of the first value in the array to be added
 *        to the output string
 * @param size an unsigned integer containing the number of elements in the array
 * @return a string containing the contents of the array, separated by spaces, in reverse order; returns empty string
 *         if the startIndex is < zero
 */
string arrayBackwardsAsString (int array[], int startIndex, unsigned int size);