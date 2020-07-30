#include "DCList.h"

static DCListNode* BuyDCListNode(ELEM_TYPE x)
{
	DCListNode *node = (DCListNode *)malloc(sizeof(DCListNode));
	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

DCListNode* DCListCreate()
{
	DCListNode *phead = (DCListNode *)malloc(sizeof(DCListNode));
	phead->next = phead->prev = phead;
	return phead;
}

void DCListPushBack(DCList *phead, ELEM_TYPE x)
{
	assert(phead);
	DCListNode *s = BuyDCListNode(x);
	DCListNode *head = *phead;
	s->prev = head->prev;
	s->next = head;
	head->prev->next = s;
	head->prev = s;
}

void DCListPushFront(DCList *phead, ELEM_TYPE x)
{
	assert(phead);
	DCListNode *s = BuyDCListNode(x);
	DCListNode *head = *phead;
	s->prev = head;
	s->next = head->next;
	head->next->prev = s;
	head->next = s;
}

void DCListShow(DCList phead)
{
	DCListNode *p = phead->next;
	while (p != phead){
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

void DCListPopBack(DCList *phead)
{
	assert(phead);
	DCListNode *head = *phead;
	if (head->next == head){//判空
		printf("当前链表为空，无法进行尾部删除!\n");
		return;
	}
	DCListNode *p = head->prev;//指向最后一个节点
	p->prev->next = head;
	head->prev = p->prev;
	free(p);
	printf("尾删成功!\n");
}

void DCListPopFront(DCList *phead)
{
	assert(phead);
	DCListNode *head = *phead;
	if (head->next == head){//判空
		printf("当前链表为空，无法进行头部删除!\n");
		return;
	}
	DCListNode *p = head->next;
	p->next->prev = head;
	head->next = p->next;
	free(p);
	printf("头删成功!\n");
}

DCListNode* DCListFind(DCList phead, ELEM_TYPE x)
{
	assert(phead);
	DCListNode* p = phead->next;
	while (p != phead && p->data != x){
		p = p->next;
	}
	if (p == phead){
		return NULL;
	}
	return p;
}

void DCListInsertByVal(DCList *phead, ELEM_TYPE x)
{
	assert(phead);
	DCListSort(*phead);//按值插入的前提是链表有序
	DCListNode *head = *phead;
	DCListNode *p = head->next;
	while (p != head && x > p->data){
		p = p->next;
	}
	DCListNode *s = BuyDCListNode(x);
	s->next = p;
	s->prev = p->prev;
	s->prev->next = s;
	s->next->prev = s;
	printf("元素插入成功!\n");
}

void DCListEraseByVal(DCList *phead, ELEM_TYPE x)
{
	assert(phead);
	DCListNode *p = DCListFind(*phead, x);
	if (p == NULL){
		printf("该数据不存在!\n");
		return;
	}
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
	printf("数据已成功删除!\n");
}

void DCListSort(DCList phead)
{
	assert(phead);
	if (phead->next == phead && phead->next->next == phead){
		printf("当前链表为空或者只有一个元素，排序无意义!\n");
		return;
	}
	DCListNode *p = phead->next;
	DCListNode *q = p->next;
	p->next = phead;
	phead->prev = p;

	while (q != phead)
	{
		p = q;
		q = q->next;

		DCListNode *tmp = phead->next;
		while (tmp != phead && p->data>tmp->data)
			tmp = tmp->next;
		p->next = tmp;
		p->prev = tmp->prev;
		p->next->prev = p;
		p->prev->next = p;
	}
	printf("排序成功!\n");
}

void DCListClear(DCList *phead)
{
	assert(phead);
	DCListNode *p = (*phead)->next;
	while (p != *phead){
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
		p = (*phead)->next;
	}
}

void DCListDestroy(DCList *phead)
{
	assert(phead);
	DCListClear(phead);
	free(*phead);
	*phead = NULL;
}