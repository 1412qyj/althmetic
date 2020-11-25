#include "../include/19MySqrt.h"

//¶þ·Ö·¨
int MySqrt(int x)
{
	if (x == 0 || x == 1)
		return x;
	int l = 0;
	int r = x;
	int mid = 0;
	int ret = 0;

	while (l <= r)
	{
		mid = l + (r - l) / 2;

		if (mid <= x / mid)
		{
			l = mid + 1;

			ret = mid;
		}
		else
		{
			r = mid - 1;
		}
	}

	return ret;
}



