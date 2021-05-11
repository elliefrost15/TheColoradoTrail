#pragma once
#include "CTInventory.h"

namespace CSC234 {
	class CTCamp {
	public:
		CTCamp();
		CTCamp(CTInventory*);
		CTCamp(CTInventory*, CTInventory*);
		CTCamp(CTInventory*, CTInventory*, CTInventory*);
		CTCamp(CTInventory*, CTInventory*, CTInventory*, CTInventory*);
		CTCamp(CTInventory*, CTInventory*, CTInventory*, CTInventory*, CTInventory*);


	private:
		CTInventory* campInventory;
		CTInventory* player1food;
		CTInventory* player2food;
		CTInventory* player3food;
		CTInventory* player4food;

	};
}
