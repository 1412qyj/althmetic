#include "../include/2ExcelSheetColumnTitle.h"

#if 0
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
#endif


string ExcelSheetColumnTitle(int n)
{
	string ret("");

	if (n > 26)
		ret += ExcelSheetColumnTitle((n-1)/26);

	ret += 'A' + (n - 1) % 26;

	return ret;
}
