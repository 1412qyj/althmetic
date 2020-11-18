#include "../include/25Partition.h"

void HeadInsertNode(ListNode *pHead, int val)
{
	ListNode *pNode = new ListNode(val);

	if (pHead->next == NULL)
	{
		pHead->next = pNode;
		pHead->val++;
		return;
	}

	pNode->next = pHead->next;
	pHead->next = pNode;

	pHead->val++;

	return;
}


//我们称第一个大于等于x的节点为基准节点
ListNode* Partition(ListNode* head, int x)
{
	ListNode *pMov = NULL;//移动指针
	ListNode *pDel = NULL;//删除节点指针，始终保持在移动指针之前
	ListNode *pMod = NULL;//保存基准节点前一个位置的地址的指针
	ListNode *pTmp = NULL;
	bool flag = true;

	pMov = head->next;
	while (pMov)
	{
		if (flag)
		{
			//此if只位找到基准节点的前一个位置
			if (pMov->val < x)
			{
				//移动指针移动
				pMod = pMov;
				pMov = pMov->next;
				continue;
			}
			else//这个else if只会被执行一次
			{
				flag = false;//当flag置0，这两个判断的任务就结束了
				//此时pMod指向基准节点的前一个位置，pMov在基准节点

				//这里开始使用pDel指针
				pDel = pMov;

				//移动pMov到新的开始
				pMov = pMov->next;
				continue;
			}
		}

		//判断如果小于x，就开始进行前向移动操作
		if (pMov->val < x)
		{
			//step1：取出这个当前的指针
			pTmp = pMov;
			pMov = pTmp->next;

			pTmp->next = NULL;//断开后连接

			pDel->next = pMov;//断开前连接

			//插入到pMob后面
			pTmp->next = pMod->next;
			pMod->next = pTmp;//到这里前向移动就完成了

			//更新pMod
			pMod = pMod->next;

			pTmp = NULL;
			continue;
		}

		pDel = pMov;
		//移动指针移动
		pMov = pMov->next;
	}


	return head;
}