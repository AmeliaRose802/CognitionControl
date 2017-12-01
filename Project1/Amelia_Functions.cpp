#include <iostream>
#include <string>
#include <stdio.h> 
#include <stdlib.h>     
#include <time.h> 
#include <Windows.h>
#include <cmath>
#include "Amelia_Header.h"
#include "Will_Header.h"
#include <fstream>
using namespace std;

/*
This function genrates a array of random intigers. the intigers are genrated in the range 0, nomOfOptions.
codeLength ints are genrated. 
The random intigers are plced into answer[]

int answer[] - empty intiger array into which the genrated numbers will be placed. Length must be greater then or equal to codeLength
int codeLangth - The number of ints that will be created
int numOfOptions - The upper limit of the range in which the numbers will be genrated. 
*/
void genrateCode( int answer[], int codeLength, int numOfOptions) 
{
	srand(time(NULL));

	for (int i = 0; i < codeLength; i++) 
	{
		answer[i] = (rand() % numOfOptions)+1;
	}

}
/*
This function prints out the content of an array on one line with one space between each element
int answer[] - The array to be printed
int codeLength - number of elemnts in answer[]
*/
void printArray(int answer[], int codeLength) 
{
	for (int i = 0; i < codeLength; i++) 
	{
		cout <<  answer[i] << " ";
	}
}

string formatArray(int answer[], int codeLength)
{
	string row = "";

	for (int i = 0; i < codeLength; i++)
	{
		row.append(answer[i] +" " );
	}
	return row;
}


void formatedPrinter(int guess[], int codeLength) {
	static int i = 1;
	cout << i << ". " << formatArray(guess, codeLength) << " Feedback: " << "0 0 0 0" << endl;
	i++;
}

/*
This function gets an array of intigers from the user 
int guess[] - array that will hold the numbers entered by the user. Length must be greater then or equal to codeLength
int codeLength - The number of ints that are needed
*/
void getGuess(int guess[], int codeLength) {
	for (int i = 0; i < codeLength; i++) {
		cin >> guess[i];
	}
}
/*
int checkRightNumWrongSpot(int answer[], int guess[], const int codeLength) {
	int checkGuess[100];
	int checkAnswer[100];



	copyArray(checkAnswer, answer, codeLength);
	copyArray(checkGuess, guess, codeLength);
	int ws = 0;
	int rs = 0;
	cout << endl;
	for (int i = 0; i < codeLength; i++) {
		cout << "\nNew code digit being tested\n\n";

		for (int j = 0; j < codeLength; j++) {
			cout << "answer["<< i<<"]  = " << checkAnswer[i] << " guess["<< j <<"] = " << checkGuess[j] << endl;
			if ((checkAnswer[i] == checkGuess[j]) && (i != j ))
			{
				cout << "Right num wrong spot \n";
				ws++;
				checkAnswer[j] = -1;
				cout << checkGuess[j];
			}
			if (checkAnswer[i] == checkGuess[j] && (i == j))
			{
				checkAnswer[j] = -1;
				cout << "Right Num Right Spot \n";
				rs++;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
			}
		}

	}
	cout << "Right Num wrong spot " << ws << " Right number right spot " << rs << endl;

	return 0;
}*/



void copyArray(int newArray[], int oldArray[], int codeLength) {
	for (int i = 0; i < codeLength; i++) {
		newArray[i] = oldArray[i];
	}
}

void printLogo() {
	cout << "   _____                  _ _   _              _____            _             _ " << endl;
	cout << "  / ____|                (_) | (_)            / ____|          | |           | |" << endl;
	cout << " | |     ___   __ _ _ __  _| |_ _  ___  _ __ | |     ___  _ __ | |_ _ __ ___ | |" << endl;
	cout << " | |    / _ \\ / _` | '_ \\| | __| |/ _ \\| '_ \\| |    / _ \\| '_ \\| __| '__/ _ \\| |" << endl;
	cout << " | |___| (_) | (_| | | | | | |_| | (_) | | | | |___| (_) | | | | |_| | | (_) | |" << endl;
	cout << "  \\_____\\___/ \\__, |_| |_|_|\\__|_|\\___/|_| |_|\\_____\\___/|_| |_|\\__|_|  \\___/|_|" << endl;
	cout << "               __/ |                                                            " << endl;
	cout << "              |___/                                                             " << endl;
	cout << "\n\n\n\n\n";
}

/*Gambeling functions*/

double calcPermutations(int codeLength, int codeOptions) {
	double prob = (double)pow(codeOptions, codeLength);
	cout << prob;
	return prob;
}

double calcChances(int codeLength, int codeOptions, int numRows) {
	return ((1 / calcPermutations(codeLength, codeOptions) ) *numRows);
}

double calcReward(int codeLength, int codeOptions, int numRows, double bet) {
	//Calcuates a payout based on the chances of failure and an arbatary modifier to make payout less
	double payOut = bet + ((1 - calcChances(codeLength, codeOptions, numRows))*bet / 10);
	return payOut;
}

double calcScore(int codeLength, int codeOptions, int rowsNeeded) {
	return ((codeLength * codeOptions) / rowsNeeded);
}

int readInAccounts(struct player accounts[], string filename) {
	ifstream reader(filename);
	int id = 0;

	if (reader.is_open()){
	//Read data info array's
		while ((!reader.eof()) && (id < 1000))
		{
			reader >> accounts[id].name;
			reader >> accounts[id].balance;
			reader >> accounts[id].CC_Num;
			reader >> accounts[id].avgScore;
			reader >> accounts[id].defaultRows;
			reader >> accounts[id].defaultCodelength;
			reader >> accounts[id].defaultNumOptions;
		}
	}
	else {
		cout << "\n Fatle Error: File could not be read\n";
		id = -1;
	}

	return id;

}
