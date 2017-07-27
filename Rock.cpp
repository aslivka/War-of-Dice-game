#include "Rock.hpp"


Rock::Rock() : Tool(1, 'r')
{
	strength = 1;
}

Rock::Rock(int eStrength) : Tool(eStrength, 'r')
{
	SetStrength(eStrength);
}

Rock::~Rock()
{


}

int Rock::fight(Tool* a)
{
	if (a->getType() == 'r')
	{
		//compare strength
		if ((ROCKAGAINSTROCK * strength) > this->strength)
		{
			cout << (ROCKAGAINSTROCK * strength) << endl;
			cout << this->strength;
			return -1;
		}
		if ((ROCKAGAINSTROCK * strength) < this->strength)
		{
			cout << (ROCKAGAINSTROCK * strength) << endl;
			cout << this->strength;
			return 1;
		}
		else
			0;
	}

	if (a->getType() == 'p')
	{
		//compare strength
		if ((ROCKAGAINSTPAPER * strength) > this->strength)
		{
			cout << (ROCKAGAINSTPAPER * strength) << endl;
			cout << this->strength;
			return -1;
		}
		if ((ROCKAGAINSTPAPER * strength) < this->strength)
		{
			cout << (ROCKAGAINSTPAPER * strength) << endl;
			cout << this->strength;
			return 1;
		}
		else
			return 0;
	}

	if (a->getType() == 's')
	{
		//compare strength
		if ((ROCKAGAINSTSCISSORS * strength) > this->strength)
		{
			cout << (ROCKAGAINSTSCISSORS * strength) << endl;
			cout << this->strength;
			return -1;
		}
		if ((ROCKAGAINSTSCISSORS * strength) < this->strength)
		{
			cout << (ROCKAGAINSTSCISSORS * strength) << endl;
			cout << this->strength;
			return 1;
		}
		else
			return 0;
	}
}
