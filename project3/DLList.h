/*
 *
 * Date created: 10/29/2015
 *
 */
 
#pragma once

#include "DLNode.h"
#include <cassert>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class DLList {
  public:
    DLList ();
    ~DLList ();
    unsigned int getSize ();
    void pushFront (int newContents);
    void pushBack (int newContents);
    void insert (int newContents);
    int getFront () const;
    int getBack () const;
    bool get (int target);
    void popFront ();
    void popBack ();
    bool removeFirst (int target);
    bool removeAll (int target);
    void clear ();
    friend ostream& operator<< (ostream& out, const DLList& src);
string toString () const;
  private:
    unsigned int nodeCount;
    DLNode* head;
    DLNode* tail;
};

