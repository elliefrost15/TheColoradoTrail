#include <iostream>
#include <time.h>
#include "CTInventory.h"
#include "CTFunctions.h"
#include "CTItem.h"
#include <Windows.h>
using namespace std;

namespace CSC234 {

	// Default constructor
	CTInventory::CTInventory() { inventory = { new CTItem() }; }

	// Constructor to make a generalInventory
	CTInventory::CTInventory(string inventoryName, int size) {
		if (inventoryName == "makeGeneralInventory")
			setGeneralInventory(size);
		else inventory = { new CTItem() };
		setVectorSize(size);
	}

	// Make an inventory based on a vector input
	CTInventory::CTInventory(vector<CTItem*> newstuff) {
		vectorSize = 0;
		for (int i = 0; i < newstuff.size(); i++) {
			inventory.push_back(newstuff.at(i));
			vectorSize++;
		}
		setVectorSize(vectorSize);
	}
	
	// Create inventory with vector and max size
	CTInventory::CTInventory(vector<CTItem*> stuff, int maxSize) { 
		inventory = stuff; 
		setVectorSize(maxSize);
	}
	
	// Inventory maintenance 
	void CTInventory::setVectorSize(int count) { vectorSize = count; }
	int CTInventory::getVectorSize() { return vectorSize; }
	void CTInventory::setInventory(vector<CTItem*> stuff) { inventory = stuff; }
	void CTInventory::addItem(CTItem* item) { inventory.push_back(item); }
	void CTInventory::removeItem(int index) { inventory.erase(inventory.begin() + index); }
	void CTInventory::clearInventory() { inventory.clear(); }
	CTItem* CTInventory::getItem(int index) { return inventory.at(index); }
	int CTInventory::size() { return (int)inventory.size(); }

	// Search for an item
	int CTInventory::findItem(CTItem* item) { 
		for (int i = 0; i < inventory.size(); i++) {
			if (inventory.at(i) = item) {
				return i; 
				break;
			}
		}
		return 101;
	}

	// Print the contents of an inventory
	void CTInventory::printList() {
		if (getVectorSize() == 0) cout << "No items in this inventory.";
		else {
			for (int i = 0; i < inventory.size(); i++) {
				CTItem* temp = inventory.at(i);
				temp->printItem();
				if (i % 3 == 0) cout << endl;
			}
		}
		cout << endl;
	}

	// Print the contents of a personal inventory
	void CTInventory::printPersonalInventory() {
		if (getVectorSize() == 0) cout << "No items in your inventory.";
		for (int i = 0; i < inventory.size(); i++) {
			inventory.at(i)->printPersonalItem();
			cout << " ";
			if (i % 3 == 0) cout << endl;
		}
		cout << endl;
	}

	// Print the contents of a camp inventory
	void CTInventory::printCampInventory() {
		if (getVectorSize() == 0) cout << "No items in your camp inventory.";
		else {
			for (int i = 0; i < inventory.size(); i++) {
				inventory.at(i)->printCampItem();
				cout << " ";
				if (i % 3 == 0) cout << endl;
			}
		}
		cout << endl;
	}

	// Print the contents of a food inventory
	void CTInventory::printFoodInventory() {
		if (getVectorSize() == 0) cout << "No food items in your inventory.";
		else {
			for (int i = 0; i < inventory.size(); i++) {
				inventory.at(i)->printFoodItem();
				cout << " ";
				if (i % 3 == 0) cout << endl;
			}
		}
		cout << endl;
	}

	// Print a store's contents
	vector<vector<CTItem*>> CTInventory::printStoreInventory() {
		vector<CTItem*> misc = {};
		vector<CTItem*> household = {};
		vector<CTItem*> clothing = {};
		vector<CTItem*> miscfood = {};
		vector<CTItem*> proteins = {};
		vector<CTItem*> carbs = {};
		vector<CTItem*> fruitveg = {};

		CTItem* temp;

		for (int i = 0; i < inventory.size(); i++) {
			temp = inventory.at(i);
			if (temp->isClothing()) clothing.push_back(temp);
			else if (temp->isHousehold()) household.push_back(temp);
			else if (temp->isProtein()) proteins.push_back(temp);
			else if (temp->isCarb()) carbs.push_back(temp);
			else if (temp->isFruitVeg()) fruitveg.push_back(temp);
			else if (temp->isFood()) miscfood.push_back(temp);
			else misc.push_back(temp);
		}
		vector<vector<CTItem*>> storeInventory = { misc, household, clothing,
			miscfood, proteins, carbs, fruitveg };
		if (misc.size() > 0) {
			cout << "_________________________________________________________" << endl;
			cout << "          [1] MISCELLANEOUS ITEMS FOR PURCHASE" << endl;
			cout << "_________________________________________________________" << endl;
			for (int i = 0; i < misc.size(); i++) {
				cout << "[" << i+1 << "] ";
				misc.at(i)->printItem();
				printf("   $%3.2f", misc.at(i)->getItemPrice());
				cout << endl;
				Sleep(200);
			}
			cout << endl;
		}
		if (household.size() > 0) {
			cout << "_________________________________________________________" << endl;
			cout << "             [2] HOUSEHOLD ITEMS FOR PURCHASE" << endl;
			cout << "_________________________________________________________" << endl;
			for (int i = 0; i < household.size(); i++) {
				cout << "[" << i + 1 << "] ";
				household.at(i)->printCampItem();
				printf("   $%3.2f", household.at(i)->getItemPrice());
				cout << endl;
				Sleep(200);
			}
			cout << endl;
		}
		if (clothing.size() > 0) {
			cout << "_________________________________________________________" << endl;
			cout << "             [3] CLOTHING ITEMS FOR PURCHASE" << endl;
			cout << "_________________________________________________________" << endl;
			for (int i = 0; i < clothing.size(); i++) {
				cout << "[" << i + 1 << "] ";
				clothing.at(i)->printClothingItem();
				printf("   $%3.2f", clothing.at(i)->getItemPrice());
				cout << endl;
				Sleep(200);
			}
			cout << endl;
		}
		if (miscfood.size() > 0) {
			cout << "_________________________________________________________" << endl;
			cout << "               [4] FOOD ITEMS FOR PURCHASE" << endl;
			cout << "_________________________________________________________" << endl;
			for (int i = 0; i < miscfood.size(); i++) {
				cout << "[" << i + 1 << "] ";
				miscfood.at(i)->printFoodItem();
				printf("   $%3.2f", miscfood.at(i)->getItemPrice());
				cout << endl;
				Sleep(200);
			}
			cout << endl;
		}
		if (proteins.size() > 0) {
			cout << "_________________________________________________________" << endl;
			cout << "                     [5] PROTEINS" << endl;
			cout << "_________________________________________________________" << endl;
			for (int i = 0; i < proteins.size(); i++) {
				cout << "[" << i + 1 << "] ";
				proteins.at(i)->printFoodItem();
				printf("   $%3.2f", proteins.at(i)->getItemPrice());
				cout << endl;
				Sleep(200);
			}
			cout << endl;
		}
		if (carbs.size() > 0) {
			cout << "_________________________________________________________" << endl;
			cout << "                      [6] CARBS" << endl;
			cout << "_________________________________________________________" << endl;
			for (int i = 0; i < carbs.size(); i++) {
				cout << "[" << i + 1 << "] ";
				carbs.at(i)->printFoodItem();
				printf("   $%3.2f", carbs.at(i)->getItemPrice());
				cout << endl;
				Sleep(200);
			}
			cout << endl;
		}
		if (fruitveg.size() > 0) {
			cout << "_________________________________________________________" << endl;
			cout << "                 [7] FRUITS & VEGGIES" << endl;
			cout << "_________________________________________________________" << endl;
			for (int i = 0; i < fruitveg.size(); i++) {
				cout << "[" << i + 1 << "] ";
				fruitveg.at(i)->printFoodItem();
				printf("   $%3.2f", fruitveg.at(i)->getItemPrice());
				cout << endl;
				Sleep(200);
			}
			cout << endl;
		}
		return storeInventory;
	}
	
	// Make an inventory of random items
	void CTInventory::makeRandomInventory(int qty) {
		srand((unsigned)time(0));
		int length = (int)tempInventory.size();
		inventory.clear();
		for (int i = 0; i < qty; i++) 
			inventory.push_back(tempInventory.at(rand() % length));
	}

	// Inventory builders
	void CTInventory::makeInventory(vector<CTItem*> items, int qty) {
		tempInventory.clear();
		tempInventory = items;
		makeRandomInventory(qty);
	}
	void CTInventory::makeInventory(vector<CTItem*> items, vector<CTItem*> items2, int qty) {
		vector<CTItem*> temp = items;
		temp.insert(temp.end(), items2.begin(), items2.end());
		tempInventory.clear();
		tempInventory = temp;
		makeRandomInventory(qty);
	}
	void CTInventory::makeInventory(vector<CTItem*> items, vector<CTItem*> items2, vector<CTItem*> items3, int qty) {
		items.insert(items.end(), items2.begin(), items2.end());
		items.insert(items.end(), items3.begin(), items3.end());
		tempInventory.clear();
		tempInventory = items;
		makeRandomInventory(qty);
	}
	void CTInventory::makeInventory(vector<CTItem*> items, vector<CTItem*> items2, vector<CTItem*> items3, vector<CTItem*> items4, int qty) {
		items.insert(items.end(), items2.begin(), items2.end());
		items.insert(items.end(), items3.begin(), items3.end());
		items.insert(items.end(), items4.begin(), items4.end());
		tempInventory.clear();
		tempInventory = items;
		makeRandomInventory(qty);
	}
	void CTInventory::makeInventory(vector<CTItem*> items, vector<CTItem*> items2, vector<CTItem*> items3, vector<CTItem*> items4, vector<CTItem*> items5, int qty) {
		items.insert(items.end(), items2.begin(), items2.end());
		items.insert(items.end(), items3.begin(), items3.end());
		items.insert(items.end(), items4.begin(), items4.end());
		items.insert(items.end(), items5.begin(), items5.end());
		tempInventory.clear();
		tempInventory = items;
		makeRandomInventory(qty);
	}
	void CTInventory::makeInventory(vector<CTItem*> items, vector<CTItem*> items2, vector<CTItem*> items3, vector<CTItem*> items4, vector<CTItem*> items5, vector<CTItem*> items6, int qty) {
		items.insert(items.end(), items2.begin(), items2.end());
		items.insert(items.end(), items3.begin(), items3.end());
		items.insert(items.end(), items4.begin(), items4.end());
		items.insert(items.end(), items5.begin(), items5.end());
		items.insert(items.end(), items6.begin(), items6.end());
		tempInventory.clear();
		tempInventory = items;
		makeRandomInventory(qty);
	}
	vector<CTItem*> CTInventory::makeGeneralFoodInventory() {
		vector<CTItem*> temp;
		temp.insert(temp.end(), generalMeat.begin(), generalMeat.end());
		temp.insert(temp.end(), generalFruit.begin(), generalFruit.end());
		temp.insert(temp.end(), generalSweets.begin(), generalSweets.end());
		temp.insert(temp.end(), generalMisc.begin(), generalMisc.end());
		temp.insert(temp.end(), generalStarches.begin(), generalStarches.end());
		temp.insert(temp.end(), generalVeg.begin(), generalVeg.end());
		return temp;
	}
	void CTInventory::setGeneralFoodInventory() {
		vector<CTItem*> temp;
		temp.insert(temp.end(), generalMeat.begin(), generalMeat.end());
		temp.insert(temp.end(), generalFruit.begin(), generalFruit.end());
		temp.insert(temp.end(), generalSweets.begin(), generalSweets.end());
		temp.insert(temp.end(), generalMisc.begin(), generalMisc.end());
		temp.insert(temp.end(), generalStarches.begin(), generalStarches.end());
		temp.insert(temp.end(), generalVeg.begin(), generalVeg.end());
		inventory = temp;
	}
	void CTInventory::setGeneralFoodInventory(int qty) {
		vector<CTItem*> temp;
		temp.insert(temp.end(), generalMeat.begin(), generalMeat.end());
		temp.insert(temp.end(), generalFruit.begin(), generalFruit.end());
		temp.insert(temp.end(), generalSweets.begin(), generalSweets.end());
		temp.insert(temp.end(), generalMisc.begin(), generalMisc.end());
		temp.insert(temp.end(), generalStarches.begin(), generalStarches.end());
		temp.insert(temp.end(), generalVeg.begin(), generalVeg.end());
		makeInventory(temp, qty);
	}
	vector<CTItem*> CTInventory::makeMedFoodInventory() {
		vector<CTItem*> temp = makeGeneralFoodInventory();
		temp.insert(temp.end(), medMeat.begin(), medMeat.end());
		temp.insert(temp.end(), medDairy.begin(), medDairy.end());
		temp.insert(temp.end(), medFruit.begin(), medFruit.end());
		temp.insert(temp.end(), medSweets.begin(), medSweets.end());
		temp.insert(temp.end(), medMisc.begin(), medMisc.end());
		temp.insert(temp.end(), medStarches.begin(), medStarches.end());
		temp.insert(temp.end(), medVeg.begin(), medVeg.end());
		return temp;
	}
	void CTInventory::setMedFoodInventory() {
		vector<CTItem*> temp = makeGeneralFoodInventory();
		temp.insert(temp.end(), medMeat.begin(), medMeat.end());
		temp.insert(temp.end(), medDairy.begin(), medDairy.end());
		temp.insert(temp.end(), medFruit.begin(), medFruit.end());
		temp.insert(temp.end(), medSweets.begin(), medSweets.end());
		temp.insert(temp.end(), medMisc.begin(), medMisc.end());
		temp.insert(temp.end(), medStarches.begin(), medStarches.end());
		temp.insert(temp.end(), medVeg.begin(), medVeg.end());
		inventory = temp;
	}
	void CTInventory::setMedFoodInventory(int qty) {
		vector<CTItem*> temp = makeGeneralFoodInventory();
		temp.insert(temp.end(), medMeat.begin(), medMeat.end());
		temp.insert(temp.end(), medDairy.begin(), medDairy.end());
		temp.insert(temp.end(), medFruit.begin(), medFruit.end());
		temp.insert(temp.end(), medSweets.begin(), medSweets.end());
		temp.insert(temp.end(), medMisc.begin(), medMisc.end());
		temp.insert(temp.end(), medStarches.begin(), medStarches.end());
		temp.insert(temp.end(), medVeg.begin(), medVeg.end());
		makeInventory(temp, qty);
	}
	vector<CTItem*> CTInventory::makeRareFoodInventory() {
		vector<CTItem*> temp = makeMedFoodInventory();
		temp.insert(temp.end(), rareMeat.begin(), rareMeat.end());
		temp.insert(temp.end(), rareDairy.begin(), rareDairy.end());
		temp.insert(temp.end(), rareFruit.begin(), rareFruit.end());
		temp.insert(temp.end(), rareSweets.begin(), rareSweets.end());
		temp.insert(temp.end(), rareMisc.begin(), rareMisc.end());
		temp.insert(temp.end(), rareStarches.begin(), rareStarches.end());
		temp.insert(temp.end(), rareVeg.begin(), rareVeg.end());
		return temp;
	}
	void CTInventory::setRareFoodInventory() {
		vector<CTItem*> temp = makeMedFoodInventory();
		temp.insert(temp.end(), rareMeat.begin(), rareMeat.end());
		temp.insert(temp.end(), rareDairy.begin(), rareDairy.end());
		temp.insert(temp.end(), rareFruit.begin(), rareFruit.end());
		temp.insert(temp.end(), rareSweets.begin(), rareSweets.end());
		temp.insert(temp.end(), rareMisc.begin(), rareMisc.end());
		temp.insert(temp.end(), rareStarches.begin(), rareStarches.end());
		temp.insert(temp.end(), rareVeg.begin(), rareVeg.end());
		inventory = temp;
	}
	void CTInventory::setRareFoodInventory(int qty) {
		vector<CTItem*> temp = makeMedFoodInventory();
		temp.insert(temp.end(), rareMeat.begin(), rareMeat.end());
		temp.insert(temp.end(), rareDairy.begin(), rareDairy.end());
		temp.insert(temp.end(), rareFruit.begin(), rareFruit.end());
		temp.insert(temp.end(), rareSweets.begin(), rareSweets.end());
		temp.insert(temp.end(), rareMisc.begin(), rareMisc.end());
		temp.insert(temp.end(), rareStarches.begin(), rareStarches.end());
		temp.insert(temp.end(), rareVeg.begin(), rareVeg.end());
		makeInventory(temp, qty);
	}
	vector<CTItem*> CTInventory::makeGeneralInventory() {
		vector<CTItem*> temp = makeGeneralFoodInventory();
		temp.insert(temp.end(), generalGeneral.begin(), generalGeneral.end());
		temp.insert(temp.end(), generalKitchen.begin(), generalKitchen.end());
		temp.insert(temp.end(), generalTools.begin(), generalTools.end());
		temp.insert(temp.end(), indulgences.begin(), indulgences.end());
		temp.insert(temp.end(), generalLinens.begin(), generalLinens.end());
		temp.insert(temp.end(), generalClothes.begin(), generalClothes.end());
		return temp;
	}
	void CTInventory::setGeneralInventory() {
		vector<CTItem*> temp = makeGeneralFoodInventory();
		temp.insert(temp.end(), generalGeneral.begin(), generalGeneral.end());
		temp.insert(temp.end(), generalKitchen.begin(), generalKitchen.end());
		temp.insert(temp.end(), generalTools.begin(), generalTools.end());
		temp.insert(temp.end(), indulgences.begin(), indulgences.end());
		temp.insert(temp.end(), generalLinens.begin(), generalLinens.end());
		temp.insert(temp.end(), generalClothes.begin(), generalClothes.end());
		setInventory(temp);
	}
	void CTInventory::setGeneralInventory(int qty) {
		vector<CTItem*> temp = makeGeneralFoodInventory();
		temp.insert(temp.end(), generalGeneral.begin(), generalGeneral.end());
		temp.insert(temp.end(), generalKitchen.begin(), generalKitchen.end());
		temp.insert(temp.end(), generalTools.begin(), generalTools.end());
		temp.insert(temp.end(), indulgences.begin(), indulgences.end());
		temp.insert(temp.end(), generalLinens.begin(), generalLinens.end());
		temp.insert(temp.end(), generalClothes.begin(), generalClothes.end());
		makeInventory(temp, qty);
	}
	vector<CTItem*> CTInventory::makeMedInventory() {
		vector<CTItem*> temp = makeGeneralInventory();
		temp.insert(temp.end(), medGeneral.begin(), medGeneral.end());
		temp.insert(temp.end(), medKitchen.begin(), medKitchen.end());
		temp.insert(temp.end(), medTools.begin(), medTools.end());
		temp.insert(temp.end(), medLinens.begin(), medLinens.end());
		temp.insert(temp.end(), medClothes.begin(), medClothes.end());
		temp.insert(temp.end(), heatStove.begin(), heatStove.end());
		return temp;
	}
	void CTInventory::setMedInventory() {
		vector<CTItem*> temp = makeGeneralInventory();
		temp.insert(temp.end(), medGeneral.begin(), medGeneral.end());
		temp.insert(temp.end(), medKitchen.begin(), medKitchen.end());
		temp.insert(temp.end(), medTools.begin(), medTools.end());
		temp.insert(temp.end(), medLinens.begin(), medLinens.end());
		temp.insert(temp.end(), medClothes.begin(), medClothes.end());
		temp.insert(temp.end(), heatStove.begin(), heatStove.end());
		inventory = temp;
	}
	void CTInventory::setMedInventory(int qty) {
		vector<CTItem*> temp = makeGeneralInventory();
		temp.insert(temp.end(), medGeneral.begin(), medGeneral.end());
		temp.insert(temp.end(), medKitchen.begin(), medKitchen.end());
		temp.insert(temp.end(), medTools.begin(), medTools.end());
		temp.insert(temp.end(), medLinens.begin(), medLinens.end());
		temp.insert(temp.end(), medClothes.begin(), medClothes.end());
		temp.insert(temp.end(), heatStove.begin(), heatStove.end());
		makeInventory(temp, qty);
	}
	vector<CTItem*> CTInventory::makeRareInventory() {
		vector<CTItem*> temp = makeMedInventory();
		temp.insert(temp.end(), rareGeneral.begin(), rareGeneral.end());
		temp.insert(temp.end(), rareLinens.begin(), rareLinens.end());
		temp.insert(temp.end(), rareClothes.begin(), rareClothes.end());
		return temp;
	}
	void CTInventory::setRareInventory() {
		vector<CTItem*> temp = makeMedInventory();
		temp.insert(temp.end(), rareGeneral.begin(), rareGeneral.end());
		temp.insert(temp.end(), rareLinens.begin(), rareLinens.end());
		temp.insert(temp.end(), rareClothes.begin(), rareClothes.end());
		inventory = temp;
	}
	void CTInventory::setRareInventory(int qty) {
		vector<CTItem*> temp = makeMedInventory();
		temp.insert(temp.end(), rareGeneral.begin(), rareGeneral.end());
		temp.insert(temp.end(), rareLinens.begin(), rareLinens.end());
		temp.insert(temp.end(), rareClothes.begin(), rareClothes.end());
		makeInventory(temp, qty);
	}
	vector<CTItem*> CTInventory::getInventory() {
		return inventory;
	}

	// Print an inventory
	void CTInventory::printInventory() {
		for (int i = 0; i < inventory.size(); i++) {
			inventory[i]->printItem();
		}
	}

	// Print an inventory with numbers
	void CTInventory::printNumberedInventory() {
		for (int i = 0; i < inventory.size(); i++) {
			cout << "[" << i << "] ";
			inventory[i]->printItem();
		}
	}

	// Empty Item
	CTItem* CTInventory::emptyItem() {
		CTItem* emptyItem = new CTItem();
		return emptyItem; delete emptyItem;
	}

	// General Items
	CTItem* CTInventory::backgammon() {
		CTItem* backgammon = new CTItem("Backgammon board", 0.25, 1.0, 999.9);
		return backgammon;
	}
	CTItem* CTInventory::candles() {
		CTItem* candles = new CTItem(true, "Candles", 0.70, 0.5, 14.0, false, false, true, false);
		return candles; delete candles;
	}
	CTItem* CTInventory::canvasyd() {
		CTItem* canvasyd = new CTItem("Yards of canvas", 1.0, 5, 14.0, false, false, false, true);
		return canvasyd; delete canvasyd;
	}
	CTItem* CTInventory::cards() {
		CTItem* cards = new CTItem("Playing cards", 0.40, 1, 999.9, false, false, true, false);
		return cards; delete cards;
	}
	CTItem* CTInventory::letterpaper() {
		CTItem* letterpaper = new CTItem("Letter paper", 0.15, 1.0, 1.0, false, false, false, true);
		return letterpaper; delete letterpaper;
	}
	CTItem* CTInventory::matches() {
		CTItem* matches = new CTItem(true, "Tinderbox(matches)", 0.40, 1.0, 14.0, false, false, false, true);
		return matches; delete matches;
	}
	CTItem* CTInventory::postage() {
		CTItem* postage = new CTItem("Postage", 0.02, 1.0, 1.0, false, false, false, true);
		return postage; delete postage;
	}
	CTItem* CTInventory::sewingkit() {
		CTItem* sewingkit = new CTItem("Sewing kit with pins, needles, and thread", 0.40, 1,30.0, false, false, false, true);
		return sewingkit; delete sewingkit;
	}
	CTItem* CTInventory::shavehaircut() {
		CTItem* shavehaircut = new CTItem("Shave and a haircut", 0.75, 0.0,1.0,false, false, false, false);
		return shavehaircut; delete shavehaircut;
	}
	CTItem* CTInventory::soap() {
		CTItem* soap = new CTItem(true,true, "Soap", 0.25, 1.0,14.0);
		return soap; delete soap;
	}

	// Kitchen Items
	CTHousehold* CTInventory::billy() {
		CTHousehold* billy = new CTHousehold("Billy(tin pail)", 0.50);
		return billy; delete billy;
	}
	CTHousehold* CTInventory::coffeepot() {
		CTHousehold* coffeepot = new CTHousehold("Cast iron coffee pot", 0.75);
		return coffeepot; delete coffeepot;
	}
	CTHousehold* CTInventory::drinkingglass() {
		CTHousehold* drinkingglass = new CTHousehold("Drinking glass", 0.15);
		return drinkingglass; delete drinkingglass;
	}
	CTHousehold* CTInventory::ironpot() {
		CTHousehold* ironpot = new CTHousehold("Cast iron pot", 1.00);
		return ironpot; delete ironpot;
	}
	CTHousehold* CTInventory::knifefork() {
		CTHousehold* knifefork = new CTHousehold("Knife and fork", 1.20);
		return knifefork; delete knifefork;
	}
	CTHousehold* CTInventory::teakettle() {
		CTHousehold* teakettle = new CTHousehold("Tea kettle", 1.00);
		return teakettle; delete teakettle;
	}
	CTHousehold* CTInventory::tincup() {
		CTHousehold* tincup = new CTHousehold("Tin cup", 0.0);
		return tincup; delete tincup;
	}

	// Tools and hardware
	CTHuntItems* CTInventory::gunpowderlb() {
		CTHuntItems* gunpowder = new CTHuntItems(false,"Pound of gunpowder", 1.0, 1.0, 500.0);
		return gunpowder; delete gunpowder;
	}
	CTHuntItems* CTInventory::leadlb() {
		CTHuntItems* leadlb = new CTHuntItems(false,"Pound of lead", 0.30, 1.0, 30.0);
		return leadlb; delete leadlb;
	}
	CTHuntItems* CTInventory::rifle() {
		CTHuntItems* rifle = new CTHuntItems("Hunting Rifle", 35.00, 1.0, 999.9, false, false, false, false);
		return rifle; delete rifle;
	}
	CTItem* CTInventory::nails() {
		CTItem* nails = new CTItem(true, true, "Box of nails", 1.00, 1.0, 28.0);
		return nails; delete nails;
	}
	CTItem* CTInventory::pickaxe() {
		CTItem* pickaxe = new CTItem("Pickaxe", 1.75, 1.0, 999.9, false, false, false, true);
		return pickaxe; delete pickaxe;
	}
	CTItem* CTInventory::pocketknife() {
		CTItem* pocketknife = new CTItem("Pocket knife", 0.50, 1.0, 999.9, false, false, false, true);
		return pocketknife; delete pocketknife;
	}
	CTItem* CTInventory::screws() {
		CTItem* screws = new CTItem(true, true, "Box of screws", 1.50, 1.0, 28.0);
		return screws; delete screws;
	}
	CTItem* CTInventory::shovel() {
		CTItem* shovel = new CTItem("Shovel", 1.00, 1.0, 999.9, false, false, false, true);
		return shovel; delete shovel;
	}

	// FOOD SECTION
	// Meat from the store
	CTProtein* CTInventory::baconlb() {
		CTProtein* baconlb = new CTProtein(true, "Pound of Cured bacon", 0.10, 1.0,1.5);
		return baconlb; delete baconlb;
	}
	CTProtein* CTInventory::baconlb(double lbs) {
		CTProtein* baconbylb = new CTProtein(true, "Pound of Cured bacon", 0.10, lbs, (1.5*lbs));
		return baconbylb; delete baconbylb;
	}
	CTProtein* CTInventory::bacon100() {
		CTProtein* bacon100 = new CTProtein(true,"100lbs of Bacon", 20.0, 100.0, 400.0);
		return bacon100; delete bacon100;
	}
	CTProtein* CTInventory::bearmeat() {
		CTProtein* bearmeat = new CTProtein(true,"Pound of Bear meat", 0.20, 1.0,2.0);
		return bearmeat; delete bearmeat;
	}
	CTProtein* CTInventory::bearmeat(double lbs) {
		CTProtein* bearmeat = new CTProtein(true, "Pound of Bear meat", 0.20, lbs, 2.0);
		return bearmeat; delete bearmeat;
	}
	CTProtein* CTInventory::beeflb() {
		CTProtein* beeflb = new CTProtein(true, "Pound of Beef", 0.15, 1.0, 2.0);
		return beeflb; delete beeflb;
	}
	CTProtein* CTInventory::beeflb(double lbs) {
		CTProtein* beeflb = new CTProtein(true, "Pound of Beef", 0.15, lbs, 2.0);
		return beeflb; delete beeflb;
	}
	CTProtein* CTInventory::canchicken() {
		CTProtein* canchicken = new CTProtein(false, "Canned chicken", 0.57, 1.0,1.0);
		return canchicken; delete canchicken;
	}
	CTProtein* CTInventory::canoysters() {
		CTProtein* canoysters = new CTProtein(false,"Canned oysters", 0.15, 1.0,1.0);
		return canoysters; delete canoysters;
	}
	CTProtein* CTInventory::cansalmon() {
		CTProtein* cansalmon = new CTProtein(false, "Canned salmon", 0.15, 1.0,1.0);
		return cansalmon; delete cansalmon;
	}
	CTProtein* CTInventory::duck() {
		CTProtein* duck = new CTProtein(false, "Duck", 0.30, 1.0,3.0);
		return duck; delete duck;
	}
	CTProtein* CTInventory::grouse() {
		CTProtein* grouse = new CTProtein(false, "Grouse", 0.25, 1.0,1.0);
		return grouse; delete grouse;
	}
	CTProtein* CTInventory::hams100() {
		CTProtein* hams100 = new CTProtein(true,"Hams", 25.0, 100.0, 300.0);
		return hams100; delete hams100;
	}
	CTProtein* CTInventory::muttonlb() {
		CTProtein* muttonlb = new CTProtein(true, "Pound of Mutton(lamb)", 0.13, 1.0,2.0);
		return muttonlb; delete muttonlb;
	}
	CTProtein* CTInventory::pheasant() {
		CTProtein* pheasant = new CTProtein(false,"Pheasant", 0.25, 1.0,2.0);
		return pheasant; delete pheasant;
	}

	CTProtein* CTInventory::salmon() {
		CTProtein* salmon = new CTProtein(false,"Salmon", 0.15, 1.0,2.0);
		return salmon; delete salmon;
	}
	CTProtein* CTInventory::sirloin() {
		CTProtein* sirloin = new CTProtein(true,"Sirloin", 0.20, 1.0,2.0);
		return sirloin; delete sirloin;
	}
	CTProtein* CTInventory::turkey() {
		CTProtein* turkey = new CTProtein(false,"Turkey", 0.15, 1.0,5.0);
		return turkey; delete turkey;
	}

	// Wild game for hunting
	CTWildGame* CTInventory::noluck() {
		CTWildGame* noluck = new CTWildGame("No luck today!", 0.0, 0.0, 0.0);
		return noluck; delete noluck;
	}
	CTWildGame* CTInventory::huntedantelope() {
		CTWildGame* huntedantelope = new CTWildGame(true, "Hunted Antelope",0.002,100.0,200.0);
		return huntedantelope; delete huntedantelope;
	}
	CTWildGame* CTInventory::huntedantelope(double size) {
		CTWildGame* huntedantelope = new CTWildGame(true,"Hunted Antelope", 0.002, size, 2.0);
		return huntedantelope; delete huntedantelope;
	}
	CTWildGame* CTInventory::huntedbear() {
		CTWildGame* huntedbear = new CTWildGame(true, "Hunted Bear", 0.002, 500.0, 1000.0);
		return huntedbear; delete huntedbear;
	}
	CTWildGame* CTInventory::huntedbear(double size) {
		CTWildGame* huntedbear = new CTWildGame(true, "Hunted Bear", 0.002, size, 2.0);
		return huntedbear; delete huntedbear;
	}
	CTWildGame* CTInventory::huntedbuffalo() {
		CTWildGame* huntedbuffalo = new CTWildGame(true, "Hunted Buffalo",0.002,2000.0,4000.0);
		return huntedbuffalo; delete huntedbuffalo;
	}
	CTWildGame* CTInventory::huntedbuffalo(double size) {
		CTWildGame* huntedbuffalo = new CTWildGame(true, "Hunted Buffalo", 0.002, size, 2.0);
		return huntedbuffalo; delete huntedbuffalo;
	}
	CTWildGame* CTInventory::hunteddeer() {
		CTWildGame* hunteddeer = new CTWildGame(true, "Hunted Deer",0.005, 300.0, 600.0);
		return hunteddeer; delete hunteddeer;
	}
	CTWildGame* CTInventory::hunteddeer(double size) {
		CTWildGame* hunteddeer = new CTWildGame(true, "Hunted Deer", 0.005, size, 2.0);
		return hunteddeer; delete hunteddeer;
	}
	CTWildGame* CTInventory::huntedduck() {
		CTWildGame* huntedduck = new CTWildGame("Hunted Duck",0.03, 1.0, 3.0);
		return huntedduck; delete huntedduck;
	}
	CTWildGame* CTInventory::huntedducks(double qty) {
		CTWildGame* huntedduck = new CTWildGame("Hunted Ducks",0.03, qty, 3.0);
		return huntedduck; delete huntedduck;
	}
	CTWildGame* CTInventory::huntedelk() {
		CTWildGame* huntedelk = new CTWildGame(true, "Hunted Elk",0.005, 700.0, 1400.0);
		return huntedelk; delete huntedelk;
	}
	CTWildGame* CTInventory::huntedelk(double size) {
		CTWildGame* huntedelk = new CTWildGame(true, "Hunted Elk", 0.005, size, 2.0);
		return huntedelk; delete huntedelk;
	}
	CTWildGame* CTInventory::huntedgeese() {
		CTWildGame* huntedgeese = new CTWildGame("Hunted Geese", 0.03, 1.0, 2.0);
		return huntedgeese; delete huntedgeese;
	}
	CTWildGame* CTInventory::huntedgeese(double qty) {
		CTWildGame* huntedgeese = new CTWildGame("Hunted Geese", 0.03, qty, 2.0);
		return huntedgeese; delete huntedgeese;
	}
	CTWildGame* CTInventory::huntedgrouse() {
		CTWildGame* huntedgrouse = new CTWildGame("Hunted Grouse",0.03, 1.0, 1.0);
		return huntedgrouse; delete huntedgrouse;
	}
	CTWildGame* CTInventory::huntedgrouses(double qty) {
		CTWildGame* huntedgrouse = new CTWildGame("Hunted Grouses", 0.03, qty, qty);
		return huntedgrouse; delete huntedgrouse;
	}
	CTWildGame* CTInventory::huntedpheasant() {
		CTWildGame* huntedpheasant = new CTWildGame("Hunted Pheasant",0.03, 1.0, 2.0);
		return huntedpheasant; delete huntedpheasant;
	}
	CTWildGame* CTInventory::huntedpheasants(double qty) {
		CTWildGame* huntedpheasant = new CTWildGame("Hunted Pheasants",0.03, qty, 2.0);
		return huntedpheasant; delete huntedpheasant;
	}
	CTWildGame* CTInventory::pinenuts() {
		CTWildGame* pinenuts = new CTWildGame(true, "Found Pinenuts", 0.01, 1.0, 0.25);
		return pinenuts; delete pinenuts;
	}
	CTWildGame* CTInventory::pinenuts(double qty) {
		CTWildGame* pinenuts = new CTWildGame(true, "Found Pinenuts", 0.01, qty, 0.25);
		return pinenuts; delete pinenuts;
	}
	CTWildGame* CTInventory::wildraspberries() {
		CTWildGame* wildraspberries = new CTWildGame("Wild Raspberries", 0.01, 1.0, 0.25);
		return wildraspberries; delete wildraspberries;
	}
	CTWildGame* CTInventory::wildraspberries(double qty) {
		CTWildGame* wildraspberries = new CTWildGame("Wild Raspberries", 0.01, qty, 0.25);
		return wildraspberries; delete wildraspberries;
	}
	CTWildGame* CTInventory::huntedrabbit() {
		CTWildGame* huntedrabbit = new CTWildGame("Hunted Rabbits",0.05, 2.0, 4.0);
		return huntedrabbit; delete huntedrabbit;
	}
	CTWildGame* CTInventory::huntedrabbits(double qty) {
		qty = qty * 2;
		CTWildGame* huntedrabbit = new CTWildGame("Hunted Rabbits", 0.05, qty, 4.0);
		return huntedrabbit; delete huntedrabbit;
	}
	CTWildGame* CTInventory::huntedsquirrel() {
		CTWildGame* huntedsquirrel = new CTWildGame("Hunted Squirrels", 0.01,1.0, 0.5);
		return huntedsquirrel; delete huntedsquirrel;
	}
	CTWildGame* CTInventory::huntedsquirrels(double qty) {
		CTWildGame* huntedsquirrels = new CTWildGame("Hunted Squirrels", 0.01, qty, (qty/2));
		return huntedsquirrels; delete huntedsquirrels;
	}
	CTWildGame* CTInventory::wildstrawberries() {
		CTWildGame* wildstrawberries = new CTWildGame("Wild Strawberries", 0.01, 1.0, 0.5);
		return wildstrawberries; delete wildstrawberries;
	}
	CTWildGame* CTInventory::wildstrawberries(double qty) {
		CTWildGame* wildstrawberries = new CTWildGame("Wild Strawberries", 0.01, qty, (qty/2));
		return wildstrawberries; delete wildstrawberries;
	}
	CTWildGame* CTInventory::caughttrout() {
		CTWildGame* caughttrout = new CTWildGame("Creek Trout", 0.02, 1.0, 1.0);
		return caughttrout; delete caughttrout;
	}
	CTWildGame* CTInventory::caughttrout(double qty) {
		CTWildGame* caughttrout = new CTWildGame("Creek Trout", 0.02, qty, qty);
		return caughttrout; delete caughttrout;
	}
	CTWildGame* CTInventory::huntedturkey() {
		CTWildGame* huntedturkey = new CTWildGame("Hunted Turkey",0.05,1.0, 5.0);
		return huntedturkey; delete huntedturkey;
	}
	CTWildGame* CTInventory::huntedturkeys(double qty) {
		CTWildGame* huntedturkey = new CTWildGame("Hunted Turkeys", 0.05,qty, 5.0);
		return huntedturkey; delete huntedturkey;
	}

	// Indulgences
	CTItem* CTInventory::beer() {
		CTItem* beer = new CTItem("Gallon of Beer", 0.40, 1.0);
		return beer; delete beer;
	}
	CTItem* CTInventory::tobacco() {
		CTItem* tobacco = new CTItem(true,false,"Tobacco", 1.0, 1.0, 14.0);
		return tobacco; delete tobacco;
	}
	CTItem* CTInventory::whiskey() {
		CTItem* whiskey = new CTItem("Homemade corn whiskey", 8.00, 1.0);
		return whiskey; delete whiskey;
	}

	// Dairy
	CTFood* CTInventory::butter() {
		CTFood* butter = new CTFood(true, false,"Butter", 0.30, 1.0,14.0);
		return butter; delete butter;
	}
	CTFood* CTInventory::cheese() {
		CTFood* cheese = new CTFood(true, false,"Cheese", 0.15, 1.0,14.0);
		return cheese; delete cheese;
	}
	CTFood* CTInventory::condmilk() {
		CTFood* condmilk = new CTFood("Condensed milk", 0.17, 1.0);
		return condmilk; delete condmilk;
	}
	CTFood* CTInventory::milk() {
		CTFood* milk = new CTFood("Milk", 0.10, 1.0);
		return milk; delete milk;
	}

	// Fruit
	CTFruitVeg* CTInventory::canfruit() {
		CTFruitVeg* canfruit = new CTFruitVeg(false,"Canned fruit", 0.40, 1.0,1.0);
		return canfruit; delete canfruit;
	}
	CTFruitVeg* CTInventory::currants() {
		CTFruitVeg* currants = new CTFruitVeg(true,"Dried currants", 0.20, 1.0,5.0);
		return currants; delete currants;
	}
	CTFruitVeg* CTInventory::driedappleslb() {
		CTFruitVeg* driedappleslb = new CTFruitVeg(true,"Pound of Dried apples", 0.10, 1.0,5.0);
		return driedappleslb; delete driedappleslb;
	}
	CTFruitVeg* CTInventory::peaches() {
		CTFruitVeg* peaches = new CTFruitVeg(true,"Dried peaches", 0.27, 1.0,7.0);
		return peaches; delete peaches;
	}
	CTFruitVeg* CTInventory::raisins() {
		CTFruitVeg* raisins = new CTFruitVeg(true,"Raisins", 0.18, 1.0,7.0);
		return raisins; delete raisins;
	}

	// Sweets
	CTFood* CTInventory::chocolate() {
		CTFood* chocolate = new CTFood("Chocolate", 1.00, 1.0,7.0,1.0);
		return chocolate; delete chocolate;
	}
	CTFood* CTInventory::fruitpie() {
		CTFood* fruitpie = new CTFood("Fruit Pie", 0.10, 1.0,1.0);
		return fruitpie; delete fruitpie;
	}
	CTFood* CTInventory::jamstraw() {
		CTFood* jamstraw = new CTFood("Strawberry jam", 0.30, 1.0,14.0,1.0);
		return jamstraw; delete jamstraw;
	}
	CTFood* CTInventory::molasses() {
		CTFood* molasses = new CTFood("Gallon of Molasses", 4.00, 1.0,14.0);
		return molasses; delete molasses;
	}
	CTFood* CTInventory::sugarlb() {
		CTFood* sugar = new CTFood(true, true,"Sugar by the pound", 0.25, 1.0, 28.0);
		return sugar; delete sugar;
	}
	CTFood* CTInventory::sugar100() {
		CTFood* sugar100 = new CTFood("100lbs of Sugar", 35.0, 100.0, 1000.0);
		return sugar100; delete sugar100;
	}

	// Misc
	CTFood* CTInventory::coffee() {
		CTFood* coffee = new CTFood(true, true, "Pound of Coffee", 0.35, 1.0, 14.0);
		return coffee; delete coffee;
	}
	CTFood* CTInventory::lardlb() {
		CTFood* lardlb = new CTFood(true, true, "Pound of Lard", 0.15, 1.0,14.0);
		return lardlb; delete lardlb; 
	}
	CTFood* CTInventory::oilgal() {
		CTFood* oilgal = new CTFood("Gallon of Oil", 1.15, 1.0,28.0);
		return oilgal; delete oilgal;
	}
	CTFood* CTInventory::saltlb() {
		CTFood* salt = new CTFood(true,true,"Pound of Salt", 1.00, 1.0, 60.0);
		return salt; delete salt;
	}
	CTFood* CTInventory::spices() {
		CTFood* spices = new CTFood("Spices for cooking and remedies", 2.00, 1.0,28.0,1.0);
		return spices; delete spices;
	}
	CTFood* CTInventory::tea() {
		CTFood* tea = new CTFood(true, false,"Tea by the pound", 0.50, 1.0,28.0);
		return tea; delete tea;
	}

	// Starches
	CTCarb* CTInventory::beanslb() {
		CTCarb* beanslb = new CTCarb(true,true,"Pound of Dried pinto beans", 0.25, 1.0,4.0);
		return beanslb; delete beanslb;
	}
	CTCarb* CTInventory::cake() {
		CTCarb* cake = new CTCarb(false,false, "Sweet Cake", 0.10, 1.0,1.0);
		return cake; delete cake;
	}
	CTCarb* CTInventory::cornmeallb() {
		CTCarb* cornmeallb = new CTCarb(true,true,"Pound of Corn meal", 0.15, 1.0,4.0);
		return cornmeallb; delete cornmeallb;
	}
	CTCarb* CTInventory::crackers() {
		CTCarb* crackers = new CTCarb(true,false, "Crackers", 0.13, 1.0,2.0);
		return crackers; delete crackers;
	}
	CTCarb* CTInventory::flourlb() {
		CTCarb* flourlb = new CTCarb(true,true,"Flour by the pound", 0.30, 1.0,2.0);
		return flourlb; delete flourlb;
	}
	CTCarb* CTInventory::flour100() {
		CTCarb* flour100 = new CTCarb(false,false, "100lbs of Flour", 20.0, 100.0, 200.0);
		return flour100; delete flour100;
	}
	CTCarb* CTInventory::loafofbread() {
		CTCarb* loafofbread = new CTCarb(false,false,"Loaf of Bread", 0.10, 1.0,1.0);
		return loafofbread; delete loafofbread;
	}
	CTCarb* CTInventory::oatslb() {
		CTCarb* oatslb = new CTCarb(true,false,"Oats by the pound", 0.04, 1.0,1.0);
		return oatslb; delete oatslb;
	}
	CTCarb* CTInventory::ricelb() {
		CTCarb* ricelb = new CTCarb(true,true, "Rice by the pound", 0.40, 1.0, 3.0);
		return ricelb; delete ricelb;
	}
	CTCarb* CTInventory::rice100() {
		CTCarb* rice100 = new CTCarb(true,false,"100lbs of Rice", 20.0, 100.0, 300.0);
		return rice100; delete rice100;
	}

	// Vegetables
	CTFruitVeg* CTInventory::canveg() {
		CTFruitVeg* canveg = new CTFruitVeg(false,"Canned veggies", 0.25, 1.0,10);
		return canveg; delete canveg;
	}
	CTFruitVeg* CTInventory::cornlb() {
		CTFruitVeg* cornlb = new CTFruitVeg(true,"Pound of Corn", 0.03, 1.0,2.0);
		return cornlb; delete cornlb;
	}
	CTFruitVeg* CTInventory::cornbushel() {
		CTFruitVeg* cornbushel = new CTFruitVeg(false,"Bushel of Corn", 8.0, 56.0, 112.0);
		return cornbushel; delete cornbushel;
	}
	CTFruitVeg* CTInventory::driedcorn() {
		CTFruitVeg* driedcorn = new CTFruitVeg(false,"Can of Dried corn", 0.12, 1.0,1.0);
		return driedcorn; delete driedcorn;
	}
	CTCarb* CTInventory::potatoeslb() {
		CTCarb* potatoeslb = new CTCarb(true,false,"Pound of Potatoes", 0.02, 1.0,2.0);
		return potatoeslb; delete potatoeslb;
	}

	// Household linens
	CTHousehold* CTInventory::bedblanketwool() {
		CTHousehold* bedblanketwool = new CTHousehold("Heavy wool blanket", 18.00);
		return bedblanketwool; delete bedblanketwool;
	}
	CTHousehold* CTInventory::bedcomforterwool() {
		CTHousehold* bedcomforterwool = new CTHousehold("Wool comforter", 16.0);
		return bedcomforterwool; delete bedcomforterwool;
	}
	CTHousehold* CTInventory::bedcovercanvas() {
		CTHousehold* bedcovercanvas = new CTHousehold("Canvas bed cover", 10.00);
		return bedcovercanvas; delete bedcovercanvas;
	}
	CTHousehold* CTInventory::bedquilt() {
		CTHousehold* bedquilt = new CTHousehold("Cotton quilt", 12.00);
		return bedquilt; delete bedquilt;
	}
	CTHousehold* CTInventory::linensheets() {
		CTHousehold* linensheets = new CTHousehold("Linen bedsheets", 1.00);
		return linensheets; delete linensheets;
	}
	CTHousehold* CTInventory::pillowfeather() {
		CTHousehold* pillowfeather = new CTHousehold("Feather pillow", 3.00);
		return pillowfeather; delete pillowfeather;
	}
	CTHousehold* CTInventory::towel() {
		CTHousehold* towel = new CTHousehold("Cotton towel", 1.10);
		return towel; delete towel;
	}

	// Heating/Cooking/Cabin
	CTHousehold* CTInventory::heater() {
		CTHousehold* heater = new CTHousehold("Cast iron heater", 5.00);
		return heater; delete heater;
	}
	CTHousehold* CTInventory::stovemedium() {
		CTHousehold* stovemedium = new CTHousehold("Medium iron stove", 12.00);
		return stovemedium; delete stovemedium;
	}
	CTHousehold* CTInventory::stovelarge() {
		CTHousehold* stovelarge = new CTHousehold("Large Iron cookstove", 20.00);
		return stovelarge; delete stovelarge;
	}
	CTHousehold* CTInventory::washbasin() {
		CTHousehold* washbasin = new CTHousehold("Wash basin", 0.50);
		return washbasin; delete washbasin;
	}

	// Clothing
	CTClothes* CTInventory::emptyClothes() {
		CTClothes* emptyClothes = new CTClothes();
		return emptyClothes; delete emptyClothes;
	}
	CTClothes* CTInventory::bootsdressleather() {
		CTClothes* bootsdressleather = new CTClothes("Leather dress boots", 8.50, 1.0, true, true, 2.0, 6.0);
		return bootsdressleather; delete bootsdressleather;
	}
	CTClothes* CTInventory::bootsrubber() {
		CTClothes* bootsrubber = new CTClothes("Rubber knee - high indian boots", 4.00, 1.0, true, true, 1.0, 6.0);
		return bootsrubber; delete bootsrubber;
	}
	CTClothes* CTInventory::bootsworkleather() {
		CTClothes* bootsworkleather = new CTClothes("Leather work boots", 6.00, 1.0, true, true, 3.0, 6.0);
		return bootsworkleather; delete bootsworkleather;
	}
	CTClothes* CTInventory::coatjacket() {
		CTClothes* coatjacket = new CTClothes("Cotton jacket", 6.75, 1.0, true, true, 2.0, 9.0);
		return coatjacket; delete coatjacket;
	}
	CTClothes* CTInventory::coatwaist() {
		CTClothes* coatwaist = new CTClothes("Waistcoat", 6.00, 1.0, true, true, 2.0, 9.0);
		return coatwaist; delete coatwaist;
	}
	CTClothes* CTInventory::coatwoolover() {
		CTClothes* coatwoolover = new CTClothes("Wool overcoat", 20.00, 1.0, false, true, 6.0, 10.0);
		return coatwoolover; delete coatwoolover;
	}
	CTClothes* CTInventory::coverallsdenim() {
		CTClothes* coverallsdenim = new CTClothes("Denim coveralls", 4.00, 1.0, true, true, 3.0, 4.0);
		return coverallsdenim; delete coverallsdenim;
	}
	CTClothes* CTInventory::glovesleather() {
		CTClothes* glovesleather = new CTClothes("Leather gloves", 1.00, 1.0, true, true, 2.0, 7.0);
		return glovesleather; delete glovesleather;
	}
	CTClothes* CTInventory::hatfelt() {
		CTClothes* hatfelt = new CTClothes("Wide brim felt hat", 1.75, 1.0, true, true, 2.0, 1.0);
		return hatfelt; delete hatfelt;
	}
	CTClothes* CTInventory::leatherbelt() {
		CTClothes* leatherbelt = new CTClothes("Leather belt", 2.5, 1.0, true, true, 0.0, 3.0);
		return leatherbelt; delete leatherbelt;
	}
	CTClothes* CTInventory::mittenswool() {
		CTClothes* mittenswool = new CTClothes("Wool winter mittens", 1.00, 1.0, false, true, 3.0, 7.0);
		return mittenswool; delete mittenswool;
	}
	CTClothes* CTInventory::necktie() {
		CTClothes* necktie = new CTClothes("Cotton neck-kerchief", 0.50, 1.0, true, true, 0.0, 8.0);
		return necktie; delete necktie;
	}
	CTClothes* CTInventory::pantsdresscotton() {
		CTClothes* pantsdresscotton = new CTClothes("Cotton dress pants", 3.50, 1.0, true, true, 1.0, 4.0);
		return pantsdresscotton; delete pantsdresscotton;
	}
	CTClothes* CTInventory::pantsworkblack() {
		CTClothes* pantsworkblack = new CTClothes("Black denim work pants", 3.50, 1.0, true, true, 2.0, 4.0);
		return pantsworkblack; delete pantsworkblack;
	}
	CTClothes* CTInventory::pantsworkdenim() {
		CTClothes* pantsworkdenim = new CTClothes("Cotton denim work trousers", 3.00, 1.0, true, true, 2.0, 4.0);
		return pantsworkdenim; delete pantsworkdenim;
	}
	CTClothes* CTInventory::pantsworkheavy() {
		CTClothes* pantsworkheavy = new CTClothes("Heavy weight denim work pants", 4.25, 1.0, true, true, 3.0, 4.0);
		return pantsworkheavy; delete pantsworkheavy;
	}
	CTClothes* CTInventory::pantsworkwool() {
		CTClothes* pantsworkwool = new CTClothes("Wool work trousers", 4.20, 1.0, false, true, 4.0, 4.0);
		return pantsworkwool; delete pantsworkwool;
	}
	CTClothes* CTInventory::shirtdresscotton() {
		CTClothes* shirtdresscotton = new CTClothes("Cotton dress shirt", 2.50, 1.0, true, true, 1.0, 2.0);
		return shirtdresscotton; delete shirtdresscotton;
	}
	CTClothes* CTInventory::shirtworkblack() {
		CTClothes* shirtworkblack = new CTClothes("Black longsleeve work shirt", 2.50, 1.0, true, true, 3.0, 2.0);
		return shirtworkblack; delete shirtworkblack;
	}
	CTClothes* CTInventory::shirtworkcotton() {
		CTClothes* shirtworkcotton = new CTClothes("Longsleeve cotton work shirt", 2.00, 1.0, true, true, 2.0, 2.0);
		return shirtworkcotton; delete shirtworkcotton;
	}
	CTClothes* CTInventory::shirtworkplaid() {
		CTClothes* shirtworkplaid = new CTClothes("Plaid work shirt", 2.00, 1.0, true, true, 1.0, 2.0);
		return shirtworkplaid; delete shirtworkplaid;
	}
	CTClothes* CTInventory::shoesdress() {
		CTClothes* shoesdress = new CTClothes("Dress shoes", 4.00, 1.0, true, true, 1.0, 6.0);
		return shoesdress; delete shoesdress;
	}
	CTClothes* CTInventory::socksheavywool() {
		CTClothes* socksheavywool = new CTClothes("Heavy wool socks", 1.50, 1.0, false, true, 3.0, 5.0);
		return socksheavywool; delete socksheavywool;
	}
	CTClothes* CTInventory::sockswool() {
		CTClothes* sockswool = new CTClothes("Wool socks", 1.00, 1.0, true, true, 2.0, 5.0);
		return sockswool; delete sockswool;
	}
	CTClothes* CTInventory::vestwool() {
		CTClothes* vestwool = new CTClothes("Merino wool vest", 3.00, 1.0, true, true, 3.0, 9.0);
		return vestwool; delete vestwool;
	}
	CTClothes* CTInventory::undergarments() {
		CTClothes* undergarments = new CTClothes("Merino drawers and undershirt", 4.50, 1.0);
		return undergarments; delete undergarments;
	}

}