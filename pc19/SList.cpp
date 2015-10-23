#include "SList.h"
#include "SLNode.h"

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
		cout << "" << endl;
	} else {
		while (current != NULL) {
			listStream << current->getContents() << ",";
			current = current->getNextNode();
		}
	}
	
	return(listStream.str().substr(0,listStream.str().length() - 1));
}