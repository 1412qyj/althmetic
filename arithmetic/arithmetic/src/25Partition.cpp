#include "../include/25Partition.h"

void CreateList(struct ListNode* L, vector<int> nums)
{
	int i = 0;
	for (i = 0; i < nums.size(); i++)
	{
		ListNode *p = (ListNode*)malloc(sizeof(struct ListNode));
		p->val = nums[i];
		p->next = nullptr;
		L->next = p;
		L = L->next;
	}

	return;
}

//我们称第一个大于等于x的节点为基准节点
ListNode* Partition(ListNode* head, int x)
{
#if 1
	auto q = head;
	auto p = head;
	int tmp;

	while (q)
	{
		if (q->val < x)
		{
			tmp = q->val;
			q->val = p->val;
			p->val = tmp;

			p = p->next;
		}

		q = q->next;
	}

	return head;
#else

	ListNode* befor = new ListNode(0);
	ListNode* after = new ListNode(0);
	ListNode* p1 = befor;
	ListNode* p2 = after;
	if (head->next == nullptr)
		return head;
	while (head != nullptr)
	{
		if (head->val < x)
		{
			p1->next = head;
			p1 = p1->next;
			head = head->next;
		}
		else
		{
			p2->next = head;
			p2 = p2->next;
			head = head->next;
		}
	}
	p2->next = nullptr;
	p1->next = after->next;
	return befor->next;
#endif
}