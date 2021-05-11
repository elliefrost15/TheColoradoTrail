#pragma once
#include <string>
#include <vector>
using namespace std;

namespace CSC234 {
	class CTItem {
	public:
		CTItem();
		CTItem(string);
		CTItem(string, double);
		CTItem(string, double, int);
		CTItem(string, double, double);
		CTItem(string, double, int, int);
		CTItem(string, double, double, double);
		CTItem(string, double, double, int);
		CTItem(string, double, double, double, bool, bool, bool, bool);
		CTItem(bool, string, double, double, double, bool, bool, bool, bool);
		CTItem(bool, bool, string, double, double, double);
		string getItemName();
		double getItemPrice();
		double findFullPrice();
		double getItemSize();
		void setFullSize(double);
		double findFullSize();
		void setFullLife();
		double findFullLife();
		double getItemLife();
		void buyMultiple(double);
		bool isFood();
		bool isClothing();
		bool isHousehold();
		bool isMisc();
		bool isProtein();
		bool isCarb();
		bool isFruitVeg();
		bool isHunting();
		bool isByThePound();
		bool forSummer();
		bool forWinter();
		void printItem();
		void printPersonalItem();
		void printFoodItem();
		void printCampItem();
		void printStoreItem();
		void printClothingItem();
		bool needToReplenish();
		double howWarm();
		double howFilling();
		double howGoodForYou();
		double whatKindOfFood();
	protected:
		string name;
		double price;
		double totalPrice = 0;
		double size;
		double fullSize = 0;
		double life;
		double fullLife = 0;
		double noexpiration = 1000.0;
		bool carb = false;
		bool clothing = false;
		bool food = false;
		bool fruitVeg = false;
		bool household = false;
		bool hunting = false;
		bool misc = true;
		bool pound = false;
		bool protein = false;
		bool replenish = false;
		bool summer = false;
		bool winter = false;
		double warmth = 0;
		double foodCategory = 99.9;
		double howFillingNum = 0;
		double howGood = 0;

	};
	class CTClothes : public CTItem {
	public:
		CTClothes();
		CTClothes(string, double, double);
		CTClothes(string, double, double, bool, bool, double, double);

	private:
		int clothingCategory;
	};
	class CTFood : public CTItem {
	public:
		CTFood();
		CTFood(string, double, double);
		CTFood(string, double, double, double);
		CTFood(string, double, double, double, double);
		CTFood(string, double, double, double, double, double);
		CTFood(bool, string, double, double, double, double);
		CTFood(bool,bool, string, double, double, double);
	};
	class CTProtein : public CTFood {
	public: CTProtein();
		  CTProtein(bool, string, double, double, double);
	};
	class CTFruitVeg : public CTFood {
	public: CTFruitVeg();
		  CTFruitVeg(bool, string, double, double, double);
	};
	class CTCarb : public CTFood {
	public: CTCarb();
		  CTCarb(bool,bool,string, double, double, double);
	};
	class CTHuntItems : public CTItem {
	public:
		CTHuntItems();
		CTHuntItems(string, double, double, double);
		CTHuntItems(string, double, double, double, bool, bool, bool, bool);
		CTHuntItems(bool, string, double, double, double);
		int makeBullets();
	};
	class CTBullets : public CTHuntItems {
	public: 
		CTBullets();
		CTBullets(int);
		void fireShots(int);
		void stockBullets(int);
	private:
		int numberOfBullets;
	};
	class CTWildGame : public CTItem {
	public:
		CTWildGame();
		CTWildGame(string, double);
		CTWildGame(string, double, double);
		CTWildGame(string, double, double, double);
		CTWildGame(bool, string, double, double, double);
		double getGamePrice();
	private:
		double animalPrice = 0;
	};
	class CTHousehold : public CTItem {
	public:
		CTHousehold();
		CTHousehold(string, double);
	};
}
