#include "RPSGame.hpp"

RPSGame::RPSGame()
{
	human_wins = 0;
	computer_wins = 0;
	ties = 0;
}

RPSGame::~RPSGame()
{

}

bool RPSGame::menu()
{
		bool testAgain = true;

		do
		{
			cout << "Welcome to Rock, Paper, Scissors! Do you want to choose different strengths for the tools?" << endl;
			cout << "Enter Y, for YES and N for NO" << endl;
			string a = ""; //create string to hold entry   bool isAChar(const string input)
			getline(cin, a); //store entered line in variable
			if (isAChar(a))
			{
				char b = a[0];
				if (b == 'y' || b == 'Y')
				{
					differentStrengths();
					if (startGame() == false)
					{
						return false;
					}
				}

				if (b == 'n' || b == 'N')
				{
					if (startGame() == false)
					{
						return false;
					}
				}
			}

		} while (testAgain);
}


void RPSGame::differentStrengths()
{
	cout << "Would you like to set the strength of rock?" << endl;
	cout << "Enter 'y' for yes and 'n' for no" << endl;
	
	string userInput;
	getline(cin, userInput);

	char input = userInput[0];

	while (input != 'y' && input != 'n')
	{
		cout << "Enter 'y' for yes and 'n' for no" << endl;
		cin >> userInput;
		char input = userInput[0];
	}

	if (input == 'y')
	{
		rPower = setDiffStrength();
		cin.ignore();
	}
	/*************************************************************/

	cout << "Would you like to set the strength of paper?" << endl;
	cout << "Enter 'y' for yes and 'n' for no" << endl;

	getline(cin, userInput);

	input = userInput[0];

	while (input != 'y' && input != 'n')
	{
		cout << "Enter 'y' for yes and 'n' for no" << endl;
		cin >> userInput;
		input = userInput[0];
	}

	if (input == 'y')
	{
		pPower = setDiffStrength();
		cin.ignore();
	}

	/*************************************************************/

	cout << "Would you like to set the strength of scissors?" << endl;
	cout << "Enter 'y' for yes and 'n' for no" << endl;

	getline(cin, userInput);

	input = userInput[0];

	while (input != 'y' && input != 'n')
	{
		cout << "Enter 'y' for yes and 'n' for no" << endl;
		cin >> userInput;
		input = userInput[0];
	}

	if (input == 'y')
	{
		sPower = setDiffStrength();
		cin.ignore();
	}
}


int RPSGame::setDiffStrength()
{
	cout << "Choose a number between 1 and 20" << endl;

	int strenInput;
	cin >> strenInput;

	while (strenInput < 1 || strenInput > 20)
	{
		cout << "Choose a number between 1 and 20" << endl;
		cin >> strenInput;
	}

	return strenInput;
}


bool RPSGame::startGame()
{
		bool testAgain = true;
		do
		{
			cout << "Choose your tool (r-rock, p-paper, s-scissor, e-exit):";
			string a = ""; //create string to hold entry   bool isAChar(const string input)
			getline(cin, a); //store entered line in variable
			if (isAChar(a))
			{
				int result;
				string computerSelected;
				char b = a[0];
				if (b == 'r' || b == 'R')
				{
					human = new Rock(rPower);
					computerSelected = computerChoice();
					cout << endl;
					cout << "Computer chose " << computerSelected << "." << endl;
					cout << endl;
					//computer = new Tool();
					//computer->SetType(computerSelected[0]);
					result = human->fight(computer);
					
					determineWinner(&result);
				}

				if (b == 'p' || b == 'P')
				{
					human = new Paper(pPower);
					computerSelected = computerChoice();
					cout << endl;
					cout << "Computer chose " << computerSelected << "." << endl;
					cout << endl;
					//computer = new Tool();
					//computer->SetType(computerSelected[0]);
					result = human->fight(computer);
					
					determineWinner(&result);						
				}

				if (b == 's' || b == 'S')
				{
					human = new Scissors(sPower);
					computerSelected = computerChoice();
					cout << endl;
					cout << "Computer chose " << computerSelected << "." << endl;
					cout << endl;
					//computer = new Tool();
					//computer->SetType(computerSelected[0]);
					result = human->fight(computer);
					
					determineWinner(&result);
				}
				
				if (b == 'e' || b == 'E')
				{

					return false;
				}
			}
			delete human;
			delete computer;
		} while (testAgain);
}


string RPSGame::computerChoice()
{
	
	int rNumber = rand() % 3 + 1;

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


bool RPSGame::isAChar(const string input)
{
		//It's easier during implementation to assume the value is char, then
		//check for cases where this condition is violated
		bool charValue = true;

		unsigned int strLen = input.length();

		if (strLen != 1 || isalpha(input[0]) == false)
		{
			charValue = false;
		}

		return charValue;
}

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

