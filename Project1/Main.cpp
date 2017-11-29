#include <iostream>
#include <string>
#include <Windows.h>
#include "Amelia_Header.h"
#include "Will_Header.h"
using namespace std;
//TODO It would be cool to make it so when they run out of rows it gives them the option to input their credit card to go on playing
//Global constant length is used in multible files and never changes
const int MAX_CODE_LENGTH = 10;

int main() {

	//Define varibles that remain throughout game 
	int codeLength;
	int numOptions;
	int rounds;
	bool hasWon = false;
	string name;

	int code[MAX_CODE_LENGTH];
	int guess[MAX_CODE_LENGTH];
	
	

	/*
	genrateCode(code, CODE_LENGTH, NUM_OPTIONS);
	printArray(code, CODE_LENGTH);
	cout << "Enter " << CODE_LENGTH << " ints: ";
	getGuess(guess, CODE_LENGTH);
	
	

	checkSpot(guess, code, CODE_LENGTH);
	*/

	//Print out logo to console
	cout << " Welcome To:  \n\n\n\n";
	cout << "   _____                  _ _   _              _____            _             _ " << endl;
	cout << "  / ____|                (_) | (_)            / ____|          | |           | |" << endl;
	cout << " | |     ___   __ _ _ __  _| |_ _  ___  _ __ | |     ___  _ __ | |_ _ __ ___ | |" << endl;
	cout << " | |    / _ \\ / _` | '_ \\| | __| |/ _ \\| '_ \\| |    / _ \\| '_ \\| __| '__/ _ \\| |" << endl;
	cout << " | |___| (_) | (_| | | | | | |_| | (_) | | | | |___| (_) | | | | |_| | | (_) | |" << endl;
	cout << "  \\_____\\___/ \\__, |_| |_|_|\\__|_|\\___/|_| |_|\\_____\\___/|_| |_|\\__|_|  \\___/|_|" << endl;
	cout << "               __/ |                                                            " << endl;
	cout << "              |___/                                                             " << endl;
	cout << "\n\n\n\n\n";
	


	//Get any set up info we want like name, number of turns allowed etc

	//Get name (might use later for save files)
	cout << "Please enter your name: ";
	getline(cin, name);

	//Get code length
	//TODO force this to be less then max
	cout << "How long would you like your code to be: (max is "<<MAX_CODE_LENGTH<<"): ";
	cin >> codeLength;

	//Get num of options in code
	cout << "How many options should your code have: ";
	cin >> numOptions;
	
	//Get number of rounds
	cout << "How many guesses would you like before game over: ";
	cin >> rounds;

	//Genrate correct code 
	genrateCode(code, codeLength, numOptions);

	//Print out instuructions 
	cout << "\n\n\n";
	cout << "instructions: \n";
	cout << "1. Enter " << codeLength << " numbers after the prompt \n";
	cout << "2. The input must be whole numbers in the range 1 to " << numOptions << "\n";
	cout << "3. Do not enter strings or anything else into the prompt \n\n\n";

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
		cout << " /$$     /$$                        /$$      /$$ /$$          " << endl;
		cout << "|  $$   /$$/                       | $$  /$ | $$|__/          " << endl;
		cout << " \\  $$ /$$//$$$$$$  /$$   /$$      | $$ /$$$| $$ /$$ /$$$$$$$ " << endl;
		cout << "  \\  $$$$//$$__  $$| $$  | $$      | $$/$$ $$ $$| $$| $$__  $$" << endl;
		cout << "   \\  $$/| $$  \\ $$| $$  | $$      | $$$$_  $$$$| $$| $$  \\ $$" << endl;
		cout << "    | $$ | $$  | $$| $$  | $$      | $$$/ \\  $$$| $$| $$  | $$" << endl;
		cout << "    | $$ |  $$$$$$/|  $$$$$$/      | $$/   \\  $$| $$| $$  | $$" << endl;
		cout << "    |__/  \\______/  \\______/       |__/     \\__/|__/|__/  |__/" << endl;

		cout << "You Win";
	}
	else {
		cout << "You Luse";
	}
	cout << endl;
	system("pause");
}





//FUNCTIONS

//Genrate code
//Get guess
//compair guess and code
//Genrate feetback
//Fourmat output of arrays
