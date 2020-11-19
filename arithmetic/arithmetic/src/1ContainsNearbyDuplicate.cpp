#include "../include/1ContainsNearbyDuplicate.h"

#if 1

bool ContainsNearbyDuplicate(vector<int>& nums, int k)
{
	unordered_map<int, int> hashmap;//键是数组的数，值是数组的下标

	for (int i = 0; i < nums.size(); i++)
	{ 
		if (hashmap.count(nums[i]) == 0)//如果找不到这个数，说明是第一次碰到这个数
		{
			hashmap.insert(pair<int, int>(nums[i], i));
		}
		else //找到相同的数
		{
			if (i - hashmap[nums[i]] > k)//说明不满足，更新nums[i]键的值
			{
				hashmap[nums[i]] = i;
			}
			else
			{
				return true;
			}
		}

	}
	
	return false;
}

#else

bool ContainsNearbyDuplicate(int* nums, int numsSize, int k)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < numsSize; i++)
	{
		for(j = i+1; j <= MIN(numsSize-1, i+k); j++)
		{
			if (nums[j] == nums[i])
			{
				return true;
			}
		}
		
	}

	return false;
}

#endif