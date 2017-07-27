#include "Paper.hpp"

Paper::Paper() : Tool(1, 'p')
{
		strength = 1;
}

Paper::Paper(int eStrength) : Tool(eStrength, 'p')
{
	SetStrength(eStrength);
}

Paper::~Paper()
{
}

int Paper:: fight(Tool* a)
{	
		if (a->getType() == 'r')
		{
			
			//compare strength
			if (PAPERAGAINSTROCK *strength > this->strength) //PAPERAGAINSTROCK *
			{
				
				return -1;
			}
			if (PAPERAGAINSTROCK *strength < this->strength)  //PAPERAGAINSTROCK *
			{
				
				return 1;
			}

			else
				return 0;
		}

		if (a->getType() == 'p')
		{
			//compare strength
			if (PAPERAGAINSTPAPER *strength > this->strength)  //PAPERAGAINSTPAPER *
			{
				
				return -1;
			}
			if (PAPERAGAINSTPAPER *strength < this->strength)  //PAPERAGAINSTPAPER *
			{
				return 1;
			}
			else
				return 0;
		}

		if (a->getType() == 's')
		{
			
			//compare strength
			if (PAPERAGAINSTSCISSORS *strength > this->strength +1)  //PAPERAGAINSTSCISSORS *
			{
				return -1;
			}
			if (PAPERAGAINSTSCISSORS *strength < this->strength +1)  //PAPERAGAINSTSCISSORS *
			{
				return 1;
			}
			else
				return 0;
		}
}
