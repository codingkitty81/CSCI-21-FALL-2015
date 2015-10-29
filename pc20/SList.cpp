#include "SList.h"

SList::SList () : head(NULL), size(0) {}

SList::~SList () {
	clear ();
}
        
void SList::insertHead (int contents) {
	SLNode* temp = new SLNode(contents);
	temp->setNextNode(head);
	head = temp;
	size++;
}

void SList::insertTail (int contents) {
	SLNode* temp = new SLNode(contents);
	temp->setNextNode(NULL);
	
	if (head == NULL) {
		head = temp;
	} else {
		SLNode* tail = head;
			while (tail->getNextNode() != NULL) {
				tail = tail->getNextNode();
			}
		tail->setNextNode(temp);
	}
	size++;
}
        
void SList::removeHead () {
	SLNode* current;
	
	if (head != NULL) {
		current = head;
		head = head->getNextNode();
		delete current;
		size--;
	}
}

void SList::removeTail () {
	if (head != NULL) {
		if (head->getNextNode() == NULL) {
			delete head;
			head = NULL;
		} else {
			SLNode* nextToTail = head;
			SLNode* tail = head->getNextNode();
				while (tail->getNextNode() != NULL) {
					nextToTail = tail;
					tail = tail->getNextNode();
				}
			delete tail;
			nextToTail->setNextNode(NULL);
		}
		size--;
	}
}
//http://www.c4learn.com/data-structure/insert-node-at-middle-position-singly-linked-list/
void SList::insert (int contents) {
	if (head == NULL || head->getContents() > contents) {
		insertHead(contents);
	} else if (head->getNextNode() == NULL && head->getContents() < contents) {
		insertTail(contents);
	} else {
		SLNode* tempNode1 = head;
		SLNode* tempNode2 = tempNode1->getNextNode();
		
			while (tempNode2->getContents() < contents && tempNode2->getNextNode() != NULL) {
				    tempNode1 = tempNode2;
				    tempNode2 = tempNode2->getNextNode();
			}
		
		if (tempNode2->getContents() >= contents) {	
    		tempNode2 = tempNode1->getNextNode();
    		SLNode* newNode = new SLNode(contents);
    		tempNode1->setNextNode(newNode);
    		newNode->setNextNode(tempNode2);
    		size++;
		} else {
		    insertTail(contents);
		}
	}
}

bool SList::removeFirst (int contents) {
	SLNode* compareNode = new SLNode(contents);
	SLNode* current = head;
	SLNode* previous = NULL;
	bool found = false;
	
	while (current != NULL) {
		if (current->getContents() == compareNode->getContents()) {
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
}

void SList::clear() {
	SLNode* current;
	
	while (head != NULL) {
		current = head;
		head = head->getNextNode();
		delete current;
		size--;
	}
}
        
unsigned int SList::getSize () const {
	return size;
}

string SList::toString () const {
	stringstream listStream;
	SLNode* current;
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
}
