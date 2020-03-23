#include <gtest/gtest.h>
#include <Calc.h>

TEST(CalcTest, CalcInitZero)
{
	Calc calc;
	EXPECT_EQ(0, calc.GetVal());
}

TEST(CalcTest, CalcReset)
{
	Calc calc;
	calc.Reset();
	EXPECT_EQ(0, calc.GetVal());
}

TEST(OperandTestSuite, CalcAddition)
{
	Calc calc;
	float val[] = {2, 3};
	calc.Addition(val);
	EXPECT_EQ(5, calc.GetVal());
}

TEST(OperandTestSuite, CalcSubtration)
{
	Calc calc;
	float val[] = { 10, 6 };
	calc.Subtraction(val);
	EXPECT_EQ(4, calc.GetVal());
}

TEST(OperandTestSuite, CalcMultiplication)
{
	Calc calc;
	float val[] = { 5, 3 };
	calc.Multiplication(val);
	EXPECT_EQ(15, calc.GetVal());
}

TEST(OperandTestSuite, CalcDivision)
{
	Calc calc;
	float val[] = { 8, 2 };
	calc.Division(val);
	EXPECT_EQ(4, calc.GetVal());
}

TEST(OperandTestSuite, CalcFactorial)
{
	Calc calc;
	float val[] = { 6 };
	calc.Factorial(val);
	EXPECT_EQ(720, calc.GetVal());
}

TEST(OperandTestSuite, CalcModulus)
{
	Calc calc;
	float val[] = { 5, 3 };
	calc.Modulus(val);
	EXPECT_EQ(2, calc.GetVal());
}

TEST(OperandTestSuite, CalcModulusNegative)
{
	Calc calc;
	float val[] = { -8, 5 };
	calc.Modulus(val);
	EXPECT_EQ(2, calc.GetVal());
}

TEST(MemoryTestSuite, MemorizeAfterAdd)
{
	Calc calc;
	float val[] = { 1, 2 };
	calc.Addition(val);
	EXPECT_EQ(3, calc.MemAdd());
}

TEST(MemoryTestSuite, MemorizeAfterSub)
{
	Calc calc;
	float val[] = { 100.5, 50 };
	calc.Subtraction(val);
	EXPECT_EQ(50.5, calc.MemAdd());
}

TEST(MemoryTestSuite, MemNChanged)
{
	Calc calc;
	float val[] = { 5, 5 };
	float tmp = calc.Multiplication(val);
	calc.MemAdd();
	val[0] = calc.GetVal();
	val[1] = 6;
	calc.Multiplication(val);
	EXPECT_EQ(tmp, calc.GetMem());
}

TEST(MemoryTestSuite, MemChanged)
{
	Calc calc;
	float val[] = { 5, 5 };
	float tmp = calc.Division(val);
	calc.MemAdd();
	val[0] = calc.GetVal();
	val[1] = 6;
	calc.Division(val);
	calc.MemAdd();
	EXPECT_NE(tmp, calc.GetMem());
}

TEST(MemoryTestsuite, MemIndependant)
{
	Calc calc;
	float val[] = { 5, 3 };
	float tmp = calc.Addition(val);
	calc.MemAdd();
	calc.Reset();
	EXPECT_EQ(tmp, calc.GetMem());
}

TEST(MemoryResetTestSuite, MemReset)
{
	Calc calc;
	float val[] = { 5, 3 };
	calc.Addition(val);
	calc.MemAdd();
	calc.MemReset();
	EXPECT_EQ(0, calc.GetMem());
}

TEST(NegativeOperandTestSuite, BasicTest)
{
	Calc calc;
	float val[] = { 5 };
	float res = calc.Negative(val);
	EXPECT_EQ(-5, res);
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}