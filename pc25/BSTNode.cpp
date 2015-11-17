#include "BSTNode.h"

BSTNode::BSTNode() : leftChild(NULL), rightChild(NULL), contents(0) {}

BSTNode::BSTNode(int newContents) : leftChild(NULL), rightChild(NULL), contents(newContents) {}

BSTNode::~BSTNode() {
    leftChild = NULL;
    rightChild = NULL;
}

void BSTNode::setContents(int newContents) {
    contents = newContents;
}

int BSTNode::getContents() const {
    return contents;
}

int& BSTNode::getContents() {
    return contents;
}

void BSTNode::setLeftChild(BSTNode* newLeft) {
    leftChild = newLeft;
}

void BSTNode::setRightChild(BSTNode* newRight) {
    rightChild = newRight;
}

BSTNode* BSTNode::getLeftChild() const {
    return leftChild;
}

BSTNode*& BSTNode::getLeftChild() {
    return leftChild;
}

BSTNode* BSTNode::getRightChild() const {
    return rightChild;
}

BSTNode*& BSTNode::getRightChild() {
    return rightChild;
}