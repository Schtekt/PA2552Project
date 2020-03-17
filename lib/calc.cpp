#include "Calc.h"

Calc::Calc(): m_currVal(0)
{
}

float Calc::Addition(float valOne, float valTwo)
{
	m_currVal = valOne + valTwo;
	return m_currVal;
}

float Calc::Subtraction(float valOne, float valTwo)
{
	return 0.0f;
}

float Calc::Multiplication(float valOne, float valTwo)
{
	return 0.0f;
}

float Calc::Division(float valOne, float valTwo)
{
	return 0.0f;
}

float Calc::GetVal() const
{
	return m_currVal;
}

float Calc::MemAdd()
{
	return 0.0f;
}

float Calc::GetMem() const
{
	return 0.0f;
}

void Calc::Reset()
{
}

void Calc::MemReset()
{
}
