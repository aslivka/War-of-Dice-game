/******************************************************************************
** Program      : Group Project: Rock, Paper, Scissors
** Author       : Paul Bodnar, Jeremy Einhorn, Michael Johnson, Amir Rasekh and
**                Artem Slivka
** Date         : 07/30/2017
** Description  : This program plays a game of Rock, Paper, Scissors, with
**				  either preset Tool strengths or user-entered strengths.
******************************************************************************/

#include <iostream>
#include <string>
#include "RPSGame.hpp"
#include <ctime>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{	
	srand(size_t(time(NULL)));
	
	string menuChoice;

	//Starting the menu for the program
	do
	{
		cout << "\t====Program menu====" << endl;
		cout << "1: Play a game of rock-paper-scissors!" << endl;
		cout << "2: Exit" << endl << endl;
		
		//Storing user's menu choice
		do
		{
			cout << "Enter menu option (as integer): ";
			getline(cin, menuChoice);
		} while (menuChoice != "1" && menuChoice != "2");
	
		//Starting game
		if (menuChoice == "1")
		{
			RPSGame game1;
			game1.menu();
		}
		
	} while (menuChoice != "2");

	return 0;
}