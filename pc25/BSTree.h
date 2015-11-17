/*
 * BSTree.h for Programming Challenge 25
 * This file contains the declarations of the functions utilized by BSTree.cpp.
 * This program allows for the consruction, destruction, and manipulation of a
 * Binary Search Tree. The user can create a Binary Search Tree, insert nodes
 * into the tree, have the contents of the tree output,get the size of the tree,
 * and clear out the entire tree if desired.
 *
 * Katherine Jouzapaitis
 * Date created: 11/10/2015
 * Date last modified: 11/16/2015
 *
 * Resources:
 * http://www.cplusplus.com/forum/general/1551/
 * http://www.cplusplus.com/forum/general/3509/
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
     * Calls the private function insert(int, root).
     * @param contents an integer containing the contents to the node to be
     * inserted into the tree.
     * @return the bool results of the private function insert(int, root).
     */
    bool insert (int contents);
    
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
     * Calls the private function inOrder(root, ostream&).
     * @param out the reference to an ostringstream.
     */
    void inOrder (ostream& out);
  private:
  
    /**
     * Inserts a node that does not already exist into the tree.
     * @param contents an integer containing the contents to the node to be
     * inserted into the tree.
     * @return true if node can be inserted into the tree, otherwise return false.
     */
    bool insert (int contents, BSTNode*& newNode);
    
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
     * @param out a reference to an ostringstream to be built upon as the tree is
     * traversed with each output followed by a space.
     */
    void inOrder (BSTNode* node, ostream& out);
    
    BSTNode* root;
    unsigned int size;
};