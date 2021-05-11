#include "CTItem.h"
#include <string>
#include <iostream>
using namespace std;

namespace CSC234 {
	// Create empty item
	CTItem::CTItem() {
		name = "";
		price = 0;
		size = 0;
		life = 0;
	}
	// Item constructor
	CTItem::CTItem(string iname) {
		name = iname;
		price = 0;
		size = 0;
		life = noexpiration;
	}
	// Item constructor
	CTItem::CTItem(string iname, double iprice) {
		name = iname;
		price = iprice;
		size = 0;
		life = noexpiration;
	}
	// Item name, price, decimal size
	CTItem::CTItem(string iname, double iprice, double isize) {
		name = iname;
		price = iprice;
		size = isize;
		life = noexpiration;
	}
	// Item name, price, decimal life, size
	CTItem::CTItem(string iname, double iprice, double isize, double ilife) {
		name = iname;
		price = iprice;
		size = isize;
		life = isize;
	}
	// Item constructor
	CTItem::CTItem(string iname, double iprice, double isize, double ilife,
		bool isFood, bool isClothing, bool isHousehold, bool isMisc) {
		name = iname;
		price = iprice;
		size = isize;
		life = ilife;
		food = isFood;
		clothing = isClothing;
		household = isHousehold;
		misc = isMisc;
	}
	// Item constructor
	CTItem::CTItem(bool ireplenish, string iname, double iprice, double isize, double ilife,
		bool isFood, bool isClothing, bool isHousehold, bool isMisc) {
		replenish = ireplenish;
		name = iname;
		price = iprice;
		size = isize;
		life = ilife;
		food = isFood;
		clothing = isClothing;
		household = isHousehold;
		misc = isMisc;
	}
	// Item constructor
	CTItem::CTItem(bool ipound, bool ireplenish, string iname, double iprice, double isize, double ilife) {
		replenish = ireplenish;
		name = iname;
		price = iprice;
		size = isize;
		life = ilife;
		pound = ipound;
	}

	// Item maintenence
	string CTItem::getItemName() { return name; }
	double CTItem::getItemPrice() { return price; }
	double CTItem::findFullPrice() { 
		totalPrice = (price * fullSize);
		return totalPrice;
	}
	double CTItem::getItemSize() { return size; }
	void CTItem::setFullSize(double newSize) { fullSize = newSize; }
	double CTItem::findFullSize() { return fullSize; }
	double CTItem::getItemLife() { return life; }
	void CTItem::setFullLife() { fullLife = (life/size) * fullSize; }
	double CTItem::findFullLife() { setFullLife(); return fullLife; }

	// Increment an item based on player input from store
	void CTItem::buyMultiple(double newSize) {
		setFullSize(newSize);
		size = findFullSize();
		price = findFullPrice();
		life = findFullLife();
	}

	// Check item conditions
	bool CTItem::needToReplenish() { return replenish; }
	bool CTItem::isFood() { return food; }
	bool CTItem::isClothing() { return clothing; }
	bool CTItem::isHousehold() { return household; }
	bool CTItem::isMisc() { return misc; }
	bool CTItem::isByThePound() { return pound; }

	// Print an item
	void CTItem::printItem() {
		cout << getItemName() << "   ";
	}
	// Print a personal item
	void CTItem::printPersonalItem() {
		printItem();
	}
	// Print a food item
	void CTItem::printFoodItem() {
		cout << getItemName() << ", " << size;
		if (isByThePound()) cout << "lbs.";
		cout << ", enough for " << life << " days";
	}
	// Print a camp item
	void CTItem::printCampItem() {
		printItem();
	}
	// Print a clothing item
	void CTItem::printClothingItem() {
		cout << getItemName() <<", warmth " << howWarm();
	}
	// Print a store item
	void CTItem::printStoreItem() {
		if (isFood()) printFoodItem();
		else if (isClothing()) printClothingItem();
		else if (isHousehold()) printCampItem();
		else printPersonalItem();
		printf("$%3.2f", getItemPrice());
	}

	// Clothes constructor
	CTClothes::CTClothes() {
		name = "";
		price = 0;
		size = 0;
		life = noexpiration;
		summer = false;
		winter = false;
		warmth = 0;
		clothingCategory = 99;
		misc = false;
		clothing = true;
	}
	// Clothes constructor
	CTClothes::CTClothes(string cname, double cprice, double csize, bool csummer, bool cwinter, 
		double cwarmth, double ccat) {
		name = cname;
		price = cprice;
		size = csize;
		life = noexpiration;
		summer = csummer;
		winter = cwinter;
		warmth = cwarmth;
		clothingCategory = ccat;
		misc = false;
		clothing = true;
	}
	// Clothes constructor
	CTClothes::CTClothes(string cname, double cprice, double csize) {
		name = cname;
		price = cprice;
		size = csize;
		summer = true;
		winter = true;
		warmth = 1;
		life = noexpiration;
		clothingCategory = 99;
		misc = false;
		clothing = true;
	}

	// Check clothes conditions
	bool CTItem::forSummer() { return summer; }
	bool CTItem::forWinter() { return winter; }
	double CTItem::howWarm() { return warmth; }

	// Food constructor
	CTFood::CTFood() {
		name = "";
		price = 0;
		size = 0;
		howFillingNum = 0;
		foodCategory = 99;
		food = true;
		misc = false;
	}
	// Food constructor
	CTFood::CTFood(string fname, double fprice, double fsize) {
		name = fname;
		price = fprice;
		size = fsize;
		howFillingNum = 0;
		howGood = 0;
		foodCategory = 99;
		food = true;
		misc = false;
	}
	// Food constructor
	CTFood::CTFood(string fname, double fprice, double fsize, double ffill) {
		name = fname;
		price = fprice;
		size = fsize;
		howFillingNum = ffill;
		howGood = 0;
		foodCategory = 99;
		food = true;
		misc = false;
	}
	// Food constructor
	CTFood::CTFood(string fname, double fprice, double fsize, double ffill, double fhow) {
		name = fname;
		price = fprice;
		size = fsize;
		howFillingNum = ffill;
		howGood = fhow;
		food = true;
		misc = false;
	}
	// Food constructor
	CTFood::CTFood(string fname, double fprice, double fsize, double ffill, double fhow, double fcat) {
		name = fname;
		price = fprice;
		size = fsize;
		howFillingNum = ffill;
		howGood = fhow;
		foodCategory = fcat;
		food = true;
		misc = false;
	}
	// Food constructor
	CTFood::CTFood(bool ireplenish, string fname, double fprice, double fsize, double ilife, double fhow) {
		replenish = ireplenish;
		name = fname;
		price = fprice;
		size = fsize;
		life = ilife;
		howGood = fhow;
		foodCategory = 99;
		food = true;
		misc = false;
	}
	// Food constructor
	CTFood::CTFood(bool ipound,bool ireplenish, string fname, double fprice, double fsize, double ilife) {
		replenish = ireplenish;
		name = fname;
		price = fprice;
		size = fsize;
		life = ilife;
		foodCategory = 99;
		food = true;
		misc = false;
	}

	// Check food conditions
	double CTItem::howFilling() { return howFillingNum; }
	double CTItem::howGoodForYou() { return howGood; }
	double CTItem::whatKindOfFood() { return foodCategory; }
	bool CTItem::isProtein() { return protein; }
	bool CTItem::isCarb() { return carb; }
	bool CTItem::isFruitVeg() { return fruitVeg; }

	// Food protein constructor
	CTProtein::CTProtein() {
		name = "";
		price = 0.0;
		size = 0.0;
		life = 0.0;
		food = true;
		protein = true;
		misc = false;
	}
	// Food protein constructor
	CTProtein::CTProtein(bool ipound, string iname, double iprice, double isize, double ilife) {
		name = iname;
		price = iprice;
		size = isize;
		life = ilife;
		pound = ipound;
		food = true;
		protein = true;
		misc = false;
	}
	// Food fruit/veg constructor
	CTFruitVeg::CTFruitVeg() {
		name = "";
		price = 0.0;
		size = 0.0;
		life = 0.0;
		food = true;
		fruitVeg = true;
		misc = false;
	}
	// Food fruit/veg constructor
	CTFruitVeg::CTFruitVeg(bool ipound, string iname, double iprice, double isize, double ilife) {
		name = iname;
		price = iprice;
		size = isize;
		life = ilife;
		pound = ipound;
		food = true;
		fruitVeg = true;
		misc = false;
	}
	// Food carb constructor
	CTCarb::CTCarb() {
		name = "";
		price = 0.0;
		size = 0.0;
		life = 0.0;
		food = true;
		carb = true;
		misc = false;
	}
	// Food carb constructor
	CTCarb::CTCarb(bool ipound, bool ireplenish, string iname, double iprice, double isize, double ilife) {
		replenish = ireplenish;
		name = iname;
		price = iprice;
		size = isize;
		life = ilife;
		pound = ipound;
		food = true;
		carb = true;
		misc = false;
	}

	// Hunting items constructor
	CTHuntItems::CTHuntItems() {
		name = "";
		price = 0.0;
		size = 0.0;
		life = 0.0;
		hunting = true;
		misc = false;
	}
	// Hunting items constructor
	CTHuntItems::CTHuntItems(string iname, double iprice, double isize, double ilife,
		bool isFood, bool isClothing, bool isHousehold, bool isMisc) {
		name = iname;
		price = iprice;
		size = isize;
		life = ilife;
		food = isFood;
		clothing = isClothing;
		household = isHousehold;
		misc = isMisc;
		hunting = true;
		misc = false;
	}
	// Hunting items constructor
	CTHuntItems::CTHuntItems(string iname, double iprice, double isize, double ilife) {
		name = iname;
		price = iprice;
		size = isize;
		life = ilife; 
		hunting = true;
		misc = false;
	}
	// Hunting items constructor
	CTHuntItems::CTHuntItems(bool ipound, string iname, double iprice, double isize, double ilife) {
		name = iname;
		price = iprice;
		size = isize;
		life = ilife;
		pound = ipound;
		hunting = true;
		misc = false;
	}

	// Hunting actions
	int CTHuntItems::makeBullets() { return 0; }
	bool CTItem::isHunting() { return hunting; }

	// Making bullets
	CTBullets::CTBullets() { numberOfBullets = 0; }
	CTBullets::CTBullets(int bullets) { numberOfBullets = bullets; }
	void CTBullets::fireShots(int shots) { numberOfBullets = numberOfBullets - shots; }
	void CTBullets::stockBullets(int bullets) { numberOfBullets = numberOfBullets + bullets; }

	// Wild game constructor
	CTWildGame::CTWildGame() {
		name = "";
		price = 0.0;
		size = 0.0;
		life = 0.0;
		food = true;
		protein = true;
		misc = false;
		animalPrice = price * size;
	}
	// Wild game constructor
	CTWildGame::CTWildGame(string iname, double ilife) {
		name = iname;
		price = 0.0;
		size = 0.0;
		life = ilife;
		food = true;
		protein = true;
		misc = false;
		animalPrice = price * size;
	}
	// Wild game constructor
	CTWildGame::CTWildGame(string iname, double isize, double ilife) {
		name = iname;
		price = 0.0;
		size = isize;
		life = ilife;
		food = true;
		protein = true;
		misc = false;
		animalPrice = price * size;
	}
	// Wild game constructor
	CTWildGame::CTWildGame(string iname, double iprice, double isize, double ilife) {
		name = iname;
		price = iprice;
		size = isize;
		life = ilife;
		food = true;
		protein = true;
		misc = false;
		animalPrice = price * size;
	}
	// Wild game constructor
	CTWildGame::CTWildGame(bool ipound, string iname, double iprice, double isize, double ilife) {
		name = iname;
		price = iprice;
		size = isize;
		life = ilife;
		food = true;
		protein = true;
		misc = false;
		pound = ipound;
		animalPrice = price * size;
	}
	// Get the price for animal hunted
	double CTWildGame::getGamePrice() { return animalPrice; }

	// Household items constructor
	CTHousehold::CTHousehold() {
		name = "";
		price = 0.0;
		size = 0.0;
		life = 0.0;
		household = true; 
		misc = false;
	}
	// Household items constructor
	CTHousehold::CTHousehold(string iname, double iprice) {
		name = iname;
		price = iprice;
		size = 0.0;
		life = 999.9;
		household = true;
		misc = false;
	}
}
