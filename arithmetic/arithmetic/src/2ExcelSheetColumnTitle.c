#include "../include/2ExcelSheetColumnTitle.h"

DLL_EXPORT char * ExcelSheetColumnTitle(int n)
{
	int numA = 0;
	int numLast = 0;
	int i = 0;

	char *p_ret = NULL;

	numA = n / 26;

	numLast = n % 26;

	p_ret = (char *)malloc(numA + 1 + 1);
	if (p_ret == NULL)
		return NULL;

	while (i < numA)
	{
		p_ret[i] = 'A';
		i++;
	}

	p_ret[i++] = 'A' + numLast - 1;

	p_ret[i] = '\0';

	return p_ret;
}