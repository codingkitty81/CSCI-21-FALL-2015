/*
 * Programming Challenge 22 - template header
 * This is a template for the SList class which allows for the construction,
 * destruction, and manipulation of a singly linked list. By working with SLNode.h
 * the list can have new nodes added to the head, tail, or middle of the list.
 * Nodes can also be removed, and the contents of the nodes can be displayed.
 *
 * Katherine Jouzapaitis
 * Date created: 11/4/2015
 * Date last modified: 11/5/2015
 */

#pragma once
#include "SLNode.h"
#include <cassert>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

template <typename listyBits>
class SList {
    private:
        SLNode<listyBits>* head;
        unsigned int size;  
    
    public:
        /**
         * Default constructor.
         * Initializes head to NULL and size to 0.
         */
        SList () : head(NULL), size(0) {};
        
        /**
         * Destructor.
         * Calls the clear function.
         */
        virtual ~SList () {
            clear();
        };
        
        /**
         * Creates a new SLNode and places it at the head of the list.
         * @param contents type declared by template containing the contents to be
         * placed in the list.
         */
        void insertHead (listyBits contents) {
            SLNode<listyBits>* temp = new SLNode<listyBits>(contents);
        	temp->setNextNode(head);
        	head = temp;
        	size++;
        };
        
        /**
         * Creates a new SLNode and places it at the tail (end) of the list.
         * @param contents type declared by template containing the contents to be placed
         * in the list.
         */ 
        void insertTail (listyBits contents) {
            SLNode<listyBits>* temp = new SLNode<listyBits>(contents);
        	temp->setNextNode(NULL);
	
        	if (head == NULL) {
        		head = temp;
        	} else {
        		SLNode<listyBits>* tail = head;
        			while (tail->getNextNode() != NULL) {
        				tail = tail->getNextNode();
        			}
        		tail->setNextNode(temp);
        	}
        	size++;
        };
        
        /**
         * Removes the head node from the list.
         */ 
        void removeHead () {
            SLNode<listyBits>* current;
	
        	if (head != NULL) {
    	    	current = head;
    		    head = head->getNextNode();
    	    	delete current;
        		size--;
        	}
        };
        
        /**
         * Removes the tail (end) node from the list.
         */ 
        void removeTail () {	
            if (head != NULL) {
		        if (head->getNextNode() == NULL) {
			        delete head;
			        head = NULL;
		    } else {
		    	SLNode<listyBits>* nextToTail = head;
			    SLNode<listyBits>* tail = head->getNextNode();
				    while (tail->getNextNode() != NULL) {
					    nextToTail = tail;
					    tail = tail->getNextNode();
		    }
			delete tail;
			nextToTail->setNextNode(NULL);
			tail = nextToTail;
		    }
		    size--;
	        }
        };
        
        /**
         * Creates a new SLNode and inserts in the list so the values are in
         * accending order from head to tail.
         * @param contents type declared by template containing the value to be tested and
         * inserted into the list.
         */
        void insert (listyBits contents) {
            if (head == NULL || head->getContents() > contents) {
		        insertHead(contents);
	        } else if (head->getNextNode() == NULL && head->getContents() <= contents) {
	        	insertTail(contents);
	        } else {
		        SLNode<listyBits>* tempNode1 = head;
		        SLNode<listyBits>* tempNode2 = tempNode1->getNextNode();
		
			        while (tempNode2->getContents() < contents && tempNode2->getNextNode() != NULL) {
				        tempNode1 = tempNode2;
				        tempNode2 = tempNode2->getNextNode();
			        }
		
		        if (tempNode2->getContents() >= contents) {	
    		        tempNode2 = tempNode1->getNextNode();
    		        SLNode<listyBits>* newNode = new SLNode<listyBits>(contents);
    		        tempNode1->setNextNode(newNode);
    		        newNode->setNextNode(tempNode2);
    	        	size++;
		        } else {
		            insertTail(contents);
		        }
	         }
        };
        
        /**
         * Removes the first occurance of the parameter value.
         * @param contents type declared by template containing a value to be found and
         * removed from the list.
         * @return true if value is removed, otherwise return false if value
         * is not in the list.
         */
        bool removeFirst (listyBits contents) {
            SLNode<listyBits>* current = head;
	        SLNode<listyBits>* previous = NULL;
	        bool found = false;
	
	        while (current != NULL) {
	        	if (current->getContents() == contents) {
		        	found = true;
		        	break;
	        	}
	        	previous = current;
		        current = current->getNextNode();
        	}
	
        	if (found == true) {
        		if (previous == NULL) {
	           		head = current->getNextNode();
	        	} else {
        			previous->setNextNode(current->getNextNode());
        		}
	    	delete current;
	    	size--;
        	}
      	
        	return found;
        };
        
        /**
         * Removes all occurances of a given value in the list.
         * @param target type declared by template containing the value to be searched for
         * and then removed from the list.
         * @return true if all occurances of the target were found and removed, otherwise
         * return false.
         */
        bool removeAll (listyBits target) {
            bool foundAll = false;
            int foundCount = 0;
            
            while (foundAll == false) { 
                if (removeFirst(target) == true) {
                    foundCount++;
                } else {
                    foundAll = true;
                }
            }
            
            if (foundCount == 0) {
                foundAll = false;
            }
            
            return foundAll;
        };
        
        /**
         * Clears the entire contents of the list and frees all the
         * memory associated with the nodes.
         */
        void clear() {
            SLNode<listyBits>* current;
	
        	while (head != NULL) {
		        current = head;
		        head = head->getNextNode();
		        delete current;
		        size--;
	        }
        };
        
        /**
         * Gets the size of the list.
         * @return an unsigned integer containing the number of nodes
         * in the list.
         */
        unsigned int getSize () const {
            return size;
        };
        
        /**
         * Gets a string of all the contents of the list.
         * @return a string representation of the contents of the list,
         * using a NUM1, NUM2, ..., LASTNUM format, and will return an
         * empty string if the list is empty.
         */ 
        string toString () const {
            stringstream listStream;
	        SLNode<listyBits>* current;
	        current = head;
	
	        if (head == NULL){
	        	listStream << "" << ",";
        	} else {
        		while (current != NULL) {
	        		listStream << current->getContents() << ",";
	        		current = current->getNextNode();
	        	}
        	}
	
        	return(listStream.str().substr(0,listStream.str().length() - 1));

        };
        
};