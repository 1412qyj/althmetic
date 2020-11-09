#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/5MinDepth.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test5
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO:  在此输入测试代码
			LPSTR p_input = new char[MAX_PATH];

			GetPrivateProfileStringA("test5", "Input", "", p_input, MAX_PATH, INI_PATH);

			int ioutput = GetPrivateProfileIntA("test5", "Output", 0, INI_PATH);

			stringstream sstr(p_input);

			int inums[MAX_PATH];
			char tmp[10];
			int i = 0;

			while (sstr >> tmp)
			{
				if (!strncmp(tmp, "null", 4))
				{
					inums[i] = -1;
				}

				inums[i] = atoi(tmp);

				i++;
			}

			TreeNode *p_tree = CreateTree(inums, 0, i);

			Assert::AreEqual(ioutput, MinDepth(p_tree));
		}

	};
}