#include "../include/5MinDepth.h"

int MinDepth(TreeNode* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	if (root->left == nullptr)
	{
		return 1 + MinDepth(root->right);
	}

	if (root->right == nullptr)
	{
		return 1 + MinDepth(root->left);
	}

	return MIN(MinDepth(root->left), MinDepth(root->right)) + 1;
}