#include "Interface.h"

int Interface::getIntInput()
{
	int in;
	while (true)
	{
		std::cin >> in;
		//Confirm valid input
		if (!std::cin)
		{
			std::cout << "Please only give integer input" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else
			break;


	}
	return in;
}

float Interface::getFloatInput()
{
	float in;
	while (true)
	{
		std::cin >> in;
		//Confirm valid input
		if (!std::cin)
		{
			std::cout << "Please only give integer input" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else
			break;


	}
	return in;
}

Interface::Interface()
{
	Function addition(&Calc::Addition, "Addition", "Please input two numbers, num1 + num2", 2);
	functions.push_back(addition);

	Function substraction(&Calc::Subtraction, "Subtraction", "Please input two numbers, num1 - num2", 2);
	functions.push_back(substraction);

	Function multiplication(&Calc::Multiplication, "Multiplication", "Please input two numbers, num1 * num2", 2);
	functions.push_back(multiplication);

	Function division(&Calc::Division, "Division", "Please input two numbers, num1 / num2", 2);
	functions.push_back(division);

	Function factorial(&Calc::Factorial, "Factorial", "Please input one numbers, !num1", 1);
	functions.push_back(factorial);

	Function modulus(&Calc::Modulus, "Modulus", "Please input two numbers, num1 mod num2", 2);
	functions.push_back(modulus);

	Function negative(&Calc::Negative, "Negative", "Please input one numbers, -num1", 1);
	functions.push_back(negative);
}

void Interface::run()
{
	while (true) {
		//Print overhead text
		std::cout << HEADER << std::endl;
		std::cout << "Input the number to choose the operator to use." << std::endl;

		//Print the avaible options
		int i = 0;
		for (; i < functions.size(); i++) {
			std::cout << (i+1) << ": " << functions.at(i).name << std::endl;
		}
		std::cout << (i+1) << ": Exit" << std::endl;

		//Take input to select option
		int in = getIntInput();

		if (in == (i + 1)) {
			break;
		}
		else if(in > 0 && in < (i + 1)){
			system("cls");
			std::cout << HEADER << std::endl;
			std::cout << functions.at(in - 1).name << ": " << functions.at(in - 1).instruction << std::endl;

			float* var = new float[functions.at(in - 1).nrOfInputs];
			for (int j = 0; j < functions.at(in - 1).nrOfInputs; j++) {
				var[j] = getFloatInput();
			}

			float result = (calc.*functions.at(in - 1).func)(var);

			std::cout << "Result: " << result << std::endl;
			std::cout << "Click any key to continue..." << std::endl;
			std::getchar();
			std::getchar();
			delete var;
		}
		system("cls");
	}
}
