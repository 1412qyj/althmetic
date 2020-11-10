#include <iostream>
#include <Windows.h>

#define DEBUG

#ifdef DEBUG
#include "../include/12IsValid.h"
#endif

using namespace std;

int main()
{

#ifdef DEBUG
	cout << IsValid("{}]]") << endl;


#endif

	system("pause");
	return 0;
}