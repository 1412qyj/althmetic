#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/25Partition.h"
#include <sstream>
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define INI_PATH "../arithmetic/config/config_test25.ini"

namespace Test25
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test25)
		{
			// TODO:  在此输入测试代码
			int i = 0;//辅助数
			int ini_key = 0; //ini文件的k
			int val = 0; 
			int j = 0;
			int array[1000];
			bool result = false;
			
			//获取一共有多少个[章节]数
			int ini_Numbers = GetPrivateProfileIntA("config_test25", "number", 0, INI_PATH);

			for (i = 1; i <= ini_Numbers; i++)
			{
				result = false;
				char sectionName[15] = { "Test" }, sectionCount[10], ini_arrays[1024], ini_out[1024];
				itoa(i, sectionCount, 10);
				strcat(sectionName, sectionCount);
				ini_key = GetPrivateProfileIntA(sectionName, "k", 0, INI_PATH);
				GetPrivateProfileStringA(sectionName, "array", "", ini_arrays, sizeof(ini_arrays), INI_PATH);
				char *p_ini_arrays = strtok(ini_arrays, ",");
				while (p_ini_arrays != NULL)
				{
					val = atoi(p_ini_arrays);
					array[j] = val;
					j++;
					p_ini_arrays = strtok(NULL, ",");
				}
				vector<int> nums(array, array + j);
				j = 0;
				struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));  //头结点(不存值)
				head->next = NULL;
				CreateList(head, nums);
				ListNode* head1 = Partition(head, ini_key);
				vector<int> array_act;
				vector<int> array_out;
				head1 = head1->next;
				while (head1 != nullptr)
				{
					array_act.push_back(head1->val);
					head1 = head1->next;
				}
				GetPrivateProfileStringA(sectionName, "output", "", ini_out, sizeof(ini_out), INI_PATH);
				char *p_ini_arrays5 = strtok(ini_out, ",");
				while (p_ini_arrays5 != NULL)
				{
					array_out.push_back(atoi(p_ini_arrays5));
					p_ini_arrays5 = strtok(NULL, ",");
				}
				if (array_out == array_act)
					result = true;
				array_act.clear();
				array_out.clear();
				Assert::IsTrue(result);
			}
		}

	};
}