#include "Calc.h"

Calc::Calc(): m_currVal(0)
{
}

float Calc::addition(float valOne, float valTwo)
{
	m_currVal = valOne + valTwo;
	return m_currVal;
}

float Calc::GetVal() const
{
	return m_currVal;
}
