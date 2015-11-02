/*
 *
 * Date Created: 10/29/2015
 *
 */

#pragma once

#include <cassert>
#include <cstdlib>

class DLNode {
  public:
    DLNode ();
    DLNode (int newContents);
    virtual ~DLNode ();
    void setContents (int newContents);
    void setNext (DLNode* newNext);
    void setPrevious (DLNode* newPrevious);
    int getContents () const;
    DLNode* getNext () const;
    DLNode* getPrevious () const;
    
  private:
    int contents;
    DLNode* prevNode;
    DLNode* nextNode;
};