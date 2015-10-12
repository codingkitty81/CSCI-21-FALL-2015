/*
 * Programming Project 2
 * This program is designed to give the user the choice to test two classes, box
 * and prize, either through interactive or automated means. CinReader is
 * utilized to handle the user's input and expections that might occur.
 * 
 * Katherine Jouzapaitis
 * Date created: 9/27/2015
 * Date last modified: 10/11/2015
 */
#include "box.h"
#include "prize.h"
#include "CinReader.h"
#include <cstdlib>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

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

/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest ();


int main (int argc, char* argv[]) {
	
    // CODE HERE -- INTERACTIVE TEST
    //
    // add additional functions as needed to support interactive test
	mainMenu ();
	
    return 0;
}

void mainMenu () {
    CinReader reader;
    while (true) {
        cout << "MAIN MENU\n" << endl;
        cout << "[1] Box    -- interactive test" << endl;
        cout << "[2] Prize  -- interactive test" << endl;
        cout << "[3] Run official unit test" << endl;
        cout << "[0] Quit" << endl;
        cout << "Your choice: ";
        
        switch (reader.readInt(0,3)) {
            case 0:
                exit(1);
                break;
            case 1:
                boxMenu();
                break;
            case 2:
                prizeMenu();
                break;
            case 3:
                unittest();
                pause ();
                break;
        }
    }
}

void boxMenu () {
    Box box1;
    CinReader reader;
    string newName = "";
    unsigned int newValue = 0;
    unsigned int prizeRemove = 0;
    
    theBoxMenu:
    system("clear");
    cout << "BOX TEST\n" << endl;
    cout << "Box info -> " << box1.getBoxNumber() << ", " << box1.getBoxColor() << endl;
    cout << "[1] Add prize" << endl;
    cout << "[2] View prizes" << endl;
    cout << "[3] Remove prize" << endl;
    cout << "[4] Change Box number" << endl;
    cout << "[5] Change Box color" << endl;
    cout << "[6] View prize capacity" << endl;
    cout << "[7] View prize count" << endl;
    cout << "[0] Back to main menu" << endl;
    cout << "Your choice: ";
    
    switch (reader.readInt(0,7)) {
        case 0:
            system("clear");
            box1.~Box();
            mainMenu ();
            break;
        case 1:
            system("clear");
            cout << "New prize name (current = NO NAME): ";
                newName = reader.readString();
            cout << "New prize value (current = 0): ";
                newValue = reader.readInt();
                
            if (box1.getPrizeCount() < box1.getPrizeCapacity()) {
                box1.addPrize(Prize (newName, newValue));
            } else {
                cout << "Your prize could not be added." << endl;
            }
            
            pause ();
            goto theBoxMenu;
            break;
        case 2:
            system("clear");
            
            if (box1.getPrizeCount() == 0){
                cout << '\n';
            } else {
               for (unsigned int i = 0; i < box1.getPrizeCount(); i++) {
                   cout << i + 1 << ": " << box1.getPrize(i).getPrizeName() << endl;
               } 
            }
            
            pause ();
            goto theBoxMenu;
            break;
        case 3:
            system("clear");
            
            if (box1.getPrizeCount() == 0){
                cout << '\n';
            } else {
               for (unsigned int i = 0; i < box1.getPrizeCount(); i++) {
                   cout << i + 1 << ": " << box1.getPrize(i).getPrizeName() << endl;
               } 
            }
            
            cout << "Remove which prize (0 to cancel)? ";
                prizeRemove = reader.readInt(0, box1.getPrizeCount());
            
                if (prizeRemove == 0) {
                    system("clear");
                    goto theBoxMenu;
                } else {
                    box1.removePrize(prizeRemove - 1);
                    cout << "Prize number " << prizeRemove << " removed." << endl;
                    pause ();
                    goto theBoxMenu;
                }
                break;
        case 4:
            system("clear");
            cout << "Current number is: " << box1.getBoxNumber() << endl;
            cout << "\nEnter in a new number: ";
                box1.setBoxNumber(reader.readInt());
            cout << "\nNew box number is: " << box1.getBoxNumber() << endl;
            pause ();
            goto theBoxMenu;
            break;
        case 5:
            system("clear");
            cout << "Current color is: " << box1.getBoxColor() << endl;
            cout << "\nEnter in a new color: ";
                box1.setBoxColor(reader.readString());
            cout << "\nNew box color is: " << box1.getBoxColor() << endl;
            pause ();
            goto theBoxMenu;
            break;
        case 6:
            system("clear");
            cout << "Current prize capacity: " << box1.getPrizeCapacity() << endl;
            pause ();
            goto theBoxMenu;
            break;
        case 7:
            system("clear");
            cout << "Current prize count: " << box1.getPrizeCount() << endl;
            pause ();
            goto theBoxMenu;
            break;
    }
}

void prizeMenu () {
    Prize prize1;
    Prize prize2;
    CinReader reader;
    string p1Name;
    unsigned int p1Value = 0;
    string p2Name;
    unsigned int p2Value = 0;
    
    thePrizeMenu:
    system("clear");
    cout << "PRIZE TEST\n" << endl;
    cout << "Prize info -> " << prize1.getPrizeName() << ", $" << prize1.getPrizeValue() << endl;
    cout << "[1] Prize name" << endl;
    cout << "[2] Prize value" << endl;
    cout << "[3] Compare two prizes" << endl;
    cout << "[0] Back to main menu" << endl;
    cout << "Your choice: ";
    
    switch (reader.readInt(0,3)) {
        case 0:
            system("clear");
            prize1.~Prize();
            mainMenu ();
            break;
        case 1:
            system("clear");
            cout << "Prize name: " << prize1.getPrizeName() << endl;
            cout << "\nUpdate (y/n)? ";
            
            if (reader.readChar("yn") == 'y') {
                cout << "Enter new prize name: ";
                    prize1.setPrizeName(reader.readString());
                cout << "\nPrize name updated." << endl;
            }
            
            pause ();
            goto thePrizeMenu;
            break;
        case 2:
            system("clear");
            cout << "Prize value: " << prize1.getPrizeValue() << endl;
            cout << "\nUpdate (y/n)? ";
            
            if (reader.readChar("yn") == 'y') {
                cout << "Enter new prize value: ";
                    prize1.setPrizeValue(reader.readInt());
                cout << "\nPrize value updated." << endl;
            }
            
            pause ();
            goto thePrizeMenu;
            break;
        case 3:
            system("clear");
            cout << "First, set the Name and Value of the prizes being compared.\n" << endl;
            cout << "Prize 1 ->" << endl;
            cout << "Prize name (current = NO NAME): ";
                p1Name = reader.readString();
            cout << "Prize value (current = 0): ";
                p1Value = reader.readInt();
            cout << "\nPrize 2 ->" << endl;
            cout << "Prize name (current = NO NAME): ";
                p2Name = reader.readString();
            cout << "Prize value (current = 0): ";
                p2Value = reader.readInt();
              
            Prize prize1(p1Name, p1Value); 
            Prize prize2(p2Name, p2Value);
            if (prize1 == prize2) {
                cout << "Yes. The two prizes are the same." << endl;
            } else {
                cout << "No. The two prizes are not the same." << endl;
            }
        
            pause ();
            goto thePrizeMenu;
            break;
    }
}

void pause () {
    cout << "\nPress enter to continue...";
                cin.get();
    system("clear");
}
/*
 * Unit testing functionb1. Do not alter.
 */

void unittest () {

    unsigned short utCount = 35;
    unsigned short utPassed = 0;

    cout << "\nSTARTING UNIT TEST\n\n";
	
    Box b1;
    Box b2(42, "blue", 3);
	
    cout << "** TESTING DEFAULT BOX **\n\n";
	
    try {
        btassert<bool>(b1.getBoxNumber() == 0);
        cout << "Passed TEST 1: Box getBoxNumber()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 1 Box getBoxNumber() #\n";
    }
	
    try {
        btassert<bool>(b1.getBoxColor() == "NO COLOR");
        cout << "Passed TEST 2: Box getBoxColor()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 2 Box getBoxColor() #\n";
    }
    
    try {
        btassert<bool>(b1.getPrizeCapacity() == 5);
        cout << "Passed TEST 3: Box getPrizeCapacity()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 3 Box getPrizeCapacity() #\n";
    }
	
    try {
        btassert<bool>(b1.getPrizeCount() == 0);
        cout << "Passed TEST 4: Box getPrizeCount()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 4 Box getPrizeCount() #\n";
    }
	
    b1.setBoxNumber(99);
    try {
        btassert<bool>(b1.getBoxNumber() == 99);
        cout << "Passed TEST 5: Box setBoxNumber()/getBoxNumber()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 5 Box setBoxNumber()/getBoxNumber() #\n";
    }
	
    b1.setBoxColor("red");
    try {
        btassert<bool>(b1.getBoxColor() == "red");
        cout << "Passed TEST 6: Box setBoxColor()/getBoxColor()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 6 Box setBoxColor()/getBoxColor() #\n";
    }
    
    cout << "\n** TESTING CUSTOM BOX **\n\n";
	
    try {
        btassert<bool>(b2.getBoxNumber() == 42);
        cout << "Passed TEST 7: Box getBoxNumber()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 7 Box getBoxNumber() #\n";
    }
	
    try {
        btassert<bool>(b2.getBoxColor() == "blue");
        cout << "Passed TEST 8: Box getBoxColor()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 8 Box getBoxColor() #\n";
    }
    
    try {
        btassert<bool>(b2.getPrizeCapacity() == 3);
        cout << "Passed TEST 9: Box getPrizeCapacity()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 9 Box getPrizeCapacity() #\n";
    }
	
    try {
        btassert<bool>(b2.getPrizeCount() == 0);
        cout << "Passed TEST 10: Box getPrizeCount()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 10 Box getPrizeCount() #\n";
    }
	
    try {
        btassert<bool>(b2.getPrize(0) == Prize());
        cout << "Passed TEST 11: Box getPrize(0)\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 11 Box getPrize(0) #\n";
    }
	
    try {
        btassert<bool>(b2.removePrize(0) == Prize());
        cout << "Passed TEST 12: Box removePrize(0)\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 12 Box removePrize(0) #\n";
    }
    
    b2.addPrize(Prize("BRONZE PRIZE", 1));
    try {
        btassert<bool>(b2.getPrizeCount() == 1);
        cout << "Passed TEST 13: Box addPrize()/getPrizeCount()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 13 Box addPrize()/getPrizeCount() #\n";
    }
    
    b2.addPrize(Prize("SILVER PRIZE", 100));
    try {
        btassert<bool>(b2.getPrizeCount() == 2);
        cout << "Passed TEST 14: Box addPrize()/getPrizeCount()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 14 Box addPrize()/getPrizeCount() #\n";
    }
        
    b2.addPrize(Prize("GOLD PRIZE", 1000));
    try {
        btassert<bool>(b2.getPrizeCount() == 3);
        cout << "Passed TEST 15: Box addPrize()/getPrizeCount()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 15 Box addPrize()/getPrizeCount() #\n";
    }
    
    try {
        btassert<bool>(b2.addPrize(Prize("DIAMOND PRIZE", 999)) == false);
        cout << "Passed TEST 16: Box addPrize(ARRAY FULL)\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 16 Box addPrize(ARRAY FULL) #\n";
    }
	
    try {
        btassert<bool>(b2.getPrize(1) == Prize("SILVER PRIZE", 100));
        cout << "Passed TEST 17: Box getPrize(1)\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 17 Box getPrize(1) #\n";
    }
	
    try {
        btassert<bool>(b2.removePrize(2) == Prize("GOLD PRIZE", 1000));
        cout << "Passed TEST 18: Box removePrize(2)\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 18 Box removePrize(2) #\n";
    }
    
    try {
        btassert<bool>(b2.getPrizeCount() == 2);
        cout << "Passed TEST 19: Box getPrizeCount()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 19 Box getPrizeCount() #\n";
    }
	
    try {
        btassert<bool>(b2.removePrize(2) == Prize());
        cout << "Passed TEST 20: Box removeCargo(2)\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 20 Box removeCargo(2) #\n";
    }
	
    try {
        btassert<bool>(b2.getPrize(2) == Prize());
        cout << "Passed TEST 21: Box getPrize(2)\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 21 Box getPrize(2) #\n";
    }
	
    try {
        btassert<bool>(b2.addPrize(Prize("RUBY PRIZE", 9999)) == true);
        cout << "Passed TEST 22: Box addPrize(\"RUBY PRIZE\", 9999)\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 22 Box addPrize(\"RUBY PRIZE\", 9999) #\n";
    }
    
    try {
        btassert<bool>(b2.getPrizeCount() == 3);
        cout << "Passed TEST 23: Box getPrizeCount()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 23 Box getPrizeCount() #\n";
    }
	
    try {
        btassert<bool>(b2.getPrizeCapacity() == 3);
        cout << "Passed TEST 24: Box getPrizeCapacity()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 24 Box getPrizeCapacity() #\n";
    }
	
    cout << "\n** TESTING PRIZE **\n\n";
	
    Prize p1;
	
    try {
        btassert<bool>(p1.getPrizeName() == "NO NAME");
        cout << "Passed TEST 25: Prize getPrizeName()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 25 Prize getPrizeName() #\n";
    }
	
    try {
        btassert<bool>(p1.getPrizeValue() == 0);
        cout << "Passed TEST 26: Prize getPrizeValue()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 26 Prize getPrizeValue() #\n";
    }
	
    p1.setPrizeName("FOOD PRIZE");
    try {
        btassert<bool>(p1.getPrizeName() == "FOOD PRIZE");
        cout << "Passed TEST 27: Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 27 Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName() #\n";
    }
	
    p1.setPrizeValue(17);
    try {
        btassert<bool>(p1.getPrizeValue() == 17);
        cout << "Passed TEST 28: Prize setPrizeValue(17)/getPrizeValue()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 28 Prize setPrizeValue(17)/getPrizeValue() #\n";
    }
	
    Prize p2("HAT PRIZE", 50);
	
    try {
        btassert<bool>(p2.getPrizeName() == "HAT PRIZE");
        cout << "Passed TEST 29: Prize getPrizeName()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 29 Prize getPrizeName() #\n";
    }
	
    try {
        btassert<bool>(p2.getPrizeValue() == 50);
        cout << "Passed TEST 30: Prize getPrizeValue()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 30 Prize getPrizeValue() #\n";
    }
    
    try {
        btassert<bool>(!(p1 == p2));
        cout << "Passed TEST 31: !(Prize == Prize)\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 31 !(Prize == Prize) #\n";
    }
    
    p2.setPrizeName("FOOD PRIZE");
    try {
        btassert<bool>(p2.getPrizeName() == "FOOD PRIZE");
        cout << "Passed TEST 32: Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 32 Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName() #\n";
    }
	
    p2.setPrizeValue(17);
    try {
        btassert<bool>(p2.getPrizeValue() == 17);
        cout << "Passed TEST 33: Prize setPrizeValue(17)/getPrizeValue()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 33 Prize setPrizeValue(17)/getPrizeValue() #\n";
    }
    
    try {
        btassert<bool>(p1 == p2);
        cout << "Passed TEST 34: (Prize == Prize)\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 34 (Prize == Prize) #\n";
    }
    
    p2.setPrizeValue(1);
    try {
        btassert<bool>(!(p1 == p2));
        cout << "Passed TEST 35: !(Prize == Prize)\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 35 !(Prize == Prize) #\n";
    }
	
    cout << "\nUNIT TEST COMPLETE\n\n";
    
    cout << "PASSED " << utPassed << " OF " << utCount << " UNIT TEST";
    if (utCount > 1) {
        cout << "S";
    }
    cout << "\n\n";
}

template <typename X, typename A>
void btassert (A assertion) {
    if (!assertion)
        throw X();
}
