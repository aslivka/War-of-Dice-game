/******************************************************************************
** Author       : Paul Bodnar, Jeremy Einhorn, Michael Johnson, Amir Rasekh and
**                Artem Slivka
** Date         : 07/30/2017
** Description  : RPSGame.cpp is the implementation file for class RPSGame. It 
**				  contains function definitions for the class. The class
**				  manages play for a game of Rock Paper Scissors.
******************************************************************************/

#include "RPSGame.hpp"
#include <iostream>

/*********************************************************************
** Description	: This is the default constructor for class RPSGame.
*********************************************************************/
RPSGame::RPSGame()
{
	human = NULL;
	computer = NULL;
	human_wins = 0;
	computer_wins = 0;
	ties = 0;
}

/*********************************************************************
** Description	: This is the default destructor for class RPSGame.
*********************************************************************/
RPSGame::~RPSGame()
{
	if (human != NULL)
		delete human;
	if (computer != NULL)
		delete computer;
}

/*********************************************************************
** Description	: This function controls setup for the game. It allows 
**				  user to select if they want to play with preset 
**				  strengths or enter the strengths instead for the
**				  human player.
*********************************************************************/
bool RPSGame::menu()
{
	string userDiffStrenChoice = "";

	cout << "Welcome to Rock, Paper, Scissors! Do you want to choose different" 
	     << " strengths for the tools?" << endl;
	clearValues();

	do
	{
		cout << "Enter Y for YES and N for NO: ";
		getline(cin, userDiffStrenChoice);
	} while (userDiffStrenChoice != "y" && 
		     userDiffStrenChoice != "n" && 
		     userDiffStrenChoice != "Y" && 
		     userDiffStrenChoice != "N");

	if (userDiffStrenChoice == "y" || userDiffStrenChoice == "Y")
	{
		differentStrengths();
		if (!startGame())
		{
			return false;
		}
	}
	else
	{
		if (!startGame())
		{
			return false;
		}
	}
}


void RPSGame::clearValues()
{
	rPower = 1;
	pPower = 1;
	sPower = 1;
	human_wins = 0;
	computer_wins = 0;
	ties = 0;
}

/*********************************************************************
** Description	: This function manages user input for different
**				  strength of tools. 
*********************************************************************/
void RPSGame::differentStrengths()
{
	string userInput = "";

	cout << "Would you like to set the strength of rock?" << endl;
	do
	{
		cout << "Enter 'y' for yes and 'n' for no: ";
		getline(cin, userInput);
	} while (userInput != "y" && userInput != "n"
          && userInput != "Y" && userInput != "N");

	if (userInput == "y" || userInput == "Y")
	{
		do
		{
			//cout << "I'm here " << endl << endl;
			//system("pause");
			rPower = getUnsignedInt("Choose a number between 1 and 20: ");
		} while (rPower < 1 || rPower > 20);
	}
	/*************************************************************/

	cout << "Would you like to set the strength of paper?" << endl;
	do
	{
		cout << "Enter 'y' for yes and 'n' for no: ";
		getline(cin, userInput);
	} while (userInput != "y" && userInput != "n"
          && userInput != "Y" && userInput != "N");

	if (userInput == "y" || userInput == "Y")
	{
		do
		{
			pPower = getUnsignedInt("Choose a number between 1 and 20: ");
		} while (pPower < 1 || pPower > 20);
	}
	/*************************************************************/

	cout << "Would you like to set the strength of scissors?" << endl;
	do
	{
		cout << "Enter 'y' for yes and 'n' for no: ";
		getline(cin, userInput);
	} while (userInput != "y" && userInput != "n"
		  && userInput != "Y" && userInput != "N");

	if (userInput == "y" || userInput == "Y")
	{
		do
		{
			sPower = getUnsignedInt("Choose a number between 1 and 20: ");
		} while (sPower < 1 || sPower > 20);
	}
}


/*********************************************************************
** Description	: This function does user validation for
**				  unsigned integers.
*********************************************************************/
int RPSGame::getUnsignedInt(string prompt) const
{
	string userInput;

	do
	{
		cout << prompt;
		getline(cin, userInput);
	} while (!(isUnsignedInt(userInput)) || userInput == "0" || userInput == "");

	return stoi(userInput);
}

/*********************************************************************
** Description	: This function checks if a test string has the format
**				  of unsigned integer. 
*********************************************************************/
bool RPSGame::isUnsignedInt(string input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		if (!isdigit(input[i]))
		{
			return false;
		}
	}
	return true;
}

/*********************************************************************
** Description	: This function completes a round of gameplay, then 
**				  displays the win/los/tie results.
*********************************************************************/
bool RPSGame::startGame()
{
	do
	{
		string userChoice = "";
		int result;
		string computerSelected;

		do
		{
			cout << "Choose your tool (r-rock, p-paper, s-scissor, e-exit): ";
			getline(cin, userChoice); //store entered line in variable
		} while (userChoice != "r" && userChoice != "R"
			  && userChoice != "p" && userChoice != "P"
			  && userChoice != "s" && userChoice != "S"
			  && userChoice != "e" && userChoice != "E");

		if (userChoice == "r" || userChoice == "R")
		{
			human = new Rock(rPower);
			computerSelected = computerChoice();
			cout << endl;
			cout << "Computer chose " << computerSelected << "." << endl
				 << endl;
			result = human->fight(computer);
			determineWinner(&result);
		}

		if (userChoice == "p" || userChoice == "P")
		{
			human = new Paper(pPower);
			computerSelected = computerChoice();
			cout << endl;
			cout << "Computer chose " << computerSelected << "." << endl
				 << endl;
			result = human->fight(computer);
			determineWinner(&result);
		}

		if (userChoice == "s" || userChoice == "S")
		{
			human = new Scissors(sPower);
			computerSelected = computerChoice();
			cout << endl;
			cout << "Computer chose " << computerSelected << "." << endl << endl;
			result = human->fight(computer);
			determineWinner(&result);
		}

		if (userChoice == "e" || userChoice == "E")
		{
			return false;
		}
	} while (true);
}

/*********************************************************************
** Description	: This function randomly chooses the tool type
**				  for the computer player and returns the selected type.
*********************************************************************/
string RPSGame::computerChoice()
{
	int rNumber = rand() % 3;

		if (rNumber == 1)
		{
			computer = new Rock(rPower);
			return "rock";
		}
		if (rNumber == 2)
		{
			computer = new Paper(pPower);
			return "paper";
		}
		else
		{
			computer = new Scissors(sPower);
			return "scissors";
		}
}

/*********************************************************************
** Description	: This function calculates the round results for both
**				  players, then displays the round and overall results.
*********************************************************************/
void RPSGame::determineWinner(const int *result)
{
	if (*result == 1)
	{
		computer_wins += 1;
		cout << "Computer Wins! :-(" << endl;
		cout << endl;
		cout << "Human Wins: " << human_wins << endl;
		cout << endl;
		cout << "Computer Wins: " << computer_wins << endl;
		cout << endl;
		cout << "Ties: " << ties << endl;
		cout << endl;
		cout << endl;
	}

	if (*result == -1)
	{
		human_wins += 1;
		cout << "You Win!!!" << endl;
		cout << endl;
		cout << "Human Wins: " << human_wins << endl;
		cout << endl;
		cout << "Computer Wins: " << computer_wins << endl;
		cout << endl;
		cout << "Ties: " << ties << endl;
		cout << endl;
		cout << endl;

	}
	if (*result == 0)
	{
		ties += 1;
		cout << "Draw" << endl;
		cout << endl;
		cout << "Human Wins: " << human_wins << endl;
		cout << endl;
		cout << "Computer Wins: " << computer_wins << endl;
		cout << endl;
		cout << "Ties: " << ties << endl;
		cout << endl;
		cout << endl;
	}
}

//bool RPSGame::isAChar(const string& input)
//{
//		//It's easier during implementation to assume the value is char, then
//		//check for cases where this condition is violated
//		bool charValue = true;
//
//		unsigned int strLen = input.length();
//
//		if (strLen != 1 || isalpha(input[0]) == false)
//		{
//			charValue = false;
//		}
//
//		return charValue;
//}

//int RPSGame::setDiffStrength()
//{
//	int strenInput;
//
//	do
//	{
//		strenInput = isUnsignedInt("Choose a number between 1 and 20: ");
//	} while (strenInput < 1 || strenInput > 20);
//	return strenInput;
//}