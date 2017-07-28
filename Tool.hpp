/******************************************************************************
** Author       : Paul Bodnar, Jeremy Einhorn, Michael Johnson, Amir Rasekh and
**                Artem Slivka
** Date         : 07/30/2017
** Description  : Tool.hpp is the header file for class Tool. It contains
**				  function declarations for the class.
******************************************************************************/

#ifndef TOOL_HPP
#define TOOL_HPP

static const double RVP = 0.5;
static const double RVS = 2;
static const double RVR = 1;
static const double PVR = 2;
static const double PVS = 0.5;
static const double	PVP = 1;
static const double	SVP = 2;
static const double	SVR = 0.5;
static const double SVS = 1;

class Tool
{
protected:
	int strength;
	char type;

public:
	Tool();
	Tool(int, char);
	virtual ~Tool();
	virtual int fight(Tool*);
	void SetStrength(int s);
	void SetType(char a);
	char getType();
};
#endif
