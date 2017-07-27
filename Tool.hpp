#ifndef TOOL_HPP
#define TOOL_HPP

static const double ROCKAGAINSTPAPER = 0.5;
static const double ROCKAGAINSTSCISSORS = 2;
static const double ROCKAGAINSTROCK = 1;
static const double PAPERAGAINSTROCK = 2;
static const double PAPERAGAINSTSCISSORS = 0.5;
static const double	PAPERAGAINSTPAPER=1;
static const double	SCISSORSAGAINSTPAPER=2;
static const double	SCISSORSAGAINSTROCK =0.5;
static const double SCISSORSAGAINSTSCISSORS = 1;

#include <string>
#include <iostream>
using namespace std;

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
