#include "box.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

Box::Box () : boxNumber(0), boxColor("NO COLOR"), prizeCapacity(5), prizeCount(0) {
    prizes = new Prize[prizeCapacity];
    scratch = Prize();
}

Box::Box (unsigned int newBoxNumber, string newBoxColor, unsigned int newPrizeCapacity) : boxNumber(newBoxNumber), boxColor(newBoxColor), prizeCapacity(newPrizeCapacity) {
    prizes = new Prize[prizeCapacity];
    prizeCount = 0;
    scratch = Prize();
}

Box::~Box () {
    if (prizes != NULL) {
        delete [] prizes;
        prizes = NULL;
    }
}

void Box::setBoxNumber (unsigned int newBoxNumber) {
    boxNumber = newBoxNumber;
}

void Box::setBoxColor (string newBoxColor) {
    boxColor = newBoxColor;
}

unsigned int Box::getBoxNumber () const {
    return boxNumber;
}

string Box::getBoxColor () const {
    return boxColor;
}

unsigned int Box::getPrizeCapacity () const {
    return prizeCapacity;
}

unsigned int Box::getPrizeCount () const {
    return prizeCount;
}

bool Box::addPrize (Prize prize) {
    if (prizeCount >= prizeCapacity) {
        return false;
    } else {
        prizes[prizeCount] = prize;
        prizeCount++;
        return true;
    }
}

Prize& Box::getPrize (unsigned int index) {
    if (index < prizeCount) {
        return prizes[index];
    } else {
        return scratch;
    }
}

Prize Box::removePrize (unsigned int index) {
    if (prizeCount == 0 || index >= prizeCount || index < 0) {
        return scratch;
    } else {
        Prize tempPrize;
        
        tempPrize = prizes[index];
    
        rotate(prizes + index, prizes + index + 1, prizes + prizeCapacity);
        prizes[prizeCapacity - 1] = Prize();
        
        prizeCount--;
        return tempPrize;
    }
}
