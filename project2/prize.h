#pragma once

#include <string>
using namespace std;

class Prize {
    public:
        /**
         * Default constructor.
         * Initializes prizeName to "NO NAME" and prizeValue to 0.
         */
        Prize ();
        
        /**
         * Overloaded constructor.
         * Initializes prizeName to newPrizeName, and prizeValue to newPrizeValue.
         * @param newPrizeName a string containing the desired name for a new prize.
         * @param newPrizeValue an unsigned int containing the desired value of
         *        a new prize.
         */
        Prize (string newPrizeName, unsigned int newPrizeValue);
        
        /**
         * Destructor.
         * Frees the memory associated with prizeName and prizeValue.
         */
        virtual ~Prize ();
        
        /**
         * Friend overload operator.
         * Compares two prizes. Returns true if the Prizes are equivilent,
         * otherwise returns false.
         */
        friend bool operator == (Prize p1, Prize p2);
    
        /**
         * Set the Prize's name.
         * @param newPrizeName a string containing the new name for a Prize.
         */
        void setPrizeName (string newPrizeName);
        
        /**
         * Set the Prize's value.
         * @param newPrizeValue an unsigned integer containing the new value for a Prize.
         */
        void setPrizeValue (unsigned int newPrizeValue);
        
        /**
         * Get the Prize's name.
         * @return a string containing a Prize's name.
         */
        string getPrizeName () const;
        
        /**
         * Get the Prize's value.
         * @return an unsigned int containing a Prize's value.
         */
        unsigned int getPrizeValue () const;
        
    private:
        string prizeName;
        unsigned int prizeValue;
};
