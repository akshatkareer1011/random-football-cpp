/**
    A Football game made using random numbers, much like Ludo.
    Copyright (C) 2019  Snehit Sah

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

    Contact the author : snehitsah[at]gmail[dot]com
**/

#ifndef _PLAYERDATA_
#define _PLAYERDATA_

#include<iostream>
#include<string.h>

using namespace std;

//Function for delay
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}



HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CP;

void gotoXY(int x, int y)
{
    CP.X = x;
    CP.Y = y;
    SetConsoleCursorPosition(console, CP);
}

// Structure to hold variables
// for various power-ups
struct powerups
{
    // Power-up to allow player to
    // attempt a shoot before they
    // reach the goalkeeper
    int longShot;

    // Power-up to allow player to
    // select upto 8 numbers depending
    //on difficulty chosen
    int lucky8;

    // Power-up to allow player to
    // skip the toss at start of
    // match and instead commence
    // the game himself
    int skipTheToss;
};

class userData
{
    // Variable to store score
    // index 0 : wins
    // index 1 : loses
    // index 2 : draws
    int score[3];

    // Variable to hold player's name
    char playerName[50];

    // Coins, or the virtual money
    long int coins;

    // Power-up database
    powerups playerPowerUp;



public:
    //Function to input player's data
    void input();
    // Function to return pointer
    // to the playerName array
    const char *getPlayerName() const;
};

// Function to input
// user data
void userData::input()
{
    gotoXY(15, 5);
    cout << "Enter Player's Name: ";
    scanf(" %[^\n]s\n", playerName);
}

// Function to return pointer
// to the playerName array
const char *userData::getPlayerName() const
{
    return playerName;
}

// Function to save user
// data on the disk
void saveData(userData &u)
{
    /**Function to save data
     * from the class &u (passed as argument)
     * to a file in binary format
     * Save file location should be:
     * C:\RandomFootball\[playerName].dat
     *
     *Player Name is in the playerName variable
     */
    u.input();
    char saveFileName[100];
    strcpy(saveFileName, "C:\\RandomFootball\\");
    strcat(saveFileName, u.getPlayerName());
    strcat(saveFileName, ".dat");
    ofstream savePlayerData;
    savePlayerData.open(saveFileName, ios::binary);
    gotoXY(20, 7);
    cout<<"Game data saved!";
}

// Function to load user
// data from the disk
void loadData(userData &u)
{
    /**Function to load data
     * from the file at :
     * C:\RandomFootball\[name].dat
     * to the class u passed as argument
     *
     * name has also been passed as argument
     */
addUserData:
    u.input();
    char loadFileName[100];
    strcpy(loadFileName, "C:\\RandomFootball\\");
    strcat(loadFileName, u.getPlayerName());
    strcat(loadFileName, ".dat");
    ifstream loadPlayerData;
    loadPlayerData.open(loadFileName, ios::binary);
    if (loadPlayerData)
    {
        gotoXY(18, 7);
        cout<<"Loading game data ";
        delay(1000);
        cout<<". ";
        delay(1000);
        cout<<". ";
        delay(1000);
        cout<<". ";
        gotoXY(18, 9);
        cout << "Saved game data loaded!";
    }
    else
    {
        gotoXY(18, 7);
        cout<<"Loading game data ";
        delay(1000);
        cout<<". ";
        delay(1000);
        cout<<". ";
        delay(1000);
        cout<<". ";
        gotoXY(18, 9);
        cout << "No game data saved by this name! Please retry!";
        delay(3000);
        system("cls");
        goto addUserData;
    }
}

#endif
