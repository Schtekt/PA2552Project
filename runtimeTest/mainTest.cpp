#include <gtest/gtest.h>
#include <Calc.h>

TEST(CalcTest, CalcInitZero)
{
	Calc calc;
	EXPECT_EQ(0, calc.GetVal());
}

TEST(CalcTest, CalcAddition)
{
	Calc calc;
	calc.Addition(2,3);
	EXPECT_EQ(5, calc.GetVal());
}

TEST(CalcTest, CalcSubtration)
{
	Calc calc;
	calc.Subtraction(10, 6);
	EXPECT_EQ(4, calc.GetVal());
}

TEST(CalcTest, CalcMultiplication)
{
	Calc calc;
	calc.Multiplication(5, 3);
	EXPECT_EQ(15, calc.GetVal());
}

TEST(CalcTest, CalcDivision)
{
	Calc calc;
	calc.Division(8, 2);
	EXPECT_EQ(4, calc.GetVal());
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}