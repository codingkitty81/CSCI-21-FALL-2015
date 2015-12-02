/*
 * Item.h for Programming Challenge 28
 * Allows for the construction, destruction, and manipulation of an item. Also allows for
 * the details of the item to be output as a string. This parent class works with 
 * MagicItem and FoodItem classes to practice inheritance. 
 *
 * Katherine Jouzapaitis
 * Date created: 12/1/2015
 * Date last modified: 12/2/2015
 */
#pragma once
#include <string>
#include <sstream>
using namespace std;

class Item {
  public:
    
    /**
     * Constructor of a new item.
     * Allows for overloading, but has defaults assigned.
     * @param newName a string defaulted to "item", can be overloaded with any other string
     * as a name for a new item.
     * @param newValue an unsigned int defaulted to 0, can be overloaded with any value 
     * in range as the value for a new item.
     */
    Item (string newName = "item", unsigned int newValue = 0);
    
    /**
     * Destructor.
     */
    virtual ~Item ();
    
    /**
     * Sets the name of an already created item.
     * @param newName a string containing the new name of an item.
     */
    void setName (string newName);
    
    /**
     * Sets the value of an already created item.
     * @param newValue an unsigned int containing the new value of an item.
     */
    void setValue (unsigned int newValue);
    
    /**
     * Gets the name of an already created item.
     * @return a string containing the name of an item.
     */
    string getName ();
    
    /**
     * Gets the value of an already created item.
     * @return an unsigned int containing the value of an item.
     */
    unsigned int getValue ();
    
    /**
     * Puts all the details of an item into a string for output.
     * @return a string containing all the details of an item in the format of
     * NAME, $VALUE.
     */
    string toString ();
    
  private:
    string name;
    unsigned int value;
};