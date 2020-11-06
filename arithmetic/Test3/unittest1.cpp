#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/3IsUgly.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test3
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO:  在此输入测试代码
			int input = 0;
			LPSTR p_output = new char[MAX_PATH];
			bool flag;

			input = GetPrivateProfileIntA("test", "input", 6, INI_PATH);
			GetPrivateProfileStringA("test", "output", "", p_output, MAX_PATH, INI_PATH);

			flag = (strncmp(p_output, "true", 4) == 0) ? true : false;

			Assert::AreEqual(flag, IsUgly(input));
		}

	};
}