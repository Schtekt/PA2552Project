#include <gtest/gtest.h>
#include <Calc.h>

TEST(CalcTest, CalcInitZero)
{
	Calc calc;
	EXPECT_EQ(0, calc.GetVal());
}

TEST(OperandTestSuite, CalcAddition)
{
	Calc calc;
	calc.Addition(2,3);
	EXPECT_EQ(5, calc.GetVal());
}

TEST(OperandTestSuite, CalcSubtration)
{
	Calc calc;
	calc.Subtraction(10, 6);
	EXPECT_EQ(4, calc.GetVal());
}

TEST(OperandTestSuite, CalcMultiplication)
{
	Calc calc;
	calc.Multiplication(5, 3);
	EXPECT_EQ(15, calc.GetVal());
}

TEST(OperandTestSuite, CalcDivision)
{
	Calc calc;
	calc.Division(8, 2);
	EXPECT_EQ(4, calc.GetVal());
}

TEST(MemoryTestSuite, MemorizeAfterAdd)
{
	Calc calc;
	calc.Addition(1, 2);
	EXPECT_EQ(3, calc.MemAdd());
}

TEST(MemoryTestSuite, MemorizeAfterSub)
{
	Calc calc;
	calc.Subtraction(100.5, 50);
	EXPECT_EQ(50.5, calc.MemAdd());
}

TEST(MemoryTestSuite, MemNChanged)
{
	Calc calc;
	float tmp = calc.Multiplication(5, 5);
	calc.MemAdd();
	calc.Multiplication(calc.GetVal(), 6);
	EXPECT_EQ(tmp, calc.GetMem());
}

TEST(MemoryTestSuite, MemChanged)
{
	Calc calc;
	float tmp = calc.Division(5, 5);
	calc.MemAdd();
	calc.Division(calc.GetVal(), 6);
	calc.MemAdd();
	EXPECT_NE(tmp, calc.GetMem());
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}