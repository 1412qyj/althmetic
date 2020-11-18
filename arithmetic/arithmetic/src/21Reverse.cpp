#include "../include/21Reverse.h"

#if 1
int Reverse(int x)
{
	if (x == 0)
		return x;

	long nums = 0L;

	while (x > 0)
	{
		nums = nums*10 + (x % 10);

		x = x / 10;
	}

	if (int(nums) != nums)
		return 0;

	return (int)nums;
}


#else
int Reverse(int x)
{
	stringstream sstr;

	sstr << x;

	string str;

	sstr >> str;
	
	reverse(str.begin(), str.end());

	int ret = atoi(str.c_str());

	return  (ret > INT_MAX || ret < INT_MIN) ? 0 : ret;
}

#endif