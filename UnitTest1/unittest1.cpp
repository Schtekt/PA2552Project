#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Project/Shape.h"
#include "../Project/Shape.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestingSpace
{		
	TEST_CLASS(Week_1)
	{
	public:
		
		TEST_METHOD(AreaTest)
		{
			// TODO: Your test code here
			Shape tmp(5);
			Assert::AreEqual(5, tmp.GetArea());
		}

	};
}