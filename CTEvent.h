#pragma once
#include <string>
#include <iostream>
#include "CTItem.h"
using namespace std;

namespace CSC234 {
	class CTEvent {
	public:
		CTEvent();
		CTEvent(string);
		CTEvent(string, int);
		CTEvent(string, double);
		CTEvent(int, string);
		CTEvent(double, string);
		void printEvent();

	private:
		string title;
		int damage;
		double dbldamage;
		int gain;
		double dblgain;
		void goodEvent();
		void badEvent();
		void neutralEvent();
		void propertyLoss();
		void foodLoss();
		void foundItem(CTItem*);
		void receivedGift(CTItem*);
		void trade(CTItem*, CTItem*);

	};
}
