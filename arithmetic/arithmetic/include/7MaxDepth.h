#ifndef __CPP_MAX_DEPTH_H
#define __CPP_MAX_DEPTH_H

#include "common.h"



struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#ifdef __cplusplus
extern "C" {
#endif

	int MaxDepth(TreeNode*);
	TreeNode * CreateTree(int *data, int index, int size);
	void printTree(TreeNode *p_tree);

#ifdef __cplusplus
}
#endif


#endif