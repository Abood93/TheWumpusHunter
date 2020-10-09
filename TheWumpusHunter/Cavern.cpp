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
	thePlayer.setID(0);
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
void Cavern::playGame()
{	
	bool playMore = true;
	int caveEvent;
	int newCave;
	int theCave;
	int passageList[PASS_PER_CAVE];
	int choice;
	int arrowCount = 5;

		while (playMore)
		{
			newGame();
				bool playerAlive = true;
				bool wumpusAlive = true;
				while (playerAlive && wumpusAlive)
				{
					theCave = thePlayer.getID();
					for (int i = 0; i < PASS_PER_CAVE; i++)
						passageList[i] = theWumpusCaves[theCave].getPassage(i);
					thePlayer.showCave(passageList);
					choice = thePlayer.chooseAction(); 
					switch (choice)
					{
						case C6_MOVE:
							newCave = thePlayer.chooseCave(passageList);
							caveEvent = theWumpusCaves[newCave].enterCave(thePlayer);
							//start
							theWumpusCaves[theCave].deletePlayer();
							if (caveEvent == E9_BAT_MOVES_PLAYER)
							{
								int whichCave;
								bool caveFound = false;
								while (!caveFound)
								{
									whichCave = (rand() % CAVE_COUNT);
									caveFound = theWumpusCaves[whichCave].addBat();
								}
								caveEvent = theWumpusCaves[whichCave].enterCave(thePlayer);
							}
							if (caveEvent == E10_WUMPUS_KILLS_PLAYER)
							{
								thePlayer.showText(textMessage[S19_GAME_LOST_WUMPUS]);
								playerAlive = false;
							}
							if (caveEvent == E11_PIT_KILLS_PLAYER)
							{
								thePlayer.showText(textMessage[S20_GAME_LOST_PIT]);
								playerAlive = false;
							}
							if (caveEvent == E12_PLAYER_MOVE_COMPLETE)
							{
								checkNearbyCaves();
							}
							//end
							break;
						case C8_SHOOT: 
							newCave = thePlayer.chooseCave(passageList);
							cerr << "cave chosen = " << newCave << endl;
							caveEvent = theWumpusCaves[newCave].shootInCave();
							//E10_WUMPUS_KILLS_PLAYER
							//playerAlive = false;
							//E11_PIT_KILLS_PLAYER
							//playerAlive = false;
							arrowCount--;
							if (arrowCount >= 1)
							{
								thePlayer.showText(textMessage[S17_ARROWS_LEFT]);
								cout << arrowCount << endl;
							}
							else
								thePlayer.showText(textMessage[S18_GAME_LOST_ARROWS]);
							cerr << "cave event = " << caveEvent << endl;
							break;
						case C4_QUIT:
							playMore = thePlayer.keepPlaying();
							if (!playMore)
								wumpusAlive = false;
							break;
						case C10_HELP:
							thePlayer.showText(textMessage[S11_SHOW_HELP]);
							break;
						case C13_PRINTCAVERN:
							printCavern();
							break;
						case C14_EASTEREGG:
							thePlayer.showText(textMessage[S12_EASTER_EGG_MESSAGE]);
							break;
					}
				}
		}
}

bool Cavern::sniff()
{
	int thisCave;
	int adjacentCave;
	int i;
	bool wumpusNear;
	thisCave = thePlayer.getID();
	wumpusNear = false;
	for (i = 0; i < theWumpusCaves[thisCave].getPassageCount(); i++)
	{
		adjacentCave = theWumpusCaves[thisCave].getPassage(i);
		if (theWumpusCaves[adjacentCave].hasWumpus() == true)
			wumpusNear = true;

	}
	return wumpusNear;
}

bool Cavern::feel()
{
	int thisCave;
	int adjacentCave;
	int i;
	bool pitNear;
	thisCave = thePlayer.getID();
	pitNear = false;
	for (i = 0; i < theWumpusCaves[thisCave].getPassageCount(); i++)
	{
		adjacentCave = theWumpusCaves[thisCave].getPassage(i);
		if (theWumpusCaves[adjacentCave].hasPit() == true)
			pitNear = true;

	}
	return pitNear;
}
bool Cavern::listen()
{
	int thisCave;
	int adjacentCave;
	int i;
	bool batNear;
	thisCave = thePlayer.getID();
	batNear = false;
	for (i = 0; i < theWumpusCaves[thisCave].getPassageCount(); i++)
	{
		adjacentCave = theWumpusCaves[thisCave].getPassage(i);
		if (theWumpusCaves[adjacentCave].hasBat() == true)
			batNear = true;

	}
	return batNear;
}

bool Cavern::checkNearbyCaves()
{
	bool cenario = false;

	if (sniff() == true)
	{
		cenario = true;
		thePlayer.showText(textMessage[S14_SNIFF]);
	}
	if (feel() == true)
	{
		cenario = true;
		thePlayer.showText(textMessage[S15_FEEL]);
	}
	if (listen() == true)
	{
		cenario = true;
		thePlayer.showText(textMessage[S16_LISTEN]);
	}
	return cenario;
}

int Cavern::whereIsWumpus()
{
	for (int i = 0; i < CAVE_COUNT; i++)
			if (theWumpusCaves[i].hasWumpus())
				return theWumpusCaves[i].getID();
	return RETURN_ERROR;
}

Cavern::Cavern()
{
	int i, j;
	bool passageAdded;
	for (i = 0; i < CAVE_COUNT; i++)
	{
		theWumpusCaves[i].setID(i);
		for (j = 0; j < PASS_PER_CAVE; j++)
		{
			passageAdded = theWumpusCaves[i].addPassage(CAVES[i][j]);
			if (passageAdded == false)
			{
				cout << "Error - Invalid configuration.\n";
				exit(-1);
			}
		}
	}
	newGame();
}
