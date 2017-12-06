#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<string>
#include<vector>
#include "Amelia_Header.h"
#include "Will_Header.h"

using namespace std;



bool checkSpot(int guess[], int answer[], const int CODE_LENGTH)
{
	//Set up temp arrays
	int tempGuess[100];
	int tempAnswer[100];

	//Set up counter vars
	int rightNum = 0;
	int rnWrongSpot = 0;
	int matches = 0;
	bool hasWon = false;

	//Cody the arrays
	copyArray(tempGuess, guess, CODE_LENGTH);
	copyArray(tempAnswer, answer, CODE_LENGTH);


	//Get all matches
	for (int i = 0; i < CODE_LENGTH; i++) 
	{
		for (int j = 0; j < CODE_LENGTH; j++)
		{
			if (tempAnswer[i] == tempGuess[j])
			{
				matches++;

				//Set the index to impossible values so nums cant be counted twice
				tempAnswer[j] = -1;
				tempGuess[i] = -2;

			}

		}
	}

	//Reset the arrays
	copyArray(tempGuess, guess, CODE_LENGTH);
	copyArray(tempAnswer, answer, CODE_LENGTH);

	//gets right num right spot
	for (int k = 0; k < CODE_LENGTH; k++)
	{
		if (tempAnswer[k] == tempGuess[k]) 
		{
			rightNum++;
		}
	}

	//Calculate how many are in wrong spot by subtracting the number in the right spot from the total number of matches
	rnWrongSpot = matches - rightNum;

	if (rightNum >= CODE_LENGTH) 
	{
		hasWon = true;
	}
	else 
	{
		cout << "                      Right Num Wrong Spot:  " << rnWrongSpot << " Right Num Right Spot " << rightNum;
	}
	return hasWon;
}

