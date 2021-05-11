#include "CTClothing.h"
#include <iostream>
using namespace std;

namespace CSC234 {
	// Create the default outfit
	CTClothing::CTClothing() {
		hat = clothes.hatfelt();
		shirt = clothes.shirtworkcotton();
		belt = clothes.leatherbelt();
		pants = clothes.pantsworkdenim();
		shoes = clothes.bootsworkleather();
		socks = clothes.sockswool();
		hands = clothes.emptyClothes();
		misc = clothes.necktie();
		midlayer = clothes.coatjacket();
		outerlayer = clothes.emptyClothes();
		warmth = howWarmAreThey();
	}

	// Display the player's outfit
	void CTClothing::printOutfit() {
		cout << "You're wearing a " << shirt->getItemName() << " and " << pants->getItemName() << endl
			<< "with " << shoes->getItemName() << " over " << socks->getItemName() << "." << endl;
		if (hat->getItemName() != "" || belt->getItemName() != "" || hands->getItemName() != ""
			|| misc->getItemName() != "" || midlayer->getItemName() != "" || outerlayer->getItemName() != "") {
			cout << "You also have on";
			if (hat->getItemName() != "") cout << " " << hat->getItemName();
			if (belt->getItemName() != "") cout << ", " << belt->getItemName();
			if (hands->getItemName() != "") cout << ", " << hands->getItemName();
			if (misc->getItemName() != "") cout << ", " << misc->getItemName();
			if (midlayer->getItemName() != "") cout << ", " << midlayer->getItemName();
			if (outerlayer->getItemName() != "") cout << ", " << outerlayer->getItemName();
		}
		cout << endl << "Your outfit warmth is... " << howWarmAreThey() << endl;
	}

	// Check the total sum of clothing warmth against the temp input for summer
	bool CTClothing::summerReady(int temp) {
		howWarmAreThey();
		if (temp > 80) return (warmth < 8);
		else if (temp > 70) return (warmth < 9);
		else if (temp > 60) return (warmth < 10);
		else if (temp > 50)	return (warmth < 11);
		else if (temp > 40) return (warmth < 12);
		else return warmth < 13;
	}

	// Check the total sum of clothing warmth against the temp input for winter
	bool CTClothing::winterReady(int temp) {
		howWarmAreThey();
		if (temp < 50) return (warmth > 11);
		else if (temp < 40) return (warmth > 12);
		else if (temp < 30) return (warmth > 13);
		else if (temp < 20) return (warmth > 14);
		else if (temp < 10) return (warmth > 15);
		else if (temp < 0) return (warmth > 16);
		else return (warmth > 17);
	}

	// Find the total warmth value for the outfit.
	double CTClothing::howWarmAreThey() {
		warmth = hat->howWarm() + shirt->howWarm() 
			+ belt->howWarm() + pants->howWarm() + shoes->howWarm() 
			+ socks->howWarm() + hands->howWarm() + misc->howWarm() 
			+ midlayer->howWarm() + outerlayer->howWarm();
		return warmth;
	}
	void CTClothing::changeClothes(CTItem* newItem) {
	}
}