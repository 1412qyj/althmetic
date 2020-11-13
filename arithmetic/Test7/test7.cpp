#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test7
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test7)
		{
			// TODO:  在此输入测试代码
			LPSTR p_input = new char[MAX_PATH];

			GetPrivateProfileStringA("test7", "Input", "", p_input, MAX_PATH, INI_PATH);
			int ioutput = GetPrivateProfileIntA("test7", "Output", 0, INI_PATH);

			stringstream sstr;

			sstr << p_input;
			int inums[MAX_PATH];
			int size = 0;
			char tmp[10];

			while (sstr >> tmp)
			{
				if (!strncmp(tmp, "null", 4))
				{
					inums[size] = -1;
				}
				else
				{
					inums[size] = atoi(tmp);
				}

				size++;
			}

			//创建二叉树
			TreeNode *p_tree = CreateTree7(inums, 0, size);

			Assert::AreEqual(ioutput, MaxDepth(p_tree));

		}

	};
}