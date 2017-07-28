/******************************************************************************
** Author       : Paul Bodnar, Jeremy Einhorn, Michael Johnson, Amir Rasekh and
**                Artem Slivka
** Date         : 07/30/2017
** Description  : Scissors.cpp is the implementation file for class Scissors. 
**				  It contains function definitions for the class.
******************************************************************************/

#include "Scissors.hpp"

/*********************************************************************
** Description	: This is the default constructor for class Scissors.
*********************************************************************/
Scissors::Scissors() : Tool(1, 's')
{
	strength = 1;
}

/*********************************************************************
** Description	: This is the 2nd constructor for class Scissors.
**				  It allows user to set strength.
*********************************************************************/
Scissors::Scissors(int eStrength) : Tool(eStrength, 's')
{
	SetStrength(eStrength);
}

/*********************************************************************
** Description	: This is the default destructor for class Scissors.
*********************************************************************/
Scissors::~Scissors()
{

}

/*********************************************************************
** Description	: This function allows Scissors object to fight another
**				  Tool opponent.
*********************************************************************/
int Scissors::fight(Tool* a)
{
	if (a->getType() == 'r')
	{
		//compare strength
		if (SVR *strength > this->strength)
		{
			return -1;
		}
		if (SVR *strength < this->strength)
		{
			return  1;
		}

		return 0;
	}

	if (a->getType() == 'p')
	{
		//compare strength
		if (SVP * strength > this->strength)
		{
			return -1;
		}
		if (SVP * strength < this->strength)
		{
			return 1;
		}

		return 0;
	}

	if (a->getType() == 's')
	{
		//compare strength
		if (SVS * strength > this->strength)
		{
			return -1;
		}
		if (SVS * strength < this->strength)
		{
			return 1;
		}

		return 0;
	}
}

