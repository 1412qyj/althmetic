#include "../include/5MinDepth.h"

int MinDepth(TreeNode* root)
{
	int ret = 0;

	if (!root)return 0;
	if (!root->left && !root->right) return 1;
	else if (!root->left && root->right) return MinDepth(root->right) + 1;
	else if (root->left && !root->right) return MinDepth(root->left) + 1;
	else return min(MinDepth(root->left) + 1, MinDepth(root->right) + 1);

	return ret;
}



#ifdef PRINT
void prinTree(TreeNode *p_tree)
{
	if (p_tree != nullptr)
	{
		cout << p_tree->val << endl;

		prinTree(p_tree->left);

		prinTree(p_tree->right);
	}
}

#endif