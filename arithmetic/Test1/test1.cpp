#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/1ContainsNearbyDuplicate.h"
#include <cstring>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test1)
		{
			// TODO:  ÔÚ´ËÊäÈë²âÊÔ´úÂë

			//³É¹¦²âÊÔ
			LPSTR p_array = new char[MAX_PATH];
			LPSTR p_key = new char[MAX_PATH];
			LPSTR p_output = new char[MAX_PATH];
			int p_nums[MAX_PATH];
			string str;
			char tmp[10];
			int i = 0;
			int cout = 0;
			bool result;

			GetPrivateProfileStringA("test1", "Array", "", p_array, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test1", "Key", "", p_key, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test1", "Output", "", p_output, MAX_PATH, INI_PATH);

			
			istringstream sstr(p_array);

			//char *nums-> int* nums
			//get nums in Array
			
			while (sstr >> tmp)
			{
				p_nums[i] = atoi(tmp);
				cout++;
				i++;
			}

			result = (strncmp(p_output, "true", 4) == 0) ? true : false;

			Assert::AreEqual(result, ContainsNearbyDuplicate(p_nums, cout, atoi(p_key)));



			//Ê§°Ü²âÊÔ
			LPSTR p_array1 = new char[MAX_PATH];
			LPSTR p_key1 = new char[MAX_PATH];
			LPSTR p_output1 = new char[MAX_PATH];

			GetPrivateProfileStringA("test1", "Array1", "", p_array1, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test1", "Key1", "", p_key1, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test1", "Output1", "", p_output1, MAX_PATH, INI_PATH);

			stringstream sstr1(p_array1);
			memset(p_nums, 0, sizeof(int) * MAX_PATH);
			i = 0;
			cout = 0;
			while (sstr1 >> tmp)
			{
				p_nums[i] = atoi(tmp);
				cout++;
				i++;
			}


			result = (strncmp(p_output1, "true", 4) == 0) ? true : false;
			Assert::AreEqual(result, ContainsNearbyDuplicate(p_nums, cout, atoi(p_key1)));
		}
	};
}