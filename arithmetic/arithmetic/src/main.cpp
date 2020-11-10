#include <iostream>
#include <Windows.h>

#define DEBUG

#ifdef DEBUG
#include "../include/12IsValid.h"
#include "../include/13MyAtoi.h"
#endif

using namespace std;

int main()
{

#ifdef DEBUG
	//cout << IsValid("{}]]") << endl;
	
	int i = MyAtoi("-91283472332");

	cout << i << endl;


#endif

	system("pause");
	return 0;
}