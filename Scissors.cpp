
#include "Scissors.hpp"

Scissors::Scissors() : Tool(1, 's')
{
	strength = 1;
}


Scissors::Scissors(int eStrength) : Tool(eStrength, 's')
{
	SetStrength(eStrength);
}

Scissors::~Scissors()
{

}

int Scissors::fight(Tool* a)
{
		if (a->getType() == 'r')
		{
			//compare strength
			if (SCISSORSAGAINSTROCK *strength > this->strength)
			{
				return -1;
			}
			if (SCISSORSAGAINSTROCK *strength < this->strength)
			{
				return  1;
			}
			else
				return 0;
		}

		if (a->getType() == 'p')
		{
			//compare strength
			if (SCISSORSAGAINSTPAPER *strength > this->strength)
			{
				return -1;
			}
			if (SCISSORSAGAINSTPAPER *strength < this->strength)
			{
				return 1;
			}
			else
				return 0;
		}

		if (a->getType() == 's')
		{
			//compare strength
			if (SCISSORSAGAINSTSCISSORS *strength > this->strength)
			{
				return -1;
			}
			if (SCISSORSAGAINSTSCISSORS *strength < this->strength)
			{
				return 1;
			}
			else
				return 0;
		}
}

