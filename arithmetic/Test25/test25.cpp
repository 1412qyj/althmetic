#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/25Partition.h"
#include <sstream>
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test25
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test25)
		{
			// TODO:  在此输入测试代码
			char *pIn = new char[MAX_PATH];
			char *pOut = new char[MAX_PATH];

			GetPrivateProfileStringA("test25", "Input", "", pIn, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test25", "Output", "", pOut, MAX_PATH, INI_PATH);
			int iKey = GetPrivateProfileIntA("test25", "Key", 0, INI_PATH);

			stringstream sstrIn;
			stringstream sstrOut;
			vector<int> vecIn;
			vector<int> vecOut;
			int tmp;

			sstrIn << pIn;
			sstrOut << pOut;

			while (sstrIn >> tmp)
			{
				vecIn.push_back(tmp);
			}
			while (sstrOut >> tmp)
			{
				vecOut.push_back(tmp);
			}

			//创建头节点
			ListNode *pHead = new ListNode(0);//头节点的数字是链表的总长度

			//循环头插， 因为头插数据会反，所以我们将数据反向头插
			vector<int>::reverse_iterator iter;

			for (iter = vecIn.rbegin(); iter != vecIn.rend(); iter++)
			{
				tmp = *iter;
				HeadInsertNode(pHead, *iter);
			}

			ListNode *pRet = Partition(pHead, iKey);

			vector<int> vecRet;

			pHead = pHead->next;
			while (pHead)
			{
				vecRet.push_back(pHead->val);
				pHead = pHead->next;
			}

			bool bResult = (vecRet == vecOut) ? true : false;
			
			Assert::IsTrue(bResult);
		}

	};
}