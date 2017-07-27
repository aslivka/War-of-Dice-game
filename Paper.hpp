#ifndef PAPER_HPP
#define PAPER_HPP

#include "Tool.hpp"
#include <iostream>
#include <string>
using namespace std;

class Paper : public Tool
{

public:
	Paper();
	Paper(int eStrength);
	~Paper();
	int fight(Tool* a);
	
};
#endif