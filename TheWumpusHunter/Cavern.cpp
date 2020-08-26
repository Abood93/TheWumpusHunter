#include<iostream>
#include"Cave.h"
#include"TheWumpusHunter.h"
#include"Cavern.h"
using namespace std;

void Cavern::printCavern()
{
	Cave x;  
	int i, j;  
	for (i = 0; i < cCaveCount; i++)
	{
		cout << "Cave number: " << i << " connected to the following caves: ";
		for (j = 0; j < x.getPassageCount(); j++)
			cout << " " << theWumpusCaves[i].getPassage(j);
		cout << "." << endl;
	}
}

Cavern::Cavern()
{
	int i, j;
	bool passageAdded;
	for (i = 0; i < cCaveCount; i++)

		for (j = 0; j < cPassPerCave; j++)
		{
			passageAdded = theWumpusCaves[i].addPassage(cCaves[i][j]);
			if (passageAdded == false)
			{
				cout << "Error - Invalid configuration.\n";
				exit(-1);
			}
		}
}
