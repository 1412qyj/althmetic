#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/24LengthOfLongestSubstring.h"
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test24
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test24)
		{
			// TODO:  在此输入测试代码
			char *pIn = new char[MAX_PATH];
			int iOut = 0;

			GetPrivateProfileStringA("test24", "Input", "", pIn, MAX_PATH, INI_PATH);
			iOut = GetPrivateProfileIntA("test24", "Output", 0, INI_PATH);

			Assert::AreEqual(iOut, LengthOfLongestSubstring(pIn));
		}

	};
}