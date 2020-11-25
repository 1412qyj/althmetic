#include "../include/22Rotate.h"


#if 1

void Rotate(vector<int>& nums, int k)
{
	std::rotate(nums.begin(), nums.end() - k%nums.size(), nums.end());
}

#else
void Rotate(vector<int>& nums, int k)
{
	int tmp = 0;

	for (int i = 0; i < k; i++)
	{
		tmp = nums.back();
		nums.pop_back();
		nums.insert(nums.begin(), tmp);
	}
}	
#endif