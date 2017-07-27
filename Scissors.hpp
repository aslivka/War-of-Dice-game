#ifndef SCISSORS_HPP
#define SCISSORS_HPP

#include "Tool.hpp"
#include <string>
#include <iostream>

using namespace std;

class Scissors : public Tool
{
public:

	Scissors();
	Scissors(int eStrength);
	~Scissors();
	int fight(Tool* a);
	
};

#endif