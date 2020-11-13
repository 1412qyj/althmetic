#include "../include/10BinaryTreePaths.h"

vector<string> BinaryTreePaths(TreeNode* root)
{
	vector<string> vec_paths;
	vector<string> vec_l, vec_r;
	string node = "";
	stringstream sstr;
	sstr << root->val;
	node += sstr.str();
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


TreeNode * CreateTree(int *data, int index, int size)
{
	TreeNode *pnode = nullptr;

	if (index >= size || data[index] == -1)
		return nullptr;

	else
	{
		pnode = (TreeNode *)malloc(sizeof(TreeNode));

		pnode->val = data[index];
		pnode->left = CreateTree(data, 2 * index + 1, size);
		pnode->right = CreateTree(data, 2 * index + 2, size);
	}

	return pnode;
}

