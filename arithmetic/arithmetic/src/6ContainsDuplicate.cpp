#include "../include/6ContainsDuplicate.h"

bool ContainsDuplicate(vector<int>& nums)
{
	set<int> set_nums(nums.begin(), nums.end());

	if (nums.size() != set_nums.size())
		return true;
	
	return false;
}