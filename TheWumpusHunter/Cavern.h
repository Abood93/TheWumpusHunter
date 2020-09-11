#pragma once

#include"Cave.h"
#include"Player.h"

class Cavern
{
public:
	void newGame();
	void printCavern();
	Cavern();
private:
	Cave theWumpusCaves[CAVE_COUNT];
	Player thePlayer;
};
