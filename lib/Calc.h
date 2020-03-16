#ifndef CALC_H
#define CALC_H

class Calc
{
private:
	int m_currVal;
public:
	Calc();
	float addition(float valOne, float valTwo);
	float GetVal() const;
};

#endif