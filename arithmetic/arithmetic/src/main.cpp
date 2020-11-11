#include <iostream>
#include <Windows.h>

#define DEBUG

#ifdef DEBUG
#include "../include/15WordPattern.h"
#include "../include/5MinDepth.h"
#endif

using namespace std;

int main()
{

#ifdef DEBUG

	int nums[] = { 3 ,9 ,20 ,-1 ,-1 ,15 ,7 };
	int nums1[] = { 1 ,2 ,4 ,-1 ,3 ,5 ,-1 , -1, -1, -1, -1};
	TreeNode *p_tree = CreateTree(nums, 0 , sizeof(nums)/sizeof(int));
	TreeNode *p_tree1 = CreateTree(nums1, 0, sizeof(nums1) / sizeof(int));
	cout << MinDepth(p_tree) << endl;
	cout << MinDepth(p_tree1) << endl;
#endif

	system("pause");
	return 0;
}