#include "../include/14SingleNumber.h"

#if 1
int SingleNumber(vector<int>& nums)
{
	unordered_map<int, int> map;

	for(int i = 0; i < nums.size(); i++)
	{
		if (map.find(nums[i]) == map.end())
		{
			map.insert(pair<int, int>(nums[i], 1));
		}
		else
		{
			map.erase(nums[i]);
		}
	}

	return map.begin()->first;
}

#else

int SingleNumber(vector<int>& nums)
{
	if (nums.size() == 1)
		return nums[0];

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