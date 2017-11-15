#include <iostream>
#include <string>
#include <stdio.h> 
#include <stdlib.h>     
#include <time.h> 
#include <Windows.h>
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

int checkRightNumWrongSpot(int answer[], int guess[], const int codeLength) {
	int checkGuess[codeLength];
	int checkAnswer[codeLength];
	int rightNum = 0;
	for (int i = 0; i < codeLength; i++) {
		for (int j = 0; j < codeLength; j++)
		{

			cout << "j = " << j << " i = " << i << " answer[i] = " << answer[i] << "guess[j] = " << guess[j] << endl;
			if ((answer[i] == guess[j]) && (i != j))
			{
				cout << "Another right number in the wrong spot" << endl;
				cout << "rightNum = " << rightNum << endl;
				rightNum++;
			}
		}
	}

	cout << "Right Numbers Wrong spot: " << rightNum;
	return (rightNum/2);
}
void copyArray(int newArray[], int oldArray[], int codeLength) {
	for (int i = 0; i < codeLength; i++) {
		newArray[i] = oldArray[i];
	}
}