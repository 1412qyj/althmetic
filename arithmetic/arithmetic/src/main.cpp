#include <iostream>
#include <Windows.h>

#define DEBUG

#ifdef DEBUG
#include "../include/12IsValid.h"
#include "../include/13MyAtoi.h"
#include "../include/14SingleNumber.h"
#endif

using namespace std;

int main()
{

#ifdef DEBUG
	int nums[3] = {2, 2, 1};
	vector<int> vec(nums, nums+3);
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);

	

	cout << SingleNumber(vec) << endl;
	cout << SingleNumber(v) << endl;

#endif

	system("pause");
	return 0;
}