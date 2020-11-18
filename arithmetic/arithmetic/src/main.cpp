#include <iostream>
#include <Windows.h>
#include "../include/common.h"
#define DEBUG

#ifdef DEBUG
#include "../include/17WordBreak.h"
#include "../include/21Reverse.h"
#include "../include/1ContainsNearbyDuplicate.h"
#include "../include/9AddBinary.h"
#endif

using namespace std;



int main()
{

#ifdef DEBUG
	string s1("11");
	string s2("100");


	cout << AddBinary(s1, s2) << endl;
#endif

	system("pause");
	return 0;
}