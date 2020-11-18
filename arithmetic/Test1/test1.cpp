#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/1ContainsNearbyDuplicate.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test1)
		{
			// TODO:  ‘⁄¥À ‰»Î≤‚ ‘¥˙¬Î

			//≥…π¶≤‚ ‘
			LPSTR p_array = new char[MAX_PATH];
			int i_key = 0;
			LPSTR p_output = new char[MAX_PATH];
			
			GetPrivateProfileStringA("test1", "Array", "", p_array, MAX_PATH, INI_PATH);
			i_key = GetPrivateProfileIntA("test1", "Key", 0, INI_PATH);
			GetPrivateProfileStringA("test1", "Output", "", p_output, MAX_PATH, INI_PATH);

			vector<int> nums;

			stringstream sstr;
			int tmp;

			sstr << p_array;

			while (sstr >> tmp)
			{
				nums.push_back(tmp);
			}

			bool result;

			result = !strncmp(p_output, "true", 4) ? true : false;

			if (result)
			{
				Assert::IsTrue(ContainsNearbyDuplicate(nums, i_key));
			}
			else
			{
				Assert::IsFalse(ContainsNearbyDuplicate(nums, i_key));
			}

			// ß∞‹≤‚ ‘
			GetPrivateProfileStringA("test1", "Array1", "", p_array, MAX_PATH, INI_PATH);
			i_key = GetPrivateProfileIntA("test1", "Key1", 0, INI_PATH);
			GetPrivateProfileStringA("test1", "Output1", "", p_output, MAX_PATH, INI_PATH);

			sstr.clear();
			nums.clear();

			sstr << p_array;

			while (sstr >> tmp)
			{
				nums.push_back(tmp);
			}

			result = !strncmp(p_output, "true", 4) ? true : false;

			if (result)
			{
				Assert::IsTrue(ContainsNearbyDuplicate(nums, i_key));
			}
			else
			{
				Assert::IsFalse(ContainsNearbyDuplicate(nums, i_key));
			}
		}
	};
}