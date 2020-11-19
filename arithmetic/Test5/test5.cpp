#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/5MinDepth.h"
#include <cstring>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test5
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test5)
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
					i++;
					continue;
				}

				inums[i] = atoi(tmp);

				i++;
			}

			TreeNode *p_tree = CreateTree(inums, 0, i);

			Assert::AreEqual(ioutput, MinDepth(p_tree));

			//============================================
			free(p_tree);
			p_tree = nullptr;

			GetPrivateProfileStringA("test5", "Input1", "", p_input, MAX_PATH, INI_PATH);

			ioutput = GetPrivateProfileIntA("test5", "Output1", 0, INI_PATH);

			memset(inums, 0, sizeof(int) * MAX_PATH);

			stringstream sstr1(p_input);

			while (sstr1 >> tmp)
			{
				if (!strncmp(tmp, "null", 4))
				{
					inums[i] = -1;
				}

				inums[i] = atoi(tmp);

				i++;
			}

			//p_tree = CreateTree(inums, 0, i);
			int array[] = { 1, 2, 4, -1, 3, 5, -1, -1, -1, -1, -1 };
			p_tree = CreateTree(array, 0, sizeof(array)/ sizeof(int));
			Assert::AreEqual(ioutput, MinDepth(p_tree));

			//================================================

			Assert::AreEqual(0, MinDepth(nullptr));

		}

	};
}