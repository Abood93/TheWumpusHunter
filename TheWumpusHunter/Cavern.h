#pragma once
#ifndef MI1
#define MI1
#include"Cave.h"
class Cavern
{
public:
	void newGame();
	void printCavern();
	Cavern();
private:
	Cave theWumpusCaves[CAVE_COUNT];
};
#endif