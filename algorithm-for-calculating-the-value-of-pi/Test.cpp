#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Курсач/Myclass.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Myclass obj;
			Assert::AreEqual(true, obj.IsPointInCircle(1, 0.2, 0.3));// TODO: Разместите здесь код своего теста
		}

		TEST_METHOD(TestMethod2)
		{
			Myclass obj;
			Assert::AreEqual(false, obj.IsPointInCircle(1, 1, 1));// TODO: Разместите здесь код своего теста
		}

		TEST_METHOD(TestMethod3)
		{
			Myclass obj;
			Assert::AreEqual(true, obj.IsPointInCircle(1, 0.6, -0.4));// TODO: Разместите здесь код своего теста
		}
	};
}
