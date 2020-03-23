#include "Calc.h"

Calc::Calc(): m_currVal(0)
{
}

float Calc::Addition(float var[])
{
	m_currVal = var[0] + var[1];
	return m_currVal;
}

float Calc::Power(float var[])
{
	return 0.0f;
}

float Calc::Subtraction(float var[])
{
	m_currVal = var[0] - var[1];
	return m_currVal;
}

float Calc::Multiplication(float var[])
{
	m_currVal = var[0] * var[1];
	return m_currVal;
}

float Calc::Division(float var[])
{
	m_currVal = var[0] / var[1];
	return m_currVal;
}

float Calc::Factorial(float var[])
{
	float totalVal = 1;
	for (int i = 1; i <= var[0]; i++)
	{
		totalVal = totalVal * i;
	}
	m_currVal = totalVal;
	return m_currVal;
}

float Calc::Modulus(float var[])
{
	int result = ((int)var[1] + ((int)var[0] % (int)var[1])) % (int)var[1];
	m_currVal = result;
	return m_currVal;
}

float Calc::Negative(float var[])
{
	m_currVal = -var[0];
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
