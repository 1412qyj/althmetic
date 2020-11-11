#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/15WordPattern.h"
#include <sstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Test15
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test15)
		{
			// TODO:  在此输入测试代码
			//正确的测试
			LPSTR p_pattern_1 = new char[MAX_PATH];
			LPSTR p_string_1 = new char[MAX_PATH];
			LPSTR p_result_1 = new char[6];
			
			GetPrivateProfileStringA("test15", "Pattern1", "", p_pattern_1, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test15", "String1", "", p_string_1, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test15", "Result1", "", p_result_1, 6, INI_PATH);

			bool b_result_1 = (!strncmp(p_result_1, "true", 4)) ? true : false;

			Assert::AreEqual(b_result_1, WordPattern(p_pattern_1, p_string_1));

			//测试pattern和string的个数不一致
			LPSTR p_pattern_2 = new char[MAX_PATH];
			LPSTR p_string_2 = new char[MAX_PATH];
			LPSTR p_result_2 = new char[6];
			GetPrivateProfileStringA("test15", "Pattern2", "", p_pattern_2, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test15", "String2", "", p_string_2, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test15", "Result2", "", p_result_2, 6, INI_PATH);

			bool b_result_2 = (!strncmp(p_result_2, "true", 4)) ? true : false;

			Assert::AreEqual(b_result_2, WordPattern(p_pattern_2, p_string_2));

			//测试pattern和string不匹配
			LPSTR p_pattern_3 = new char[MAX_PATH];
			LPSTR p_string_3 = new char[MAX_PATH];
			LPSTR p_result_3 = new char[6];
			GetPrivateProfileStringA("test15", "Pattern3", "", p_pattern_3, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test15", "String3", "", p_string_3, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test15", "Result3", "", p_result_3, 6, INI_PATH);

			bool b_result_3 = (!strncmp(p_result_3, "true", 4)) ? true : false;

			Assert::AreEqual(b_result_3, WordPattern(p_pattern_3, p_string_3));

			LPSTR p_pattern_4 = new char[MAX_PATH];
			LPSTR p_string_4 = new char[MAX_PATH];
			LPSTR p_result_4 = new char[6];
			GetPrivateProfileStringA("test15", "Pattern4", "", p_pattern_4, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test15", "String4", "", p_string_4, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test15", "Result4", "", p_result_4, 6, INI_PATH);

			bool b_result_4 = (!strncmp(p_result_4, "true", 4)) ? true : false;

			Assert::AreEqual(b_result_4, WordPattern(p_pattern_4, p_string_4));

		}

	};
}