#include <iostream>
#include <vector>
#include "CTPlayer.h"
#include "CTFunctions.h"
using namespace std;

namespace CSC234 {

	// Default player constructor
	CTPlayer::CTPlayer() {
		setName("");
		setAge(0);
		setBio("");
		setPlayerWallet(0.0);
		setInventory(new CTInventory());
		setClothing(new CTClothing());
		getPlayerProfile();
		luckNumber = 0;
	}
	// Alt player constructor
	CTPlayer::CTPlayer(int random, int numPlayer) {
		CTPlayer* pprofile = getGroup(random, numPlayer);
		playerNumber = numPlayer + 1;
		setName(pprofile);
		setAge(pprofile);
		setBio(pprofile);
		setPlayerWallet(pprofile);
		setInventory(pprofile);
		setClothing(new CTClothing());
		getPlayerProfile();
		luckNumber = rand() % 10;
	}
	// Alt player constructor
	CTPlayer::CTPlayer(CTPlayer* pprofile) {
		setName(pprofile);
		setAge(pprofile);
		setBio(pprofile);
		setPlayerWallet(pprofile);
		setInventory(pprofile);
		setClothing(pprofile);
		setFoodInventory(pprofile);
	}
	// Alt player constructor
	CTPlayer::CTPlayer(string pbio, string pname, int page, double pmoney, CTInventory* pinventory) {
		setBio(pbio);
		setName(pname);
		setAge(page);
		setPlayerWallet(pmoney);
		setInventory(pinventory);
		setClothing(new CTClothing());
	}
	// Alt player constructor
	CTPlayer::CTPlayer(string pbio, string pname, int page, double pmoney, CTInventory* pinventory, CTClothing* pclothing) {
		setBio(pbio);
		setName(pname);
		setAge(page);
		setPlayerWallet(pmoney);
		setInventory(pinventory);
		setClothing(pclothing);
	}
	// Alt player constructor
	CTPlayer::CTPlayer(string pbio, string pname, int page, double pmoney, CTInventory* pinventory, CTInventory* pfood) {
		setBio(pbio);
		setName(pname);
		setAge(page);
		setPlayerWallet(pmoney);
		setInventory(pinventory);
		clothing = new CTClothing();
		setFoodInventory(pfood);
	}
	
	// Create different player profiles in a group
	CTPlayer* CTPlayer::getGroup(int random, int playerNum) {
		if (random == 0) {
			CTPlayer* profileArrayOne[4] = {
				new CTPlayer("CTPsamplebio.txt", "Jacob Devault", 40, 104.30, 
					new CTInventory(vector<CTItem*>{inventory->soap(), inventory->tincup(),
						inventory->pocketknife(), inventory->shovel(), inventory->pickaxe(), inventory->crackers()}, 20),
					new CTInventory(vector<CTItem*>{new CTFood("Flour by the pound",0.0,20.0,40.0),
						new CTFood("Pounds of Bacon",0.0,5.0,10.0), 
						new CTFood("Pounds of Coffee",0.0,1.0,34.0), 
						new CTItem("Pounds of Rice", 0.0,5.0,15.0), 
						new CTFood("Beans",0.0,10.0,40.0), 
						new CTFood("Dried Apples", 0.0,2.0,14.0), 
						new CTFood("Cornmeal",0.0,5.0,25.0), 
						new CTFood("Lard",0.0,10,24), 
						new CTFood("Potatoes", 0.0,10.0,30.0)},9)), //Illinois vector<CTItem*> { candles, soap, billy, } , 20
				new CTPlayer("CTPsamplebio.txt", "Charles Devault", 30, 94.25, 
					new CTInventory(vector<CTItem*>{inventory->soap(), inventory->tincup(),inventory->pocketknife(), inventory->shovel(), inventory->pickaxe(), inventory->crackers()}, 20),
					new CTInventory(vector<CTItem*>{new CTFood("Flour by the pound",0.0,22.0,50.0),new CTFood("Pounds of Bacon",0.0,6.0,7.0), new CTFood("Pounds of Coffee",0.0,1.0,34.0), new CTItem("Pounds of Rice", 0.0,4.0,12.0), new CTFood("Beans",0.0,12.0,50.0), new CTFood("Dried Apples",0.0,1.0,7.0), new CTFood("Cornmeal",0.0,4.0,20.0), new CTFood("Lard",0.0,12,29), new CTFood("Potatoes", 0.0,11.0,33.0)},9)), //Ohio
				new CTPlayer("CTPsamplebio.txt", "Joseph Charles Devault", 23, 63.45, 
					new CTInventory(vector<CTItem*>{inventory->soap(), inventory->tincup(),inventory->pocketknife(), inventory->shovel(), inventory->pickaxe(), inventory->crackers()}, 20),
					new CTInventory(vector<CTItem*>{new CTFood("Flour by the pound",0.0,20.0,40.0),new CTFood("Pounds of Bacon",0.0,5.0,10.0), new CTFood("Pounds of Coffee",0.0,1.0,34.0), new CTItem("Pounds of Rice", 0.0,5.0,15.0), new CTFood("Beans",0.0,10.0,40.0), new CTFood("Dried Apples", 0.0,2.0,14.0), new CTFood("Cornmeal",0.0,5.0,25.0), new CTFood("Lard",0.0,10,24), new CTFood("Potatoes", 0.0,10.0,30.0)},9)), //Ohio
				new CTPlayer("CTPsamplebio.txt", "Lewis Devault", 41, 115.30, 
					new CTInventory(vector<CTItem*>{inventory->soap(), inventory->tincup(),inventory->pocketknife(), inventory->shovel(), inventory->pickaxe(), inventory->crackers()}, 20),
					new CTInventory(vector<CTItem*>{new CTFood("Flour by the pound",0.0,22.0,50.0),new CTFood("Pounds of Bacon",0.0,6.0,7.0), new CTFood("Pounds of Coffee",0.0,1.0,34.0), new CTItem("Pounds of Rice", 0.0,4.0,12.0), new CTFood("Beans",0.0,12.0,50.0), new CTFood("Dried Apples",0.0,1.0,7.0), new CTFood("Cornmeal",0.0,4.0,20.0), new CTFood("Lard",0.0,12,29), new CTFood("Potatoes", 0.0,11.0,33.0)},9)) //Ohio
			};
			return profileArrayOne[playerNum];
		}
		else if (random == 1) {
			CTPlayer* profileArrayTwo[4] = {
				new CTPlayer("CTPsamplebio.txt", "James Thomas Evans", 22, 130.45,
					new CTInventory(vector<CTItem*>{inventory->soap(), inventory->tincup(),inventory->pocketknife(), inventory->shovel(), inventory->pickaxe(), inventory->crackers()}, 20),
					new CTInventory(vector<CTItem*>{inventory->flourlb(),new CTFood("Flour by the pound",0.0,20.0,40.0),new CTFood("Pounds of Bacon",0.0,5.0,10.0), new CTFood("Pounds of Coffee",0.0,1.0,34.0), new CTItem("Pounds of Rice", 0.0,5.0,15.0), new CTFood("Beans",0.0,10.0,40.0), new CTFood("Dried Apples", 0.0,2.0,14.0), new CTFood("Cornmeal",0.0,5.0,25.0), new CTFood("Lard",0.0,10,24), new CTFood("Potatoes", 0.0,10.0,30.0)},9)), //Pennsylvania
				new CTPlayer("CTPsamplebio.txt", "William Green", 40, 225.45,
					new CTInventory(vector<CTItem*>{inventory->soap(), inventory->tincup(),inventory->pocketknife(), inventory->shovel(), inventory->pickaxe(), inventory->crackers()}, 20),
					new CTInventory(vector<CTItem*>{new CTFood("Flour by the pound",0.0,22.0,50.0),new CTFood("Pounds of Bacon",0.0,6.0,7.0), new CTFood("Pounds of Coffee",0.0,1.0,34.0), new CTItem("Pounds of Rice", 0.0,4.0,12.0), new CTFood("Beans",0.0,12.0,50.0), new CTFood("Dried Apples",0.0,1.0,7.0), new CTFood("Cornmeal",0.0,4.0,20.0), new CTFood("Lard",0.0,12,29), new CTFood("Potatoes", 0.0,11.0,33.0)},9)), //England
				new CTPlayer("CTPsamplebio.txt", "Samuel Larry Davis", 27, 98.30,
					new CTInventory(vector<CTItem*>{inventory->soap(), inventory->tincup(),inventory->pocketknife(), inventory->shovel(), inventory->pickaxe(), inventory->crackers()}, 20),
					new CTInventory(vector<CTItem*>{new CTFood("Flour by the pound",0.0,20.0,40.0),new CTFood("Pounds of Bacon",0.0,5.0,10.0), new CTFood("Pounds of Coffee",0.0,1.0,34.0), new CTItem("Pounds of Rice", 0.0,5.0,15.0), new CTFood("Beans",0.0,10.0,40.0), new CTFood("Dried Apples", 0.0,2.0,14.0), new CTFood("Cornmeal",0.0,5.0,25.0), new CTFood("Lard",0.0,10,24), new CTFood("Potatoes", 0.0,10.0,30.0)},9)), //New York
				new CTPlayer("CTPsamplebio.txt", "Martin Hagar", 40, 160.45,
					new CTInventory(vector<CTItem*>{inventory->soap(), inventory->tincup(),inventory->pocketknife(), inventory->shovel(), inventory->pickaxe(), inventory->crackers()}, 20),
					new CTInventory(vector<CTItem*>{new CTFood("Flour by the pound",0.0,22.0,50.0),new CTFood("Pounds of Bacon",0.0,6.0,7.0), new CTFood("Pounds of Coffee",0.0,1.0,34.0), new CTItem("Pounds of Rice", 0.0,4.0,12.0), new CTFood("Beans",0.0,12.0,50.0), new CTFood("Dried Apples",0.0,1.0,7.0), new CTFood("Cornmeal",0.0,4.0,20.0), new CTFood("Lard",0.0,12,29), new CTFood("Potatoes", 0.0,11.0,33.0)},9)) // Prussia
			};
			return profileArrayTwo[playerNum];
		}
		else if (random == 2) {
			CTPlayer* profileArrayThree[4] = {
				new CTPlayer("CTPsamplebio.txt", "Robert Clark", 38, 145.70, 
					new CTInventory(vector<CTItem*>{inventory->soap(), inventory->tincup(),inventory->pocketknife(), inventory->shovel(), inventory->pickaxe(), inventory->crackers()}, 20),
					new CTInventory(vector<CTItem*>{inventory->flourlb(),new CTFood("Flour by the pound",0.0,20.0,40.0),new CTFood("Pounds of Bacon",0.0,5.0,10.0), new CTFood("Pounds of Coffee",0.0,1.0,34.0), new CTItem("Pounds of Rice", 0.0,5.0,15.0), new CTFood("Beans",0.0,10.0,40.0), new CTFood("Dried Apples", 0.0,2.0,14.0), new CTFood("Cornmeal",0.0,5.0,25.0), new CTFood("Lard",0.0,10.0,24.0), new CTFood("Potatoes", 0.0,10.0,30.0)},9)), //Indiana
				new CTPlayer("CTPsamplebio.txt", "John Reasoner", 30, 132.40,
					new CTInventory(vector<CTItem*>{inventory->soap(), inventory->tincup(),inventory->pocketknife(), inventory->shovel(), inventory->pickaxe(), inventory->crackers()}, 20),
					new CTInventory(vector<CTItem*>{new CTFood("Flour by the pound",0.0,22.0,50.0),new CTFood("Pounds of Bacon",0.0,6.0,7.0), new CTFood("Pounds of Coffee",0.0,1.0,34.0), new CTItem("Pounds of Rice", 0.0,4.0,12.0), new CTFood("Beans",0.0,12.0,50.0), new CTFood("Dried Apples",0.0,1.0,7.0), new CTFood("Cornmeal",0.0,4.0,20.0), new CTFood("Lard",0.0,12.0,29.0), new CTFood("Potatoes", 0.0,11.0,33.0)},9)), //Ohio
				new CTPlayer("CTPsamplebio.txt", "Garret Reasoner", 27,109.25,
					new CTInventory(vector<CTItem*>{inventory->soap(), inventory->tincup(),inventory->pocketknife(), inventory->shovel(), inventory->pickaxe(), inventory->crackers()}, 20),
					new CTInventory(vector<CTItem*>{new CTFood("Flour by the pound",0.0,20.0,40.0),new CTFood("Pounds of Bacon",0.0,5.0,10.0), new CTFood("Pounds of Coffee",0.0,1.0,34.0), new CTItem("Pounds of Rice", 0.0,5.0,15.0), new CTFood("Beans",0.0,10.0,40.0), new CTFood("Dried Apples", 0.0,2.0,14.0), new CTFood("Cornmeal",0.0,5.0,25.0), new CTFood("Lard",0.0,10.0,24.0), new CTFood("Potatoes", 0.0,10.0,30.0)},9)), //Indiana
				new CTPlayer("CTPsamplebio.txt", "John Reasoner", 19, 74.30, 
				new CTInventory(vector<CTItem*>{inventory->soap(), inventory->tincup(),inventory->pocketknife(), inventory->shovel(), inventory->pickaxe(), inventory->crackers()}, 20),
					new CTInventory(vector<CTItem*>{new CTFood("Flour by the pound",0.0,22.0,50.0),new CTFood("Pounds of Bacon",0.0,6.0,7.0), new CTFood("Pounds of Coffee",0.0,1.0,34.0), new CTItem("Pounds of Rice", 0.0,4.0,12.0), new CTFood("Beans",0.0,12.0,50.0), new CTFood("Dried Apples",0.0,1.0,7.0), new CTFood("Cornmeal",0.0,4.0,20.0), new CTFood("Lard",0.0,12.0,29.0), new CTFood("Potatoes", 0.0,11.0,33.0)},9)) //Indiana
			};
			return profileArrayThree[playerNum];
		}
		else if (random == 3) {
			CTPlayer* profileArrayFour[4] = {
				new CTPlayer("CTPsamplebio.txt","Ralph Lowe", 40, 147.30, 
					new CTInventory(vector<CTItem*>{inventory->soap(), inventory->tincup(),inventory->pocketknife(), inventory->shovel(), inventory->pickaxe(), inventory->crackers()}, 20),
					new CTInventory(vector<CTItem*>{inventory->flourlb(),new CTFood("Flour by the pound",0.0,20.0,40.0),new CTFood("Pounds of Bacon",0.0,5.0,10.0), new CTFood("Pounds of Coffee",0.0,1.0,34.0), new CTItem("Pounds of Rice", 0.0,5.0,15.0), new CTFood("Beans",0.0,10.0,40.0), new CTFood("Dried Apples", 0.0,2.0,14.0), new CTFood("Cornmeal",0.0,5.0,25.0), new CTFood("Lard",0.0,10.0,24.0), new CTFood("Potatoes", 0.0,10.0,30.0)},9)),//Maine
				new CTPlayer("CTPsamplebio.txt","Christof Holk", 30, 130.25,
					new CTInventory(vector<CTItem*>{inventory->soap(), inventory->tincup(),inventory->pocketknife(), inventory->shovel(), inventory->pickaxe(), inventory->crackers()}, 20),
					new CTInventory(vector<CTItem*>{new CTFood("Flour by the pound",0.0,22.0,50.0),new CTFood("Pounds of Bacon",0.0,6.0,7.0), new CTFood("Pounds of Coffee",0.0,1.0,34.0), new CTItem("Pounds of Rice", 0.0,4.0,12.0), new CTFood("Beans",0.0,12.0,50.0), new CTFood("Dried Apples",0.0,1.0,7.0), new CTFood("Cornmeal",0.0,4.0,20.0), new CTFood("Lard",0.0,12.0,29.0), new CTFood("Potatoes", 0.0,11.0,33.0)},9)),//Denmark
				new CTPlayer("CTPsamplebio.txt","Fredrik Asmusser", 35, 160.25, 
					new CTInventory(vector<CTItem*>{inventory->soap(), inventory->tincup(),inventory->pocketknife(), inventory->shovel(), inventory->pickaxe(), inventory->crackers()}, 20),
					new CTInventory(vector<CTItem*>{new CTFood("Flour by the pound",0.0,20.0,40.0),new CTFood("Pounds of Bacon",0.0,5.0,10.0), new CTFood("Pounds of Coffee",0.0,1.0,34.0), new CTItem("Pounds of Rice", 0.0,5.0,15.0), new CTFood("Beans",0.0,10.0,40.0), new CTFood("Dried Apples", 0.0,2.0,14.0), new CTFood("Cornmeal",0.0,5.0,25.0), new CTFood("Lard",0.0,10.0,24.0), new CTFood("Potatoes", 0.0,10.0,30.0)},9)), //Denmark
				new CTPlayer("CTPsamplebio.txt", "Henry Hager", 28, 180.95,
					new CTInventory(vector<CTItem*>{inventory->soap(), inventory->tincup(),inventory->pocketknife(), inventory->shovel(), inventory->pickaxe(), inventory->crackers()}, 20),
					new CTInventory(vector<CTItem*>{new CTFood("Flour by the pound",0.0,22.0,50.0),new CTFood("Pounds of Bacon",0.0,6.0,7.0), new CTFood("Pounds of Coffee",0.0,1.0,34.0), new CTItem("Pounds of Rice", 0.0,4.0,12.0), new CTFood("Beans",0.0,12.0,50.0), new CTFood("Dried Apples",0.0,1.0,7.0), new CTFood("Cornmeal",0.0,4.0,20.0), new CTFood("Lard",0.0,12.0,29.0), new CTFood("Potatoes", 0.0,11.0,33.0)},9))//Bavaria
			};
			return profileArrayFour[playerNum];
		}
		else return new CTPlayer();
	}

	// Player maintenence
	void CTPlayer::setName(CTPlayer* profile) { name = profile->getName(); }
	void CTPlayer::setName(string pname) { name = pname; }
	string CTPlayer::getName() { return name; }
	void CTPlayer::setAge(CTPlayer* profile) { age = profile->getAge(); }
	void CTPlayer::setAge(int page) { age = page; } 
	int CTPlayer::getAge() { return age; }
	void CTPlayer::setBio(CTPlayer* profile) { bio = profile->getBio(); }
	void CTPlayer::setBio(string filename) { bio = filename; } 
	string CTPlayer::getBio() { return this->bio; } 
	string CTPlayer::getBio(string filename) { return filename; }
	void CTPlayer::printBio() { printFile(this->bio); } 
	void CTPlayer::printBio(string filename) { printFile(filename); }
	void CTPlayer::editBio(string edit) {	}
	void CTPlayer::setPlayerWallet(CTPlayer* profile) { walletTotal = profile->getWallet(); }
	void CTPlayer::setPlayerWallet(double money) { walletTotal = money; }
	void CTPlayer::setInventory(CTPlayer* profile) { inventory = profile->getInventory(); }
	void CTPlayer::setInventory(CTInventory* inv) { inventory = inv; }
	void CTPlayer::setCampInventory(CTPlayer* profile) { inventory = profile->getCampInventory(); }
	void CTPlayer::setCampInventory(CTInventory* inv) { campInventory = inv; }
	void CTPlayer::setFoodInventory(CTPlayer* profile) { inventory = profile->getFoodInventory(); }
	void CTPlayer::setFoodInventory(CTInventory* inv) { foodInventory = inv; }
	void CTPlayer::setClothing(CTPlayer* profile) { clothing = profile->getClothing(); }
	void CTPlayer::setClothing(CTClothing* clothes) { clothing = clothes; }
	CTClothing* CTPlayer::getClothing() { return clothing; }
	void CTPlayer::printClothing() { clothing->printOutfit(); }
	void CTPlayer::changeClothing(CTItem* newclothes) { clothing->changeClothes(newclothes); }
	double CTPlayer::getWallet() { return walletTotal; } 

	// Print one of the player's inventories
	void CTPlayer::printAnInventory() {
		cout << "Which inventory would you like to print?" << endl
			<< "[1] Personal Inventory" << endl
			<< "[2] Food Inventory" << endl
			<< "[3] Camp Inventory (shared)" << endl
			<< "[4] Clothing" << endl;
		int print;
		cin >> print;
		switch (print) {
		case 1: inventory->printPersonalInventory(); break;
		case 2: foodInventory->printFoodInventory(); break;
		case 3: campInventory->printCampInventory(); break;
		case 4: clothing->printOutfit(); break;
		default: break;
		}
		cout << "Do you want to print another inventory? (y/n) ";
		char yesNo;
		cin >> yesNo;
		while (yesNo != 'y' && yesNo != 'n') {
			cout << "Invalid input, please try again (y/n) ";
			cin >> yesNo;
		}
		if (yesNo == 'y') printAnInventory();
	}

	// Print a specific inventory
	void CTPlayer::printAnInventory(int print) {
		switch (print) {
		case 1: inventory->printPersonalInventory(); break;
		case 2: foodInventory->printFoodInventory(); break;
		case 3: campInventory->printCampInventory(); break;
		case 4: clothing->printOutfit(); break;
		default: break;
		}
	}
	
	// Player inventory maintenence
	CTInventory* CTPlayer::getInventory() { return inventory; }
	void CTPlayer::addToInventory(CTItem* newItem) { inventory->addItem(newItem); }
	CTInventory* CTPlayer::getCampInventory() { return campInventory; }
	void CTPlayer::addToCampInventory(CTItem* newItem) { campInventory->addItem(newItem); }
	CTInventory* CTPlayer::getFoodInventory() { return foodInventory; }
	void CTPlayer::addToFoodInventory(CTItem* newItem) { foodInventory->addItem(newItem); }

	// Print player profile
	void CTPlayer::getPlayerProfile() {
		cout << "PLAYER " << playerNumber << " Your character is........" << endl;
		cout << name << ", age " << age << ", wallet contents ";
		printf("$%3.2f\n", walletTotal);
		Sleep(500);
		cout << "PERSONAL INVENTORY: " << endl;
		inventory->printList();
		Sleep(500);
		cout << "FOOD STORE: " << endl;
		foodInventory->printFoodInventory();
		Sleep(500);
		cout << "SHARED CAMP ITEMS: " << endl;
		campInventory->printCampInventory();
		printFile("CTPsamplebio.txt",200);
		cout << endl;
		clothing->printOutfit();
		cout << "----------------------------------------------------------------------" << endl;
	}

	// Player maintenence
	void CTPlayer::increaseLuck() { luckNumber++; } 
	void CTPlayer::decreaseLuck() { luckNumber--; }
	int CTPlayer::getLuck() { return luckNumber; }
	void CTPlayer::setWallet(double money) { walletTotal = money; } 
	double CTPlayer::getWalletTotal() { return walletTotal; } 
	void CTPlayer::deposit(double money) { walletTotal = walletTotal + money; }
	void CTPlayer::withdrawl(double money) { walletTotal = walletTotal - money; }
	void CTPlayer::paycheck(double pay) { walletTotal = walletTotal + pay; }
	void CTPlayer::paycheck(double pay, int date) { }
	void CTPlayer::addGrubstake(double newgrubstake) { grubstake = newgrubstake; }
	double CTPlayer::grubstakeBalance() { return grubstake; }
	void CTPlayer::payGrubstake(double grubpay) { grubstake = grubstake - grubpay; }
}
