#include "recursive.h"

unsigned int factorial (unsigned int value) {
    unsigned int temp = 1;
    
    if (value <= 1) {
        return 1;
    } else {
        temp = value * factorial(value - 1);
    }
    
    return temp;
}

unsigned int fibonacci (unsigned int fibValue) {
    
    if (fibValue == 0) {
        return 0;
    } else if (fibValue == 1) {
        return 1;
    } else {
        return (fibonacci(fibValue - 1) + fibonacci(fibValue - 2));
    }
}

bool wordIsPalindrome (string word) {
    for(unsigned int i = 0; i < word.length(); ++i) {
			word[i] = tolower(word[i]);
		}

    if (word.length() == 0 || word.length() == 1) {
        return true;
    } else {
        string first = word.substr(0,1);
        string last = word.substr((word.length() - 1), 1);

        if (first == last) {
            word = word.substr((0 + 1), (word.length() - 2));
            if (word.length() <= 1){
                return true;
            } else {
                return wordIsPalindrome(word);
            }
        } else {
            return false;  
        }
    }
}

string arrayForwardsAsString (int array[], unsigned int startIndex, unsigned int size) {
    stringstream arrayString;
    
    if (startIndex >= size) {
        return arrayString.str();
    }
    
    arrayString << array[startIndex] << " ";
    startIndex++;
    
    if (startIndex < size) {
        arrayString << arrayForwardsAsString(array, startIndex, size);
    }
    
    return arrayString.str();
    
}

string arrayBackwardsAsString (int array[], int startIndex, unsigned int size) {
    stringstream arrayString;
    
    if (startIndex < 0) {
        return arrayString.str();
    }
    
    arrayString << array[startIndex] << " ";
    startIndex--;
    
    if (startIndex >= 0) {
        arrayString << arrayBackwardsAsString(array, startIndex, size);
    }
    
    return arrayString.str();
}