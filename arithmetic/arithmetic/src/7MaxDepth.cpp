#include "../include/7MaxDepth.h"

int MaxDepth(TreeNode* root)
{
	if (root == nullptr)
		return 0;

	int maxl = 0;
	int maxr = 0;


	if (root->left != nullptr)
	{
		maxl = MaxDepth(root->left);
	}

	if (root->right != nullptr)
	{
		maxr = MaxDepth(root->right);
	}

	return (maxl > maxr) ? (maxl+1) : (maxr+1);
}



