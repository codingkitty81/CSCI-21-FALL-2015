/*
 * Programming Challenge 28
 */
#define CATCH_CONFIG_MAIN
//#include "../catch.hpp"
#include "catch.hpp"
#include "Item.h"
#include "FoodItem.h"
#include "MagicItem.h"

TEST_CASE ("Item/FoodItem/MagicItem class functionality") {
	SECTION("Item, default constructor") {
		Item item;
		CHECK(item.getName() == "item");
		CHECK(item.getValue() == 0);
		CHECK(item.toString() == "item, $0");

		item.setName("car");
		item.setValue(35000);
		CHECK(item.getName() == "car");
		CHECK(item.getValue() == 35000);
		CHECK(item.toString() == "car, $35000");		
	}

	SECTION("Item, overloaded constructor") {
		Item mItem("game", 25);
		CHECK(mItem.toString() == "game, $25");
	}

	SECTION("FoodItem, default constructor") {
		FoodItem foodItem;
		CHECK(foodItem.getName() == "fooditem");
		CHECK(foodItem.getValue() == 0);
		CHECK(foodItem.toString() == "fooditem, $0, 0.00 nounits, 0 calories");
		CHECK(foodItem.getUnitOfMeasure() == "nounits");
		CHECK(foodItem.getCalories() == 0);
		CHECK(foodItem.getUnits() == 0);

		foodItem.setName("cupcake");
		foodItem.setValue(5);
		foodItem.setUnitOfMeasure("cake(s)");
		foodItem.setUnits(1.5);
		foodItem.setCalories(200);
		CHECK(foodItem.getName() == "cupcake");
		CHECK(foodItem.getValue() == 5);
		CHECK(foodItem.toString() == "cupcake, $5, 1.50 cake(s), 200 calories");
		CHECK(foodItem.getUnitOfMeasure() == "cake(s)");
		CHECK(foodItem.getCalories() == 200);
		CHECK(foodItem.getUnits() == 1.5);
	}

	SECTION("FoodItem, overloaded constructor") {
		FoodItem mFoodItem("coffee", 1, 10, "ounces", 10.25);
		CHECK(mFoodItem.toString() == "coffee, $1, 10.25 ounces, 10 calories");
	}

	SECTION("MagicItem, default constructor") {
		MagicItem magicItem;
		CHECK(magicItem.getDescription() == "no description");
		CHECK(magicItem.getManaRequired() == 0);

		magicItem.setName("wand");
		magicItem.setValue(1000);
		magicItem.setDescription("jewel-encrusted");
		magicItem.setManaRequired(50);
		CHECK(magicItem.getName() == "wand");
		CHECK(magicItem.getValue());
		CHECK(magicItem.getDescription() == "jewel-encrusted");
		CHECK(magicItem.getManaRequired() == 50);
		CHECK(magicItem.toString() == "wand, $1000, jewel-encrusted, requires 50 mana");
	}

	SECTION("MagicItem, overloaded constructor") {
		MagicItem mMagicItem("staff", 999, "carved wood", 125);
		CHECK(mMagicItem.toString() == "staff, $999, carved wood, requires 125 mana");
	}
}
