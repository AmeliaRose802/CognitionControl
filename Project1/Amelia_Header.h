#include <string>
using namespace std;
#pragma once


void genrateCode(int code[], int codeLength, int numOfOptions);
void printArray(int code[], int codeLength);
void getGuess(int guess[], int codeLength);
void copyArray(int newArray[], int oldArray[], int codeLength);
void printLogo();
double calcPermutations(int codeLength, int codeOptions);
double calcReward(int codeLength, int codeOptions, int numRows, double bet);
double calcChances(int codeLength, int codeOptions, int numRows);
double calcScore(int codeLength, int codeOptions, int rowsNeeded);
int getData(string filename, struct player accounts[]);
int makeAccount(struct player accounts[], int numAccounts, string fileName);
bool saveAccounts(struct player accounts[], int numAccounts, string fileName);
void printUserAccount(struct player accounts[], int id);
void printWinScreen();
void memberMenu(int id, struct player accounts[], string fileName, int numAccounts);
void modifyAccount(struct player accounts[], int id, string fileName, int numAccounts);
void makeDeposit(struct player accounts[], int id);
double playGame(int bet, int id, struct player accounts[]);
void breakKneeCaps();
void setAvgScore(int id, double newScore, struct player accounts[]);

struct player
{
	long int CC_Num;
	double avgScore;
	int numGames;
	int defaultRows;
	int defaultNumOptions;
	int defaultCodelength;
	double balance;
};

const int MAX_CODE_LENGTH = 10;
const int MAX_ACCOUNTS = 200;