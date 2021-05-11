#pragma once
#include "CTItem.h"
#include "CTInventory.h"
using namespace std;

namespace CSC234 {
	class CTClothing {
	public:
		CTClothing();
		void printOutfit();
		bool summerReady(int);
		bool winterReady(int);
		void changeClothes(CTItem*);
	private:
		CTInventory clothes;
		CTClothes* hat;
		CTClothes* shirt;
		CTClothes* pants;
		CTClothes* belt;
		CTClothes* shoes;
		CTClothes* socks;
		CTClothes* hands;
		CTClothes* misc;
		CTClothes* midlayer;
		CTClothes* outerlayer;
		double howWarmAreThey();
		double warmth;
	};
}