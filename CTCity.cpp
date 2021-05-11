#include "CTCity.h"
#include <fstream>
#include "CTFunctions.h"
using namespace std;

namespace CSC234 {

	// Default constructor
	CTCity::CTCity() {
		cityName = "";
		cityfilename = "";
	}

	// City constructor with just the city name
	CTCity::CTCity(string city) {
		cityName = city;
		cityfilename = "";
	}

	// City constructor with a name and text file
	CTCity::CTCity(string city, string filename) {
		cityName = city;
		cityfilename = filename;
	}
	// City constructor
	CTCity::CTCity(string city, CTLocation* newlocation) {
		cityName = city;
		cityfilename = "";
		location = newlocation;
	}
	// City constructor
	CTCity::CTCity(string city, string filename, CTLocation* newlocation) {
		cityName = city;
		cityfilename = filename;
		location = newlocation;
	}
	// City constructor
	CTCity::CTCity(string city, string filename, GeneralStore* location) {
		cityName = city;
		cityfilename = filename;
		store = location;
	}
	// City constructor
	CTCity::CTCity(string city, string filename, GeneralStore* location, GoHunting* hunt) {
		cityName = city;
		cityfilename = filename;
		store = location;
		hunting = hunt;
	}

	// Display the city information
	void CTCity::printCity(vector<CTPlayer> players) {
		cout << "LOCATION: " << this->cityName << endl;
		if (this->cityfilename != "") 
			printFile(cityfilename);
		fadeoff();
		//cout << "You look around and see..." << endl;
		hunting->hunt(players);
		store->printLocation(players);
		fadeoff();
	}

	// Display city info for a specific city
	void CTCity::printCity(CTCity* city) {
		printFile(city->getFilename());
		/*if (locations.size() > 0) {
			for (int i = 0; i < locations.size(); i++) {
				CTLocation* temp = locations.at(i);
				temp->printLocation();
			}
		}*/
	}

	// Return city info
	string CTCity::getFilename() { return cityfilename; }
	string CTCity::getCityName() { return cityName; }
}
