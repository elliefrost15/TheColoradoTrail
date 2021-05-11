#include "ColoradoTrail.h"
#include <windows.h>
#include <iostream>
#include "CTFunctions.h"
using namespace std;

namespace CSC234 {

	// Colorado Trail constructor
	// Change as other story lines become available
	ColoradoTrail::ColoradoTrail() {
		storyline = 1;
		numPlayers = 1;
		yesNo = 'y';
	}

	// Return a new game to WolfCasino
	ColoradoTrail* ColoradoTrail::makeGame() {
		return new ColoradoTrail();
	}

	// On start begin the run function
	void ColoradoTrail::start() {
		run();
	}

	// Start the game
	void ColoradoTrail::run() {
		clearScreen();
		printSleep("W E L C O M E  T O");
		printFile("CTcoloradotraillogo.txt", 10);
		setStoryline();
		getStoryline(storyline);
	}

	// Prompt user to select storyline
	void ColoradoTrail::setStoryline() {
		printSleep("Please choose your historical experience...");
		printSleep("[1] FiftyNiners, the Miners of 1859");
		printSleep("COMING SOON [2] Homesteaders, the ranchers and land owners of the Rockies");
		printSleep("COMING SOON [3] Snowshoe Messengers, the mailmen of the mountains");
		printSleep("COMING SOON [4] Sugar Beet Hands, the farmers of the high desert");
		printSleep("COMING SOON [5] Soft Footsteps, the Indians meeting a new world");
		printSleep("COMING SOON [6] Industrial Pawns, the factory workers of the growing state");
		cin >> storyline;
		if (storyline == 2) {
			printSleep("Come back and learn more about the hearty adventurers who came");
			printSleep("west in search of land of their own and the freedom to set the");
			printSleep("course of their own destiny. For now, we'll venture towards the gold...");
			printSleep("", 1500);
			storyline = 1;
		}
		else if (storyline == 3) {
			printSleep("We'll have to cross that mountain range another day on homemade");
			printSleep("skis of local pine another day. Today we follow the rush to Pike's Peak.");
			printSleep("", 1500);
			storyline = 1;
		}
		else if (storyline == 4) {
			printSleep("That root is still buried deep, much like the sugar beet itself.");
			printSleep("Let's check into the national fuss over gold in the high country.");
			printSleep("", 1500);
			storyline = 1;
		}
		else if (storyline == 5) {
			printSleep("The scouts are still out in search of information on the Indians.");
			printSleep("While they're out, let's see what the miners are up to...");
			printSleep("", 1500);
			storyline = 1;
		}
		else if (storyline == 6) {
			printSleep("Despite their protests and work danger, there still isn't enough reputable");
			printSleep("information about the work conditions in the factories. But we've got");
			printSleep("a yarn about gold to tell...");
			printSleep("", 1500);
			storyline = 1;
		}
		else {
			storyline = 1;
		}
		clearScreen();
	}

	// Start the storyline selected 
	void ColoradoTrail::getStoryline(int sL) {
		cout << "Is this your first time playing? (y/n) ";
		cin >> yesNo;
		while (yesNo != 'y' && yesNo != 'n') {
			cout << "Invalid input, please try again (y/n) ";
			cin >> yesNo;
		}
		if (yesNo == 'y') { // If it is the first time playing display CThowtoplay.txt
			clearScreen();
			printFile("CThowtoplay.txt", 10);
			fadeoff();
		}
		printFile("CThowmanyplayers.txt", 10);
		cin >> numPlayers;
		while (numPlayers != 1 && numPlayers != 2 && numPlayers != 3 && numPlayers != 4) {
			cout << "Invalid input, please try again (1-4) ";
			cin >> numPlayers;
		}
		clearScreen();
		if (sL == 1) { // Create a new miner timeline
			CTTimeline* minerTimeline = new CTTimeline(sL, numPlayers);
		}
	}
}
