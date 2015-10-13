/*
 * box.h for Programming Project 2
 * This file contains the declarations for the functions executed by box.cpp.
 * Working with box.cpp this portion of the program is responsible for the construction
 * and destruction of a box object, as well allowing the manipulation of the 
 * box's information and "placing, viewing, and removing" prizes within the box.
 *
 * Katherine Jouzapaitis
 * Date created: 9/27/2015
 * Date last modified: 10/12/2015
 */

#pragma once

#include "prize.h"
#include <string>
using namespace std;

class Box {
    public:
    
        /**
         * Default constructor.
         * Initializes boxNumber to 0, boxColor to "NO COLOR", prizeCapacity to
         * 5, prizeCount to 0, and prizes to the size prizeCapacity.
         */
        Box ();
        
        /**
         * Overloaded constructor.
         * Initializes boxNumber to newBoxNumber, boxColor to newBoxColor,
         * prizeCapacity to newPrizeCapacity, prizeCount to 0, and prizes to
         * the size to match the newPrizeCapacity.
         * @param newBoxNumber an unsigned integer containing the desired
         *        number for a box.
         * @param newBoxColor a string containing the desired color for a box.
         * @param newPrizeCapacity an unsigned integer containing the desired
         *        number of prizes a box can contain.
         * 
         */
        Box (unsigned int newBoxNumber, string newBoxColor, unsigned int newPrizeCapacity);
        
        /**
         * Destructor.
         * Frees the memory associated with the box.
         */
        virtual ~Box ();
        
        /**
         * Sets the number of the box.
         * @param newBoxNumber an unsigned integer containing the new number
         *        for the box.
         */
        void setBoxNumber (unsigned int newBoxNumber);
        
        /**
         * Sets the color of the box.
         * @param newBoxColor a string containing the new name for the box.
         */
        void setBoxColor (string newBoxColor);
        
        /**
         * Gets the number of the box.
         * @return an unsigned int containing the number of the box.
         */
        unsigned int getBoxNumber () const;
        
        /**
         * Gets the color of the box.
         * @return a string containing the color of the box.
         */
        string getBoxColor () const;
        
        /**
         * Gets the number of prizes the box can hold.
         * @return an unsigned integer containing the capacity of the box.
         */
        unsigned int getPrizeCapacity () const;
        
        /**
         * Gets the number of prizes in the box.
         * @return an unsigned integer containing the number of prizes in the box.
         */
        unsigned int getPrizeCount () const;
        
        /**
         * Places a prize in the box and increments the count of prizes in the 
         * array.
         * @param newPrize Prize containing a Prize that is "placed" inside the
         *        box.
         * @return true if the Prize can be added to the box, otherwise return
         *         false.
         */
        bool addPrize (Prize prize);
        
        /**
         * Retrieve a reference to the prize at a specified index in the array.
         * @param index an unsigned integer containing the zero-based index of
         *        the item to be retrieved.
         * @return if index is valid, a reference to the Prize at the specified
         *         index, else return scratch data member.
         */
        Prize& getPrize (unsigned int index);
        
        /**
         * Removes the prize at the specified index in the array. Decrement
         * prize count and "pack" the array so that all valid prizes are
         * contiguous in the array.
         * @param index an unsigned integer containing the zero-based index of
         *        the prize to be removed.
         * @return if the index is valid, the Prize at the specified index, else
         *         return scratch data member.
         */
        Prize removePrize (unsigned int index);
        
    private:
        unsigned int boxNumber;
        string boxColor;
        Prize scratch;
        Prize* prizes;
        unsigned int prizeCapacity;
        unsigned int prizeCount;
};