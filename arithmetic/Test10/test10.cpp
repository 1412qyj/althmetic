#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/10BinaryTreePaths.h"
#include <sstream>
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test10
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test10)
		{
			// TODO:  在此输入测试代码
			char *pIn = new char[MAX_PATH];
			char *pOut = new char[MAX_PATH];

			GetPrivateProfileStringA("test10", "Input", "", pIn, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test10", "Output", "", pOut, MAX_PATH, INI_PATH);

			stringstream sstrIn;
			stringstream sstrOut;

			sstrIn << pIn;
			sstrOut << pOut;

			int size = 0;
			int nums[MAX_PATH];
			vector<string> vecStrOut;
			string strTmp;

			while (sstrOut >> strTmp)
			{
				vecStrOut.push_back(strTmp);
			}

			while (sstrIn >> strTmp)
			{
				if (!strncmp("null", strTmp.c_str(), 4))
				{
					nums[size] = -1;
				}
				else
				{
					nums[size] = atoi(strTmp.c_str());
				}

				size++;
			}

			TreeNode *pTree = CreateTree(nums, 0, size);

			vector<string> vecRet = BinaryTreePaths(pTree);

			bool bResult = (vecRet == vecStrOut) ? true : false;
			
			Assert::IsTrue(bResult);
		}

	};
}