#include "../include/14SingleNumber.h"

#if 0
int SingleNumber(vector<int>& nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		if(find(nums.begin()+i+1, nums.end(), nums[i]) == nums.end())
			return nums[i];
	}

	return INT_MAX;
}

#else

int SingleNumber(vector<int>& nums)
{
	sort(nums.begin(), nums.end());

	//判断首尾的值
	if (nums[0] != nums[1])
		return nums[0];

	if (nums[nums.size() - 1] != nums[nums.size() - 2])
		return nums[nums.size() - 1];

	//判断剩下的值
	for (int i = 1; i < nums.size() - 1; i++)
	{
		if ((nums[i] != nums[i - 1]) && (nums[i] != nums[i + 1]))
			return nums[i];
	}

	return INT_MAX;
}

#endif