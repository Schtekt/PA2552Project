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
	float Factorial(float val);
	float Modulus(int val, int mod);
	float Negative(float val);
	float GetVal() const;
	float MemAdd();
	float GetMem() const;
	void Reset();
	void MemReset();
};

#endif