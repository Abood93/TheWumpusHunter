#pragma once
//#define UNIT_TESTS
//#define ICOSAHEDRON
#define DODECAHEDRON

//The dodecahedron
#ifdef DODECAHEDRON
constexpr int CAVE_COUNT = 20;
constexpr int PASS_PER_CAVE = 3;
constexpr int CAVES[CAVE_COUNT][PASS_PER_CAVE] = { { 1, 4, 7 }, { 0, 2, 9 }, { 1, 3, 11 }, { 2, 4, 13 },{ 0, 3, 5 },
	{ 4, 6, 14 }, { 5, 7, 16 }, { 0, 6, 8 }, { 7, 9, 17 }, { 1, 8, 10 },
	{ 9, 11, 18 }, { 2, 10, 12 }, { 11, 13, 19 }, { 3, 12, 14 }, { 5, 13, 15 },
	{ 14, 16, 19 }, { 6, 15, 17 }, { 8, 16, 18 }, { 10, 17, 19 }, { 12, 15, 18 } };
#endif



//The icosahedron
#ifdef ICOSAHEDRON
constexpr int CAVE_COUNT = 12;
constexpr int PASS_PER_CAVE = 5;
constexpr int CAVES[CAVE_COUNT][PASS_PER_CAVE] = {
{1, 2, 3, 4, 7},   {0, 2, 4, 8, 11}, {0, 1, 7, 10, 11},
{0, 4, 5, 6, 7},    {0, 1, 3, 5, 8},	{3, 4, 6, 8, 9},
{3, 5, 7, 9, 10},    {0, 2, 3, 6, 10},   {1, 4, 5, 9, 11},
{5, 6, 8, 10, 11},	{2, 6, 7, 9, 11}, {1, 2, 8, 9, 10}
};
#endif



constexpr int RETURN_ERROR = -1;
constexpr int BAT_COUNT = 2;
constexpr int PIT_COUNT = 2;
constexpr int WUMPUS_COUNT = 1;
constexpr int PLAYER_COUNT = 1;
constexpr int E1_PLAYER_MOVES = 100;
constexpr int E2_PLAYER_SHOOTS = 101;
constexpr int E3_PLAYER_QUITS_GAME = 102;
constexpr int E4_PLAYER_ASKS_FOR_HELP = 103;
constexpr int E5_PLAYER_PRINTS_CAVERN = 104;
constexpr int E6_PLAYER_REQUESTS_EASTER_EGG = 105;
constexpr int E7_PLAYER_KEEPS_PLAYING = 106;
constexpr int E8_PLAYER_DECLINES_MORE_PLAY = 107;
constexpr int E9_BAT_MOVES_PLAYER = 108;
constexpr int E10_WUMPUS_KILLS_PLAYER = 109;
constexpr int E11_PIT_KILLS_PLAYER = 110;
constexpr int E12_PLAYER_MOVE_COMPLETE = 111;
constexpr int E13_ARROW_TO_EMPTY_CAVE_AND_WUMPUS_STAYS = 112;
constexpr int E14_ARROW_TO_EMPTY_CAVE_AND_WUMPUS_MOVES = 113;
constexpr int E15_ARROW_KILLS_WUMPUS = 114;
constexpr int E16_ARROW_KILLS_BAT_AND_WUMPUS_MOVES = 115;
constexpr int E17_ARROW_KILLS_BAT_AND_WUMPUS_STAYS = 116;
constexpr int E18_ARROW_MISSES_BAT_AND_WUMPUS_MOVES = 117;
constexpr int E19_ARROW_MISSES_BAT_AND_WUMPUS_STAYS = 118;
constexpr int E20_ARROW_MISSES_WUMPUS_AND_WUMPUS_MOVES = 119;
constexpr int E21_PLAYER_USED_LAST_ARROW = 120;
constexpr int E22_WUMPUS_EATS_BAT = 121;
constexpr int E23_WUMPUS_FALLS_INTO_PIT = 122;
constexpr int E24_WUMPUS_STAYS_ASLEEP = 123;
constexpr int E25_WUMPUS_MOVE_COMPLETE = 124;
constexpr int E26_HELP = 125;
constexpr int E27_EASTEREGG = 126;
constexpr int E28_NUMBER_OF_ARROWS = 5;

struct MsgData
{
	int thisCave;
	int cavePassages[PASS_PER_CAVE];
	bool player;
	bool wumpus;
	bool bat;
	bool pit;
	int arrows;
};