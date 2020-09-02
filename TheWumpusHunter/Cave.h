#pragma once
#ifndef MI2
#define MI2
#include"TheWumpusHunter.h"

class Cave
{
public:
	bool addPassage(int);
	int  getPassage(int);
	int  getPassageCount(); 
	bool addBat();
	bool addPit();
	bool addWumpus();
	bool addPlayer();
	bool hasBat();
	bool hasPit();
	bool hasWumpus();
	bool hasPlayer();
	void deleteBat();
	void deletePit();
	void deleteWumpus();
	void deletePlayer();
	void clearCave();
private:
	int passageCount = 0;
	int cavePassages[PASS_PER_CAVE];
	bool has_Bat;
	bool has_Pit;
	bool has_Wumpus;
	bool has_Player;
};

#endif