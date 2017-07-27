#ifndef ROCK_HPP
#define ROCK_HPP

#include "Tool.hpp"
#include <string>
#include <iostream>

using namespace std;

class Rock : public Tool
{
public:

	Rock();
	Rock(int eStrength);
	~Rock();
	int fight(Tool* a);
	
}; 

#endif