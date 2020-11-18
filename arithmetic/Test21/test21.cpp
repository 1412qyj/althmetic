#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/21Reverse.h"
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test21
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test21)
		{
			// TODO:  在此输入测试代码
			int i_in = 0; 
			int i_out = 0;
			
			
			i_in = GetPrivateProfileIntA("test21", "Input", 0, INI_PATH);
			i_out = GetPrivateProfileIntA("test21", "Output", 0, INI_PATH);

			Assert::AreEqual(i_out, Reverse(i_in));

			
			i_in = GetPrivateProfileIntA("test21", "Input1", 0, INI_PATH);
			i_out = GetPrivateProfileIntA("test21", "Output1", 0, INI_PATH);

			int ret = Reverse(i_in);

			Assert::AreEqual(0, ret);
			
			
			i_in = GetPrivateProfileIntA("test21", "Input2", 0, INI_PATH);
			i_out = GetPrivateProfileIntA("test21", "Output2", 0, INI_PATH);

			Assert::AreEqual(i_out, Reverse(i_in));

			
			i_in = GetPrivateProfileIntA("test21", "Input3", 0, INI_PATH);
			i_out = GetPrivateProfileIntA("test21", "Output3", 0, INI_PATH);

			Assert::AreEqual(i_out, Reverse(i_in));
			
		}

	};
}