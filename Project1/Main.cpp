#include <iostream>
#include <string>
#include "Amelia_Header.h"
using namespace std;

int main() {
	const int CODE_LENGTH = 4;
	const int NUM_OPTIONS = 6;
	int code[CODE_LENGTH];
	int guess[CODE_LENGTH];
	genrateCode(code, CODE_LENGTH, NUM_OPTIONS);
	printArray(code, CODE_LENGTH);

	
	//Define varibles that remain throughout turn 


	//Get any set up info we want like name, number of turns allowed etc

	//

	cout << endl;
	system("pause");
}

//FUNCTIONS

//Genrate code
//Get guess
//compair guess and code
//Genrate feetback
//Fourmat output of arrays
