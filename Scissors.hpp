/******************************************************************************
** Author       : Paul Bodnar, Jeremy Einhorn, Michael Johnson, Amir Rasekh and
**                Artem Slivka
** Date         : 07/30/2017
** Description  : Scissors.hpp is the header file for class Scissors. It contains
**				  function declarations for the class.
******************************************************************************/

#ifndef SCISSORS_HPP
#define SCISSORS_HPP

#include "Tool.hpp"
#include <string>
#include <iostream>

class Scissors : public Tool
{
public:
	Scissors();
	Scissors(int eStrength);
	~Scissors();
	int fight(Tool* a) override;
	int getStrength();
};

#endif