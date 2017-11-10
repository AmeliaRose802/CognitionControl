#include <iostream>
#include <string>
#include <stdio.h> 
#include <stdlib.h>     
#include <time.h> 
using namespace std;

void genrateCode( int code[], int codeLength, int numOfOptions) 
{
	srand(time(NULL));

	for (int i = 0; i < codeLength; i++) 
	{
		code[i] = (rand() % numOfOptions)+1;
	}

}

void printArray(int code[], int codeLength) 
{
	for (int i = 0; i < codeLength; i++) 
	{
		cout <<  code[i] << " ";
	}
}