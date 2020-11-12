#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/22Rotate.h"
#include <sstream>
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test22
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test22)
		{
			// TODO:  在此输入测试代码
			LPSTR chp_in = new char[MAX_PATH];
			int i_key = 0;
			LPSTR chp_out = new char[MAX_PATH];

			GetPrivateProfileStringA("test22", "Input", "", chp_in, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test22", "Output", "", chp_out, MAX_PATH, INI_PATH);
			i_key = GetPrivateProfileIntA("test22", "key", 0, INI_PATH);

			stringstream sstr_in;
			stringstream sstr_out;

			sstr_in << chp_in;
			sstr_out << chp_out;

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

			bool result;

			Rotate(vec_in, i_key);

			result = (vec_in == vec_out) ? true : false;

			Assert::IsTrue(result);
		}

	};
}