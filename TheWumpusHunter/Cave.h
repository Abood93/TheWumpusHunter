#pragma once
class Cave
{
public:
	bool addPassage(int);
	int  getPassage(int);
	int  getPassCount();
private:
	int passageCount = 0;
	int cavePassages[3];
};