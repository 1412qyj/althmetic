#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/14SingleNumber.h"
#include <sstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace Test14
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test14)
		{
			// TODO:  在此输入测试代码

			LPSTR p_input = new char[MAX_PATH];
			GetPrivateProfileStringA("test14", "Input", "", p_input, MAX_PATH, INI_PATH);
			
			int i_output = GetPrivateProfileIntA("test14", "Output", 0, INI_PATH);

			stringstream sstr_input;

			sstr_input << p_input;
			
			int tmp;

			vector<int> vec;

			while (sstr_input >> tmp)
			{
				vec.push_back(tmp);
			}

			Assert::AreEqual(i_output, SingleNumber(vec));

			memset(p_input, 0, MAX_PATH);

			GetPrivateProfileStringA("test14", "Input1", "", p_input, MAX_PATH, INI_PATH);

			i_output = GetPrivateProfileIntA("test14", "Output1", 0, INI_PATH);

			sstr_input.clear();

			sstr_input << p_input;

			vec.clear();

			while (sstr_input >> tmp)
			{
				vec.push_back(tmp);
			}

			Assert::AreEqual(i_output, SingleNumber(vec));


			GetPrivateProfileStringA("test14", "Input2", "", p_input, MAX_PATH, INI_PATH);

			i_output = GetPrivateProfileIntA("test14", "Output2", 0, INI_PATH);

			sstr_input.clear();

			sstr_input << p_input;

			vec.clear();

			while (sstr_input >> tmp)
			{
				vec.push_back(tmp);
			}

			Assert::AreEqual(i_output, SingleNumber(vec));


			//=========================================
			vector<int> vectmp;
			vectmp.push_back(1);

			Assert::AreEqual(vectmp[0], SingleNumber(vectmp));
		}

	};
}