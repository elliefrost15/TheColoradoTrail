#pragma once
#include <string>
using namespace std;

namespace CSC234 {
	class CTAction {
	public:
		CTAction();
		CTAction(string);
		void printAction();
	private:
		string actionname;
	};
}
