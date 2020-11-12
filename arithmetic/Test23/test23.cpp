#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/23RestoreIpAddresses.h"
#include <sstream>
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test23
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test23)
		{
			// TODO:  在此输入测试代码

			LPSTR chp_in = new char[MAX_PATH];
			LPSTR chp_out = new char[MAX_PATH];
			stringstream sstr_out;
			string str;
			bool b_result;
			vector<string> vstr_out;
			

			GetPrivateProfileStringA("test23", "Input", "", chp_in, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test23", "Output", "", chp_out, MAX_PATH, INI_PATH);

			

			sstr_out << chp_out;
			

			while (sstr_out >> str)
			{
				vstr_out.push_back(str);
			}

			vector<string> vstr_ret = RestoreIpAddresses(chp_in);

			

			b_result = (vstr_ret == vstr_out) ? true : false;

			Assert::IsTrue(b_result);

			//===========================================================
			GetPrivateProfileStringA("test23", "Input1", "", chp_in, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test23", "Output1", "", chp_out, MAX_PATH, INI_PATH);

			sstr_out << chp_out;


			while (sstr_out >> str)
			{
				vstr_out.push_back(str);
			}

			vstr_ret = RestoreIpAddresses(chp_in);


			set<string> setstr_ret(vstr_ret.begin(), vstr_ret.end());
			set<string> setstr_out(vstr_out.begin(), vstr_out.end());
			b_result = (setstr_out == setstr_out) ? true : false;

			Assert::IsTrue(b_result);
		}

	};
}