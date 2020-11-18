#include "../include/20MoveZeroes.h"

#if 1

void MoveZeroes(vector<int> &nums)
{
	//分割算法，满足第三个arg的数会被移到前面去，且保持原来位置不变
	stable_partition(nums.begin(), nums.end(), [](int num){return num != 0;});
}

#else

//双指针
//只移动非0的数
void MoveZeroes(vector<int>& nums)
{
	if (nums.size() == 0)
		return;

	int tmp;
	int p = 0;//p指针永远指向0元素
	int size = nums.size();

	for(int i = 0; i < size; i++)//p指针没遇到0时和l保持一致，遇到后紧跟这l
	{//i指针用来遍历
		if(nums[i] != 0)
		{
			tmp = nums[i];
			nums[i] = nums[p];
			nums[p++] = tmp;
		}
	}

	return;
}

#endif