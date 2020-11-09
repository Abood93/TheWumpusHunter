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
	 void setID(int caveID);
	 int  getID();
	 void showCave(int[]);
	 int chooseAction();
	 int chooseCave(int[]);
	 void showText(int);
	 void showText(int, const MsgData&);
private:
	int inCave; 
};

