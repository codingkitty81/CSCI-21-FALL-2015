/*
 * BSTNode.h for Programming Challenge 24
 * This file has the declarations for the functions used by BSTNode.cpp.
 * This program constructs and destructs nodes to be used in a binary search
 * tree, and allows for the manipulation of the contents of the nodes and
 * the left and right children of the node.
 *
 * Katherine Jouzapaitis
 * Date created: 11/10/2015
 * Date last modified: 11/10/2015
 */
 
#pragma once

#include <cassert>
#include <cstdlib>

class BSTNode {
    public:
        BSTNode();
        BSTNode(int newContents);
        
        virtual ~BSTNode();
        
        void setContents(int newContents);
        
        int getContents() const;
        int& getContents();
        
        void setLeftChild(BSTNode* newLeft);
        void setRightChild(BSTNode* newRight);
        
        BSTNode* getLeftChild() const;
        BSTNode*& getLeftChild();
        
        BSTNode* getRightChild() const;
        BSTNode*& getRightChild();
        
    private:
        BSTNode* leftChild;
        BSTNode* rightChild;
        int contents;
};