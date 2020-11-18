#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/2ExcelSheetColumnTitle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test2
{		
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(Test2)
		{
			// TODO:  在此输入测试代码
			//测试一
			int input = 0;
			LPSTR p_output = new char[MAX_PATH];
			string strRet;

			input = GetPrivateProfileIntA("test2", "input", 0, INI_PATH);
			GetPrivateProfileStringA("test2", "output", "", p_output, MAX_PATH, INI_PATH);
			strRet = ExcelSheetColumnTitle(input);

			Assert::AreEqual(0, strcmp(strRet.c_str(), p_output));
			

			//测试二
			strRet.clear();
			LPSTR p_output1 = new char[MAX_PATH];

			int input1 = GetPrivateProfileIntA("test2", "Input1", 0, INI_PATH);
			GetPrivateProfileStringA("test2", "Output1", "", p_output1, MAX_PATH, INI_PATH);
			strRet = ExcelSheetColumnTitle(input1);

			Assert::AreEqual(0, strcmp(strRet.c_str(), p_output1));

			//free(p_ret);
		}

	};
}