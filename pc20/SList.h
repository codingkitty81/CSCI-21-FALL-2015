/*
 * SList.h for Programming Challenge 20
 * This file provides the declarations for functions in SList.cpp. The functions
 * allow for the construction and destruction of a linked list. Allows the
 * insertion and removal of node both at the head and tail of the list. The list
 * can also be cleared out or displayed, and the program keeps track of the size
 * of the list.
 *
 * Katherine Jouzapaitis
 * Date created: 10/22/2015
 * Date last modified: 10/29/2015
 *
 * Resources:
 * http://www.c4learn.com/data-structure/insert-node-at-middle-position-singly-linked-list/
 */
 
#pragma once

#include "SLNode.h"
#include <cassert>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

class SList {
    public:
        /**
         * Default constructor.
         * Initializes head to NULL and size to 0.
         */
        SList ();
        
        /**
         * Destructor.
         * Calls the clear function.
         */
        virtual ~SList ();
        
        /**
         * Creates a new SLNode and places it at the head of the list.
         * @param contents an integer containing the contents to be
         * placed in the list.
         */
        void insertHead (int contents);
        
        /**
         * Creates a new SLNode and places it at the tail (end) of the list.
         * @param contents an integer containing the contents to be placed
         * in the list.
         */ 
        void insertTail (int contents);
        
        /**
         * Removes the head node from the list.
         */ 
        void removeHead ();
        
        /**
         * Removes the tail (end) node from the list.
         */ 
        void removeTail ();
        
        /**
         * Creates a new SLNode and inserts in the list so the values are in
         * accending order from head to tail.
         * @param contents an integer containing the value to be tested and
         * inserted into the list.
         */
        void insert (int contents);
        
        /**
         * Removes the first occurance of the parameter value.
         * @param contents an integer containing a value to be found and
         * removed from the list.
         * @return true if value is removed, otherwise return false if value
         * is not in the list.
         */
        bool removeFirst (int contents);
        
        /**
         * Clears the entire contents of the list and frees all the
         * memory associated with the nodes.
         */
        void clear();
        
        /**
         * Gets the size of the list.
         * @return an unsigned integer containing the number of nodes
         * in the list.
         */
        unsigned int getSize () const;
        
        /**
         * Gets a string of all the contents of the list.
         * @return a string representation of the contents of the list,
         * using a NUM1, NUM2, ..., LASTNUM format, and will return an
         * empty string if the list is empty.
         */ 
        string toString () const;
        
    private:
        SLNode* head;
        unsigned int size;
};