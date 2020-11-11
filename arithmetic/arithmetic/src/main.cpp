#include <iostream>
#include <Windows.h>

#define DEBUG

#ifdef DEBUG
#include "../include/15WordPattern.h"
#include "../include/5MinDepth.h"
#include "../include/18PlusOne.h"
#endif

using namespace std;

int main()
{

#ifdef DEBUG
	//int nums[] = {9, 9 ,9};
	//vector<int> vec(nums, nums + sizeof(nums) / sizeof(int));

	//vector<int> vec_ret = PlusOne(vec);

	//for (vector<int>::iterator iter = vec_ret.begin(); iter != vec_ret.end(); iter++)
	//	cout << *iter << endl;

	stringstream sstr("1 2 3");

	vector<int> vec_1, vec_2;

	int tmp;
	while (sstr >> tmp)
	{
		vec_1.push_back(tmp);
	}
	cout << "1  >";
	for (vector<int>::iterator iter = vec_1.begin(); iter != vec_1.end(); iter++)
		cout << *iter << endl;

	stringstream sstr2("1 2 4");

	while (sstr2 >> tmp)
	{
		vec_2.push_back(tmp);
	}
	cout << "2  >";

	for (vector<int>::iterator iter = vec_2.begin(); iter != vec_2.end(); iter++)
		cout << *iter << endl;
	
	if (vec_2 == PlusOne(vec_1))
		cout << "equal" << endl;

#endif

	system("pause");
	return 0;
}