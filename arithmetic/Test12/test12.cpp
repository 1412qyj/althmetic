#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/12IsValid.h"
#include <sstream>
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test12
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test12)
		{
			// TODO:  在此输入测试代码
			LPSTR p_input = new char[MAX_PATH];
			LPSTR p_output = new char[MAX_PATH];

			GetPrivateProfileStringA("test12", "Input", "", p_input, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test12", "Output", "", p_output, MAX_PATH, INI_PATH);

			stringstream sstr_input(p_input);
			stringstream sstr_output(p_output);

			char p_flag[6];
			char p_symbols[MAX_PATH];
			bool b_flag = false;

			while (sstr_input)
			{
				sstr_input >> p_symbols;
				sstr_output >> p_flag;

				b_flag = (!strncmp(p_flag, "true", 4)) ? true : false;

				Assert::AreEqual(b_flag, IsValid(p_symbols));

				memset(p_symbols, 0, MAX_PATH);
				memset(p_flag, 0, 6);
			}

		}

	};
}