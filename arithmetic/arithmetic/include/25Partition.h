#ifndef __PARTITION_H
#define __PARTITION_H
#include "common.h"

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void CreateList(struct ListNode*, vector<int>);
ListNode* Partition(ListNode* head, int x);
#endif