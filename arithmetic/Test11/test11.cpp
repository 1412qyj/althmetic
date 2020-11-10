#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/11CanWinNim.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test11
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test11)
		{
			// TODO:  在此输入测试代码
			LPSTR p_input = new char[MAX_PATH];
			LPSTR p_output = new char[MAX_PATH];

			GetPrivateProfileStringA("test11", "Input", "", p_input, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test11", "Output", "", p_output, MAX_PATH, INI_PATH);

			stringstream sstr_in(p_input);
			stringstream sstr_out(p_output);

			char flag[10];
			char nums[5];
			bool b_output;

			while (sstr_out)
			{
				sstr_out >> flag;
				sstr_in >> nums;

				b_output = (!strncmp(flag, "true", 4)) ? true : false;

				Assert::AreEqual(b_output, CanWinNim(atoi(nums)));
			}

		}

	};
}