#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <windows.h>
#include "CTDate.h"
#include "CTPlayer.h"
#include "CTLocation.h"
#include "CTQuestion.h"
using namespace std;

namespace CSC234 {
	class CTTimeline {
	public:
		CTTimeline();
		CTTimeline(int, int);
	private:
		vector<CTPlayer> players;
		CTDate date;
		CTInventory* generalInventory = new CTInventory("makeGeneralInventory", 10);
		GeneralStore* generalStore = new GeneralStore("General Store", 1, generalInventory);
		GoHunting* hunting = new GoHunting();
		CTCity* aurariaCity = new CTCity("Auraria City", "CTCaurariacityintro.txt", generalStore, hunting);

		CTDate minerTimeline[10] = {
			CTDate('S',1,1,1859, new CTNews("CTD01011859.txt"), aurariaCity, new CTAskQuestions(1)),
			CTDate('U',1,23,1859, new CTNews("CTD01151859.txt"), aurariaCity, new CTAskQuestions(2)),
			CTDate('U',2,6,1859, new CTNews("CTD02061859.txt"), aurariaCity, new CTAskQuestions(3)),
			CTDate('U',2,27,1859, new CTNews("CTD02271859.txt"), aurariaCity, new CTAskQuestions(3)),
			CTDate('U',3,13,1859, new CTNews("CTD03131859.txt"), aurariaCity, new CTAskQuestions(3)),
			CTDate('U',3,27,1859, new CTNews("CTD03271859.txt"), aurariaCity, new CTAskQuestions(3)),
			CTDate('U',4,10,1859, new CTNews("CTD03271859.txt"), aurariaCity, new CTAskQuestions(3)),
			CTDate('U',4,24,1859, new CTNews("CTD04241859.txt"), aurariaCity, new CTAskQuestions(3)),
			CTDate('U',5,8,1859, new CTNews("CTD05081859.txt"), aurariaCity, new CTAskQuestions(3)),
			CTDate('U',5,22,1859, new CTNews("CTD05221859.txt"), aurariaCity, new CTAskQuestions(3))
		};
	};
}
