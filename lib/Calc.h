#ifndef CALC_H
#define CALC_H

class Calc
{
private:
	float m_currVal;
public:
	Calc();
	float Addition(float valOne, float valTwo);
	float Subtraction(float valOne, float valTwo);
	float Multiplication(float valOne, float valTwo);
	float Division(float valOne, float valTwo);
	float GetVal() const;
};

#endif