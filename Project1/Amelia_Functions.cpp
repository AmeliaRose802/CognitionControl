#include <iostream>
#include <string>
#include <stdio.h> 
#include <stdlib.h>     
#include <time.h> 
using namespace std;

void genrateCode( int answer[], int codeLength, int numOfOptions) 
{
	srand(time(NULL));

	for (int i = 0; i < codeLength; i++) 
	{
		answer[i] = (rand() % numOfOptions)+1;
	}

}

void printArray(int answer[], int codeLength) 
{
	for (int i = 0; i < codeLength; i++) 
	{
		cout <<  answer[i] << " ";
	}
}

void getGuess(int guess[], int codeLength) {
	for (int i = 0; i < codeLength; i++) {
		cin >> guess[i];
	}
}