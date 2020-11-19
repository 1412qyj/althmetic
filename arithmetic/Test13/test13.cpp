#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/13MyAtoi.h"
#include <sstream>
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test13
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test13)
		{
			// TODO:  在此输入测试代码
			LPSTR p_input = new char[MAX_PATH];
			LPSTR p_output = new char[MAX_PATH];

			GetPrivateProfileStringA("test13", "Input", "", p_input, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test13", "Output", "", p_output, MAX_PATH, INI_PATH);

			stringstream sstr_in(p_input);
			stringstream sstr_out(p_output);
			
			char ch_nums[200];
			int num;

			while (sstr_in >> ch_nums && sstr_out >> num)
			{
				Assert::AreEqual(num, MyAtoi(ch_nums));
			}

		}

	};
}