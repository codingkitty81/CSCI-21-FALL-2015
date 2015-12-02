/*
 * MagicItem.h for Programming Challenge 28.
 * MagicItem class derived from Item class. Allows for the construction, destruction, 
 * and manipulation of a magic item. This also supports outputting the 
 * detailed information about the magic item as a string.
 *
 * Katherine Jouzapaitis
 * Date created: 12/1/2015
 * Date last modified: 12/2/2015
 */
#pragma once
#include "Item.h"

class MagicItem : public Item {
    public:
        
        /**
         * Constructor for a new MagicItem.
         * Allows for overloading, but has default values set.
         * @param newName a string defaulted to "magicitem", can be overloaded 
         * to any other desired string to name a new magic item. (Inherited from Item class)
         * @param newValue an unsigned int defaulted to 0, can be overloadeded
         * to any other value within range as the value of a new magic item. (Inherited from Item class)
         * @param newDescription a string defaulted to "no description", can be overloaded
         * to any other desired string to describe a new magic item.
         * @param newManaRequired an unsigned int defaulted to 0, can be overloaded
         * to any other value in range as the mana requirement for a new magic item.
         */
        MagicItem (string newName = "magicitem", unsigned int newValue = 0, string newDescription = "no description", unsigned int newManaRequired = 0);
        
        /**
         * Destructor.
         */
        virtual ~MagicItem ();
        
        /**
         * Sets the description of an already created magic item.
         * @param newDescription a string containing the new description for
         * the magic item.
         */
        void setDescription (string newDescription);
        
        /**
         * Sets the mana requirement of an already created magic item.
         * @param newManaRequired an unsigned int containing the new value of the 
         * mana required by the magic item.
         */
        void setManaRequired (unsigned int newManaRequired);
        
        /**
         * Gets the description of a created magic item.
         * @return a string containing the description of the magic item.
         */
        string getDescription ();
        
        /**
         * Gets the mana requirement of a created magic item.
         * @return an unsigned int containing the value of the mana requirement of
         * the magic item.
         */
        unsigned int getManaRequired ();
        
        /**
         * Puts all the details of a magic item into a string for output.
         * @return a string containing the details of a magic item in the style of
         * NAME, $VALUE, DESCRIPTION, MANAREQUIRED mana.
         */
        string toString ();

    private:
    
        string description;
        unsigned int manaRequired;
};