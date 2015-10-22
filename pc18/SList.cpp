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
        
void SList::removeHead () {
	SLNode* current;
	
	if (head != NULL) {
		current = head;
		head = head->getNextNode();
		delete current;
		size--;
	}
	

}
        
void SList::clear () {
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