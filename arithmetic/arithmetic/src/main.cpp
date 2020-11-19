#include <iostream>
#include <Windows.h>
#include "../include/common.h"
#define DEBUG

#ifdef DEBUG
#include "../include/17WordBreak.h"
#include "../include/21Reverse.h"
#include "../include/1ContainsNearbyDuplicate.h"
#include "../include/9AddBinary.h"
#include "../include/10BinaryTreePaths.h"
#include "../include/14SingleNumber.h"
#endif

using namespace std;

void prinTree(TreeNode *p_tree)
{
	if (p_tree != nullptr)
	{
		cout << p_tree->val << endl;

		prinTree(p_tree->left);

		prinTree(p_tree->right);
	}
}

int main()
{

#ifdef DEBUG
	vector<int> vec;

	vec.push_back(1);

	cout << vec.size() << endl;

	cout << SingleNumber(vec) << endl;

#endif

	system("pause");
	return 0;
}