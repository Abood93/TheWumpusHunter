#include<iostream>
#include <cstdlib>
#include"Cave.h"
#include"TheWumpusHunter.h"
#include"Cavern.h"

using namespace std;

void Cavern::printCavern()
{
	int i, j;  
	for (i = 0; i < CAVE_COUNT; i++)
	{
		cout << "Cave number: " << i << " connected to the following caves: ";
		for (j = 0; j < theWumpusCaves[i].getPassageCount(); j++)
			cout << " " << theWumpusCaves[i].getPassage(j);
		cout << "." << endl;
	}
}

void Cavern::newGame()
{
	for(int i=0;i<CAVE_COUNT;i++)
		theWumpusCaves[i].clearCave();
	theWumpusCaves[0].Cave::hasPlayer() = true;
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
}
