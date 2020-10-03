#pragma once
#include"Cave.h"
#include"Player.h"

class Cavern
{
public:
	void newGame();
	void printCavern();
	void playGame();
	bool sniff();
	bool feel();
	bool listen();
	bool checkNearbyCaves();
	Cavern();
private:
	Cave theWumpusCaves[CAVE_COUNT];
	Player thePlayer;
};

