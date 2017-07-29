/******************************************************************************
** Author       : Paul Bodnar, Jeremy Einhorn, Michael Johnson, Amir Rasekh and
**                Artem Slivka
** Date         : 07/30/2017
** Description  : Paper.hpp is the header file for class Paper. It contains
**				  function declarations for the class.
******************************************************************************/

#ifndef PAPER_HPP
#define PAPER_HPP

#include "Tool.hpp"

class Paper : public Tool
{
public:
	Paper();
	Paper(int eStrength);
	~Paper();
	int fight(Tool* a) override;
	int getStrength();
};
#endif