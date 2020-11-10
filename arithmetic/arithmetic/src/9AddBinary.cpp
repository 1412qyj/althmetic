#include "../include/9AddBinary.h"

string AddBinary(string a, string b)
{
	bool carry = false;
	int tmp = 0;

	int diff = a.size() - b.size();

	if (diff > 0)
	{
		b.insert(0, diff, '0');
	}
	else if (diff < 0)
	{
		a.insert(0, -diff, '0');
	}

	int size = a.size();
	

	for (int i = size - 1; i >= 0; i--)
	{
		tmp = a.at(i) + b.at(i) + carry - '0' - '0';

		//判断tmp有没有溢出
		if (tmp > 1)
		{
			carry = true;
			tmp -= 2;
		}
		else
		{
			carry = false;
		}

		a.replace(i, 1, 1, tmp+'0');

	}

	if (carry)
	{
		a.insert(0, 1, '1');
	}

	return a;

}