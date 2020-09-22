//���ڻ��������зַ��ͻ�������

#ifndef _SLIST_H_
#define _SLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ELEM_TYPE int

typedef struct SListNode{
	ELEM_TYPE data;//������
	struct SListNode *next;//ָ����
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
//����Ϊ����ʵ��
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
	assert(s != NULL);//����ȷ��malloc�ɹ�
	s->data = x;
	s->next = NULL;

	//���ӽڵ�
	SListNode *p = *phead;
	if (p == NULL){
		*phead = s;//������ǵ�һ���ڵ�
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
		//����Ϊ��
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