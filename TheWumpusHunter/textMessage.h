#pragma once

constexpr int S0_CAVENUM = 0;
constexpr int S1_ADJCAVE = 1;
constexpr int S2_BAT = 2;
constexpr int S3_PIT = 3;
constexpr int S4_WUMPUS = 4;
constexpr int S5_PLAYER = 5;


const string textMessage[] =
{
	/*S0_CAVENUM*/	    "Cave number: ",
	/*S1_ADJCAVE*/	    " is connected to the following caves: ",
	/*S2_BAT*/			" B ",
	/*S3_PIT*/			" * ",
	/*S4_WUMPUS*/       " W ",
	/*S5_PLAYER*/		" P "
};

constexpr int C0_NO = 0;
constexpr int C1_NO = 1;
constexpr int C2_YES = 2;
constexpr int C3_YES = 3;
constexpr int C4_QUIT = 4;
constexpr int C5_QUIT = 5;

const char playerChoice[] =
{
	/*C0_NO*/	'N',
	/*C1_NO*/	'n',
	/*C2_YES*/  'Y',
	/*C3_YES*/  'y',
	/*C4_QUIT*/ 'Q',
	/*C5_QUIT*/ 'q'
};