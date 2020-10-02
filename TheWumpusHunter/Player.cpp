#include<iostream>
#include<sstream>
#include"Player.h"
#include"TheWumpusHunter.h"
#include"textMessage.h"
#include"Cave.h"
#include"Cavern.h"
using namespace std;

void Player::showText(string messageText)
{
	cout << messageText;
}
void Player::showText(const ostringstream& outText)
{
	showText(outText.str());
}
bool Player::keepPlaying()
{
    bool validChoice = false;
    bool selection;
    char playerChoosing;
    bool gotChoice;
        while (not validChoice)
        {
            showText(textMessage[S6_KEEPPLAYING]);
            gotChoice = getChoice(playerChoosing);
            if (gotChoice)
            {
                switch (playerChoosing)
                {
                case PLAYER_CHOICE[C2_YES]:
                case PLAYER_CHOICE[C3_YES]:
                    selection = true;
                    validChoice = true;
                    break;
                case PLAYER_CHOICE[C0_NO]:
                case PLAYER_CHOICE[C1_NO]:
                    selection = false;
                    validChoice = true;
                    break;
                default:
                    showText(textMessage[S7_INVALID]);
                }
            }
        }
        return selection;
}

bool Player::getChoice(char& choice)
{
    //Gets a character from the user and stores it in choice.
    //  Returns true if successful; false otherwise

        string inText;

        if (getline(cin, inText))
        {
            stringstream(inText) >> choice;
            return true;
        }
        return false;
}

bool Player::getChoice(int& choice)
{
    string inText;

    if (getline(cin, inText))
    {
        stringstream(inText) >> choice;
        return true;
    }
    return false;
}
void Player::setID(int caveID)
{
    inCave = caveID;
}
int Player::getID()
{
    return inCave;
}

void Player::showCave(int passageList[])
{
    ostringstream outText;
    outText << textMessage[S8_CAVENUMBER] << getID() << textMessage[S9_ADJACENT_CAVES];
    for (int j = 0; j < PASS_PER_CAVE; j++)
        outText << " " << passageList[j];
    outText << ".\n";
    showText(outText);
}

int Player::chooseAction()
{
    bool validChoice = false;
    int selection;
    char playerChoosing;
    bool gotChoice;
    while (not validChoice)
    {
        showText(textMessage[S10_MAKE_CHOICE]);
        gotChoice = getChoice(playerChoosing);
        if (gotChoice)
        {
            switch (playerChoosing)
            {
            case PLAYER_CHOICE[C6_MOVE]:
            case PLAYER_CHOICE[C7_MOVE]:
                selection = C6_MOVE;
                validChoice = true;
                break;
            case PLAYER_CHOICE[C8_SHOOT]:
            case PLAYER_CHOICE[C9_SHOOT]:
                selection = C8_SHOOT;
                validChoice = true;
                break;
            case PLAYER_CHOICE[C10_HELP]:
            case PLAYER_CHOICE[C11_HELP]:
            case PLAYER_CHOICE[C12_HELP]:
                selection = C10_HELP;
                validChoice = true;
                break;
            case PLAYER_CHOICE[C4_QUIT]:
            case PLAYER_CHOICE[C5_QUIT]:
                selection = C4_QUIT;
                validChoice = true;
                break;
            case PLAYER_CHOICE[C13_PRINTCAVERN]:
                selection = C13_PRINTCAVERN;
                validChoice = true;
                break;
            case PLAYER_CHOICE[C14_EASTEREGG]:
                selection = C14_EASTEREGG;
                validChoice = true;
                break;
            default:
                showText(textMessage[S7_INVALID]);
            }
        }
    }
    return selection;
}

int Player::chooseCave(int passageList[])
{
    bool validChoice = false;
    int playerChoice;
    bool gotChoice;
    while (not validChoice)
    {
        showText(textMessage[S13_WHICH_CAVE]);
        gotChoice = getChoice(playerChoice);
        if (gotChoice)
        {
            for (int i = 0; i < PASS_PER_CAVE; i++)
            {
                if (passageList[i] == playerChoice)
                        validChoice = true;
            }
            if(!validChoice)
                showText(textMessage[S7_INVALID]);
        }
    }
   return playerChoice;
}