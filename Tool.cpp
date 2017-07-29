/******************************************************************************
** Author       : Paul Bodnar, Jeremy Einhorn, Michael Johnson, Amir Rasekh and
**                Artem Slivka
** Date         : 07/30/2017
** Description  : Tool.cpp is the implementation file for class Tool. It contains 
**				  function definitions for the class.
******************************************************************************/

#include "Tool.hpp"

/*********************************************************************
** Description	: This is the default constructor for class Tool.			
*********************************************************************/
Tool::Tool()
{

}

/*********************************************************************
** Description	: This is the 2nd constructor for class Tool. 
**				  It allows user to set strength and type.
*********************************************************************/
Tool::Tool(int str, char t)
{
	strength = str;
	type = t;
}

/*********************************************************************
** Description	: This is the default destructor for class Tool.
*********************************************************************/
Tool::~Tool()
{

}

/*********************************************************************
** Description	: This function allows user to set strength of Tool
**				  object.
*********************************************************************/
void Tool::SetStrength(int s)
{
	strength = s;
}

/*********************************************************************
** Description	: This function allows user to set type of Tool
**				  object.
*********************************************************************/
void Tool::SetType(char a)
{
	type = a;
}

/*********************************************************************
** Description	: This function returns type of Tool object.
*********************************************************************/
char Tool::getType()
{
	return type;
}

/*********************************************************************
** Description	: This function allows Tool object to fight another 
**				  Tool opponent. Implementation left for derived 
**				  classes.
*********************************************************************/
int Tool::fight(Tool* opponent)
{
	return 0;
}

int Tool::getStrength()
{
	return strength;
}
