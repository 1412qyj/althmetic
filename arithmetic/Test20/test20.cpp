#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/20MoveZeroes.h"
#include <sstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace Test20
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test20)
		{
			// TODO:  在此输入测试代码
			LPSTR str_in = new char[MAX_PATH];
			LPSTR str_out = new char[MAX_PATH];

			GetPrivateProfileStringA("test20", "Input", "", str_in, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test20", "Output", "", str_out, MAX_PATH, INI_PATH);

			stringstream sstr_in(str_in);
			stringstream sstr_out(str_out);

			vector<int> vec_in;
			vector<int> vec_out;
			int tmp = 0;

			while (sstr_in >> tmp)
			{
				vec_in.push_back(tmp);
			}

			while (sstr_out >> tmp)
			{
				vec_out.push_back(tmp);
			}

			MoveZeroes(vec_in);

			bool b_result;

			if (vec_in == vec_out)
				b_result = true;

			Assert::IsTrue(b_result);

			vec_in.clear();
			vec_out.clear();

			MoveZeroes(vec_in);

			if (vec_in == vec_out)
				b_result = true;
			else
				b_result = false;

			Assert::IsTrue(b_result);
		}

	};
}