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
void Player::setID(int x)
{
    inCave = x;
}
int Player::getID()
{
    return inCave;
}
void Player::showCave(int passageList[], int numberOfPassages)
{
    ostringstream outText;
    int i, j;
    int option;
    getChoice(option);
    showText(textMessage[S8_CAVENUMBER]);
    outText << option;
    switch (option)
    {
    case 0:
    {
        showText(textMessage[S9_ADJACENT_CAVES]);
        outText << CAVES[0][0] << " " << CAVES[0][1] << " " << CAVES[0][2];
        break;
    }
    case 1:
    {
        showText(textMessage[S9_ADJACENT_CAVES]);
        outText << CAVES[1][0] << " " << CAVES[1][1] << " " << CAVES[1][2];
        break;
    }
    case 2:
    {
        showText(textMessage[S9_ADJACENT_CAVES]);
        outText << CAVES[2][0] << " " << CAVES[2][1] << " " << CAVES[2][2];
        break;
    }
    case 3:
    {
        showText(textMessage[S9_ADJACENT_CAVES]);
        outText << CAVES[3][0] << " " << CAVES[3][1] << " " << CAVES[3][2];
        break;
    }
    case 4:
    {
        showText(textMessage[S9_ADJACENT_CAVES]);
        outText << CAVES[4][0] << " " << CAVES[4][1] << " " << CAVES[4][2];
        break;
    }
    case 5:
    {
        showText(textMessage[S9_ADJACENT_CAVES]);
        outText << CAVES[5][0] << " " << CAVES[5][1] << " " << CAVES[5][2];
        break;
    }
    case 6:
    {
        showText(textMessage[S9_ADJACENT_CAVES]);
        outText << CAVES[6][0] << " " << CAVES[6][1] << " " << CAVES[6][2];
        break;
    }
    case 7:
    {
        showText(textMessage[S9_ADJACENT_CAVES]);
        outText << CAVES[7][0] << " " << CAVES[7][1] << " " << CAVES[7][2];
        break;
    }
    case 8:
    {
        showText(textMessage[S9_ADJACENT_CAVES]);
        outText << CAVES[8][0] << " " << CAVES[8][1] << " " << CAVES[8][2];
        break;
    }
    case 9:
    {
        showText(textMessage[S9_ADJACENT_CAVES]);
        outText << CAVES[9][0] << " " << CAVES[9][1] << " " << CAVES[9][2];
        break;
    }
    case 10:
    {
        showText(textMessage[S9_ADJACENT_CAVES]);
        outText << CAVES[10][0] << " " << CAVES[10][1] << " " << CAVES[10][2];
        break;
    }
    case 11:
    {
        showText(textMessage[S9_ADJACENT_CAVES]);
        outText << CAVES[11][0] << " " << CAVES[11][1] << " " << CAVES[11][2];
        break;
    }
    case 12:
    {
        showText(textMessage[S9_ADJACENT_CAVES]);
        outText << CAVES[12][0] << " " << CAVES[12][1] << " " << CAVES[12][2];
        break;
    }
    case 13:
    {
        showText(textMessage[S9_ADJACENT_CAVES]);
        outText << CAVES[13][0] << " " << CAVES[13][1] << " " << CAVES[13][2];
        break;
    }
    case 14:
    {
        showText(textMessage[S9_ADJACENT_CAVES]);
        outText << CAVES[14][0] << " " << CAVES[14][1] << " " << CAVES[14][2];
        break;
    }
    case 15:
    {
        showText(textMessage[S9_ADJACENT_CAVES]);
        outText << CAVES[15][0] << " " << CAVES[15][1] << " " << CAVES[15][2];
        break;
    }
    case 16:
    {
        showText(textMessage[S9_ADJACENT_CAVES]);
        outText << CAVES[16][0] << " " << CAVES[16][1] << " " << CAVES[16][2];
        break;
    }
    case 17:
    {
        showText(textMessage[S9_ADJACENT_CAVES]);
        outText << CAVES[17][0] << " " << CAVES[17][1] << " " << CAVES[17][2];
        break;
    }
    case 18:
    {
        showText(textMessage[S9_ADJACENT_CAVES]);
        outText << CAVES[18][0] << " " << CAVES[18][1] << " " << CAVES[18][2];
        break;
    }
    case 19:
    {
        showText(textMessage[S9_ADJACENT_CAVES]);
        outText << CAVES[19][0] << " " << CAVES[19][1] << " " << CAVES[19][2];
        break;
    }
    }
}