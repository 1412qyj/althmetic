#include "../include/14SingleNumber.h"

int SingleNumber(vector<int>& nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		if( find(nums.begin()+i+1, nums.end(), nums[i]) == nums.end())
			return nums[i];
	}

	return INT_MAX;
}