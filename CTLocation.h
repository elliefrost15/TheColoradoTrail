#pragma once
#include <string>
#include "CTInventory.h"
#include "CTPlayer.h"
#include <iostream>
using namespace std;

namespace CSC234 {
	class CTLocation {
	public:
		CTLocation();
		CTLocation(string);
		void printLocation();
	private:
		string name;
	};
	class GeneralStore : public CTLocation {
	public:
		GeneralStore();
		GeneralStore(string, int, CTInventory*);
		GeneralStore(string, int, CTInventory*, int);
		GeneralStore(string, string, int, CTInventory*);
		GeneralStore(string, string, int, CTInventory*, int);
		void printLocation();
		void printLocation(vector<CTPlayer>);
		
	private:
		CTInventory* storeInventory;
		int storeItemQty;
		int storeLevel;
		string storeDesc;
		string storeName;
		void sellItem(CTPlayer*, vector<vector<CTItem*>>);
		int itemIndex;
		char yesNo;
	};
	class GoHunting : public CTLocation {
	public:
		GoHunting();
		void hunt(vector<CTPlayer>);
	private:
		vector<CTWildGame*> shots = {};
		CTInventory* inventory;
		CTWildGame* fireShot();
		void setPossibilites(int);
		void processGame(CTWildGame*, CTPlayer);
	};
}
