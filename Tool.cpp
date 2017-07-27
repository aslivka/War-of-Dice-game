#include "Tool.hpp"

Tool::Tool()
{


}

Tool::Tool(int str, char t)
{
	strength = str;
	type = t;
}

Tool::~Tool()
{

}

void Tool::SetStrength(int s)
	{
		strength = s;
	}

	void Tool::SetType(char a)
	{
		type = a;
	}

	char Tool::getType()
	{
		return type;
	}

	int Tool::fight(Tool* opponent)
	{
		//will be overridden, have return statement
		//to avoid compile errors
		return 0;
	}
