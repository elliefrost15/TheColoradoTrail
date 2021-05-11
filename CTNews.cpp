#include <cstring>
#include "CTNews.h"
#include <iostream>
#include <fstream>
#include "CTFunctions.h"
using namespace std;

namespace CSC234 {
	// Default constructor
	CTNews::CTNews() { filename = ""; }

	// Constructor with txt file name
	CTNews::CTNews(string file) { filename = file; }

	// Get news filename
	string CTNews::getFilename() { return filename;	}
	
	// Print the news for the CTNews object
	void CTNews::printNews() {
		printFile(this->getFilename());
		fadeoff();
	}

	// Print the news for a specific news object
	void CTNews::printNews(CTNews* news) {
		printFile(news->getFilename());
		fadeoff();
	}

}
