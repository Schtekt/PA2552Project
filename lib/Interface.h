#ifndef INTERFACE_H
#define INTERFACE_H
#include <string>
#include <iostream>
#include <vector>
#include "Calc.h"

#define HEADER "PA2552 Project Calculator\n******************************************"

class Interface {
private:
	Calc calc;
	class Function {
	public:
		float (Calc::*func)(float[]);
		std::string name;
		std::string instruction;
		int nrOfInputs;
		//(Function Pointer, Function Name, Instructions, Function parameter input)
		Function(float (Calc::*func)(float[]), std::string name, std::string instruction, int nrOfInputs) {
			this->func = func;
			this->name = name;
			this->instruction = instruction;
			this->nrOfInputs = nrOfInputs;
		}
	};

	std::vector<Function> functions;

	int getIntInput();
	float getFloatInput();
public:
	Interface();

	void run();
};

#endif // !INTERFACE_H
