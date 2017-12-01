#include <string>
using namespace std;
#pragma once


void genrateCode(int code[], int codeLength, int numOfOptions);
void printArray(int code[], int codeLength);
void getGuess(int guess[], int codeLength);
void formatedPrinter(int guess[], int codeLength);
string formatArray(int answer[], int codeLength);
void copyArray(int newArray[], int oldArray[], int codeLength);
void printLogo();
double calcPermutations(int codeLength, int codeOptions, int numRows);
double calcReward(int codeLength, int codeOptions, int numRows, double bet);
double calcChances(int codeLength, int codeOptions, int numRows);
double calcScore(int codeLength, int codeOptions, int rowsNeeded);
int readInAccounts(struct player accounts[], string filename);

struct player
{
	string name;
	double accountBal;
	int CC_Num;
	double avgScore;
	int numGames;
	int defaultRows;
	int defaultNumOptions;
	int defaultCodelength;
	double balance;
};