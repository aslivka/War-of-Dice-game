/******************************************************************************
** Author       : Paul Bodnar, Jeremy Einhorn, Michael Johnson, Amir Rasekh and
**                Artem Slivka
** Date         : 07/30/2017
** Description  : RPSGame.hpp is the header file for class RPSGame. It contains
**				  function declarations for the class.
******************************************************************************/

#ifndef RPSGAME_HPP
#define RPSGAME_HPP

#include "Tool.hpp"
#include "Rock.hpp"
#include "Paper.hpp"
#include "Scissors.hpp"
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
	int getUnsignedInt(string prompt) const;
	static bool isUnsignedInt(string);
	bool startGame();
	string computerChoice();
	void determineWinner(const int*);
};
#endif