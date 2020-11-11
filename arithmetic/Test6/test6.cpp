#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/6ContainsDuplicate.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test6
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test6)
		{
			// TODO:  在此输入测试代码
			LPSTR p_input = new char[MAX_PATH];
			LPSTR p_output = new char[6];

			GetPrivateProfileStringA("test6", "Input", "", p_input, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test6", "Output", "", p_output, 6, INI_PATH);

			stringstream sstr;
			int inums[MAX_PATH];
			char tmp[10];
			int size = 0;
			int i = 0;
			
			sstr << p_input;

			while (sstr >> tmp)
			{
				inums[i++] = atoi(tmp);
				size++;
			}

			vector<int> ivector_input;

			for (i = 0; i < size; i++)
			{
				ivector_input.push_back(inums[i]);
			}

			bool boutput = (strncmp("true", p_output, 4) == 0) ? true : false;

			Assert::AreEqual(boutput, ContainsDuplicate(ivector_input));

			//===================================================================
			GetPrivateProfileStringA("test6", "Input1", "", p_input, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test6", "Output1", "", p_output, 6, INI_PATH);

			stringstream sstr1(p_input);

			memset(inums, 0, sizeof(int) * MAX_PATH);
			i = 0;
			size = 0;
			while (sstr1 >> tmp)
			{
				inums[i++] = atoi(tmp);
				size++;
			}

			ivector_input.clear();

			for (i = 0; i < size; i++)
			{
				ivector_input.push_back(inums[i]);
			}

			boutput = (strncmp("true", p_output, 4) == 0) ? true : false;

			Assert::AreEqual(boutput, ContainsDuplicate(ivector_input));
		}

	};
}