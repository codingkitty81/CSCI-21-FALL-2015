
#include "FoodItem.h"

FoodItem::FoodItem (string newName, unsigned int newValue, unsigned int newCalories, string newUnitOfMeasure, float newUnits) : Item (newName, newValue), calories(newCalories), unitOfMeasure(newUnitOfMeasure), units(newUnits) {}

FoodItem::~FoodItem () {}

void FoodItem::setCalories (unsigned int newCalories) {
    calories = newCalories;
}

void FoodItem::setUnitOfMeasure (string newMeasure) {
    unitOfMeasure = newMeasure;
}

void FoodItem::setUnits (float newUnits) {
    units = newUnits;
}

unsigned int FoodItem::getCalories () {
    return calories;
}

string FoodItem::getUnitOfMeasure () {
    return unitOfMeasure;
}

float FoodItem::getUnits () {
    return units;
}

string FoodItem::toString () {
    stringstream outStream;
    outStream.precision(2);
    outStream << Item::toString() << ", " << fixed << units << " " << unitOfMeasure << ", " << calories << " calories";
    return outStream.str();
    
}