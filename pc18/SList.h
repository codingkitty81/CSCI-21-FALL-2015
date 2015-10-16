/*
 * SList.h for Programming Challenge 18
 * The file contains the defitions for SList.cpp and a link to SLNode.h in order
 * to test the construction, destruction, addition, removal, and diplay of items 
 * in a linked list.
 *
 * Katherine Jouzapaitis
 * Date created: 10/13/2015
 * Date last modified: 10/16/2015
 */
#pragma once
#include "SLNode.h"

#include <cassert>
#include <cstdlib>
#include <string>
using std::string;

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
         * @param content an integer containing the contents to be
         * placed in the list.
         */ 
        void insertHead (int contents);
        
        /**
         * Removes the head node from the list.
         */ 
        void removeHead ();
        
        /**
         * Clears the entire contents of the list and frees all the
         * memory associated with the nodes.
         */ 
        void clear ();
        
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