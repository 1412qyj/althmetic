#include "../include/2ExcelSheetColumnTitle.h"

string ExcelSheetColumnTitle(int n)
{
	string strRet("");
	int tmp = 0;

	while (n)
	{
		if (n == 0)
			break;

		tmp = n % 26;
		n = n / 26;

		if (tmp)
		{
			strRet = string(1, 'A'+tmp-1) + strRet;
		}
		else
		{
			strRet = "Z" + strRet;
			n--;
		}
	}

	return strRet;
}

