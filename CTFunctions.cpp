#include "CTFunctions.h"
#include <fstream>
#include <windows.h>
#include <string>
#include <iostream>
using namespace std;

namespace CSC234 {
	// Print a txt file
	void printFile(string filename) {
		string line;
		fstream monologue;
		monologue.open(filename);
		while (getline(monologue, line)) {
			printSleep(line);
		}
		monologue.close();
	}
	// Print a txt file
	void printFile(string filename, int time) {
		string line;
		fstream monologue;
		monologue.open(filename);
		while (getline(monologue, line)) {
			printSleep(line, time);
		}
		monologue.close();
	}
	// Delay print
	void printSleep(string text) {
		cout << text << endl;
		Sleep(1500);
	}
	// Delay print
	void printSleep(string text, int time) {
		cout << text << endl;
		Sleep(time);
	}
	// Slow screen clear
	void fadeoff() {
		printSleep("", 500);
		printSleep("", 500);
		printSleep("", 500);
		printSleep("", 500);
		printSleep("", 500);
		printSleep("", 500);
		printSleep("", 500);
		printSleep("", 500);
		printf("\033c");
	}
	// Clear the screen
	void clearScreen() {
		printf("\033c");
	}
}
