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
			
			int i_output = GetPrivateProfileIntA("test14", "Input", 0, INI_PATH);

			stringstream sstr_input(p_input);

			int tmp;
			vector<int> vec;

			while (sstr_input >> tmp)
			{
				vec.push_back(tmp);
			}


			Assert::AreEqual(i_output, SingleNumber(vec));
		}

	};
}