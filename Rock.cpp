/******************************************************************************
** Author       : Paul Bodnar, Jeremy Einhorn, Michael Johnson, Amir Rasekh and
**                Artem Slivka
** Date         : 07/30/2017
** Description  : Rock.cpp is the implementation file for class Rock. It contains
**				  function definitions for the class.
******************************************************************************/

#include "Rock.hpp"

/*********************************************************************
** Description	: This is the default constructor for class Rock.
*********************************************************************/
Rock::Rock() : Tool(1, 'r')
{
	strength = 1;
}

/*********************************************************************
** Description	: This is the 2nd constructor for class Rock.
**				  It allows user to set strength for Rock.
*********************************************************************/
Rock::Rock(int eStrength) : Tool(eStrength, 'r')
{
	SetStrength(eStrength);
}

/*********************************************************************
** Description	: This is the default destructor for class Rock.
*********************************************************************/
Rock::~Rock()
{

}

/*********************************************************************
** Description	: This function allows Rock object to fight another
**				  Tool opponent.
*********************************************************************/
int Rock::fight(Tool* a)
{
	if (a->getType() == 'r')
	{
		//compare strength
		if (RVR * strength > a->getStrength())
		{
			return -1;
		}
		if (RVR * strength < a->getStrength())
		{
			return 1;
		}
		
		return 0;
	}

	if (a->getType() == 'p')
	{
		//compare strength
		if (RVP * strength > a->getStrength())
		{
			return -1;
		}
		if (RVP * strength < a->getStrength())
		{
			return 1;
		}
		
		return 0;
	}

	if (a->getType() == 's')
	{
		//compare strength
		if (RVS * strength > a->getStrength())
		{
			return -1;
		}
		if (RVS * strength < a->getStrength())
		{
			return 1;
		}

		return 0;
	}
}

int Rock::getStrength()
{
	return strength;
}
