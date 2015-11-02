#include "DLList.h"

struct nodeException {
	nodeException (string newMessage="error")
	: message(newMessage) {
	}
	
	string message;
};

DLList::DLList () : nodeCount(0), head(NULL), tail(NULL) {}

DLList::~DLList () {
    clear ();
}

unsigned int DLList::getSize () {
    return nodeCount;
}
//http://www.dailyfreecode.com/Code/double-linked-list-cpp-3422.aspx
void DLList::pushFront (int newContents) {
    DLNode* tempNode = new DLNode(newContents);
    
    if (head == NULL) {
        head = tempNode;
        tail = tempNode;
    } else {
        tail = head;
        tempNode->setNext(tail);
        tempNode->setPrevious(NULL);
        head = tempNode;
        tail->setPrevious(tempNode);
    }
    
    nodeCount++;
}

void DLList::pushBack (int newContents) {
    DLNode* tempNode = new DLNode(newContents);
    tempNode->setNext(NULL);
    tempNode->setPrevious(NULL);
    
    if (head == NULL) {
        pushFront(newContents);
    } else {
        tail = head;
        
        while (tail->getNext() != NULL) {
            tail = tail->getNext();
        }
        
        tail->setNext(tempNode);
        tempNode->setPrevious(tail);
    }
    
    nodeCount++;
}

void DLList::insert (int newContents) {
    if (head == NULL || head->getContents() > newContents) {
        pushFront(newContents);
    } else if (head->getNext() == NULL && head->getContents() < newContents) {
        pushBack(newContents);
    } else {
        DLNode* previousNode = head;
        DLNode* nextUp = head->getNext();
        
        while (nextUp->getContents() < newContents && nextUp->getNext() != NULL) {
            previousNode = nextUp;
            nextUp = nextUp->getNext();
        }
        
        if (nextUp->getContents() >= newContents) {
            nextUp->setPrevious(nextUp);
            previousNode->setNext(previousNode);
            DLNode* newNode = new DLNode(newContents);
            previousNode->setNext(newNode);
            newNode->setPrevious(previousNode);
            newNode->setNext(nextUp);
            nextUp->setPrevious(newNode);
            nodeCount++;
        } else {
            pushBack(newContents);
        }
    }
}

int DLList::getFront () const {
    if (head == NULL) {
        throw nodeException("LIST EMPTY");
    } else {
        return head->getContents();
    }
}

int DLList::getBack () const {
    if (head == NULL) {
        throw nodeException("LIST EMPTY");
    } else {
        DLNode* backNode = head;
        
        while (backNode->getNext() != NULL) {
            backNode = backNode->getNext();
        }
        
        return backNode->getContents();
    }
}
//http://code.runnable.com/Us53wIV1TEVWAAHd/how-to-search-a-node-in-a-linked-list-for-c%2B%2B
bool DLList::get (int target) {
    bool nodeCheck = false;
    DLNode* tempNode = head;
    
        while (tempNode != NULL) {
            if (tempNode->getContents() == target) {
                nodeCheck = true;
            }
            
            tempNode = tempNode->getNext();
        }
    
    return nodeCheck;
}

void DLList::popFront () {
    DLNode* currentNode;
    
    if (head != NULL) {
        currentNode = head;
        head = head->getNext();
        head->setPrevious(NULL);
        delete currentNode;
        nodeCount--;
    }

}

void DLList::popBack () {
    if (head != NULL) {
        if (head->getNext() == NULL) {
            popFront();
        } else {
            DLNode* previousNode = head;
            tail = head->getNext();
                
                while (tail->getNext() != NULL) {
                    previousNode = tail;
                    tail = tail->getNext();
                }
            previousNode->setNext(NULL);
            tail->setPrevious(NULL);
            delete tail;
        }
        
        nodeCount--;
    }
}

bool DLList::removeFirst (int target) {
    DLNode* currentNode = head;
    DLNode* previousNode = NULL;
    DLNode* nextUp = currentNode->getNext();
    bool found = false;
        
    while (currentNode != NULL) {
        if (currentNode->getContents() == target) {
            found = true;
            break;
        }
            
        previousNode = currentNode;
        currentNode = nextUp;
        nextUp = nextUp->getNext();
    }
        
    if (found == true) {
        if (previousNode == NULL) {
            popFront();
        } else if (nextUp == NULL) {
            popBack();
        } else {
            currentNode->setPrevious(currentNode);
            currentNode->setNext(currentNode);
            previousNode->setNext(nextUp);
            nextUp->setPrevious(previousNode);
            delete currentNode;
        }
            
        nodeCount--;
    }
    
    return found;
}

bool DLList::removeAll (int target) {
    
    bool foundAll = false;
    
    while (foundAll == false) { 
        if (get(target) == true) {
            removeFirst(target);
        } else {
            foundAll = true;
        }
    }
    
    return foundAll;
}

void DLList::clear () {
    DLNode* toDelete = head;
    
    while (toDelete != NULL) {
        head = head->getNext();
        delete toDelete;
        toDelete = head;
        nodeCount--;
    }
    
    head = tail = NULL;
}

ostream& operator<< (ostream& out, const DLList& src) {
    stringstream listOut;
    listOut << src << ",";
    
    out << listOut.str().substr(0,listOut.str().length() - 1);
    return out;
}
  
string DLList::toString () const {
	stringstream listStream;
	DLNode* current;
	current = head;
	
	if (head == NULL){
		listStream << "" << ",";
	} else {
		while (current != NULL) {
			listStream << current->getContents() << ",";
			current = current->getNext();
		}
	}
	
	return(listStream.str().substr(0,listStream.str().length() - 1));
}