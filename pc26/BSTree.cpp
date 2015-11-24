#include "BSTree.h"

BSTree::BSTree () : root(NULL), size(0) {}

BSTree::~BSTree () {
    clear ();
}

bool BSTree::insert (int contents) {
    return insert (contents, root);
}

bool BSTree::remove (int contents) {
    return remove (contents, root);
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

bool BSTree::remove (int contents, BSTNode*& parent) {
    if (parent == NULL) {
        return false;
    } else if (contents > parent->getContents()) {
        return remove(contents, parent->getRightChild());
    } else if (contents < parent->getContents()) {
        return remove(contents, parent->getLeftChild());
    } else {
        if (parent->getLeftChild() == NULL) {
            BSTNode* temp = parent;
            parent = parent->getRightChild();
            delete temp;
            temp = NULL;
            size--;
        } else {
            removeMax(contents, parent->getLeftChild());
            parent->setContents(contents);
        }
        
        return true;
    }
}

void BSTree::removeMax (int& contents, BSTNode*& parent) {
    if (parent->getRightChild() == NULL) {
        BSTNode* temp = parent;
        contents = parent->getContents();
        parent = parent->getLeftChild();
        delete temp;
        temp = NULL;
        size--;
    } else {
        removeMax(contents, parent->getRightChild());
    }
}

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