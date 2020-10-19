#include<iostream>
#include<sstream>
#include<ctime>
#include<cstdlib>
#include "Cave.h"
#include "Cavern.h"
#include"TheWumpusHunter.h"
#include"Player.h"
#include"textMessage.h"

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
	if (has_Bat || has_Wumpus ||has_Player)
		return false;
	else
	{
		has_Bat = true;
		return true;
	}
}
bool Cave::addPit()
{
	if (has_Pit || has_Wumpus || has_Player)
		return false;
	else
	{
		has_Pit = true;
		return true;
	}
}
bool Cave::addWumpus()
{
	if (has_Wumpus || has_Bat || has_Player||has_Pit)
		return false;
	else
	{
		has_Wumpus = true;
		return true;
	}
}
bool Cave::addPlayer()
{
	if (has_Player || has_Wumpus || has_Bat || has_Pit)
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
void Cave::setID(int ID)
{
	caveID = ID;  
}
int Cave::getID()
{
	return caveID;
}

int Cave::enterCave(Player& player)
{
	int caveEvent = E12_PLAYER_MOVE_COMPLETE;
    addPlayer();
	player.setID(getID());
	if (hasWumpus())
		caveEvent = E10_WUMPUS_KILLS_PLAYER;
	if (hasPit())
		caveEvent = E11_PIT_KILLS_PLAYER;
	if (hasBat())
	{
		caveEvent = E9_BAT_MOVES_PLAYER;
		if (hasPit())
			if ((rand() % 2) == 1)
				caveEvent = E11_PIT_KILLS_PLAYER;
	}
	return caveEvent;
}

int Cave::shootInCave()
{
	int chance;
	int caveEvent = E2_PLAYER_SHOOTS;
	if (!hasWumpus() && !hasBat() && !hasPit())
	{
		chance = rand() % 4;
		if (chance >= 2)
			caveEvent = E13_ARROW_TO_EMPTY_CAVE_AND_WUMPUS_STAYS;
		else
			caveEvent = E14_ARROW_TO_EMPTY_CAVE_AND_WUMPUS_MOVES;

	}
	if (hasWumpus())
	{
		caveEvent = E15_ARROW_KILLS_WUMPUS;
	}
	if (hasBat())
	{
		chance = rand() % 2;
		if (chance == 1)
			caveEvent = E16_ARROW_KILLS_BAT_AND_WUMPUS_MOVES;
		else
			caveEvent = E17_ARROW_KILLS_BAT_AND_WUMPUS_STAYS;
	}
	return caveEvent;
}
int Cave::wumpusEntersCave()
{
	int wumpusEvent = E26_WUMPUS_MOVE_COMPLETE;

	if (hasBat())
		if (rand() % 2 == 0)
			wumpusEvent = E23_WUMPUS_EATS_BAT;
	if (hasPit())
		wumpusEvent = E24_WUMPUS_FALLS_INTO_PIT;
	if (hasPlayer())
		wumpusEvent = E22_WUMPUS_KILLS_PLAYER;
	return wumpusEvent;
}