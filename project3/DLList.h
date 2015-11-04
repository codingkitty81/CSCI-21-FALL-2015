/*
 *
 * Date created: 10/29/2015
 *
 */
 
#pragma once


//http://code.runnable.com/Us53wIV1TEVWAAHd/how-to-search-a-node-in-a-linked-list-for-c%2B%2B
//http://www.dailyfreecode.com/Code/double-linked-list-cpp-3422.aspx
#include "DLNode.h"
#include <cassert>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class DLList {
  public:
    /**
     * Default constructor.
     * Initializes head and tail to NULL, and nodeCount to 0.
     */
    DLList ();
    
    /**
     * Destructor.
     * Calls the clear function.
     */
    ~DLList ();
    
    /**
     * Gets the size of the list.
     * @return an unsigned integer containing the number of nodes
     * in the list.
     */
    unsigned int getSize () const;
    
    /**
     * Creates a new DLNode and places it at the head of the list.
     * @param contents an integer containing the contents to be
     * placed in the list.
     */
    void pushFront (int newContents);
    
    /**
     * Creates a new DLNode and places it at the tail (end) of the list.
     * @param contents an integer containing the contents to be placed
     * in the list.
     */
    void pushBack (int newContents);
    
    /**
     * Creates a new DLNode and inserts in the list so the values are in
     * accending order from head to tail.
     * @param contents an integer containing the value to be tested and
     * inserted into the list.
     */
    void insert (int newContents);
    
    /**
     * Gets the value of the head node.
     * @return an integer containing the value of the head node.
     */
    int getFront () const;
    
    /**
     * Gets the value of the tail node.
     * @return an integer containing the value of the tail node.
     */
    int getBack () const;
    
    /**
     * Searches the list for the a given value.
     * @param target an integer containing the value to be searched for
     * in the list.
     * @return true if the target is found, otherwise returns false.
     */
    bool get (int target);
    
    /**
     * Removes the head node from the list.
     */ 
    void popFront ();
    
    /**
     * Removes the tail (end) node from the list.
     */ 
    void popBack ();
    
    /**
     * Removes the first occurance of a given value in the list.
     * @param target an integer containing the value to be searched for
     * and then removed from the list.
     * @return true if the target was found and the first occurance was removed,
     * otherwise return false.
     */
    bool removeFirst (int target);
    
    /**
     * Removes all occurances of a given value in the list.
     * @param target an integer containing the value to be searched for
     * and then removed from the list.
     * @return true if all occurances of the target were found and removed, otherwise
     * return false.
     */
    bool removeAll (int target);
    
    /**
     * Clears the entire contents of the list and frees all the
     * memory associated with the nodes.
     */
    void clear ();
    
    /**
     * Friend ostream operator to handle the output of the contents of the box.
     * @param out an address pointing to the ostream object.
     * @param src an address pointing to the contents of the node to be
     * fed into the ostream for output.
     */
    friend ostream& operator<< (ostream& out, const DLList& src);

  private:
    unsigned int nodeCount;
    DLNode* head;
    DLNode* tail;
};

