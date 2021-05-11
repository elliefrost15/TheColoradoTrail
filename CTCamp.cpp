#include "CTCamp.h"

namespace CSC234 {
	// Camp constructor
	CTCamp::CTCamp() {
		campInventory = new CTInventory();
		player1food = new CTInventory();
		player2food = new CTInventory();
		player3food = new CTInventory();
		player4food = new CTInventory();
	}
	// Camp constructor
	CTCamp::CTCamp(CTInventory* cInven) {
		campInventory = cInven;
		player1food = new CTInventory();
		player2food = new CTInventory();
		player3food = new CTInventory();
		player4food = new CTInventory();
	}
	// Camp constructor
	CTCamp::CTCamp(CTInventory* cInven, CTInventory* p1f) {
		campInventory = cInven;
		player1food = p1f;
		player2food = new CTInventory();
		player3food = new CTInventory();
		player4food = new CTInventory();
	}
	// Camp constructor
	CTCamp::CTCamp(CTInventory* cInven, CTInventory* p1f, CTInventory* p2f) {
		campInventory = cInven;
		player1food = p1f;
		player2food = p2f;
		player3food = new CTInventory();
		player4food = new CTInventory();
	}
	// Camp constructor
	CTCamp::CTCamp(CTInventory* cInven, CTInventory* p1f, CTInventory* p2f, CTInventory* p3f) {
		campInventory = cInven;
		player1food = p1f;
		player2food = p2f;
		player3food = p3f;
		player4food = new CTInventory();
	}
	// Camp constructor
	CTCamp::CTCamp(CTInventory* cInven, CTInventory* p1f, CTInventory* p2f, CTInventory* p3f, CTInventory* p4f) {
		campInventory = cInven;
		player1food = p1f;
		player2food = p2f;
		player3food = p3f;
		player4food = p4f;
	}
}
