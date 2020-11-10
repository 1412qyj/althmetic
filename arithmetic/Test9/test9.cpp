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
			LPSTR p_output_1 = new char[TEST_SIZE];
			LPSTR p_input_3 = new char[TEST_SIZE];
			LPSTR p_input_4 = new char[TEST_SIZE];
			LPSTR p_output_2 = new char[TEST_SIZE];

			GetPrivateProfileStringA("test9", "Input1", "", p_input_1, TEST_SIZE, INI_PATH);
			GetPrivateProfileStringA("test9", "Input2", "", p_input_2, TEST_SIZE, INI_PATH);
			GetPrivateProfileStringA("test9", "Output1", "", p_output_1, TEST_SIZE, INI_PATH);
			GetPrivateProfileStringA("test9", "Input3", "", p_input_3, TEST_SIZE, INI_PATH);
			GetPrivateProfileStringA("test9", "Input4", "", p_input_4, TEST_SIZE, INI_PATH);
			GetPrivateProfileStringA("test9", "Output2", "", p_output_2, TEST_SIZE, INI_PATH);

			string str_output_1(p_output_1);
			string str_output_2(p_output_2);

			Assert::AreEqual(str_output_1, AddBinary(p_input_1, p_input_2));
			Assert::AreEqual(str_output_2, AddBinary(p_input_3, p_input_4));
		}

	};
}