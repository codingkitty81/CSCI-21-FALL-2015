#include "SLNode.h"

SLNode::SLNode () : nextNode(NULL), contents(0) {}

SLNode::SLNode (int newContents) : nextNode(NULL), contents(newContents) {}

SLNode::~SLNode () {
	nextNode = NULL;
}

void SLNode::setContents (int newContents) {
	contents = newContents;
}

int SLNode::getContents () const {
	return contents;
}

void SLNode::setNextNode (SLNode* newNextNode) {
	nextNode = newNextNode;
}

SLNode* SLNode::getNextNode () const {
	return nextNode;
}
