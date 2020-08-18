#include<iostream>
#include "Cavern.h"
#include"TheWumpusHunter.h"

using namespace std;

void Cavern::printCavern()
{
	int i, j;
	for (i = 0; i < cCaveCount; i++)
	{
		cout << "Cave number: " << i << " connected to the following caves: ";
		for (j = 0; j < 3; j++)
			cout << " " << cCaves[i][j];
		cout << "." << endl;
	}
}

Cavern::Cavern()
{
	cout << "The 20 caves are numbered 0 to 19." << endl;
}