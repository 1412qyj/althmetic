#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/5MinDepth.h
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test5
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TreeNode * CreateTree(int *data, int index, int size)
		{
			TreeNode *pnode = nullptr;

			if (index < size && data[index] != -1)
			{
				pnode = (TreeNode *)malloc(sizeof(TreeNode));
				if (nullptr == pnode)
				{
					perror("malloc");
					return NULL;
				}

				pnode->val = data[index];
				pnode->left = CreateTree(data, 2 * index + 1, size);
				pnode->right = CreateTree(data, 2 * index + 2, size);
			}

			return nullptr;
		}
		
		TEST_METHOD(Test5)
		{
			// TODO:  在此输入测试代码
			LPSTR p_input = new char[MAX_PATH];
			
			GetPrivateProfileStringA("test", "Input", "", p_input, MAX_PATH, INI_PATH);

			int ioutput = GetPrivateProfileIntA("test", "Output", 0, INI_PATH);

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

			TreeNode *p_tree = NULL;
			//创建一个二叉树
			p_tree = CreateTree(inums, 0, i);

			Assert::AreEqual(ioutput, MinDepth(p_tree));
			

		}

	};
}

