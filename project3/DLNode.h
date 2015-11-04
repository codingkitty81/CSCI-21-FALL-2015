/*
 * DLNode.h file for Programming Project #3
 * This file contains the definitions for the functions utilized by DLNode.cpp.
 *
 * Katherine Jouzapaitis
 * Date Created: 10/29/2015
 * Date last modified: 11/4/2015
 */

#pragma once

#include <cassert>
#include <cstdlib>

class DLNode {
  public:
    /**
     * Default constructor.
     * Initializes nextNode and prevNode to NULL, and contents to 0.
     */
    DLNode ();
    
    /**
     * Overloaded constructor.
     * Initializes nextNode and prevNode to NULL, and contents to newContents.
     * @param newContents an integer containing the contents for the node.
     */
    DLNode (int newContents);
    
    /**
     * Destructor.
     * Frees up the memory associated with the SLNode.
     */
    virtual ~DLNode ();
    
    /**
     * Sets the contents of the SLNode.
     * @param newContents an integer containing the contents for the node.
     */
    void setContents (int newContents);
    
    /**
     * Sets the address for the next Node in the linked list.
     * @param newNext an address pointing to the next node in a linked list.
     */
    void setNext (DLNode* newNext);
    
    /**
     * Sets the address for the previous Node in the linked list.
     * @param newPrevious an address pointing to the previous node in a linked list.
     */
    void setPrevious (DLNode* newPrevious);
    
    /**
     * Gets the contents of SLNode.
     * @return an integer containing the contents of SLNode.
     */
    int getContents () const;
    
    /**
     * Gets the address for the next Node in the linked list.
     * @return nextNode an address pointing to the next node in a linked list.
     */ 
    DLNode* getNext () const;
    
    /**
     * Gets the address for the previous Node in the linked list.
     * @return prevNode an address pointing to the previous node in a linked list.
     */
    DLNode* getPrevious () const;
    
  private:
    int contents;
    DLNode* prevNode;
    DLNode* nextNode;
};