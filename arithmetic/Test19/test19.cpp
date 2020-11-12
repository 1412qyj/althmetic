#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/19MySqrt.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace Test19
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test19)
		{
			// TODO:  在此输入测试代码
			int i_in = 0;
			int i_out = 0;

			i_in = GetPrivateProfileIntA("test19", "Input", 0, INI_PATH);
			i_out = GetPrivateProfileIntA("test19", "Output", 0, INI_PATH);

			Assert::AreEqual(i_out, MySqrt(i_in));

			i_in = GetPrivateProfileIntA("test19", "Input1", 0, INI_PATH);
			i_out = GetPrivateProfileIntA("test19", "Output1", 0, INI_PATH);

			Assert::AreEqual(i_out, MySqrt(i_in));
		}

	};
}