#include "../include/1ContainsNearbyDuplicate.h"

bool ContainsNearbyDuplicate(int* nums, int numsSize, int k)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < numsSize; i++)
	{
		for(j = i + k; j < numsSize; j++)
		{
			if (nums[j] == nums[i])
			{
				return true;
			}
		}
		
	}

	return false;
}