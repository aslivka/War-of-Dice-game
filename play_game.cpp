/******************************************************************************
** Program		: play_game.cpp
** Author		: Paul Bodnar, Jeremy Einhorn, Michael Johnson, Amir Rasekh and
                  Artem Slivka
** Date			: 07/30/2017
** Description	:
** Input		:
** Output		:
******************************************************************************/

#include <iostream>
#include <string>
#include "RPSGame.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{	
	RPSGame game1;
	

	int menuChoice;
	string inputString;

	do
	{
		cout << "====Program menu====" << endl;
		cout << "1: Play a game of rock-paper-scissors." << endl;
		cout << "2: Quit Program." << endl << endl;
		
		do
		{
			cout << "Enter menu option (as integer)." << endl;
			getline(cin, inputString);
			menuChoice = stoi(inputString);
		} while (menuChoice != 1 && menuChoice != 2);
	
		if (menuChoice == 1)
		{
			game1.menu();
		}
		
	} while (menuChoice != 2);

		cout << "Exiting program..." << endl;
	
	cin.get();
	return 0;
}



