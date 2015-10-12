/*
 * boxprizetest.h for Programming Project 2
 * This file contains the definitions for the functions utilized in
 * boxprizetest.cpp for the interactive portion of testing the prize and
 * box classes.
 *
 * Katherine Jouzapaitis
 * Date created: 10/12/2015
 * Date last modified: 10/12/2015
 */

/**
 * The main menu allowing the user to go to menus to run an interactive test
 * for the prize and box classes, or run an automated unit test.
 */
void mainMenu ();

/**
 * The menu giving options to test various components of the box class. The
 * user can add, view, and remove prizes. The box's color and number can be
 * changed. The user can also view the capacity of the box and the number of
 * prizes currently in the box.
 */
void boxMenu ();

/**
 * The menu giving options to test components of the prize class. The user can
 * change the name and value of the prize. The user is also able to compare
 * two prizes by entering in the names and values of the two prizes.
 */
void prizeMenu ();

/**
 * Pauses the program, requiring enter to be pressed to continue. This function
 * clears the screen before the next function is executed.
 */
void pause ();