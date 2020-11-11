#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/16ReverseBits.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace Test16
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test16)
		{
			// TODO:  在此输入测试代码
			uint32_t ui32_input = GetPrivateProfileIntA("test16", "Input", 0, INI_PATH);
			uint32_t ui32_output = GetPrivateProfileIntA("test16", "Output", 0, INI_PATH);
			
			Assert::AreEqual(ui32_output, ReverseBits(ui32_input));
		}

	};
}