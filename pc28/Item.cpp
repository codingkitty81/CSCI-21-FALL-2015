
#include "Item.h"

Item::Item(string newName, unsigned int newValue) : name(newName), value(newValue) {}

Item::~Item() {}

void Item::setName(string newName) {
    name = newName;
}

void Item::setValue(unsigned int newValue) {
    value = newValue;
}

string Item::getName() {
    return name;
}

unsigned int Item::getValue() {
    return value;
}

string Item::toString() {
    stringstream outStream;
    outStream << name << ", $" << value;
    return outStream.str();
}