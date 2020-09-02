#include<iostream>
#include "Cave.h"
#include "Cavern.h"
#include"TheWumpusHunter.h"
bool Cave::addPassage(int adjacentCave)
{
	bool passageAdded = false;
	if (adjacentCave < CAVE_COUNT && passageCount < PASS_PER_CAVE)
	{
		cavePassages[passageCount] = adjacentCave;
		passageCount++;
		passageAdded = true;
	}
	return passageAdded;
}
int Cave::getPassage(int whichPassage)
{
	int passage= RETURN_ERROR;
	if (whichPassage <= passageCount && whichPassage >= 0)
		passage = cavePassages[whichPassage];
	return passage;
}

int Cave::getPassageCount() {
	return passageCount;
}


//mutator
bool Cave::addBat()
{
	if (has_Bat)
		return false;
	else
	{
		has_Bat = true;
		return true;
	}
}
bool Cave::addPit()
{
	if (has_Pit)
		return false;
	else
	{
		has_Pit = true;
		return true;
	}
}
bool Cave::addWumpus()
{
	if (has_Wumpus)
		return false;
	else
	{
		has_Wumpus = true;
		return true;
	}
}
bool Cave::addPlayer()
{
	if (has_Player)
		return false;
	else
	{
		has_Player = true;
		return true;
	}
}


//accessor 
bool Cave::hasBat()
{
	if (has_Bat == true)
		return true;
	else
		return false;
}
bool Cave::hasPit()
{
	if (has_Pit == true)
		return true;
	else
		return false;
}
bool Cave::hasWumpus()
{
	if (has_Wumpus == true)
		return true;
	else
		return false;
}
bool Cave::hasPlayer()
{
	if (has_Player == true)
		return true;
	else
		return false;
}
void Cave::deleteBat()
{
	has_Bat = false;
}

void Cave::deletePit()
{
	has_Pit= false;
}
void Cave::deleteWumpus()
{
	has_Wumpus = false;
}
void Cave::deletePlayer()
{
	has_Player = false;
}
void Cave::clearCave()
{
	deleteBat();
	deletePit();
	deleteWumpus();
	deletePlayer();
}
