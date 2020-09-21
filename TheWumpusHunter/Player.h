#pragma once
#include<string>
using namespace std;

class Player
{
public:
	 void showText(const string);
	 void showText(const ostringstream&);
	 bool keepPlaying();
	 bool getChoice(char& choice);
	 bool getChoice(int& choice);
	 void setID();
	 int  getID();
	 void showCave(int[],int);
	 void chooseAction();
private:
	int inCave;
};

