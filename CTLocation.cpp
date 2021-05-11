#include "CTLocation.h"
#include "CTFunctions.h"
using namespace std;

namespace CSC234 {

	// Default location information
	CTLocation::CTLocation() { name = ""; }
	CTLocation::CTLocation(string newName) { name = newName; }
	void CTLocation::printLocation() { cout << name << endl; }

	// General store constructor
	GeneralStore::GeneralStore() {
		storeItemQty = 10;
		storeInventory->setGeneralInventory();
		storeLevel = 1;
		storeDesc = "";
		storeName = "General Store";
	}
	// General store constructor
	GeneralStore::GeneralStore(string name, int level, CTInventory* inventory) {
		storeItemQty = 10;
		storeInventory = inventory;
		storeLevel = level;
		storeDesc = "";
		storeName = name;
	}
	// General store constructor
	GeneralStore::GeneralStore(string name, int level, CTInventory* inventory, int qty) {
		storeItemQty = qty;
		storeInventory = inventory;
		storeLevel = level;
		storeDesc = "";
		storeName = name;
	}
	// General store constructor
	GeneralStore::GeneralStore(string name, string desc, int level, CTInventory* inventory) {
		storeItemQty = 100;
		storeInventory = inventory;
		storeLevel = level;
		storeDesc = desc;
		storeName = name;
	}
	// General store constructor
	GeneralStore::GeneralStore(string name, string desc, int level, CTInventory* inventory, int qty) {
		storeItemQty = qty;
		storeInventory = inventory;
		storeLevel = level;
		storeDesc = desc;
		storeName = name;
	}

	// Print a store
	void GeneralStore::printLocation() {
		cout << storeName << endl;
		if (storeDesc != "") printFile(storeDesc);
		storeInventory->printStoreInventory();
	}

	// Print a store and sell to a player
	void GeneralStore::printLocation(vector<CTPlayer> players) {
		cout << "          ------ G E N E R A L   S T O R E ------" << endl;
		if (storeDesc != "") printFile(storeDesc);
		vector<vector<CTItem*>> newInventory = storeInventory->printStoreInventory();
		for (auto player : players) {
			cout << player.getName() << " would you like to print your inventory? (y/n) ";
			cin >> yesNo;
			while (yesNo != 'y' && yesNo != 'n') {
				cout << "Invalid input, please try again (y/n) ";
				cin >> yesNo;
			}
			if (yesNo == 'y') player.printAnInventory();
			cout << "Would you like to make a purchase from the store? (y/n) ";
			cin >> yesNo;
			while (yesNo != 'y' && yesNo != 'n') {
				cout << "Invalid input, please try again (y/n) ";
				cin >> yesNo;
			}
			if (yesNo == 'y') sellItem(&player, newInventory);
		}
	}
	
	// Find item in store and sell to player
	void GeneralStore::sellItem(CTPlayer* player, vector<vector<CTItem*>> storeInventory) {
		cout << "Which store category contains the item you would like to purchase? (1-7) ";
		int storeCategory;
		cin >> storeCategory;
		while (storeCategory < 0 && storeCategory > 7) {
			cout << "Invalid input, please try again. (1-7) ";
			cin >> storeCategory;
		}
		cout << "Which item would you like to purchase? ";
		cin >> itemIndex;
		int qty = 0;
		storeCategory = storeCategory - 1;
		itemIndex = itemIndex - 1;
		if ((storeInventory.at(storeCategory).at(itemIndex))->isByThePound()) {
			cout << "How many pounds? ";
			cin >> qty;
		}
		else {
			cout << "How many would you like to purchase? ";
			cin >> qty;
		}
		CTItem* temp = storeInventory.at(storeCategory).at(itemIndex);
		if (qty > 1) temp->buyMultiple(qty);
		player->withdrawl(temp->getItemPrice());
		if (temp->isFood()) player->addToFoodInventory(temp);
		else if (temp->isHousehold()) player->addToCampInventory(temp);
		else if (temp->isClothing()) player->changeClothing(temp);
		else player->addToInventory(temp);
		cout << temp->getItemName() << " added to your inventory." << endl;
		cout << "Would you like to buy another item? (y/n) ";
		cin >> yesNo;
		while (yesNo != 'y' && yesNo != 'n') {
			cout << "Invalid input, please try again (y/n) ";
			cin >> yesNo;
		}
		if (yesNo == 'y') sellItem(player, storeInventory);
	}

	// GoHunting constructor
	GoHunting::GoHunting() { shots = {}; }

	// Create different hunting possibilies
	void GoHunting::setPossibilites(int luck) {
		switch (luck) {
		case 1:
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedsquirrel());
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedturkey());
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedduck());
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedpheasant());
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->pinenuts());
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedrabbit());
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedsquirrel());
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->pinenuts());
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedgeese());
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedrabbit());
			break;
		case 2:
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedantelope());
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedsquirrel());
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedturkeys(2));
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedpheasant());
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedrabbits(2));
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedgeese(2));
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->hunteddeer());
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedgrouse());
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->pinenuts());
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->caughttrout(2));
			break;
		case 3:
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedrabbits(3.0));
			shots.push_back(inventory->huntedpheasant());
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedsquirrels(5.0));
			shots.push_back(inventory->huntedelk());
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedducks(3.0));
			shots.push_back(inventory->huntedgeese());
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->hunteddeer());
			shots.push_back(inventory->huntedbear());
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedantelope());
			shots.push_back(inventory->huntedducks(3.0));
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedgrouse());
			shots.push_back(inventory->caughttrout(4.0));
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedturkeys(2.0));
			break;
		case 4:
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedantelope());
			shots.push_back(inventory->huntedbear());
			shots.push_back(inventory->hunteddeer());
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedducks(3.0));
			shots.push_back(inventory->huntedelk());
			shots.push_back(inventory->huntedgeese(3.0));
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedgrouse());
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->pinenuts()); 
			shots.push_back(inventory->huntedpheasants(2.0));
			shots.push_back(inventory->huntedrabbits(2.0));
			shots.push_back(inventory->noluck()); 
			shots.push_back(inventory->caughttrout(3.0));
			shots.push_back(inventory->huntedsquirrels(3.0));
			shots.push_back(inventory->huntedturkey());
			shots.push_back(inventory->huntedpheasants(2.0));
			shots.push_back(inventory->noluck());
			break;
		case 5:
			shots.push_back(inventory->noluck()); 
			shots.push_back(inventory->huntedantelope()); 
			shots.push_back(inventory->huntedbear()); 
			shots.push_back(inventory->huntedbuffalo());
			shots.push_back(inventory->hunteddeer());
			shots.push_back(inventory->noluck()); 
			shots.push_back(inventory->hunteddeer()); 
			shots.push_back(inventory->huntedducks(3)); 
			shots.push_back(inventory->huntedelk()); 
			shots.push_back(inventory->huntedgeese());
			shots.push_back(inventory->noluck()); 
			shots.push_back(inventory->huntedgrouses(3.0));
			shots.push_back(inventory->huntedpheasants(2.0));
			shots.push_back(inventory->huntedpheasant());
			shots.push_back(inventory->huntedrabbit());
			shots.push_back(inventory->noluck()); 
			shots.push_back(inventory->huntedrabbits(2.0));
			shots.push_back(inventory->caughttrout(3.0));
			shots.push_back(inventory->huntedsquirrels(4.0));
			shots.push_back(inventory->huntedturkeys(2.0));
			break;
		case 6:
			shots.push_back(inventory->huntedantelope());
			shots.push_back(inventory->huntedbear());
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedantelope());
			shots.push_back(inventory->hunteddeer());
			shots.push_back(inventory->hunteddeer());
			shots.push_back(inventory->huntedelk());
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedgeese(4.0));
			shots.push_back(inventory->huntedgrouse());
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedpheasants(3.0));
			shots.push_back(inventory->huntedrabbits(3.0));
			shots.push_back(inventory->huntedturkeys(2.0));
			shots.push_back(inventory->huntedgrouse());
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->hunteddeer());
			shots.push_back(inventory->caughttrout(3.0));
			shots.push_back(inventory->huntedgrouses(3.0));
			shots.push_back(inventory->huntedducks(3.0));
			  break;
		case 7: 
			shots.push_back(inventory->huntedbear()); 
			shots.push_back( inventory->huntedelk()); 
			shots.push_back( inventory->noluck()); 
			shots.push_back(inventory->huntedrabbits(3.0));
			shots.push_back(inventory->huntedgeese(4.0));
			shots.push_back( inventory->hunteddeer()); 
			shots.push_back( inventory->huntedsquirrels(4.0));
			shots.push_back( inventory->huntedturkeys(2.0));
			shots.push_back( inventory->huntedgeese(3.0));
			shots.push_back(inventory->noluck()); 
			shots.push_back( inventory->hunteddeer()); 
			shots.push_back( inventory->huntedantelope()); 
			shots.push_back( inventory->huntedantelope()); 
			shots.push_back( inventory->caughttrout(4.0));
			shots.push_back( inventory->noluck()); 
			shots.push_back(inventory->huntedbuffalo()); 
			shots.push_back( inventory->huntedgrouse()); 
			shots.push_back( inventory->huntedsquirrels(4.0));
			shots.push_back(inventory->noluck());
			shots.push_back(inventory->huntedturkeys(3.0));
			  break;
		case 8: 
			shots.push_back(inventory->huntedturkeys(2.0));
			shots.push_back(inventory->huntedpheasants(2.0));
			shots.push_back( inventory->hunteddeer()); 
			shots.push_back(inventory->noluck()); 
			shots.push_back( inventory->huntedantelope()); 
			shots.push_back( inventory->huntedbear()); 
			shots.push_back( inventory->huntedbuffalo()); 
			shots.push_back( inventory->huntedelk()); 
			shots.push_back( inventory->noluck()); 
			shots.push_back(inventory->huntedgeese(3.0));
			shots.push_back( inventory->huntedducks(3.0));
			shots.push_back( inventory->huntedgrouses(3.0));
			shots.push_back( inventory->huntedrabbits(4.0));
			shots.push_back( inventory->hunteddeer()); 
			shots.push_back(inventory->noluck()); 
			shots.push_back( inventory->huntedpheasants(3.0));
			shots.push_back( inventory->huntedantelope()); 
			shots.push_back( inventory->hunteddeer()); 
			shots.push_back( inventory->huntedelk()); 
			shots.push_back( inventory->huntedgrouse());
			  break;
		case 9: 
			shots.push_back(inventory->huntedantelope());
			shots.push_back( inventory->hunteddeer()); 
			shots.push_back( inventory->huntedelk()); 
			shots.push_back( inventory->noluck()); 
			shots.push_back(inventory->huntedbear()); 
			shots.push_back( inventory->huntedturkeys(2.0));
			shots.push_back( inventory->huntedgeese(3.0));
			shots.push_back( inventory->huntedpheasants(3.0));
			shots.push_back( inventory->noluck()); 
			shots.push_back( inventory->huntedelk()); 
			shots.push_back(inventory->huntedrabbits(3.0));
			shots.push_back( inventory->huntedturkeys(2.0));
			shots.push_back( inventory->hunteddeer()); 
			shots.push_back( inventory->huntedantelope()); 
			shots.push_back( inventory->huntedducks(4.0));
			shots.push_back(inventory->noluck()); 
			shots.push_back( inventory->huntedturkeys(3.0));
			shots.push_back( inventory->hunteddeer());
			shots.push_back( inventory->huntedantelope()); 
			shots.push_back(inventory->huntedbuffalo());
			  break;
		case 10: 
			shots.push_back(inventory->huntedantelope());
			shots.push_back( inventory->huntedantelope()); 
			shots.push_back( inventory->huntedbear()); 
			shots.push_back( inventory->noluck()); 
			shots.push_back(inventory->huntedbuffalo()); 
			shots.push_back( inventory->hunteddeer()); 
			shots.push_back( inventory->hunteddeer()); 
			shots.push_back(inventory->hunteddeer()); 
			shots.push_back( inventory->huntedducks(3.0));
			shots.push_back( inventory->huntedelk()); 
			shots.push_back(inventory->huntedelk()); 
			shots.push_back( inventory->huntedgeese(3.0));
			shots.push_back( inventory->huntedgrouses(4.0));
			shots.push_back( inventory->noluck()); 
			shots.push_back( inventory->huntedpheasants(3.0));
			shots.push_back( inventory->huntedturkeys(3.0));
			shots.push_back(inventory->huntedturkeys(2.0));
			shots.push_back( inventory->huntedrabbits(4.0));
			shots.push_back( inventory->huntedrabbits(4.0));
			shots.push_back( inventory->hunteddeer());
			   break;
		case 11: 
			shots.push_back(inventory->huntedturkeys(4.0));
			shots.push_back( inventory->huntedturkeys(3.0));
			shots.push_back( inventory->huntedrabbits(5.0));
			shots.push_back(inventory->huntedpheasants(3.0));
			shots.push_back( inventory->huntedpheasants(4.0));
			shots.push_back( inventory->huntedgrouses(3.0));
			shots.push_back( inventory->huntedelk());
			shots.push_back( inventory->huntedelk()); 
			shots.push_back(inventory->huntedducks(6.0));
			shots.push_back( inventory->hunteddeer()); 
			shots.push_back( inventory->hunteddeer()); 
			shots.push_back( inventory->hunteddeer()); 
			shots.push_back( inventory->huntedbuffalo()); 
			shots.push_back( inventory->noluck()); 
			shots.push_back(inventory->huntedbear()); 
			shots.push_back( inventory->huntedantelope()); 
			shots.push_back( inventory->huntedantelope()); 
			shots.push_back( inventory->noluck()); 
			shots.push_back( inventory->huntedelk(800.0));
			shots.push_back( inventory->hunteddeer(750.0));
			   break;
		case 12: 
			shots.push_back(inventory->huntedbuffalo()); 
			shots.push_back( inventory->huntedbuffalo()); 
			shots.push_back( inventory->huntedantelope()); 
			shots.push_back(inventory->huntedantelope(200.0));
			shots.push_back( inventory->noluck()); 
			shots.push_back( inventory->hunteddeer()); 
			shots.push_back( inventory->hunteddeer(800.0));
			shots.push_back( inventory->hunteddeer(900.0));
			shots.push_back( inventory->huntedelk()); 
			shots.push_back(inventory->huntedelk(1000.0));
			shots.push_back( inventory->huntedturkeys(4.0));
			shots.push_back( inventory->huntedrabbits(10.0));
			shots.push_back( inventory->huntedducks(6.0));
			shots.push_back( inventory->huntedgrouses(4.0));
			shots.push_back(inventory->huntedgeese(5.0));
			shots.push_back( inventory->huntedducks(4.0));
			shots.push_back( inventory->hunteddeer());
			shots.push_back( inventory->caughttrout(10.0));
			shots.push_back( inventory->huntedpheasants(3.0));
			shots.push_back( inventory->huntedsquirrels(10.0));
			   break;
		}
	}

	// Hunt for each player
	void GoHunting::hunt(vector<CTPlayer> players) {
		cout << endl << "YOUR GROUP IS OUT HUNTING ------------------------------" << endl;
		CTWildGame* game = new CTWildGame();
		for (auto player : players) {
			cout << player.getName() << " aiming...." << endl;
			switch (player.getLuck()) {
			case 1: setPossibilites(1);
				game = fireShot();
				processGame(game, player);
				break;
			case 2: setPossibilites(2);
				game = fireShot();
				processGame(game, player);
				break;
			case 3:setPossibilites(3);
				game = fireShot();
				processGame(game, player);
				break;
			case 4:
				setPossibilites(4);
				game = fireShot();
				processGame(game, player);
				break;
			case 5:
				setPossibilites(5);
				game = fireShot();
				processGame(game, player);
				break;
			case 6:
				setPossibilites(6);
				game = fireShot();
				processGame(game, player);
				break;
			case 7:
				setPossibilites(7);
				game = fireShot();
				processGame(game, player);
				break;
			case 8:
				setPossibilites(8);
				game = fireShot();
				processGame(game, player);
				break;
			case 9:
				setPossibilites(9);
				game = fireShot();
				processGame(game, player);
				break;
			case 10:
				setPossibilites(10);
				game = fireShot();
				processGame(game, player);
				break;
			case 11:
				setPossibilites(11);
				game = fireShot();
				processGame(game, player);
				break;
			case 12:
				setPossibilites(1);
				game = fireShot();
				processGame(game, player);
				break;
			}
		}
		fadeoff();
	}

	// Get a random item from the hunting possibilites
	CTWildGame* GoHunting::fireShot() {
		srand((unsigned)time(0));
		int shot = rand() % 20;
		int shot2 = rand() % 20;
		int shot3 = rand() % 20;
		int shot4 = rand() % 20;
		int shot5 = rand() % 20;
		int theShot = (shot + shot2 + shot3 + shot4 + shot5) % 5;
		return shots.at(theShot);
	}

	// Display to players what they got and give them a chance to sell or add to their inventory
	void GoHunting::processGame(CTWildGame* game, CTPlayer player) {
		if (game->getItemName() != "No luck today!") {
			cout << "ANIMAL(S) SHOT: " << game->getItemName() << ", " << game->getItemSize();
			if (game->isByThePound()) {
				cout << "lbs. It is worth $" << game->getItemPrice() << " per pound for a total of $" << game->getGamePrice() << endl;
			}
			else cout << ". They are worth $" << game->getGamePrice() << " each" << endl;
			cout << "You have $" << player.getWalletTotal() << " in your wallet." << endl;
			cout << "Would you like to sell your hunt? (y/n) ";
			char yesNo;
			cin >> yesNo;
			while (yesNo != 'y' && yesNo != 'n') {
				cout << "Invalid input, please try again (y/n) ";
				cin >> yesNo;
			}
			if (yesNo == 'y') {
				cout << "Adding $" << game->getGamePrice() << " to your wallet" << endl;
				player.paycheck(game->getGamePrice());
				cout << "Wallet total: $" << player.getWalletTotal() << endl;
			}
			else {
				cout << "Adding " << game->getItemName() << " to your food inventory" << endl;
				player.addToFoodInventory(game);
			}
		}
		else cout << game->getItemName() << endl;
	}
}
