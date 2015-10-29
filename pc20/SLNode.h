/*
 * SLNode.h for Programming Challenge 20
 * This file provides the declaration for the functions in SLNode.cpp. The
 * functions allow for Nodes to be constructed or destructed. The contents and
 * node addresses can also be manipulated for use in a linked list.
 *
 * Katherine Jouzapaitis
 * Date created: 10/22/2015
 * Date last modified: 10/22/2015
 */
#pragma once

#include <cassert>
#include <cstdlib>

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