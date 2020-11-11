#include "../include/16ReverseBits.h"

uint32_t ReverseBits(uint32_t n)
{
	uint32_t ret = 0;
	int bit = 31;

	while (n)
	{
		ret += (n & 0x1) << bit;//取出最低位，移到对应位
		bit--;
		n = n >> 1;
	}

	return ret;
}