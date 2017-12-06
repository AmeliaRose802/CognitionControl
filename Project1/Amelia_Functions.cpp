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
#include <stdio.h>
#include <ctype.h>
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


/*
This function gets an array of intigers from the user 
int guess[] - array that will hold the numbers entered by the user. Length must be greater then or equal to codeLength
int codeLength - The number of ints that are needed
*/
void getGuess(int guess[], int codeLength) 
{
	for (int i = 0; i < codeLength; i++) 
	{
		cin >> guess[i];
	}
}

/*
This function copy's each element of oldArray to newArray. 
Primalary called in checkSpot in Will's file
*/
void copyArray(int newArray[], int oldArray[], int codeLength) 
{
	for (int i = 0; i < codeLength; i++) 
	{
		newArray[i] = oldArray[i];
	}
}


void printLogo() 
{

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

void printWinScreen() 
{
	cout << " /$$     /$$                        /$$      /$$ /$$          " << endl;
	cout << "|  $$   /$$/                       | $$  /$ | $$|__/          " << endl;
	cout << " \\  $$ /$$//$$$$$$  /$$   /$$      | $$ /$$$| $$ /$$ /$$$$$$$ " << endl;
	cout << "  \\  $$$$//$$__  $$| $$  | $$      | $$/$$ $$ $$| $$| $$__  $$" << endl;
	cout << "   \\  $$/| $$  \\ $$| $$  | $$      | $$$$_  $$$$| $$| $$  \\ $$" << endl;
	cout << "    | $$ | $$  | $$| $$  | $$      | $$$/ \\  $$$| $$| $$  | $$" << endl;
	cout << "    | $$ |  $$$$$$/|  $$$$$$/      | $$/   \\  $$| $$| $$  | $$" << endl;
	cout << "    |__/  \\______/  \\______/       |__/     \\__/|__/|__/  |__/" << endl;
}

/***************************************Gambeling functions***********************************************/

/*
This function takes a length and options and calculates how many codes are possible
*/
double calcPermutations(int codeLength, int codeOptions) 
{
	double prob = (double)pow(codeOptions, codeLength);
	return prob;
}

/*
Calculates odds of winning if you guessed randomly. Dependednt on calcPermutations
*/
double calcChances(int codeLength, int codeOptions, int numRows) 
{
	double chances = ((1 / calcPermutations(codeLength, codeOptions) ) *numRows);
	if (chances > 1) {
		chances = 1;
	}
	return chances;
}

/*
Calculates a payout based on odds of not winning and bet. Devides that by ten so the house makes more
*/
double calcReward(int codeLength, int codeOptions, int numRows, double bet) 
{
	//Calcuates a payout based on the chances of failure and an arbatary modifier to make payout less
	double payOut = ((1 - calcChances(codeLength, codeOptions, numRows))*bet / 10);
	return payOut;
}

/*
Calcualtes your score. Drectly proportional to codeLength and codeOptions, inversly proportional to rowsNeeded
*/
double calcScore(int codeLength, int codeOptions, int rowsNeeded) 
{
	return (((codeLength * codeOptions) / rowsNeeded)*100);
}
/*
Update the avgrage score
*/
void setAvgScore(int id, double newScore, struct player accounts[]) 
{
	accounts[id].avgScore = ( (accounts[id].avgScore) *(accounts[id].numGames - 1) + newScore) / accounts[id].numGames;
}


/********************File IO Functions**************************/
/*
Reads the account data from the file into an array of player structs
*/
int getData(string filename, struct player accounts[])
{
	//Define file reader and a counter
	ifstream reader(filename);
	
	//Counts rows read in ie. accounts
	int i = 0;

	//check if file is open
	if (reader.is_open())
	{
		
		//Read data info array's
		while ((!reader.eof()) && (i < MAX_ACCOUNTS))
		{
			//Read each peice of data into its place int the array
			reader >> accounts[i].balance;
			reader >> accounts[i].CC_Num;
			reader >> accounts[i].avgScore;
			reader >> accounts[i].numGames;
			reader >> accounts[i].defaultRows;
			reader >> accounts[i].defaultCodelength;
			reader >> accounts[i].defaultNumOptions;
			i++;
			
		}
		
	}

	//If file did not open let user know
	else
	{
		cout << "The file could not be read\n";

	}
	//0 will be returned if file dosent exzist
	return i;
}


/*
Saves the accounts back to the file. Called by a number of functions including makeAccount and memberMenu.
Returns true if it saves sucessfully
*/
bool saveAccounts(struct player accounts[], int numAccounts, string fileName) 
{

	//define varibles
	bool sucess;
	ofstream writer(fileName);

	if (writer.is_open())
	{
		//Run through each account. 
		for (int i = 0; i < numAccounts; i++) {

			//If the file is not the first row output a new line character. 
			if ((i != 0)) 
			{
				writer << "\n";
			}
			
			//Print out all data to file
			writer <<accounts[i].balance << " " << accounts[i].CC_Num << " " << accounts[i].avgScore << " " << accounts[i].numGames << " " << accounts[i].defaultRows << " " << accounts[i].defaultCodelength << " " << accounts[i].defaultNumOptions ;
		}
		sucess = true;
	}
	else 
	{
		sucess = false;
		cout << "Writing Failed";
	}
	return sucess;
}

/*
Print out the info for one user with given id 
There is no option to print all account info since that would be a security issue
*/
void printUserAccount(struct player accounts[], int id) 
{
		cout << " id " << id << endl;
		cout << " Balance " << accounts[id].balance << endl;
		cout << " CC_Num " << accounts[id].CC_Num << endl;
		cout << " Avg Score " << accounts[id].avgScore << endl;
		cout << " Num Games " << accounts[id].numGames << endl;
		cout << " Default Rows " << accounts[id].defaultRows << endl;
		cout << " Default Code Length " << accounts[id].defaultCodelength << endl;
		cout << " Default number of options  " << accounts[id].defaultNumOptions << endl;
		cout << "\n";
}

/*
Make a new user account with inputed data.  This calls saveAccounts(). 
*/
int makeAccount(struct player accounts[], int numAccounts, string fileName) 
{
	if (numAccounts <= MAX_ACCOUNTS) 
	{
		
		//Get code length
		cout << "How long would you like your deafult code to be: (max is " << MAX_CODE_LENGTH << "): ";
		cin >> accounts[numAccounts].defaultCodelength;

		//Get num of options in code
		cout << "How many options should your default code have: ";
		cin >> accounts[numAccounts].defaultNumOptions;

		//Get number of rounds
		cout << "How many guesses would you like before game over by default: ";
		cin >> accounts[numAccounts].defaultRows;

		//Get credit card number
		cout << "What is your credit card number: ";
		cin >> accounts[numAccounts].CC_Num;

		//Get an innital deposit from the user 
		cout << "How much money would you like to deposit: ";
		cin >> accounts[numAccounts].balance;

		//Set score and games played to 0
		accounts[numAccounts].numGames = 0;
		accounts[numAccounts].avgScore = 0;

		//This isent actully charging anything to anyones credit card so dont worry :)
		cout << accounts[numAccounts].balance << " has been charged to your credit card \n";
		
		//Increment the number of accounts since a new one has been added. Must happen before calling saveAccounts so that function knows to save new account.
		numAccounts++;
		saveAccounts(accounts, numAccounts, fileName);

		//Let user know their info
		cout << "\nAccount creation sucessful \n";
		
		//No account recovery is allowed since this game is like a secret underground gabling den where you must know your info to get in
		cout << "Your account number is " << numAccounts << " please perserve this for your recourds or you wont be able to acess your account \n\n";
		
	}
	//If the array is full no more accounts can be made
	else 
	{
		cout << "Sorry, can not make account. Max Accounts has been exceeded. ";
	}

	return numAccounts;
}


/*
Modify the game stats of an account. Lets user change their saved codeLength and numOptions and rows. Gives user option to reset scores. 
*/
void modifyAccount(struct player accounts[], int id, string fileName, int numAccounts) 
{

		//Get code length
		cout << "How long would you like your new deafult code to be: (max is " << MAX_CODE_LENGTH << "): ";
		cin >> accounts[id].defaultCodelength;

		//Get num of options in code
		cout << "How many options should your default code have: ";
		cin >> accounts[id].defaultNumOptions;

		//Get number of rounds
		cout << "How many guesses would you like before game over by default: ";
		cin >> accounts[id].defaultRows;

		//Asks user if they want to wipe out all score history 
		char toWipe;
		cout << "Would you like to wipe out your score history (Y or N): ";
		cin >> toWipe;
		toWipe = toupper(toWipe);

		if (toWipe == 'Y') 
		{
			//If yes take it out 
			accounts[id].numGames = 0;
			accounts[id].avgScore = 0;
		}
	
		saveAccounts(accounts, numAccounts, fileName);

		cout << "\nAccount modified \n";
}

/*
Make a deposit in the account. Hypethically charges deposit amount to credit card on record
*/
void makeDeposit(struct player accounts[], int id) {
	cout << "Your current account balance is $" << accounts[id].balance << endl;
	int deposit;
	cout << "How much would you like to deposit: ";
	cin >> deposit;
	accounts[id].balance += deposit; 
	
}

/*
This function is an intentionally nasty peice of work. It prints out "Breaking KneeCaps" indefinatly until you close the window or the computer dies.
This is not a bug, it is a consquence. If the user gets too in debt to the house this function is called as punishment. 
*/
void breakKneeCaps() 
{
	system("Color 4C");
	while (true) 
	{
		cout << "Breaking KneeCaps ";
	}
}

/*
Gets the users bet. Checks if the user is in debt and warns them of consquences. If the user is more then $200 in debt there is a 50% chance that this will call breakKneeCaps()
*/
int getBet(double accountBal) 
{

	//get bet
	double bet;
	cout << "How much would you like to bet: $";
	cin >> bet;
	
	//Calculate what the balance will be if they louse this round
	double newBal = accountBal - bet;

	//If it is negitive issue a warning
	if (newBal < 0) {
		cout << "If you louse this round you will be in the red \n";
		cout << "We are genrously offering you a line of credit, but watch out! If you don't pay us back soon we will have to break your kneecaps\n";

		//If account is unready below $200 it will have a 50% chance of breaking knee caps  
		if ((accountBal < -200) && ((rand() % 2) ==1)) 
		{
			breakKneeCaps();
		}
		system("pause");
	}

	return bet;
}


/**********************************Game running functions********************************************/

/*
This is the main game menu. It is where players spend most of their time. It calls most everything else. 
*/
void memberMenu(int id, struct player accounts[], string fileName, int numAccounts) 
{
	system("Color 0A");

	char selection;

	//Do loop runs until selection is E for exit 
	do
	{
		//Clear and print logo 
		system("CLS");
		printLogo();
	cout << "Welcome Player " << id << endl;
	cout << "What would you like to do? \n";
	cout << "View account info   (V)\n";
	cout << "Modify Account Info (M)\n";
	cout << "Make a deposit      (D)\n";
	cout << "Play Game           (P)\n";
	cout << "Exit program        (E)\n";
	cout << "Make selection: ";
	cin >> selection; 
	selection = toupper(selection);

	//Clear the screen and print logo before printing selection data. This provides smoother experince. 
	system("CLS");
	printLogo();

	//Switch controls menu selection 
	switch (selection) 
	{
		//View info 
		case 'V':
			//Print out your account info
			printUserAccount(accounts, id);
			break;
		//Modify Info
		case 'M':
			//Call modify accounts
			modifyAccount(accounts, id, fileName, numAccounts);
			break;
		//Make a deposit
		case 'D':
			makeDeposit(accounts, id);
			break;
		//Play a game 
		case 'P':
			//Get the bet 
			double bet = getBet(accounts[id].balance);
			system("CLS");
			
			//Start the game. This one returns winnings which can be a positive or negitive number to represent winnings or losses
			double winnings = playGame(bet, id, accounts);
			//Modify balance by winnings
			accounts[id].balance += winnings;
			system("Color 0A");
			break;
	}
	system("pause");


	} 
	//stop running and exit when E is entered
	while (selection != 'E');
	
	//Save accounts before terminating
	saveAccounts(accounts, numAccounts, fileName);
}

/*
The game itself. This function calls other functions and manages the game loop. It returns the winnings or losses
*/
double playGame(int bet, int id, struct player accounts[])
{
	
	printLogo();
	system("Color 1A");
	int code[MAX_CODE_LENGTH];
	int guess[MAX_CODE_LENGTH];
	bool hasWon = false;
	double winnings;

	//Calculate a reward if player wins
	double reward = calcReward(accounts[id].defaultCodelength, accounts[id].defaultNumOptions, accounts[id].defaultRows, bet);
	double percentChance = calcChances(accounts[id].defaultCodelength, accounts[id].defaultNumOptions, accounts[id].defaultRows) * 100;
	

	//Genrate correct code 
	genrateCode(code, accounts[id].defaultCodelength, accounts[id].defaultNumOptions);

	//Print out instuructions 
	cout << "Instructions: \n";
	cout << "1. Enter " << accounts[id].defaultCodelength << " numbers after the prompt seprated by spaces\n";
	cout << "2. The input must be whole numbers in the range 1 to " << accounts[id].defaultNumOptions << "\n";
	cout << "3. Do not enter strings or anything else into the prompt \n";
	cout << "4. Your odds if you guessed randomly are: " << percentChance << "% \n";
	cout << "5. Your payout is: $" << (bet + reward) << "\n\n"; //show payout as origonal bet plus reward so it seems bigger
	

	//Start game loop
	int i = 0;
	while (i<accounts[id].defaultRows && !hasWon) //Exit when counter is greater then num of rounds, quit value is entered, or player has won 
	{ 
		cout << "\n" << (i+1)<< ".  ";  //Print prompt 
		getGuess(guess, accounts[id].defaultCodelength); //Read in user guess
		hasWon = checkSpot(guess, code, accounts[id].defaultCodelength); // Check if code was corrent. Also prints feedback
		i++;
	} //END OF GAME LOOP

	accounts[id].numGames++;
	double score = calcScore(accounts[id].defaultCodelength, accounts[id].defaultNumOptions, i);
	setAvgScore(id, score, accounts);

	//Check if win condition was met
	if (hasWon) {

		//If player has won then set winnings to reward
		system("CLS");
		printWinScreen();
		winnings = reward;


		cout << "\nYou won " << (reward+bet) << endl;
		cout << "Your score was " << score << endl;
		
	}
	else {
		cout << "\nYour code was ";
		printArray(code, accounts[id].defaultCodelength);
		cout << "\nYou lost " << bet << endl;

		winnings = -bet;
	}
	
	return winnings;
}
