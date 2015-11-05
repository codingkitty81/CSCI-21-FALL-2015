/*
 * Programming Challenge 22 - template header
 * This is a template for the SLNode class which allows for the construction,
 * destruction, and manipulation of nodes to be placed in a singly linked list.
 * The nodes can have their contents and next node pointer both set and get.
 *
 * Katherine Jouzapaitis
 * Date created: 11/4/2015
 * Date last modified: 11/5/2015
 */

#pragma once

#include <cassert>
#include <cstdlib>

template <typename nodeyBits>
class SLNode {
    private:
        SLNode<nodeyBits>* nextNode;
        nodeyBits contents;
    
    public:
        /**
         * Default constructor.
         * Initializes nextNode to NULL and contents to 0.
         */ 
        SLNode () : nextNode(NULL), contents(0) {};
        
        /**
         * Overloaded constructor.
         * Initializes nextNode to NULL and contents to newContents.
         * @param newContents type declared by template containing the contents for the node.
         */ 
        SLNode (nodeyBits newContents) : nextNode(NULL), contents(newContents) {};
        
        /**
         * Destructor.
         * Frees up the memory associated with the SLNode.
         */ 
        virtual ~SLNode () {
	        nextNode = NULL;
        };
        
        /**
         * Sets the contents of the SLNode.
         * @param newContents type declared by template containing the contents for the node.
         */
        void setContents (nodeyBits newContents) {
	        contents = newContents;
        };
        
        /**
         * Gets the contents of SLNode.
         * @return type declared by template containing the contents of SLNode.
         */
        nodeyBits& getContents () {
        	return contents;
        };
        
        /**
         * Sets the address for the next Node in the linked list.
         * @param newNextNode an address pointing to the next node in a linked list.
         */ 
        void setNextNode (SLNode<nodeyBits>* newNextNode) {
	        nextNode = newNextNode;
        };
        
        /**
         * Gets the address for the next Node in the linked list.
         * @return nextNode an address pointing to the next node in a linked list.
         */ 
        SLNode* getNextNode () const {
        	return nextNode;
        };
        
};