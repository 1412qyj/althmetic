#include "../include/8HammingWeight.h"

#if 0
int HammingWeight(unsigned int n)
{
	int count = 0;

	while (n>0)
	{
		n = n & (n - 1);
		count++;
	}

	return count;
}
#endif


int HammingWeight(unsigned int n)
{
	int count = 0;

	while (n > 0)
	{
		count += ((n % 2 == 0) ? 0 : 1);

		n = n >> 1;
	}

	return count;
}