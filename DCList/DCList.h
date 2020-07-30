#ifndef _SLIST_H_
#define _SLIST_H_

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <assert.h>


#define ELEM_TYPE int

#pragma warning(disable:4996)

//定义节点
typedef struct DCListNode{
	ELEM_TYPE data;//数据域
	//指针域
	struct DCListNode *next;//后继指针
	struct DCListNode *prev;//前驱指针
}DCListNode;

typedef DCListNode* DCList;

DCListNode* DCListCreate();
void DCListDestroy(DCList *phead);
void DCListPushBack(DCList *phead, ELEM_TYPE x);
void DCListShow(DCList phead);
void DCListPushFront(DCList *phead, ELEM_TYPE x);
void DCListPopBack(DCList *phead);
void DCListPopFront(DCList *phead);
DCListNode* DCListFind(DCList phead, ELEM_TYPE x);
void DCListClear(DCList *phead);
void DCListInsertByVal(DCList *phead, ELEM_TYPE x);
void DCListEraseByVal(DCList *phead, ELEM_TYPE x);
void DCListSort(DCList phead);


#endif /* _SLIST_H_ */