#pragma once
#include <string>
#include <Windows.h>
using namespace std;

namespace CSC234 {
	class CTNews {
	public:
		CTNews();
		CTNews(string);
		void printNews();
		void printNews(CTNews*);
	private:
		string filename;
		string getFilename();
	};
}