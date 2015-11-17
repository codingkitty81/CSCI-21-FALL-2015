#include "BSTree.h"

BSTree::BSTree () : root(NULL), size(0) {}

BSTree::~BSTree () {
    clear ();
}

bool BSTree::insert (int contents) {
    return insert (contents, root);
}

void BSTree::clear () {
    clear (root);
}

unsigned int BSTree::getSize () {
    return size;
}

void BSTree::inOrder (ostream& out) {
    inOrder (root, out);
}
//http://www.cplusplus.com/forum/general/1551/
bool BSTree::insert (int contents, BSTNode*& root) {

    bool canInsert;
    
    if (root == NULL) {
        root = new BSTNode(contents);
        canInsert = true;
    } else if (contents < root->getContents()) {
        return insert (contents, root->getLeftChild());
    } else if (contents > root->getContents()) {
        return insert (contents, root->getRightChild());
    } else {
        canInsert = false;
    }
    
    if (canInsert == true) {
        size++;
    }
    
    return canInsert;
}
//http://www.cplusplus.com/forum/general/3509/
void BSTree::clear (BSTNode*& node) {
    if (node == NULL) {
        return;
    }
    
    if (node->getLeftChild() != NULL) {
        clear(node->getLeftChild());
    }
    
    if (node->getRightChild() != NULL) {
        clear(node->getRightChild());
    }
    
    delete node;
    node = NULL;
    size--;
}

void BSTree::inOrder (BSTNode* node, ostream& out) {
    if (node != NULL) {
        if (node->getLeftChild() != NULL) {
            inOrder(node->getLeftChild(), out);
        }
        
        out << node->getContents() << " ";
        
        if (node->getRightChild() != NULL) {
            inOrder(node->getRightChild(), out);
        }
    }
}