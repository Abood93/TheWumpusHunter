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
	cout << messageText<< endl;
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
    ostringstream outText;
        while (not validChoice)
        {
            outText << textMessage[S6_KEEPPLAYING] << endl;
            cin >> playerChoosing;
            gotChoice = getChoice(playerChoosing);
                if (playerChoosing==playerChoice[2]||playerChoosing==playerChoice[3])
                {
                    selection = true;
                    validChoice = true;
                }
                    if (playerChoosing == playerChoice[0] || playerChoosing == playerChoice[1])
                    {
                        selection = false;
                        validChoice = true;
                    }
                    if (not validChoice)
                        outText << textMessage[S7_INVALID] << endl;

        }
        thePlayer.showText(outText);
 
        return selection;

}
bool Player::getChoice(char& choice)
{
    //I'll give you the code for this one
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