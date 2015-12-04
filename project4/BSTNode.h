/*
 * BSTNode.h for Programming Project 4
 * This file is the templated class for the nodes to be used in a binary search tree.
 * Nodes can be created, destructed, and manipulated within this portion of the program.
 * Pointers to the children of nodes can set and get, as well as the data within nodes
 * can be set or get.
 *
 * Katherine Jouzapaitis
 * Date created: 11/24/2015
 * Date last modified: 12/3/2015
 */

// Date created: 11/24/2015

#pragma once

#include <cassert>
#include <cstdlib>

template <typename nodeyBits>
class BSTNode {
    public:
    
        /**
         * Overloaded constructor.
         * Constructs a new node with leftChild and rightChild set to NULL, and
         * contents set to newData.
         * @param newData whatever datatype the template indicates containing 
         * the value to be set to contents.
         */
        BSTNode(nodeyBits newData) : data(newData), leftChild(NULL), rightChild(NULL) {}
        
        /**
         * Destructor.
         */
        virtual ~BSTNode() {}
        
        /**
         * Sets the data of a node after construction.
         * @param newData whatever datatype the template indicates containing
         * the value to be set to contents.
         */
        void setData(nodeyBits newData) {
            data = newData;
        }
        
        /**
         * Sets the link to the leftChild.
         * @param newLeft a reference to the address of the node to be the 
         * leftChild.
         */
        void setLeftChild(BSTNode* newLeft) {
            leftChild = newLeft;
        }
        
        /**
         * Sets the link to the rightChild.
         * @param newRight a reference to the address of the node to be the
         * rightChild.
         */
        void setRightChild(BSTNode* newRight) {
            rightChild = newRight;
        }
        
        /**
         * Gets the data of a node after construction.
         * @return whatever datatype the template indicates with the contents
         * of a node.
         */
        nodeyBits getData() const {
            return data;
        }
        
        /**
         * Gets the address of the leftChild.
         * @return BSTNode<nodeyBits>* the address to the leftChild.
         */
        BSTNode* getLeftChild() const {
            return leftChild;
        }
        
        /**
         * Gets the address to the rightChild.
         * @return BSTNode<nodeyBits>* the address to the rightChild.
         */
        BSTNode* getRightChild() const {
            return rightChild;
        }
        
        /**
         * Gets the reference to the data of a node after construction.
         * @return whatever datatype the template indicates with the contents
         * of a node.
         */
        nodeyBits& getData() {
            return data;
        }
        
        /**
         * Gets the reference to the address of the leftChild.
         * @return BSTNode<nodeyBits>*& the reference to the address to the leftChild.
         */
        BSTNode*& getLeftChild() {
            return leftChild;
        }
        
        /**
         * Gets the reference to the address to the rightChild.
         * @return BSTNode<nodeyBits>*& the reference to the address to the rightChild.
         */
        BSTNode*& getRightChild() {
            return rightChild;
        }
        
    private:
        nodeyBits data;
        BSTNode* leftChild;
        BSTNode* rightChild;
};