#include<iostream>
#include<sstream>
#include <cstdlib>
#include<ctime>
#include"Cave.h"
#include"TheWumpusHunter.h"
#include"Cavern.h"
#include"Player.h"
#include"textMessage.h"

using namespace std;


void Cavern::printCavern()
{
	ostringstream outText;
	int i, j;  
	for (i = 0; i < CAVE_COUNT; i++)
	{
		outText<< textMessage[S0_CAVENUM] << i << textMessage[S1_ADJCAVE];
		for (j = 0; j < theWumpusCaves[i].getPassageCount(); j++) 
			outText << " " << theWumpusCaves[i].getPassage(j);
		outText << ".";
		if (theWumpusCaves[i].hasBat())
			outText << textMessage[S2_BAT];
		if (theWumpusCaves[i].hasPit())
			outText << textMessage[S3_PIT];
		if (theWumpusCaves[i].hasWumpus())
			outText << textMessage[S4_WUMPUS];
		if (theWumpusCaves[i].hasPlayer())
			outText << textMessage[S5_PLAYER];
		outText << endl;
	}
	thePlayer.showText(outText);
}

void Cavern::newGame()
{
	int i;
	int whichCave;
	bool objectAdded;
	for( i=0;i<CAVE_COUNT;i++)
		theWumpusCaves[i].clearCave();

	//add ....bat,pit,wumpus,player.
	theWumpusCaves[0].addPlayer();
	for (i = 0; i < BAT_COUNT; i++)
	{
		objectAdded = false;
		while (!objectAdded)
		{
		whichCave = (rand() % 20);
		objectAdded = theWumpusCaves[whichCave].addBat();
		}
	}
	for (i = 0; i < PIT_COUNT; i++)
	{
		objectAdded = false;
		while (!objectAdded)
		{
			whichCave = (rand() % 20);
			objectAdded = theWumpusCaves[whichCave].addPit();
		}
	}
	for (i = 0; i < WUMPUS_COUNT; i++)
	{
		objectAdded = false;
		while (!objectAdded)
		{
			whichCave = (rand() % 20);
			objectAdded = theWumpusCaves[whichCave].addWumpus();
		}
	}
}

Cavern::Cavern()
{
	int i, j;
	bool passageAdded;
	for (i = 0; i < CAVE_COUNT; i++)

		for (j = 0; j < PASS_PER_CAVE; j++)
		{
			passageAdded = theWumpusCaves[i].addPassage(CAVES[i][j]);
			if (passageAdded == false)
			{
				cout << "Error - Invalid configuration.\n";
				exit(-1);
			}
		}

	newGame();
}
