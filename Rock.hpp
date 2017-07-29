/******************************************************************************
** Author       : Paul Bodnar, Jeremy Einhorn, Michael Johnson, Amir Rasekh and
**                Artem Slivka
** Date         : 07/30/2017
** Description  : Rock.hpp is the header file for class Rock. It contains
**				  function declarations for the class.
******************************************************************************/

#ifndef ROCK_HPP
#define ROCK_HPP

#include "Tool.hpp"

class Rock : public Tool
{
public:
	Rock();
	Rock(int eStrength);
	~Rock();
	int fight(Tool* a) override;
	int getStrength();
}; 

#endif