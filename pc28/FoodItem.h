/*
 * FoodItem.h for Programming Challenge 28
 * FoodItem class derived from the Item class. Allows for the construction, destruction, and manipulation
 * of a food item. Also handles the output of the details of the food item in a string.
 *
 * Katherine Jouzapaitis
 * Date created: 12/1/2015
 * Date last modified: 12/2/2015
 */
#pragma once
#include "Item.h"
#include <iomanip>

class FoodItem : public Item {
    public:
        
        /**
         * Constructor for the FoodItem.
         * Allows for overloading, but has default values for all details.
         * @param newName a string defaulted to "fooditem", can be overloaded to any string
         * desired as the name of a new food item. (Inherited from Item class)
         * @param newValue an unsigned int defaulted to 0, can be overloaded to any
         * value in range as the new value of a new food item. (Inherited from the Item class)
         * @param newCalories an unsigned int defaulted to 0, can be overloaded to any
         * value in range as the new calorie value for a new food item.
         * @param newUnitsOfMeasure a string defaulted to "nounits", can be overloaded to any
         * string desired as the description of the units of measure for a new food item.
         * @param units a float defaulted to 0, can be overloaded to any value in range
         * as the units of a new food item.
         */
        FoodItem (string newName = "fooditem", unsigned int newValue = 0, unsigned int newCalories = 0, string newUnitOfMeasure = "nounits", float newUnits = 0);
        
        /**
         * Destructor.
         */
        virtual ~FoodItem ();
        
        /**
         * Sets the calorie value of an already created food item.
         * @param newCalories an unsigned int containing the value within range to be
         * the new calorie count for a food item.
         */
        void setCalories (unsigned int newCalories);
        
        /**
         * Sets the unit of measure of an already created food item.
         * @param newMeasure a string containing the description of the unit of measure
         * for a food item.
         */
        void setUnitOfMeasure (string newMeasure);
        
        /**
         * Sets the units of an already created food item.
         * @param newUnits a float containing the value within range to be the new units
         * of a food item.
         */
        void setUnits (float newUnits);
        
        /**
         * Gets the calorie count of a food item.
         * @return an unsigned int containing the value of the calories of a food item.
         */
        unsigned int getCalories ();
        
        /**
         * Gets the units of measure of a food item.
         * @return a string containing the description of the unit of measure of a food item.
         */
        string getUnitOfMeasure ();
        
        /**
         * Gets the units of a food item.
         * @return a float containing the value of the units of a food item.
         */
        float getUnits ();
        
        /**
         * Puts all the details of a food item into a string for output.
         * @return a string containing the details of a food item in the format of
         * NAME, $VALUE, UNITS UNITOFMEASURE, CALORIES calories. UNITS will display 
         * to the hundreths decimal place.
         */
        string toString ();
        
    private:
        
        unsigned int calories;
        string unitOfMeasure;
        float units;
};