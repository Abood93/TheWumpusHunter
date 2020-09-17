#pragma once

constexpr int S0_CAVENUM = 0;
constexpr int S1_ADJCAVE = 1;
constexpr int S2_BAT = 2;
constexpr int S3_PIT = 3;
constexpr int S4_WUMPUS = 4;
constexpr int S5_PLAYER = 5; 
constexpr int S6_KEEPPLAYING = 6;
constexpr int S7_INVALID = 7;


const string textMessage[] =
{
	/*S0_CAVENUM*/	    "Cave number: ",
	/*S1_ADJCAVE*/	    " is connected to the following caves: ",
	/*S2_BAT*/			" B ",
	/*S3_PIT*/			" * ",
	/*S4_WUMPUS*/       " W ",
	/*S5_PLAYER*/		" P ",
	/*S6_KEEPPLAYING*/  "Do you want to keep playing?",
	/*S7_INVALID*/      "Invalid input!"
};

constexpr int C0_NO = 0;
constexpr int C1_NO = 1;
constexpr int C2_YES = 2;
constexpr int C3_YES = 3;
constexpr int C4_QUIT = 4;
constexpr int C5_QUIT = 5;
constexpr int C6_MOVE = 6;
constexpr int C7_MOVE = 7;
constexpr int C8_SHOOT = 8;
constexpr int C9_SHOOT = 9;
constexpr int C10_HELP = 10;
constexpr int C11_HELP = 11;
constexpr int C12_HELP = 12;
constexpr int C13_PRINTCAVERN = 13;
constexpr int C14_EASTEREGG = 14;


constexpr char playerChoice[] =
{
	/*C0_NO*/	'N',
	/*C1_NO*/	'n',
	/*C2_YES*/  'Y',
	/*C3_YES*/  'y',
	/*C4_QUIT*/ 'Q',
	/*C5_QUIT*/ 'q',
	/*C6_MOVE*/ 'M',
	/*C7_MOVE*/ 'm',
	/*C8_SHOOT*/ 'S',
	/*C9_SHOOT*/ 's',
	/*C10_HELP*/ 'H',
	/*C11_HELP*/ 'h',
	/*C12_HELP*/ '?',
	/*C13_PRINTCAVERN*/ '+',
	/*C14_EASTEREGG*/ '_'

}; 
