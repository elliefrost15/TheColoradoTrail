#include "CTEvent.h"

namespace CSC234 {

	CTEvent::CTEvent() {
		title = "";
		damage = 0;
		dbldamage = 0;
		gain = 0;
		dblgain = 0;
	}

	CTEvent::CTEvent(string newTitle) {
		title = newTitle;
	}

	CTEvent::CTEvent(string newTitle, int newDamage) {
		title = newTitle;
		damage = newDamage;
	}

	CTEvent::CTEvent(string newTitle, double newDamage) {
		title = newTitle;
		dbldamage = newDamage;
	}

	CTEvent::CTEvent(int newGain, string newTitle) {
		title = newTitle;
		gain = newGain;
	}

	CTEvent::CTEvent(double newGain, string newTitle) {
		title = newTitle;
		dblgain = newGain;
	}

	void CTEvent::printEvent() {
		cout << title << endl;
	}

	void CTEvent::goodEvent() {

	}

	void CTEvent::badEvent() {

	}

	void CTEvent::neutralEvent() {

	}

	void CTEvent::propertyLoss() {

	}

	void CTEvent::foodLoss() {

	}

	void CTEvent::foundItem(CTItem*) {

	}

	void CTEvent::receivedGift(CTItem*) {

	}

	void CTEvent::trade(CTItem*, CTItem*) {

	}

}
