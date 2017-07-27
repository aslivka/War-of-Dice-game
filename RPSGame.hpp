#ifndef RPSGAME_HPP
#define RPSGAME_HPP

#include "Rock.hpp"
#include "Paper.hpp"
#include "Scissors.hpp"
#include <iostream>
#include <string>

using namespace std;

class RPSGame
{
protected:
	Tool *human;
	Tool *computer;
	int human_wins;
	int computer_wins;
	int ties;
	int rPower = 1;
	int pPower = 1;
	int sPower = 1;

public:

	RPSGame();
	~RPSGame();
	bool menu();
	void differentStrengths();
	int setDiffStrength();
	bool startGame();
	bool isAChar(const string input);
	string computerChoice();
	void determineWinner(const int*);		
};
#endif