#include "../include/22Rotate.h"

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