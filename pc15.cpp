/*
 * Programming Challenge 15
 * This program creates a shopping list with a default length to hold up to 25 items.
 * There is also an overloading option to create a list of a different length at
 * the time of creation. Along with being able to add and remove items, items can
 * be looked up by index. Once done with the list, the user can either deconstruct
 * the list entirely, or reset the list to a new length and start again. Exceptions
 * will be thrown if trying to add items to a full list, get an item from an empty
 * list, get an item with an index not in the list's range, trying to create a list
 * that holds less than one item, trying to remove an item from an empty list, and
 * when trying to remove an item with an index outside of the list's range.
 *
 * Katherine Jouzapaitis
 * Date created: 9/23/2015
 * Date last modified: 9/28/2015
 *
 * Resources:
 * http://forums.codeguru.com/showthread.php?464643-Virtual-outside-class-declaration
 * http://www.cplusplus.com/doc/tutorial/dynamic/
 */
#include <cassert>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class ShoppingList {
    public:

        /*
         * Default constructor.
         * Initializes maxItems to 25, items to size maxItems, and itemCount to 0.
         */
        ShoppingList ();

        /*
         * Overloaded constructor.
         * Initializes maxItems to newMaxItems, items to size maxItems, and itemCount to 0.
         * @param newMaxItems an unsigned integer containing the desired size of
         *        the items array
         */
        ShoppingList (unsigned int newMaxItems);

        /*
         * Destructor.
         * Frees the memory associated with items.
         */
        virtual ~ShoppingList ();

        /*
         * Get the maximum number of items in this ShoppingList.
         * @return an unsigned integer containing the maximum number of items
         *         in this ShoppingList
         */
        unsigned int getMaxItems () const;

    	/*
    	 * Get the count of the number of items in this ShoppingList.
    	 * @return an unsigned integer containing the count of number of items
    	 *         in this ShoppingList
    	 */
    	unsigned int getItemCount () const;
		
    	/*
    	 * Place an item at a specified index in the array and increment the count of items in 
         * the array.
    	 * @param theItem a string containing the item to be added to the array
    	 * @return true if the item can be added, otherwise return false
    	 */
    	bool addItem (string theItem);

        /*
         * Retrieve the value of the item at a specified index in the array.
         * @param index an unsigned integer containing the zero-based index
         *        of the item to be retrieved
         * @return if index is valid, a string containing the value of the item
         *         at the specified index
         * @throw ArrayException with the message "INVALID ARRAY INDEX" if index is invalid
         */
        string getItem (unsigned int index) const;

        /*
    	 * Retrieve a reference to the item at a specified index in the array.
    	 * @param index an unsigned integer containing the zero-based index
    	 *        of the item to be retrieved
    	 * @return if index is valid, a reference to the string at the specified index
    	 * @throw ArrayException with the message "INVALID ARRAY INDEX" if index is invalid
    	 */
    	string& getItem (unsigned int index);
		
        /*
         * Remove the item at a specified index in the array. Decrement item count a "pack" 
         * the array so that all valid items are contiguous in the array.
         * @param index an unsigned integer containing the zero-based index
         *        of the item to be removed
         * @return the value of the string at the specified index
         * @throw ArrayException with the message "INVALID ARRAY INDEX" if index is invalid
         */
        string removeItem (unsigned int index);

        /*
         * Reset the items array by freeing its associated memory and re-allocating to a 
         * specified size.
         * @param newMaxItems an unsigned integer containing the desired max size of items
         * @throw ArrayException with the message "INVALID ARRAY SIZE" if newMaxItems is less than 1
         */
        void reset (unsigned int newMaxItems);

    private:
        
        string* items;
        unsigned int maxItems;
        unsigned int itemCount;
};

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

int main () {
    unittest();

    return 0;
}

// CODE HERE -- FUNCTION DEFINITIONS
ShoppingList::ShoppingList() : maxItems(25), itemCount(0) {
    items = new string[maxItems];
}

ShoppingList::ShoppingList (unsigned int newMaxItems) : maxItems(newMaxItems), itemCount(0) {
    items = new string[maxItems];
}

ShoppingList::~ShoppingList () {
    delete [] items;
}

unsigned int ShoppingList::getMaxItems () const {
    return maxItems;
}

unsigned int ShoppingList::getItemCount () const {
    return itemCount;
}

bool ShoppingList::addItem (string theItem) {
    if (itemCount >= maxItems) {
        return false;
        throw ArrayException("INVALID ARRAY INDEX");
    } else {
        items[itemCount] = theItem;
        itemCount++;
        return true;
    }
}

string ShoppingList::getItem (unsigned int index) const {
    if (index >= maxItems || items[index] == "") {
        throw ArrayException("INVALID ARRAY INDEX");
    } else {
        return items[index];
    }
}

string& ShoppingList::getItem (unsigned int index) {
    if (index >= maxItems || items[index] == "") {
        throw ArrayException("INVALID ARRAY INDEX");
    } else {
        return items[index];
    }
}

string ShoppingList::removeItem (unsigned int index) {
    string itemRemoved;
    if (index >= maxItems) {
        throw ArrayException("INVALID ARRAY INDEX");
    } else {
        itemRemoved = items[index];
        
        rotate(items + index, items + index + 1, items + maxItems);
        items[maxItems - 1] = "";
        
        itemCount--;
        return itemRemoved;
    }
}

void ShoppingList::reset (unsigned int newMaxItems) {
    delete [] items;
    itemCount = 0;
    maxItems = newMaxItems;
    
    if (newMaxItems < 1) {
        items = new string[1];
        maxItems = 1;
        throw ArrayException("INVALID ARRAY SIZE");
    } else {
        items = new string[newMaxItems];
    }
}
/*
 * Unit testing functions. Do not alter.
 */

void unittest () {

    unsigned short utCount = 30;
    unsigned short utPassed = 0;

    cout << "\nSTARTING UNIT TEST\n\n";

    ShoppingList* myList = new ShoppingList;

    cout << "* DEFAULT CONSTRUCTOR *\n\n";

    try {
        btassert<bool>(myList->getMaxItems() == 25);
        cout << "Passed TEST 1: ShoppingList::getMaxItems () \n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 1: ShoppingList::getMaxItems () #\n";
    }

    try {
        btassert<bool>(myList->getItemCount() == 0);
        cout << "Passed TEST 2: ShoppingList::getItemCount () \n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 2: ShoppingList::getItemCount () #\n";
    }

    try {
        myList->getItem(0);
        btassert<bool>(false);
    } catch (ArrayException e) {
        try {
            btassert<bool>(e.message == "INVALID ARRAY INDEX");
            cout << "Passed TEST 3: ShoppingList::getItem(0) EXCEPTION HANDLING \n";
            ++utPassed;
        } catch (bool b) {
            cout << "# FAILED TEST 3: ShoppingList::getItem(0) EXCEPTION HANDLING #\n";
        }
    } catch(bool b) {
        cout << "# FAILED TEST 3: ShoppingList::getItem(0) EXCEPTION HANDLING #\n";
    }

    try {
        btassert<bool>(myList->addItem("apples") == true);
        cout << "Passed TEST 4: ShoppingList::addItem(\"apples\") \n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 4: ShoppingList::addItem(\"apples\") #\n";
    }

    try {
        btassert<bool>(myList->getItemCount() == 1);
        cout << "Passed TEST 5: ShoppingList::getItemCount () \n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 5: ShoppingList::getItemCount () #\n";
    }

    try {
        btassert<bool>(myList->getItem(0) == "apples");
        cout << "Passed TEST 6: ShoppingList::getItem(0) \n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 6: ShoppingList::getItem(0) #\n";
    }

    myList->getItem(0) = "oranges";
    try {
        btassert<bool>(myList->getItem(0) == "oranges");
        cout << "Passed TEST 7: string& ShoppingList::getItem(0) \n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 7: string& ShoppingList::getItem(0) #\n";
    }

    try {
        btassert<bool>(myList->removeItem(0) == "oranges");
        cout << "Passed TEST 8: ShoppingList::removeItem(0) \n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 8: ShoppingList::removeItem(0) #\n";
    }

    try {
        btassert<bool>(myList->getItemCount() == 0);
        cout << "Passed TEST 9: ShoppingList::getItemCount () \n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 9: ShoppingList::getItemCount () #\n";
    }

    for (unsigned int i=0; i<myList->getMaxItems(); i++)
        myList->addItem("grapes");

    try {
        btassert<bool>(myList->getItemCount() == 25);
        cout << "Passed TEST 10: ShoppingList::getItemCount () \n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 10: ShoppingList::getItemCount () #\n";
    }

    try {
        myList->getItem(26);
        btassert<bool>(false);
    } catch (ArrayException e) {
        try {
            btassert<bool>(e.message == "INVALID ARRAY INDEX");
            cout << "Passed TEST 11: ShoppingList::getItem(11) EXCEPTION HANDLING \n";
            ++utPassed;
        } catch (bool b) {
            cout << "# FAILED TEST 11: ShoppingList::setItem(11) EXCEPTION HANDLING #\n";
        }
    } catch(bool b) {
        cout << "# FAILED TEST 11: ShoppingList::setItem(11) EXCEPTION HANDLING #\n";
    }

    try {
        btassert<bool>(myList->addItem("bananas") == false);
        cout << "Passed TEST 12: ShoppingList::addItem(\"bananas\") \n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 12: ShoppingList::getItem(\"bananas\") #\n";
    }

    unsigned int itemsToRemove = myList->getItemCount();
    for (unsigned int i=0; i<itemsToRemove; i++)
        myList->removeItem(0);

    try {
        btassert<bool>(myList->getItemCount() == 0);
        cout << "Passed TEST 13: ShoppingList::getItemCount () \n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 13: ShoppingList::getItemCount () #\n";
    }

    try {
        myList->getItem(0) = "oranges";
        btassert<bool>(false);
    } catch (ArrayException e) {
        try {
            btassert<bool>(e.message == "INVALID ARRAY INDEX");
            cout << "Passed TEST 14: string& ShoppingList::getItem(0) EXCEPTION HANDLING \n";
            ++utPassed;
        } catch (bool b) {
            cout << "# FAILED TEST 14: string& ShoppingList::setItem(0) EXCEPTION HANDLING #\n";
        }
    } catch(bool b) {
        cout << "# FAILED TEST 14: string& ShoppingList::setItem(0) EXCEPTION HANDLING #\n";
    }

    try {
        btassert<bool>(myList->getMaxItems() == 25);
        cout << "Passed TEST 15: ShoppingList::getMaxItems () \n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 15: ShoppingList::getMaxItems () #\n";
    }

    delete myList;
    myList = new ShoppingList(1);

    cout << "\n* OVERLOADED CONSTRUCTOR *\n\n";

    try {
        btassert<bool>(myList->getMaxItems() == 1);
        cout << "Passed TEST 16: ShoppingList::getMaxItems () \n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 16: ShoppingList::getMaxItems () #\n";
    }

    try {
        btassert<bool>(myList->addItem("apples") == true);
        cout << "Passed TEST 17: ShoppingList::addItem(\"apples\") \n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 17: ShoppingList::addItem(\"apples\") #\n";
    }

    try {
        btassert<bool>(myList->getItem(0) == "apples");
        cout << "Passed TEST 18: ShoppingList::getItem(0) \n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 18: ShoppingList::getItem(0) #\n";
    }

    try {
        myList->removeItem(1);
        btassert<bool>(false);
    } catch (ArrayException e) {
        try {
            btassert<bool>(e.message == "INVALID ARRAY INDEX");
            cout << "Passed TEST 19: ShoppingList::removeItem(1) EXCEPTION HANDLING \n";
            ++utPassed;
        } catch (bool b) {
            cout << "# FAILED TEST 19: ShoppingList::removeItem(1) EXCEPTION HANDLING #\n";
        }
    } catch(bool b) {
        cout << "# FAILED TEST 19: ShoppingList::removeItem(1) EXCEPTION HANDLING #\n";
    }

    try {
        myList->getItem(1);
        btassert<bool>(false);
    } catch (ArrayException e) {
        try {
            btassert<bool>(e.message == "INVALID ARRAY INDEX");
            cout << "Passed TEST 20: ShoppingList::getItem(1) EXCEPTION HANDLING \n";
            ++utPassed;
        } catch (bool b) {
            cout << "# FAILED TEST 20: ShoppingList::getItem(1) EXCEPTION HANDLING #\n";
        }
    } catch(bool b) {
        cout << "# FAILED TEST 20: ShoppingList::getItem(1) EXCEPTION HANDLING #\n";
    }

    cout << "\n* RESET FUNCTION *\n\n";

    try {
        myList->reset(0);
        btassert<bool>(false);
    } catch (ArrayException e) {
        try {
            btassert<bool>(e.message == "INVALID ARRAY SIZE");
            cout << "Passed TEST 21: ShoppingList::reset(0) EXCEPTION HANDLING \n";
            ++utPassed;
        } catch (bool b) {
            cout << "# FAILED TEST 21: ShoppingList::reset(0) EXCEPTION HANDLING #\n";
        }
    } catch(bool b) {
        cout << "# FAILED TEST 21: ShoppingList::reset(0) EXCEPTION HANDLING #\n";
    }

    try {
        btassert<bool>(myList->getMaxItems() == 1);
        cout << "Passed TEST 22: ShoppingList::getMaxItems () \n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 22: ShoppingList::getMaxItems () #\n";
    }

    myList->reset(5);

    try {
        btassert<bool>(myList->getMaxItems() == 5);
        cout << "Passed TEST 23: ShoppingList::getMaxItems () \n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 23: ShoppingList::getMaxItems () #\n";
    }

    try {
        btassert<bool>(myList->getItemCount() == 0);
        cout << "Passed TEST 24: ShoppingList::getItemCount () \n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 24: ShoppingList::getItemCount () #\n";
    }

    for (unsigned int i=0; i<myList->getMaxItems(); i++)
        myList->addItem("grapes");

    try {
        btassert<bool>(myList->getItemCount() == 5);
        cout << "Passed TEST 25: ShoppingList::getItemCount () \n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 25: ShoppingList::getItemCount () #\n";
    }

    try {
        myList->getItem(6);
        btassert<bool>(false);
    } catch (ArrayException e) {
        try {
            btassert<bool>(e.message == "INVALID ARRAY INDEX");
            cout << "Passed TEST 26: ShoppingList::getItem(6) EXCEPTION HANDLING \n";
            ++utPassed;
        } catch (bool b) {
            cout << "# FAILED TEST 26: ShoppingList::setItem(6) EXCEPTION HANDLING #\n";
        }
    } catch(bool b) {
        cout << "# FAILED TEST 26: ShoppingList::setItem(6) EXCEPTION HANDLING #\n";
    }

    try {
        btassert<bool>(myList->addItem("bananas") == false);
        cout << "Passed TEST 27: ShoppingList::addItem(\"bananas\") \n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 27: ShoppingList::getItem(\"bananas\") #\n";
    }

    itemsToRemove = myList->getItemCount();
    for (unsigned int i=0; i<itemsToRemove; i++)
        myList->removeItem(0);

    try {
        btassert<bool>(myList->getItemCount() == 0);
        cout << "Passed TEST 28: ShoppingList::getItemCount () \n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 28: ShoppingList::getItemCount () #\n";
    }

    try {
        myList->getItem(0) = "oranges";
        btassert<bool>(false);
    } catch (ArrayException e) {
        try {
            btassert<bool>(e.message == "INVALID ARRAY INDEX");
            cout << "Passed TEST 29: string& ShoppingList::getItem(0) EXCEPTION HANDLING \n";
            ++utPassed;
        } catch (bool b) {
            cout << "# FAILED TEST 29: string& ShoppingList::setItem(0) EXCEPTION HANDLING #\n";
        }
    } catch(bool b) {
        cout << "# FAILED TEST 29: string& ShoppingList::setItem(0) EXCEPTION HANDLING #\n";
    }

    try {
        btassert<bool>(myList->getMaxItems() == 5);
        cout << "Passed TEST 30: ShoppingList::getMaxItems () \n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 30: ShoppingList::getMaxItems () #\n";
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