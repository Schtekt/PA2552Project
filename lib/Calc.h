#ifndef CALC_H
#define CALC_H

class Calc
{
private:
	float m_currVal;
	float m_memorized;
public:
	Calc();
	float Negative(float var[]);
	float Modulus(float var[]); //arg[0] mod arg[1]
	float Factorial(float var[]); //!arg[0]
	float Division(float var[]); //arg[0] / arg[1]
	float Multiplication(float var[]); //arg[0] * arg[1]
	float Subtraction(float var[]); //arg[0] - arg[1]
	float Addition(float var[]); //arg[0] + arg[1]
	float GetVal() const;
	float MemAdd();
	float GetMem() const;
	void Reset();
	void MemReset();
	float Sqroot(float val);
};

#endif