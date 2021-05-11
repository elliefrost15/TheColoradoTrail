#pragma once
#include <string>
#include <windows.h>
#include "CTInventory.h"
#include "CTClothing.h"
using namespace std;

namespace CSC234 {
	class CTPlayer {
	public:
		CTPlayer();
		CTPlayer(int, int);
		CTPlayer(CTPlayer*);
		CTPlayer(string, string, int, double, CTInventory*);
		CTPlayer(string, string, int, double, CTInventory*, CTClothing*);
		CTPlayer(string, string, int, double, CTInventory*, CTInventory*);

		string getName();
		int getAge();
		string getBio();
		string getBio(string);
		void printBio();
		void printBio(string);
		void editBio(string);
		void getPlayerProfile();
		CTClothing* getClothing();
		void printClothing();
		void changeClothing(CTItem*);

		void increaseLuck();
		void decreaseLuck();
		int getLuck();

		void setWallet(double);
		double getWallet();
		void deposit(double);
		void withdrawl(double);
		double getWalletTotal();
		void paycheck(double); 
		void paycheck(double, int);
		void addGrubstake(double);
		double grubstakeBalance();
		void payGrubstake(double);

		void printAnInventory();
		void printAnInventory(int);
		CTInventory* getInventory();
		void addToInventory(CTItem*);
		CTInventory* getCampInventory();
		void addToCampInventory(CTItem*);
		CTInventory* getFoodInventory();
		void addToFoodInventory(CTItem*);
	private:
		string bio;
		string name;
		int age;
		int luckNumber = 3;
		int playerNumber = 0;
		double walletTotal = 0;
		double grubstake = 0;
		CTInventory* inventory = new CTInventory();
		CTClothing* clothing = new CTClothing();
		CTInventory* campInventory = new CTInventory(vector<CTItem*> { inventory->backgammon(), inventory->candles(), inventory->matches(), inventory->soap(), inventory->billy(), inventory->coffeepot(), inventory->drinkingglass(), inventory->drinkingglass(), inventory->ironpot(), inventory->knifefork(), inventory->knifefork(), inventory->knifefork(), inventory->knifefork() });
		CTInventory* foodInventory = new CTInventory();

		CTPlayer* getGroup(int, int);
		void setName(CTPlayer*);
		void setName(string);
		void setAge(CTPlayer*);
		void setAge(int);
		void setBio(string);
		void setBio(CTPlayer*);
		void setPlayerWallet(CTPlayer*);
		void setPlayerWallet(double);
		void setInventory(CTPlayer*);
		void setInventory(CTInventory*);
		void setCampInventory(CTPlayer*);
		void setCampInventory(CTInventory*);
		void setFoodInventory(CTPlayer*);
		void setFoodInventory(CTInventory*);
		void setClothing(CTPlayer*);
		void setClothing(CTClothing*);

	};
}
