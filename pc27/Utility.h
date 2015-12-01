/*
 * Utility.h for Programming Challenge 27.
 * Header file for Utility.cpp, providing the function declarations for the functions
 * used. This portion of the program handles the output of the BSTree through
 * standard output and is called via function pointer.
 *
 * Katherine Jouzapaitis
 * Date created: 11/23/2015
 * Date last modified: 11/23/2015
 */
 
#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Utility {
    public:
        /**
         * Logs the output of the BSTree using standard output.
         * @param int a range of integers to be passed into the function to be
         * output.
         */
        static void log (int);
};