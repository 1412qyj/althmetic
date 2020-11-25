#include "../include/3IsUgly.h"

#if 0

bool IsUgly(int num)
{
	if (num == 1)
		return true;

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


#endif
bool IsUgly(int num)
{
	if (num == 0)
		return false;

	bool ret = true;
	while (ret && num != 1)
	{
		ret = false;
		if (num % 2 == 0)
		{
			num = num / 2;
			ret = true;
		}
		else if (num % 3 == 0)
		{
			num = num / 3;
			ret = true;
		}
		else if (num % 5 == 0)
		{
			num = num / 5;
			ret = true;
		}
	}

	return (num == 1) ? true : false;
}
