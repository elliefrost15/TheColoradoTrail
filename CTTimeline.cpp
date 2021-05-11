#include "CTTimeline.h"
#include "CTFunctions.h"
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

namespace CSC234 {

	// Default Timeline constructor
	CTTimeline::CTTimeline() {
		players = { new CTPlayer() };
	}

	// Create a timeline based on storyline and number of players
	CTTimeline::CTTimeline(int storyLine, int numPlayers) {
		srand(unsigned(time(0)));
		int random = rand() % 4;
		for (int i = 0; i < numPlayers; i++) {
			CTPlayer* tempplayer = new CTPlayer(random, i);
			players.push_back(*tempplayer);
		}
		fadeoff();
		if (storyLine == 1) {
			printSleep("THE COLORADO TRAIL: Pathway to Statehood, Life of a Fiftyniner", 500);
			printSleep("---------------------------------------------------------------------", 1000);
			date.launch(minerTimeline, this->players);
		}
	}
}
