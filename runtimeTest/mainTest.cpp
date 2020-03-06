#include <gtest/gtest.h>
#include <Calc.h>

TEST(CalcTest, CalcInitZero)
{
	Calc calc;
	EXPECT_EQ(0, calc.GetVal());
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}