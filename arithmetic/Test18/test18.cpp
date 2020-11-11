#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/18PlusOne.h"
#include <sstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace Test18
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test18)
		{
			// TODO:  在此输入测试代码
			LPSTR p_input = new char[MAX_PATH];
			LPSTR p_output = new char[MAX_PATH];

			GetPrivateProfileStringA("test18", "Input", "", p_input, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test18", "Output", "", p_output, MAX_PATH, INI_PATH);

			stringstream sstr_in;
			stringstream sstr_out;
			bool b_ret;

			sstr_in << p_input;
			sstr_out << p_output;

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
			vector<int> vec_ret = PlusOne(vec_in);
			b_ret = (vec_ret == vec_out) ? true : false;

			Assert::IsTrue(b_ret);

			//====================================================
			GetPrivateProfileStringA("test18", "Input1", "", p_input, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test18", "Output1", "", p_output, MAX_PATH, INI_PATH);

			stringstream sstr_in1;
			stringstream sstr_out1;
			sstr_in1 << p_input;
			sstr_out1 << p_output;

			vec_in.clear();
			vec_out.clear();
			vec_ret.clear();
			while (sstr_in1 >> tmp)
			{
				vec_in.push_back(tmp);
			}

			while (sstr_out1 >> tmp)
			{
				vec_out.push_back(tmp);
			}
			
			vec_ret = PlusOne(vec_in);
			b_ret = (vec_ret == vec_out) ? true : false;

			Assert::IsTrue(b_ret);

			//=================================================
			GetPrivateProfileStringA("test18", "Input2", "", p_input, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test18", "Output2", "", p_output, MAX_PATH, INI_PATH);

			stringstream sstr_in2;
			stringstream sstr_out2;
			sstr_in2 << p_input;
			sstr_out2 << p_output;

			vec_in.clear();
			vec_out.clear();
			vec_ret.clear();
			while (sstr_in2 >> tmp)
			{
				vec_in.push_back(tmp);
			}

			while (sstr_out2 >> tmp)
			{
				vec_out.push_back(tmp);
			}
			
			vec_ret = PlusOne(vec_in);
			b_ret = (vec_ret == vec_out) ? true : false;

			Assert::IsTrue(b_ret);
		}

	};
}