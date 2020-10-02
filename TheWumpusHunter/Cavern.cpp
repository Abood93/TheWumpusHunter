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
	int caveEvent;
	int newCave;
	int theCave;
	int passageList[PASS_PER_CAVE];
	bool playMore = true;
	int choice;

		while (playMore)
		{
			newGame();
				bool playerAlive = true;
				bool wumpusAlive = true;
				while (playerAlive && wumpusAlive)
				{
					//printCavern();
					theCave = thePlayer.getID();
					for (int i = 0; i < PASS_PER_CAVE; i++)
						passageList[i] = theWumpusCaves[theCave].getPassage(i);
					thePlayer.showCave(passageList);
					choice = thePlayer.chooseAction(); 
					switch (choice)
					{
						case C6_MOVE:
							newCave = thePlayer.chooseCave(passageList);
							cerr << "cave chosen = " << newCave << endl;
							caveEvent = theWumpusCaves[newCave].enterCave(thePlayer);
							cerr << "cave event = " << caveEvent << endl;
							break;
						case C8_SHOOT: 
							thePlayer.showText(textMessage[S13_WHICH_CAVE]);
							thePlayer.showText("to be implemented shoot\n");
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
