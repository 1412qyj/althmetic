#include "../include/20MoveZeroes.h"

void MoveZeroes(vector<int>& nums)
{
	int pos = 0;
	int count = 0;
	vector<int>::iterator iter;

	while ((iter = find(nums.begin()+pos, nums.end(), 0)) != nums.end())
	{
		nums.erase(iter);

		count++;

		pos++;
	}

	while (count--)
		nums.push_back(0);
}