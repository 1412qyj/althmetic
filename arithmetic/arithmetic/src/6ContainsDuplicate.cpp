#include "../include/6ContainsDuplicate.h"

bool ContainsDuplicate(vector<int>& nums)
{
	return (nums.size() > set<int>(nums.begin(), nums.end()).size());
}