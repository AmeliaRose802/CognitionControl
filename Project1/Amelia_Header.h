#include <string>
using namespace std;
#pragma once


void genrateCode(int code[], int codeLength, int numOfOptions);
void printArray(int code[], int codeLength);
void getGuess(int guess[], int codeLength);
void formatedPrinter(int guess[], int codeLength);
string feedback(int answer[], int guess[], int codeLength);
string formatArray(int answer[], int codeLength);
int checkRightNumWrongSpot(int answer[], int guess[], int codeLength)