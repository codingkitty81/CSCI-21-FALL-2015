/*
 * SLNode.h for Programming Challenge 17
 * This file contains the function declarations for SLNode.cpp in order to test
 * the creation of a linked list.
 *
 * Katherine Jouzapaitis
 * Date created: 10/13/2015
 * Date last modified: 10/13/2015
 */
#pragma once

#include <cassert>
#include <cstdlib>
#include <iostream>
using namespace std;

class SLNode {
    public:
        /**
         * Default constructor.
         * Initializes nextNode to NULL and contents to 0.
         */ 
        SLNode ();
        
        /**
         * Overloaded constructor.
         * Initializes nextNode to NULL and contents to newContents.
         * @param newContents an integer containing the contents for the node.
         */ 
        SLNode (int newContents);
        
        /**
         * Destructor.
         * Frees up the memory associated with the SLNode.
         */ 
        virtual ~SLNode ();
        
        /**
         * Sets the contents of the SLNode.
         * @param newContents an integer containing the contents for the node.
         */
        void setContents (int newContents);
        
        /**
         * Gets the contents of SLNode.
         * @return an integer containing the contents of SLNode.
         */
        int getContents () const;
        
        /**
         * Sets the address for the next Node in the linked list.
         * @param newNextNode an address pointing to the next node in a linked list.
         */ 
        void setNextNode (SLNode* newNextNode);
        
        /**
         * Gets the address for the next Node in the linked list.
         * @return nextNode an address pointing to the next node in a linked list.
         */ 
        SLNode* getNextNode () const;
        
    private:
        SLNode* nextNode;
        int contents;
};