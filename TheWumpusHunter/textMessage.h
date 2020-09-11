#pragma once

#include<sstream>

using namespace std;

ostream outText;

 constexpr int S0_SMELL = 0;
 constexpr int S1_DRAFT = 1;
 constexpr int S2_RUSTLE = 2;
 constexpr int S3_ACTION = 3;

//const string textMessage[] =
//{
//
//	/*S0_SMELL*/			{"I smell a Wumpus!\n"},
//	/*S1_DRAFT*/			{"I feel a cold draft!\n"},
//	/*S2_RUSTLE*/			{"I hear a rustling nearby!\n"},
//	/*S3_ACTION*/			{"Do you want to (M)ove, (S)hoot an arrow, or (Q)uit? "}
//};