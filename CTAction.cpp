#include "CTAction.h"
#include <iostream>

namespace CSC234 {

	// Default constructor
	CTAction::CTAction() { actionname = ""; }

	// Action from text input
	CTAction::CTAction(string name) { actionname = name; }

	// Display action info
	void CTAction::printAction() {	}

}