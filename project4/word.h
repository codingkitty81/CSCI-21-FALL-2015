/*
 * word.h for Programming Project 4
 * This file contains the declarations of the functions utilized by word.cpp.
 * This class allows for the construction, destruction, and manipulation of a Word 
 * and the count that goes along with it. There are also friend functions to
 * assist with Word comparisons and displaying the details of a Word.
 *
 * Katherine Jouzapaitis
 * Date created: 11/24/2015
 * Date last modified: 12/3/2015
 */

#pragma once
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Word {
    public:
        
        /**
         * Default constructor.
         * Itializes count to 0.
         */
        Word ();
        
        /**
         * Overloaded constructor.
         * Itializes count to 0 and word to newWord.
         */
        Word (string newWord);
        
        /**
         * Destructor.
         */
        virtual ~Word ();
        
        /**
         * Gets the string stored in the word.
         * @return a string containing a word.
         */
        string getWord () const;
        
        /**
         * Sets the string of an already created Word.
         * @param newWord a string containing a new word for a Word.
         */
        void setWord (string newWord);
        
        /**
         * Gets the count of a Word.
         * @return an unsigned int containing the count of the number of times
         * a word was attempted to be inserted in a binary search tree.
         */
        unsigned int getCount () const;
        
        /**
         * Increments the count of a Word when an insert is attempted more than once.
         */
        void incrementCount ();
        
        /**
         * A friend function to assist in comparing two Word objects.
         * @param w1 a Word to be compared to another Word. (left side of operator)
         * @param w2 a Word to be compared to another Word. (right side of operator)
         */
        friend bool operator == (Word w1, Word w2);
        
        /**
         * A friend function to assist in comparing two Word objects.
         * @param w1 a Word to be compared to another Word. (left side of operator)
         * @param w2 a Word to be compared to another Word. (right side of operator)
         */
        friend bool operator < (Word w1, Word w2);
        
        /**
         * A friend function to assist in comparing two Word objects.
         * @param w1 a Word to be compared to another Word. (left side of operator)
         * @param w2 a Word to be compared to another Word. (right side of operator)
         */
        friend bool operator > (Word w1, Word w2);
        
        /**
         * A friend function to assist in the output of Word objects.
         * @param out a pointer to an ostream to be loaded with details of the Word object.
         * @param w1 a Word object to be output.
         * @return an ostream with the details of the Word object in the format of
         * WORD COUNT.
         */
        friend ostream& operator << (ostream& out, Word w1);
        
    private:
    
        unsigned int count;
        string word;
};