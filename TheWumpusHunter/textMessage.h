#pragma once

constexpr int S0_CAVENUM = 0;
constexpr int S1_ADJCAVE = 1;
constexpr int S2_BAT = 2;
constexpr int S3_PIT = 3;
constexpr int S4_WUMPUS = 4;
constexpr int S5_PLAYER = 5; 
constexpr int S6_KEEPPLAYING = 6;
constexpr int S7_INVALID = 7;
constexpr int S8_CAVENUMBER = 8;
constexpr int S9_ADJACENT_CAVES = 9;
constexpr int S10_MAKE_CHOICE = 10;
constexpr int S11_SHOW_HELP = 11;
constexpr int S12_EASTER_EGG_MESSAGE = 12;
constexpr int S13_WHICH_CAVE = 13;
constexpr int S14_SNIFF = 14;
constexpr int S15_FEEL =15;
constexpr int S16_LISTEN = 16;
constexpr int S17_ARROWS_LEFT = 17;
constexpr int S18_GAME_LOST_ARROWS = 18;
constexpr int S19_GAME_LOST_WUMPUS = 19;
constexpr int S20_GAME_LOST_PIT = 20;
constexpr int S21_BAT_TRANSFERS = 21;
constexpr int S22_BAT_TRANSFERS_FROM_PIT = 22;
constexpr int S23_WUMPUS_STAYS_ASLEEP = 23;
constexpr int S24_ARROW_KILLS_WUMPUS = 24;
constexpr int S25_ARROW_KILLS_BAT_WUMPUS_MOVES = 25;
constexpr int S26_ARROW_KILLS_BAT_WUMPUS_STAYS = 26;
constexpr int S27_ARROW_MISSED = 27;
constexpr int S28_INTERNAL_ERROR = 28;
constexpr int S29_WUMPUS_EATS_BAT = 29;
constexpr int S30_WUMPUS_FALLS = 30;
constexpr int S31_WUMPUS_MOVED = 31;



const string textMessage[] =
{
	/*S0_CAVENUM*/	      "Cave number: ",
	/*S1_ADJCAVE*/	      " is connected to the following caves: ",
	/*S2_BAT*/			  " B ",
	/*S3_PIT*/		      " * ",
	/*S4_WUMPUS*/         " W ",
	/*S5_PLAYER*/		  " P ",
	/*S6_KEEPPLAYING*/    "Do you want to keep playing? ",
	/*S7_INVALID*/        "Not a valid choice. \n",
	/*S8_CAVENUMBER*/     "You're in cave number: ",
	/*S9_ADJACENT_CAVES*/ " Adjacent caves are: ",
	/*S10_MAKE_CHOICE*/   "Do you want to (S)hoot, (M)ove, (Q)uit or (H)elp? ",
	/*S11_SHOW_HELP*/     "\n\nRules of Hunt the Wumpus game: \n\n\
The game is set in a cavern that consists of 20 caves.\n\
Each cave has passages connecting to three other caves.\n\
(The cavern has the shape of a dodecahedron with nodes as caves and edges\n\
as passages between caves.)\n\
In the cavern there are two Bats, two Pits, and one Wumpus.\n\
The Wumpus is in his own cave, and no cave can have two Bats.\n\
However, a single cave can have both a Bat and a Pit.\n\
Each turn the player chooses either to move or shoot one of his five arrows.\n\n\
If the player moves:\n\
Whenever the player enters a cave, he \"senses\" what happens in adjacent caves:\n\
Nearby Wumpus: \"You smell something terrible nearby.\"\n\
Nearby Bat: \"You hear a rustling sound.\"\n\
Nearby Pit: \"You feel a cold wind blowing from a nearby cavern.\"\n\
The player loses the game if he enters a cave with the Wumpus or a pit.\n\
If he enters a cave with a bat, the bat carries him to another cave.\n\
If that cave has a pit, he falls into the pit and loses the game.\n\
(The bat cannot take him to the cave with the Wumpus.)\n\n\
If the player shoots: \n\
- He wins the game if he shoots to the cave with the Wumpus,\n\
     or the Wumpus moves to an adjacent cave with a pit.\n\
- He loses the game if he uses all his arrows before killing the Wumpus,\n\
     or Wumpus moves to the cave with yhe player in it.\n\
- If he shoots to a cave with a pit, the Wumpus will stay a sleep.\n\
- If he shoots to a cave with a bat, there is a 50% chance the bat is killed\n\
     and a 50% chance the bat stays alive.\n\
- If he shoots to any other cave, the Wumpus has a 75% chance of waking up\n\
     and moving to an adjacent cave.\n\n\
If the Wumpus does move to an adjacent cave, there are four possible outcomes.\n\
   1 - The Wumpus moves to the cave with the player and eats him.\n\
       The player loses the game.\n\
   2 - The Wumpus moves to a cave with a bat and eats it.\n\
   3 - The Wumpus moves to a cave with a pit and falls in.\n\
       The player wins the game.\n\
   4 - The wumpus moves to an empty cave.\n\n",
	/*S12_EASTER_EGG_MESSAGE*/   "This version of The Wumpus Hunter was developed by The Rock, \
The Hammer and Grand. Copyright 2020.  All rights reserved.\nA big thanks to the Grand for being the \
best tutor :) \n", 
    /*S13_WHICH_CAVE*/              "Which cave?",
	/*S14_SNIFF*/		            "I smell a Wumpus!\n",
	/*S15_FEEL*/                    "I feel a cold draft!\n",
	/*S16_LISTEN*/                  "I hear a rustling nearby!\n",
	/*S17_ARROWS_LEFT*/             "The number of arrows left are: ",
	/*S18_GAME_LOST_ARROWS*/        "Game lost because you consumed all arrows\n",
	/*S19_GAME_LOST_WUMPUS*/        "Game lost because the Wumpus ate you\n",
	/*S20_GAME_LOST_PIT*/           "Game lost because you fell in the Pit\n",
	/*S21_BAT_TRANSFERS*/           "You've been transfered by the Bat to cave: ",
	/*S22_BAT_TRANSFERS_FROM_PIT*/  "You've been saved from falling the Pit by the Bat.\n",
	/*S23_WUMPUS_STAYS_ASLEEP*/     "The Cave was empty and the Wumpus stayed asleep.\n",
	/*S24_ARROW_KILLS_WUMPUS*/      "Arrow killed the Wumpus and you won the game!\n",
	/*S25_ARROW_KILLS_BAT_WUMPUS_MOVES*/  "Arrow killed a Bat.\n",
	/*S26_ARROW_KILLS_BAT_WUMPUS_STAYS*/  "Arrow killed a Bat and the Wumpus stayed asleep.\n",
	/*S27_ARROW_MISSED*/            "Your Arrow missed.\n",
	/*S28_INTERNAL_ERROR*/          "Internal error, game terminated.\n",
	/*S29_WUMPUS_EATS_BAT*/         "The Wumpus moved and ate a Bat.\n",
	/*S30_WUMPUS_FALLS*/            "The Wumpus fell in a Pit, you won the game!\n",
	/*S31_WUMPUS_MOVED*/            "The Wumpus moved.\n"
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


constexpr char PLAYER_CHOICE[] =
{
	/*C0_NO*/	           'N',
	/*C1_NO*/	           'n',
	/*C2_YES*/             'Y',
	/*C3_YES*/             'y',
	/*C4_QUIT*/            'Q',
	/*C5_QUIT*/            'q',
	/*C6_MOVE*/            'M',
	/*C7_MOVE*/            'm',
	/*C8_SHOOT*/           'S',
	/*C9_SHOOT*/		   's',
	/*C10_HELP*/		   'H',
	/*C11_HELP*/		   'h',
	/*C12_HELP*/           '?',
	/*C13_PRINTCAVERN*/    '+',
	/*C14_EASTEREGG*/      '_'

}; 
