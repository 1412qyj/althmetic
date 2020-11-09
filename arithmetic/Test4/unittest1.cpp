#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/4IsPalindrome.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test4
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO:  在此输入测试代码
			int input = GetPrivateProfileIntA("test", "Input", 0, INI_PATH);

			LPSTR p_output = new char[5];

			GetPrivateProfileStringA("test", "Output", "", p_output, 5, INI_PATH);

			bool flag = (strncmp(p_output, "true", 4) == 0) ? true : false;

			Assert::AreEqual(flag, IsPalindrome(input));


		}

	};
}