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
constexpr int E1_PLAYER_MOVES = 1;
constexpr int E2_PLAYER_SHOOTS = 2;
constexpr int E3_PLAYER_QUITS_GAME = 3;
constexpr int E4_PLAYER_ASKS_FOR_HELP = 4;
constexpr int E5_PLAYER_PRINTS_CAVERN = 5;
constexpr int E6_PLAYER_REQUESTS_EASTER_EGG = 6;
constexpr int E7_PLAYER_KEEPS_PLAYING = 7;
constexpr int E8_PLAYER_DECLINES_MORE_PLAY = 8;
constexpr int E9_BAT_MOVES_PLAYER = 9;
constexpr int E10_WUMPUS_KILLS_PLAYER = 10;//repeated
constexpr int E11_PIT_KILLS_PLAYER = 11;
constexpr int E12_PLAYER_MOVE_COMPLETE = 12;
constexpr int E13_ARROW_TO_EMPTY_CAVE_AND_WUMPUS_STAYS = 13;
constexpr int E14_ARROW_TO_EMPTY_CAVE_AND_WUMPUS_MOVES = 14;
constexpr int E15_ARROW_KILLS_WUMPUS = 15;
constexpr int E16_ARROW_KILLS_BAT_AND_WUMPUS_MOVES = 16;
constexpr int E17_ARROW_KILLS_BAT_AND_WUMPUS_STAYS = 17;
constexpr int E18_ARROW_MISSES_BAT_AND_WUMPUS_MOVES = 18;
constexpr int E19_ARROW_MISSES_BAT_AND_WUMPUS_STAYS = 19;
constexpr int E20_ARROW_MISSES_WUMPUS_AND_WUMPUS_MOVES = 20;
constexpr int E21_PLAYER_USED_LAST_ARROW = 21;
constexpr int E22_WUMPUS_KILLS_PLAYER = 22;//repeated
constexpr int E23_WUMPUS_EATS_BAT = 23;
constexpr int E24_WUMPUS_FALLS_INTO_PIT = 24;
constexpr int E25_WUMPUS_STAYS_ASLEEP = 25;
constexpr int E26_WUMPUS_MOVE_COMPLETE = 26;
constexpr int E27_NUMBER_OF_ARROWS = 1;

