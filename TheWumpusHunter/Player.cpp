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
    char playerChoice;
    bool gotChoice;
        while (not validChoice)
        {
            cout << "Do you want to keep playing?" << endl;
            cin >> playerChoice;
            gotChoice = getChoice(playerChoice);
                if (playerChoice==playerChoice[2]||playerChoice==playerChoice[3])
                {
                    selection = true;
                    validChoice = true;
                }
                    if (playerChoice == playerChoice[0] || playerChoice == playerChoice[1])
                    {
                        selection = false;
                        validChoice = true;
                    }
                    if (not validChoice)
                        cout << "Invalid input!" << endl;
        }
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