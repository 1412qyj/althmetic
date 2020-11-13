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
	static TreeNode * CreateTree(int *data, int index, int size);


#ifdef __cplusplus
}
#endif


#endif