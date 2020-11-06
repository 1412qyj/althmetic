#include "../include/3IsUgly.h"

bool IsUgly(int num)
{
	if (num == 2 || num == 3 || num == 5)
	{
		return true;
	}

	bool flag = false;

	for (int i = 2; i <= num / 2; i++)
	{
		if (num % i == 0)
		{
			if (IsUgly(i))
			{
				flag = true;
				continue;
			}
			else
			{
				return false;
			}
		}
	}

	return flag;
}