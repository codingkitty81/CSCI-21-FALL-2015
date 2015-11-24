/*
 * BSTNode.h for Programming Challenge 26
 * This file has the declarations for the functions used by BSTNode.cpp.
 * This program constructs and destructs nodes to be used in a binary search
 * tree, and allows for the manipulation of the contents of the nodes and
 * the left and right children of the node.
 *
 * Katherine Jouzapaitis
 * Date created: 11/16/2015
 * Date last modified: 11/16/2015
 */
 
#pragma once

#include <cassert>
#include <cstdlib>

class BSTNode {
    public:
        /**
         * Default constructor.
         * Constructs a new node with leftChild and rightChild set to NULL, and
         * contents set to 0.
         */
        BSTNode();
        
        /**
         * Overloaded constructor.
         * Constructs a new node with leftChild and rightChild set to NULL, and
         * contents set to newContents.
         * @param newContents an integer containing the value to be set to
         * contents.
         */
        BSTNode(int newContents);
        
        /**
         * Destructor.
         * Sets leftChild and rightChild to NULL.
         */
        virtual ~BSTNode();
        
        /**
         * Sets the contents of a node after construction.
         * @param newContents an integer containing the value to be set to
         * contents.
         */
        void setContents(int newContents);
        
        /**
         * Gets the contents of a node after construction.
         * @return an integer with the value contained in a node.
         */
        int getContents() const;
        
        /**
         * Gets the reference to the contents of a node after construction.
         * @return an integer with the value contained in a node.
         */
        int& getContents();
        
        /**
         * Sets the link to the leftChild.
         * @param newLeft a reference to the address of the node to be the 
         * leftChild.
         */
        void setLeftChild(BSTNode* newLeft);
        
        /**
         * Sets the link to the rightChild.
         * @param newRight a reference to the address of the node to be the
         * rightChild.
         */
        void setRightChild(BSTNode* newRight);
        
        /**
         * Gets the address of the leftChild.
         * @return BSTNode* the address to the leftChild.
         */
        BSTNode* getLeftChild() const;
        
        /**
         * Gets the reference to the address of the leftChild.
         * @return BSTNode*& the reference to the address to the leftChild.
         */
        BSTNode*& getLeftChild();
        
        /**
         * Gets the address to the rightChild.
         * @return BSTNode* the address to the rightChild.
         */
        BSTNode* getRightChild() const;
        
        /**
         * Gets the reference to the address to the rightChild.
         * @return BSTNode*& the reference to the address to the rightChild.
         */
        BSTNode*& getRightChild();
        
    private:
        BSTNode* leftChild;
        BSTNode* rightChild;
        int contents;
};