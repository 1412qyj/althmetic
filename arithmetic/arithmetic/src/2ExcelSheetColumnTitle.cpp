#include "../include/2ExcelSheetColumnTitle.h"

#if 0

char * ExcelSheetColumnTitle(int n)
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

#endif

string ExcelSheetColumnTitle(int n)
{
	string strRet;

	while (n > 26)
	{
		strRet += "A";

		n = n - 26;
	}

	strRet.append(1, (( n == 0 )? ('/0'): ('A' + n - 1)));

	return strRet;
}