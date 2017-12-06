#include <iostream>
#include <string>
#include <Windows.h>
#include <locale>  
#include "Amelia_Header.h"
#include "Will_Header.h"
#include <fstream>
#include <stdio.h>
#include <ctype.h>
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


//CAUTION: This program will react violently if you fail to pay debts for too long. This is intentional and not a bug. 


int main() {
	system("Color 0A");
	//4A red and nastsy
	//Define varibles that remain throughout game 
	int userId;
	string fileName = "accounts.txt";

	//Make array for player accounts to be read into 
	struct player accounts[MAX_ACCOUNTS];

	//Read in the player accounts
	int numAccounts = getData(fileName, accounts);
	
	//Print out logo to console
	cout << " Welcome To:  \n\n\n\n";
	printLogo();

	
	//Check if user has account
	char hasAccount;
	cout << "Do you have an account (Y, N): ";
	cin >> hasAccount;
	hasAccount = toupper(hasAccount);
	if (hasAccount == 'Y') {
		//if so get the ID number
		cout << "For security we refer to users only by their 0 indexed intiger id number. \n";
		cout << "What is your ID number: ";
		cin >> userId;

		//Verify that it is not out of array bounds. Program will shut down if not since program is basically gangstar who dosent want people who don't know the number inside
		if (userId < 0 || userId > numAccounts) 
		{
			cout << "Account not found";
		}

		//If it is good call member menu
		else 
		{
			memberMenu(userId, accounts, fileName, numAccounts);
		}
	}
	//Otherwise drect them to make account. When finished send them to member menu
	else
	{
		cout << "Please make an account \n";

		//assigning numAccounts keeps number of accounts current when more accounts are added
		numAccounts = makeAccount(accounts, numAccounts, fileName);
		
		//The ID for all new members is one less then the number of accounts since their account is latest and the ids are index 0. 
		memberMenu((numAccounts - 1), accounts, fileName, numAccounts);
	}
}


