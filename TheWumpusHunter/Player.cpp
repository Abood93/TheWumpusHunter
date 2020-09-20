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
    bool gotChoice
    ostringstream outText;
        while (not validChoice)
        {
            showText(textMessage[S6_KEEPPLAYING]);
            gotChoice = getChoice(playerChoosing);
                if (playerChoosing==PLAYER_CHOICE[C2_YES]||playerChoosing==PLAYER_CHOICE[C3_YES])
                {
                    selection = true;
                    validChoice = true;
                }
                if (playerChoosing == PLAYER_CHOICE[C0_NO] || playerChoosing == PLAYER_CHOICE[C1_NO])
                {
                     selection = false;
                     validChoice = true;
                }
                if (not validChoice)
                     showText(textMessage[S7_INVALID]);
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