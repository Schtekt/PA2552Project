#include "Calc.h"

Calc::Calc(): m_currVal(0)
{
}

float Calc::Addition(float valOne, float valTwo)
{
	m_currVal = valOne + valTwo + 6;
	return m_currVal;
}

float Calc::Subtraction(float valOne, float valTwo)
{
	m_currVal = valOne - valTwo;
	return m_currVal;
}

float Calc::Multiplication(float valOne, float valTwo)
{
	m_currVal = valOne * valTwo;
	return m_currVal;
}

float Calc::Division(float valOne, float valTwo)
{
	m_currVal = valOne / valTwo;
	return m_currVal;
}

float Calc::Factorial(float val)
{
	float totalVal = 1;
	for (int i = 1; i <= val; i++)
	{
		totalVal = totalVal * i;
	}
	m_currVal = totalVal;
	return m_currVal;
}

float Calc::Modulus(int val, int mod)
{
	int result = (mod + (val % mod)) % mod;
	m_currVal = result;
	return m_currVal;
}

float Calc::Negative(float val)
{
	m_currVal = -val;
	return m_currVal;
}

float Calc::GetVal() const
{
	return m_currVal;
}

float Calc::MemAdd()
{
	m_memorized = m_currVal;
	return m_memorized;
}

float Calc::GetMem() const
{
	return m_memorized;
}

void Calc::Reset()
{
	m_currVal = 0;
}

void Calc::MemReset()
{
	m_memorized = 0;
}
