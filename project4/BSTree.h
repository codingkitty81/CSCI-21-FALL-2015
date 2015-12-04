/*
 * BSTree.h for Programming Project 4
 * This file is the templated class for the tree portion of a binary search tree.
 * A tree can be constructed, destructed, manipulated, and a count of the nodes is 
 * kept track of. Displaying the nodes in both ascending and descending order is
 * possible, along with node being inserted into, removed from, found within the tree.
 *
 * Katherine Jouzapaitis
 * Date created: 11/24/2015
 * Date last modified: 12/3/2015
 */

#pragma once
#include "BSTNode.h"

#include <iostream>
using namespace std;

template <typename treeBits>
class BSTree {
    public:
        /**
         * Default constructor.
         * Initializes root to NULL and size to 0.
         */
        BSTree () : size(0), root(NULL) {}
        
        /**
         * Deconstructor.
         * Calls the clear function.
         */
        virtual ~BSTree () {
            clear();
        }
        
        /**
         * Gets the number of nodes in the tree.
         * @return an unsigned int containing the number of nodes currently in
         * the Binary Search Tree.
         */
        unsigned int getSize () const {
            return size;
        }
        
        /**
         * Calls the private function clear(root).
         */
        void clear () {
            clear(root);
        }
        
        /**
         * Calls the private function insert(treeBits, BSTNode<treeBits>*).
         * @param contents a datatype indicated by the template containing the 
         * contents to the node to be inserted into the tree.
         * @return the bool results of the private function insert(treeBits, BSTNode<treeBits>*).
         */
        bool insert (treeBits contents) {
            return insert(contents, root);
        }
        
        /**
         * Calls the private function find(treeBits, BSTNode<treeBits>*).
         * @param targetData a datatype indicated by the template containing the
         * targeted data to be found.
         * @return the bool results of the private function find(treeBits, BSTNode<treeBits>*).
         */
        bool find (treeBits targetData) {
            if (root == NULL) {
                throw string ("TREE EMPTY");
            }
            return find(targetData, root);
        }
        
        /**
         * Calls the private function remove(treeBits, BSTNode<treeBits>*).
         * @param targetData a datatype indicated by the template containing the targeted value of the node to be
         * removed from the tree.
         * @return the bool results of the private function remove(treeBits, BSTNode<treeBits>*).
         */
         bool remove (treeBits targetData) {
             if (root == NULL) {
                 throw string ("TREE EMPTY");
             }
             return remove(targetData, root);
         }
        
        /**
         * Calls the private function get(treeBits, BSTNode<treeBits>*).
         * @param targetData a datatype indicated by the template the target data to
         * be searched for in the tree.
         * @return the results of the private function get(treeBits, BSTNode<treeBits>*).
         */
        treeBits* get (treeBits targetData) {
            if (root == NULL) {
                throw string ("TREE EMPTY");
            }
            return get(targetData, root);
        }
        
        /**
         * Calls the private function inOrder(BSTNode<treeBits>*).
         */
        void inOrder () {
            if (root == NULL) {
                throw string ("TREE EMPTY");
            }
            inOrder(root);
        }
        
        /**
         * Calls the private function reverseOrder(BSTNode<treeBits>*).
         */
        void reverseOrder () {
            if (root == NULL) {
                throw string ("TREE EMPTY");
            }
            reverseOrder(root);
        }
        
    private:
    
        /**
         * Deletes every node of the tree and sets them to NULL freeing the memory.
         * @param node a reference starting at the root of the tree to traverse the
         * tree and delete every node.
         */
        void clear (BSTNode<treeBits>*& tempRoot) {
            if (tempRoot == NULL) {
                return;
            }
            
            if (tempRoot->getLeftChild() != NULL) {
                clear(tempRoot->getLeftChild());
            }
            
            if (tempRoot->getRightChild() != NULL) {
                clear(tempRoot->getRightChild());
            }
            
            delete tempRoot;
            tempRoot = NULL;
            size--;
        }
        
        /**
         * Inserts a node that does not already exist into the tree.
         * @param contents a datatype indicated by the template containing the contents to the node to be
         * inserted into the tree.
         * @param tempRoot a pointer to the root of the tree so the tree can be traversed.
         * @return true if tempRoot can be inserted into the tree, otherwise return false.
         */
        bool insert (treeBits contents, BSTNode<treeBits>*& tempRoot) {
            bool canInsert;
    
                if (tempRoot == NULL) {
                    tempRoot = new BSTNode<treeBits>(contents);
                    canInsert = true;
                } else if (contents < tempRoot->getData()) {
                    return insert (contents, tempRoot->getLeftChild());
                } else if (contents > tempRoot->getData()) {
                    return insert (contents, tempRoot->getRightChild());
                } else {
                    canInsert = false;
                }
                
                if (canInsert == true) {
                    size++;
                }
            
            return canInsert;
        }
        
        /**
         * Traverses the tree looking for the targeted data.
         * @param targetData a datatype indicated by the template containing the desired
         * data to be found in the tree.
         * @param tempRoot a pointer to the root of the tree so the tree can be traversed.
         * @return true if a node matching the targeted data is found, otherwise 
         * return false.
         */
        bool find (treeBits targetData, BSTNode<treeBits>*& tempRoot) {
            if (tempRoot == NULL) {
                return false;
            } else if (targetData < tempRoot->getData()) {
                return find(targetData, tempRoot->getLeftChild());
            } else if (targetData > tempRoot->getData()) {
                return find(targetData, tempRoot->getRightChild());
            } else {
                return true;
            }
        }
        
        /**
         * Removes a node that exists in the tree.
         * @param targetData a datatype indicated by the template containing the targeted value of the node to be
         * removed from the tree.
         * @param tempRoot a pointer to the root of the tree so the tree can be traversed.
         * @return true if the node exists and is removed, otherwise return false.
         */
        bool remove (treeBits targetData, BSTNode<treeBits>*& tempRoot) {
            if (root == NULL) {
                return false;
            }
            
            if (find(targetData) == false) {
                return false;
            } else {
                if (targetData > tempRoot->getData()) {
                    return remove(targetData, tempRoot->getRightChild());
                } else if (targetData < tempRoot->getData()) {
                    return remove(targetData, tempRoot->getLeftChild());
                } else {
                    if (tempRoot->getLeftChild() == NULL) {
                        BSTNode<treeBits>* temp = tempRoot;
                        tempRoot = tempRoot->getRightChild();
                        delete temp;
                        temp = NULL;
                        size--;
                     } else {
                        removeMax(tempRoot->getData(), tempRoot->getLeftChild());
                    }
        
                    return true;
                }
            }
        }
        
        /**
         * Helper function in conjunction with remove. Finds the maximum value in
         * the left subtree when the targeted node to be removed has a leftChild or
         * two children. Once the maximum value is set to targetData, the node gets removes.
         * @param targetData a reference to the datatype targetData which the function sets
         * to the largest value of the lest subtree.
         * @param tempRoot a reference to the address of the leftChild of the targeted
         * node to be removed.
         */
        void removeMax (treeBits& targetData, BSTNode<treeBits>*& tempRoot) {
            if (tempRoot->getRightChild() == NULL) {
                BSTNode<treeBits>* temp = tempRoot;
                targetData = tempRoot->getData();
                tempRoot = tempRoot->getLeftChild();
                delete temp;
                temp = NULL;
                size--;
            } else {
                removeMax(tempRoot->getData(), tempRoot->getRightChild());
            }
        }  
        
        /**
         * Gets a pointer to the node containing the targeted data.
         * @param targetData a datatype indicated by the template which contains the 
         * targeted data to be searched for in the tree.
         * @param tempRoot a pointer to the root to allow for traversal of the tree.
         * @return on success a pointer to the node containing the targeted data,
         * otherwise return NULL.
         */
        treeBits* get (treeBits targetData, BSTNode<treeBits>* tempRoot) {
            if (tempRoot == NULL) {
                return NULL;
            }
            
            if (targetData < tempRoot->getData()) {
                return get(targetData, tempRoot->getLeftChild());
            } else if (targetData > tempRoot->getData()) {
                return get(targetData, tempRoot->getRightChild());
            } else {
                return &tempRoot->getData();
            }
         }
         
         /**
          * Works in conjunction with operator<< function to display the data
          * of the tree in ascending order.
          * @param tempRoot a pointer to the root to allow for traversal of the tree.
          */
        void inOrder (BSTNode<treeBits>* tempRoot) {
            if (tempRoot != NULL) {
                if (tempRoot->getLeftChild() != NULL) {
                    inOrder(tempRoot->getLeftChild());
                }
        
            cout << tempRoot->getData();
        
                if (tempRoot->getRightChild() != NULL) {
                    inOrder(tempRoot->getRightChild());
                }
            }
        }
        
        /**
         * Works in conjunction with operator<< function to display the data
         * of the tree in descending order.
         * @param tempRoot a pointer to the root to allow for the traversal of the tree.
         */
        void reverseOrder (BSTNode<treeBits>* tempRoot) {
            if (tempRoot != NULL) {
                if (tempRoot->getRightChild() != NULL) {
                    reverseOrder(tempRoot->getRightChild());
                }
        
            cout << tempRoot->getData();
        
                if (tempRoot->getLeftChild() != NULL) {
                        reverseOrder(tempRoot->getLeftChild());
                }
            }
        }
        
        unsigned int size;
        BSTNode<treeBits>* root;
};