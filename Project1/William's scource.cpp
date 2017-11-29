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

	bool hasWon = false;

	//Cody the arrays
	copyArray(tempGuess, guess, CODE_LENGTH);
	copyArray(tempAnswer, answer, CODE_LENGTH);


	//Get right numbers
	for (int i = 0; i < CODE_LENGTH; i++) 
	{
		for (int j = 0; j < CODE_LENGTH; j++)
		{
			if ((tempGuess[(i)] == tempAnswer[(j)]) && ((i) == (j)))
			{

				//tempGuess[i] = guess[i];
				rightNum++;

				//Set the index to impossible values so nums cant be counted twice
				tempGuess[i] = -1;
				tempAnswer[j] = -2;
			}

		}
	}

	//Reset the guess
	copyArray(tempGuess, guess, CODE_LENGTH);

	//gets right num wrong spot
	for (int i = 0; i < CODE_LENGTH; i++)
	{
		for (int j = 0; j < CODE_LENGTH; j++)
		{

			if ((tempGuess[(i)] == tempAnswer[(j)]) && ((i) != (j)))
			{
				//tempAnswer[j] = answer[j];
				rnWrongSpot++;
				tempGuess[i] = -1;
				tempAnswer[j] = -2;
			}

		}
	}
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

