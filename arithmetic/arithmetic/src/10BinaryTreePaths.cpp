#include "../include/10BinaryTreePaths.h"

#if 0

#else
vector<string> BinaryTreePaths(TreeNode* root)
{
	vector<string> vec_paths;
	vector<string> vec_l, vec_r;
	string node = "";
	char val[12] = {'\0'};
	sprintf(val, "%d", root->val);
	node += val;

	int size = node.size();
	vector<string>::iterator iter;


	if (root->left == nullptr && root->right == nullptr)
	{
		vec_paths.push_back(node);
		return vec_paths;
	}

	if (root->left != nullptr)
	{
		vec_l = BinaryTreePaths(root->left);
		node += "->";

		for (iter = vec_l.begin(); iter != vec_l.end(); iter++)
		{
			vec_paths.push_back(node+*iter);
		}
	}

	if (root->right != nullptr)
	{
		vec_r = BinaryTreePaths(root->right);
		if (node.size() == size)
			node += "->";


		for (iter = vec_r.begin(); iter != vec_r.end(); iter++)
		{
			vec_paths.push_back(node + *iter);
		}
	}

	return vec_paths;
}
#endif



