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
        while (not validChoice)
        {
            cout << "Do you want to keep playing?" << endl;
            cin >> validChoice;
                if (validChoice==true)
                {
                    selection = true;
                    validChoice = true;
                }
                    if (validChoice==false)
                    {
                        selection = false;
                        validChoice = true;
                    }
                    if (not validChoice)
                        cout << "Invalid input!" << endl;
        }
        return selection;
}
