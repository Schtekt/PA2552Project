#ifndef CALC_H
#define CALC_H

class Calc
{
private:
	float m_currVal;
	float m_memorized;
public:
	Calc();
	float Addition(float valOne, float valTwo);
	float Subtraction(float valOne, float valTwo);
	float Multiplication(float valOne, float valTwo);
	float Division(float valOne, float valTwo);
	float GetVal() const;
	float MemAdd() const;
	float GetMem() const;
};

#endif