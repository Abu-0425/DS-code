//用于基数排序中分发和回收数据

#ifndef _SLIST_H_
#define _SLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ELEM_TYPE int

typedef struct SListNode{
	ELEM_TYPE data;//数据域
	struct SListNode *next;//指针域
}SListNode;

typedef SListNode* SList;

void SListInit(SList *phead);
bool SListEmpty(SList phead);
void SListPushBack(SList *phead, ELEM_TYPE x);
void SListPopFront(SList *phead);
ELEM_TYPE SListFront(SList phead);
void SListClear(SList *phead);
void SListDestory(SList *phead);

//////////////////////////////////////////////////////////////
//以下为函数实现
void SListInit(SList *phead)
{
	assert(phead);
	*phead = NULL;
}

bool SListEmpty(SList phead)
{
	return phead == NULL;
}

void SListPushBack(SList *phead, ELEM_TYPE x)
{
	assert(phead);
	SListNode *s = (SListNode *)malloc(sizeof(SListNode));
	assert(s != NULL);//必须确保malloc成功
	s->data = x;
	s->next = NULL;

	//链接节点
	SListNode *p = *phead;
	if (p == NULL){
		*phead = s;//插入的是第一个节点
	}
	else{
		while (p->next != NULL){
			p = p->next;
		}
		p->next = s;
	}
}

void SListPopFront(SList *phead)
{
	assert(phead);
	SListNode *p = *phead;
	if (p == NULL){
		//链表为空
		return;
	}
	else{
		*phead = p->next;
		free(p);
	}
}

ELEM_TYPE SListFront(SList phead)
{
	return phead->data;
}


void SListClear(SList *phead)
{
	assert(phead);
	SListNode *p = NULL;
	while (*phead != NULL){
		p = *phead;
		*phead = p->next;
		free(p);
	}
}

void SListDestory(SList *phead)
{
	assert(phead);
	SListClear(phead);
}

#endif /* _SLIST_H_ */