#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/8HammingWeight.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test8
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test8)
		{
			// TODO:  在此输入测试代码
			LPSTR p_input = new char[MAX_PATH];
			LPSTR p_output = new char[MAX_PATH];

			GetPrivateProfileStringA("test8", "Input", "", p_input, MAX_PATH, INI_PATH);			GetPrivateProfileStringA("test8", "Input", "", p_input, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test8", "Output", "", p_output, MAX_PATH, INI_PATH);

			stringstream sstr_in(p_input);
			stringstream sstr_out(p_output);
			int iinput[MAX_PATH];
			int ioutput[MAX_PATH];
			char tmp[10];
			int size = 0;

			while (sstr_in >> tmp)
			{
				iinput[size++] = atoi(tmp);
			}

			size = 0;

			while (sstr_out >> tmp)
			{
				ioutput[size++] = atoi(tmp);
			}
			
			for (int i = 0; i < size; i++)
			{
				Assert::AreEqual(ioutput[i], HammingWeight(iinput[i]));
			}

		}

	};
}