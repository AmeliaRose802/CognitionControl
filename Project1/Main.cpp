#include <iostream>
#include <string>
#include <Windows.h>
#include <locale>  
#include "Amelia_Header.h"
#include "Will_Header.h"
#include <fstream>
using namespace std;



/*
TODO: 
Fix checker algrothim 
Add in file system account manager. - Amelia
Finish itegrating betting stuff - Amelia
Fix the output so prompt numbers are a fixed width
Add color coded responces 
Make results appear on same line as input
Format printing of doubles (round or formated printer)
Force good inputs at all points
*/



//TODO It would be cool to make it so when they run out of rows it gives them the option to input their credit card to go on playing
//Global constant length is used in multible files and never changes
const int MAX_CODE_LENGTH = 10;
const int MAX_ACCOUNTS = 100;

int main() {

	//Define varibles that remain throughout game 
	int codeLength;
	int numOptions;
	int rounds;
	double bet;
	bool hasWon = false;
	string name;
	string fileName = "accounts.txt";

	int code[MAX_CODE_LENGTH];
	int guess[MAX_CODE_LENGTH];
	
	


	//Make array for player accounts to be read into 
	struct player players[100];

	//Read in account info 
	readInAccounts(players, fileName);

	//Print out logo to console
	cout << " Welcome To:  \n\n\n\n";
	printLogo();
	


	//Get any set up info we want like name, number of turns allowed etc
	char hasAccount;
	cout << "Do you have an account (Y, N): ";
	cin >> hasAccount;
	toupper(hasAccount);

	if (hasAccount == 'Y') {

		//Get ID number 

		char defaultInfo;
		cout << "Would you like to use your default info (Y or N): ";
		cin >> defaultInfo;
		toupper(defaultInfo);
		if (defaultInfo == 'Y') {
			cout << "Using defult info, fill in later";
		}
		else {
			//Get code length
			//TODO force this to be less then max
			cout << "How long would you like your code to be: (max is " << MAX_CODE_LENGTH << "): ";
			cin >> codeLength;

			//Get num of options in code
			cout << "How many options should your code have: ";
			cin >> numOptions;

			//Get number of rounds
			cout << "How many guesses would you like before game over: ";
			cin >> rounds;
		}
	}
	else {
		//Get name (might use later for save files)
		cout << "Please enter your name: ";
		getline(cin, name);

		//Get code length
		//TODO force this to be less then max
		cout << "How long would you like your code to be: (max is " << MAX_CODE_LENGTH << "): ";
		cin >> codeLength;

		//Get num of options in code
		cout << "How many options should your code have: ";
		cin >> numOptions;

		//Get number of rounds
		cout << "How many guesses would you like before game over: ";
		cin >> rounds;

	}

	//get bet before we show them odds
	cout << "How much would you like to bet: ";
	cin >> bet;

	system("CLS");

	printLogo();
	//Genrate correct code 
	genrateCode(code, codeLength, numOptions);

	//Print out instuructions 
	cout << "Instructions: \n";
	cout << "1. Enter " << codeLength << " numbers after the prompt \n";
	cout << "2. The input must be whole numbers in the range 1 to " << numOptions << "\n";
	cout << "3. Do not enter strings or anything else into the prompt \n\n";
	cout << "4. Your iodds if you guessed randomly are: " << calcChances(codeLength, numOptions, rounds);
	cout << "5. Your payout is: " << calcReward(codeLength, numOptions, rounds, bet);
	

	//Start game loop
	int i = 0;
	while (i<rounds && !hasWon){ //Exit when counter is greater then num of rounds, quit value is entered, or player has won 
		cout << "\n" << (i+1)<< ".  "; //TODO get this to align such that it has the same width even when double digits
		getGuess(guess, codeLength);
		hasWon = checkSpot(guess, code, codeLength);
		i++;
	} //END OF GAME LOOP

	
	//Check if win condition was met
	if (hasWon) {
		system("CLS");
		cout << " /$$     /$$                        /$$      /$$ /$$          " << endl;
		cout << "|  $$   /$$/                       | $$  /$ | $$|__/          " << endl;
		cout << " \\  $$ /$$//$$$$$$  /$$   /$$      | $$ /$$$| $$ /$$ /$$$$$$$ " << endl;
		cout << "  \\  $$$$//$$__  $$| $$  | $$      | $$/$$ $$ $$| $$| $$__  $$" << endl;
		cout << "   \\  $$/| $$  \\ $$| $$  | $$      | $$$$_  $$$$| $$| $$  \\ $$" << endl;
		cout << "    | $$ | $$  | $$| $$  | $$      | $$$/ \\  $$$| $$| $$  | $$" << endl;
		cout << "    | $$ |  $$$$$$/|  $$$$$$/      | $$/   \\  $$| $$| $$  | $$" << endl;
		cout << "    |__/  \\______/  \\______/       |__/     \\__/|__/|__/  |__/" << endl;

		cout << "Your score was " << calcScore(codeLength,numOptions, i);
	}
	else {
		cout << "Your code was ";
		printArray(code, codeLength);
		cout << "\nYou are out of rows. Would you like to enter your credit card info to contunue (Y or N): ";
	}
	cout << endl;
	system("pause");
}


