#ifndef __COMMON_H
#define __COMMON_H

//c
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <math.h>
#include <stdint.h>


//c++
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <limits.h>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//define
#define INI_PATH "..\\arithmetic\\config\\config.ini"


struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#ifdef __cplusplus
extern "C"
{
#endif
	//common func
	char * GetLanguage();
	char * GetAuthor();
	TreeNode * CreateTree(int *data, int index, int size);
#ifdef __cplusplus
}
#endif

#endif