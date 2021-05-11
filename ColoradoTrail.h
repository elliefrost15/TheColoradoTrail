#pragma once
#include "CTTimeline.h"
#include "CTPlayer.h"
#include "Casino.h"

namespace CSC234 {

class ColoradoTrail : public Casino {
public:
	ColoradoTrail();
	static ColoradoTrail* makeGame();
	void start();
private:
	int storyline;
	int numPlayers;
	char yesNo;
	void run();
	void setStoryline();
	void getStoryline(int);
};

}
