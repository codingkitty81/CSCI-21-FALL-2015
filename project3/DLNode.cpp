#include "DLNode.h"

DLNode::DLNode () : contents(0), prevNode(NULL), nextNode(NULL) {}

DLNode::DLNode (int newContents) : contents(newContents), prevNode (NULL), nextNode (NULL) {}

DLNode::~DLNode () {
    nextNode = NULL;
    prevNode = NULL;
}

void DLNode::setContents(int newContents) {
    contents = newContents;
}

void DLNode::setNext (DLNode* newNext) {
    nextNode = newNext;
}

void DLNode::setPrevious (DLNode* newPrevious) {
    prevNode = newPrevious;
}

int DLNode::getContents () const {
    return contents;
}

DLNode* DLNode::getNext () const {
    return nextNode;
}

DLNode* DLNode::getPrevious () const {
    return prevNode;
}