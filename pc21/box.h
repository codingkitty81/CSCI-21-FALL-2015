/*
 * Programming Challenge 21 - template header
 * This is a template for a Box class which will allow for overloaded construction
 * of a box, the getting and setting of the contents of a box, and the ability
 * to put the contents into an ostream.
 *
 * Katherine Jouzapaitis
 * Date created: 10/29/2015
 * Date last modified: 10/29/2015
 *
 * Resources:
 * http://en.cppreference.com/w/cpp/language/operators
 * http://www.learncpp.com/cpp-tutorial/143-template-classes/
 * http://www.learncpp.com/cpp-tutorial/93-overloading-the-io-operators/
 */
 
#pragma once
#include <iostream>
using namespace std;

template <typename stuff>
class Box {
    public:
        
        /**
         * Overloaded Constructor.
         * @param newContents of whatever type is defined by the template
         * containing the contents to be placed in the box.
         */
        Box (stuff newContents) {
            contents = newContents;
        };
        
        /**
         * Gets the contents of the box.
         * @return whatever type defined by the template, the contents of the box.
         */
        stuff& getContents () {
            return contents;
        };
        
        /**
         * Sets the contents of the box.
         * @param newContents of whatever type is defined by the template
         * containing the new contents for the box.
         */
        void setContents (stuff newContents) {
            contents = newContents;
        };
        
        /**
         * Friend ostream operator to handle the output of the contents of the box.
         * @param outs an address pointing to the ostream object.
         * @param newBox an address pointing to the contents of the box to be
         * fed into the ostream for output.
         */
        friend ostream& operator<< (ostream& outs, const Box& newBox) {
            outs << newBox.contents;
            return outs;
        };
        
    private:
        stuff contents;
};

