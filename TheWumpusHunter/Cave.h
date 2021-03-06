#pragma once

#include"TheWumpusHunter.h"
#include"Player.h"

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
	void setID(int ID);
	int  getID();
	int enterCave(Player&);
	int shootInCave();
	int wumpusEntersCave();

private:
	int passageCount = 0;
	int cavePassages[PASS_PER_CAVE];
	bool has_Bat = false;
	bool has_Pit = false;
	bool has_Wumpus = false;
	bool has_Player = false;
	int caveID;
};
