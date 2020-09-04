#include<iostream>
#include <cstdlib>
#include<ctime>
#include"Cave.h"
#include"TheWumpusHunter.h"
#include"Cavern.h"
#include"Player.h"

using namespace std;

void Cavern::printCavern()
{
	thePlayer.showText("Listing the cavern\n");
	int i, j;  
	for (i = 0; i < CAVE_COUNT; i++)
	{
		cout << "Cave number: " << i << " connected to the following caves: ";
		for (j = 0; j < theWumpusCaves[i].getPassageCount(); j++) 
			cout << " " << theWumpusCaves[i].getPassage(j);
		cout << ".";
		if (theWumpusCaves[i].hasBat())
			cout << " B ";
		if (theWumpusCaves[i].hasPit())
			cout << " * " ;
		if (theWumpusCaves[i].hasWumpus())
			cout << " W ";
		if (theWumpusCaves[i].hasPlayer())
			cout << " P ";
		cout << endl;
	}

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
