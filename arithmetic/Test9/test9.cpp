#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/9AddBinary.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test9
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test9)
		{
			// TODO:  在此输入测试代码
			LPSTR p_input_1 = new char[TEST_SIZE];
			LPSTR p_input_2 = new char[TEST_SIZE];
			LPSTR p_output = new char[TEST_SIZE];


			GetPrivateProfileStringA("test9", "Input1", "", p_input_1, TEST_SIZE, INI_PATH);
			GetPrivateProfileStringA("test9", "Input2", "", p_input_2, TEST_SIZE, INI_PATH);
			GetPrivateProfileStringA("test9", "Output", "", p_output, TEST_SIZE, INI_PATH);


			stringstream sstr1(p_input_1), sstr2(p_input_2), sstr3(p_output);
			string str1, str2, str3;
			

			while (sstr1 >> str1 && sstr2 >> str2 && sstr3 >> str3)
			{
				Assert::AreEqual(str3, AddBinary(str1, str2));

				str1.clear();
				str2.clear();
				str3.clear();
			}
		}

	};
}