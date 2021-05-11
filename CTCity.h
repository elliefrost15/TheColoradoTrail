#pragma once
#include <string>
#include "CTLocation.h"
using namespace std;

namespace CSC234 {
	class CTCity {
	public:
		CTCity();
		CTCity(string);
		CTCity(string, string);
		CTCity(string, CTLocation*);
		CTCity(string, string, CTLocation*);
		CTCity(string, string, GeneralStore*);
		CTCity(string, string, GeneralStore*, GoHunting*);
		void printCity(vector<CTPlayer>);
		void printCity(CTCity*);
		string getCityName();
	private:
		string cityName;
		string cityfilename;
		GeneralStore* store;
		CTLocation* location;
		GoHunting* hunting;
		string getFilename();
	};
}
