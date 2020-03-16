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
	calc.addition(2,3);
	EXPECT_EQ(5, calc.GetVal());
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}