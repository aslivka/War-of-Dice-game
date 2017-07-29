/******************************************************************************
** Author       : Paul Bodnar, Jeremy Einhorn, Michael Johnson, Amir Rasekh and
**                Artem Slivka
** Date         : 07/30/2017
** Description  : Paper.cpp is the implementation file for class Paper. It contains
**				  function definitions for the class.
******************************************************************************/

#include "Paper.hpp"

/*********************************************************************
** Description	: This is the default constructor for class Paper.
*********************************************************************/
Paper::Paper() : Tool(1, 'p')
{
	strength = 1;
}

/*********************************************************************
** Description	: This is the 2nd constructor for class Paper.
**				  It allows user to set strength.
*********************************************************************/
Paper::Paper(int eStrength) : Tool(eStrength, 'p')
{
	SetStrength(eStrength);
}

/*********************************************************************
** Description	: This is the default destructor for class Paper.
*********************************************************************/
Paper::~Paper()
{

}

/*********************************************************************
** Description	: This function allows Paper object to fight another
**				  Tool opponent. 
*********************************************************************/
int Paper::fight(Tool* a)
{	
	if (a->getType() == 'r')
	{	
		//compare strength
		if (PVR * strength > a->getStrength())
		{	
			return -1;
		}
		if (PVR * strength < a->getStrength())
		{	
			return 1;
		}

		return 0;
	}

	if (a->getType() == 'p')
	{
		//compare strength
		if (PVP * strength > a->getStrength())
		{	
			return -1;
		}
		if (PVP * strength < a->getStrength())
		{
			return 1;
		}

		return 0;
	}

	if (a->getType() == 's')
	{	
		//compare strength
		if (PVS * strength > a->getStrength())
		{
			return -1;
		}
		if (PVS * strength < a->getStrength())
		{
			return 1;
		}

		return 0;
	}
}

int Paper::getStrength()
{
	return strength;
}