/*
 * project4-test.h for Programming Project 4
 * This file contains the declaration of the function used by project4-test.cpp.
 * This is the driver of the project using information read in from a file to create,
 * delete, manipulate, and display a binary search tree. For this particular project
 * the binary search tree will contain Word objects, which themselves contain a word
 * and a count of how many attempts were made to insert that word in the tree.
 *
 * Katherine Jouzapaitis
 * Date created: 11/24/2015
 * Date last modified: 12/3/2015
 */
#pragma once

#include <fstream>
#include <sstream>

void fileProcess(string fileName);