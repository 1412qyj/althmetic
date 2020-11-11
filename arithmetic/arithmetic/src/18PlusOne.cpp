#include "../include/18PlusOne.h"

vector<int> PlusOne(vector<int>& digits)
{
	bool carry = false;
	
	digits[digits.size() - 1] += 1;

	if (digits[digits.size() - 1] > 9)
	{
		digits[digits.size() - 1] -= 10;
		carry = true;
	}

	for (int i = digits.size() - 2; i >= 0; i--)
	{
		if (carry == false)
			break;

		digits[i] += carry;

		if (digits[i] > 9)
		{
			digits[i] -= 10;
			carry = true;
		}
		else
		{
			carry = false;
		}
	}

	if (carry)
	{
		digits.insert(digits.begin(), 1);
	}

	return digits;
}