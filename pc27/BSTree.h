/*
 * BSTree.h for Programming Challenge 27
 * This file contains the declarations of the functions utilized by BSTree.cpp.
 * This program allows for the consruction, destruction, and manipulation of a
 * Binary Search Tree. The user can create a Binary Search Tree, insert nodes
 * into the tree, have the contents of the tree output,get the size of the tree,
 * and clear out the entire tree if desired.
 *
 * Katherine Jouzapaitis
 * Date created: 11/23/2015
 * Date last modified: 11/23/2015
 */

#pragma once

#include "BSTNode.h"
#include <iostream>
using namespace std;

class BSTree {
  public:
    /**
     * Default constructor.
     * Initializes root to NULL and size to 0.
     */
    BSTree ();
    
    /**
     * Deconstructor.
     * Calls the clear function.
     */
    virtual ~BSTree ();
    
    /**
     * Calls the private function insert(int, BSTNode*).
     * @param contents an integer containing the contents to the node to be
     * inserted into the tree.
     * @return the bool results of the private function insert(int, BSTNode*).
     */
    bool insert (int contents);
    
    /**
     * Calls the private function remove(int, BSTNode*).
     * @param contents an integer containing the targeted value of the node to be
     * removed from the tree.
     * @return the bool results of the private function remove(int, BSTNode*).
     */
    bool remove (int contents);
    
    /**
     * Calls the private function clear(root).
     */
    void clear ();
    
    /**
     * Gets the number of nodes in the tree.
     * @return an unsigned int containing the number of nodes currently in
     * the Binary Search Tree.
     */
    unsigned int getSize ();
    
    /**
     * Calls the private function inOrder(BSTNode*, void (*f)(int)).
     * @param .
     */
    void inOrder (void (*f)(int));
    
    /**
     * Calls the private function reverseOrder(BSTNode*, void (*f)(int)).
     * @param .
     */
     void reverseOrder (void (*f)(int));
     
  private:
  
    /**
     * Inserts a node that does not already exist into the tree.
     * @param contents an integer containing the contents to the node to be
     * inserted into the tree.
     * @return true if node can be inserted into the tree, otherwise return false.
     */
    bool insert (int contents, BSTNode*& newNode);
    
    /**
     * Removes a node that exists in the tree.
     * @param contents an integer containing the targeted value of the node to be
     * removed from the tree.
     * @return true if the node exists and is removed, otherwise return false.
     */
    bool remove (int contents, BSTNode*& node);
    
    /**
     * Helper function in conjunction with remove. Finds the maximum value in
     * the left subtree when the targeted node to be removed has a leftChild or
     * two children. Once the maximum value is set to contents, the node gets removes.
     * @param contents a reference to the integer contents which the function sets
     * to the largest value of the lest subtree.
     * @param node a reference to the address of the leftChild of the targeted
     * node to be removed.
     */
    void removeMax (int& contents, BSTNode*& node);
    
    /**
     * Deletes every node of the tree and sets them to NULL freeing the memory.
     * @param node a reference starting at the root of the tree to traverse the
     * tree and delete every node.
     */
    void clear (BSTNode*& node);
    
    /**
     * Creates an output of all the nodes in the Binary Search Tree.
     * @param node a reference to the root of the tree in order to traverse the
     * tree to get all the contents in order.
     * @param funPtr a pointer to a function to be used to handle the output of 
     * the BSTree.
     */
    void inOrder (BSTNode* node, void (*funPtr)(int));
    
    /**
     * Creates an output of all the nodes in the Binary Search Tree in reverse order.
     * @param node a reference to the root of the tree in order to traverse the
     * tree to get all the contents in reverse order.
     * @param funPtr a pointer to a function to be used to handle the output of 
     * the BSTree.
     */
    void reverseOrder (BSTNode* node, void (*funPtr)(int));
    
    BSTNode* root;
    unsigned int size;
};