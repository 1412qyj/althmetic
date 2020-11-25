#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/17WordBreak.h"
#include <sstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace Test17
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test17)
		{
			// TODO:  在此输入测试代码
			/*test 1*/
			LPSTR p_input1 = new char[MAX_PATH];
			LPSTR p_input2 = new char[MAX_PATH];
			LPSTR p_output = new char[MAX_PATH];

			GetPrivateProfileStringA("test17", "Input1", "", p_input1, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test17", "Input2", "", p_input2, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test17", "Output", "", p_output, MAX_PATH, INI_PATH);

			stringstream sstr;
			bool b_output;

			sstr << p_input2;

			char tmp[10];
			vector<string> vec_input2;

			while (sstr >> tmp)
			{
				vec_input2.push_back(tmp);
			}

			b_output = (strncmp(p_output, "true", 4)) ? false : true;

			Assert::AreEqual(b_output, WordBreak(p_input1, vec_input2));

			
			/*test 2*/
			GetPrivateProfileStringA("test17", "Input3", "", p_input1, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test17", "Input4", "", p_input2, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test17", "Output1", "", p_output, MAX_PATH, INI_PATH);

			sstr.clear();
			sstr << p_input2;
			
			vec_input2.clear();
			while (sstr >> tmp)
			{
				vec_input2.push_back(tmp);
			}

			b_output = (strncmp(p_output, "true", 4)) ? false : true;

			Assert::AreEqual(b_output, WordBreak(p_input1, vec_input2));

			/*test 3*/
			GetPrivateProfileStringA("test17", "Input5", "", p_input1, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test17", "Input6", "", p_input2, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test17", "Output2", "", p_output, MAX_PATH, INI_PATH);

			sstr.clear();
			sstr << p_input2;

			vec_input2.clear();
			while (sstr >> tmp)
			{
				vec_input2.push_back(tmp);
			}

			b_output = (strncmp(p_output, "true", 4)) ? false : true;

			Assert::AreEqual(b_output, WordBreak(p_input1, vec_input2));
#if 0

#endif
		}

	};
}