#include "prize.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


Prize::Prize () : prizeName("NO NAME"), prizeValue(0) {
    
}

Prize::Prize (string newPrizeName, unsigned int newPrizeValue) : prizeName(newPrizeName), prizeValue(newPrizeValue) {
    
}

Prize::~Prize () {
    
}

bool operator == (Prize p1, Prize p2) {
    return ((p1.prizeName == p2.prizeName) && (p1.prizeValue == p2.prizeValue));
}

void Prize::setPrizeName (string newPrizeName) {
    prizeName = newPrizeName;
}

void Prize::setPrizeValue (unsigned int newPrizeValue) {
    prizeValue = newPrizeValue;
}

string Prize::getPrizeName () const {
    return prizeName;
}

unsigned int Prize::getPrizeValue () const {
    return prizeValue;
}