#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

#pragma warning(disable:4996)

#define ELEM_TYPE int //元素类型
#define SEQLIST_DEFAULT_SIZE 8  //顺序表默认大小


typedef struct SeqList{
	ELEM_TYPE *base;//指向申请堆空间，保存元素
	size_t size;//当前元素个数
	size_t cap;//容量
}SeqList_t;

void InitSeqList(SeqList_t *plist);//初始化顺序表
void DestorySeqList(SeqList_t *plist);//摧毁顺序表
void SeqListPrint(SeqList_t *plist);//打印顺序表
void SeqListPushBack(SeqList_t *plist, ELEM_TYPE x);//尾插
void SeqListPushFront(SeqList_t *plist, ELEM_TYPE x);//头插
void SeqListPopBack(SeqList_t *plist);//尾删
void SeqListPopFront(SeqList_t *plist);//头删
int  SeqListFind(SeqList_t *plist, ELEM_TYPE x);//按值查找
void SeqListSort(SeqList_t *plist);//排序
void SeqListPos_Insert(SeqList_t *plist, size_t pos, ELEM_TYPE x);//按位置插入
void SeqListVal_Insert(SeqList_t *plist, ELEM_TYPE x);//按值插入
void SeqListPos_Erase(SeqList_t *plist, size_t pos);//按位置删除
void SeqListVal_Erase(SeqList_t *plist, ELEM_TYPE x);//按值删除
void SeqListEraseAllVal(SeqList_t *plist, ELEM_TYPE x);//删除所有值为x的数据
void SeqListClear(SeqList_t *plist);//清空顺序表
ELEM_TYPE SeqListGetFront(SeqList_t *plist);//获取头部元素
ELEM_TYPE SeqListGetBack(SeqList_t *plist);//获取尾部元素
int  SeqListLength(SeqList_t *plist);//获取长度
int  SeqListCapacity(SeqList_t *plist);//获取容量
void SeqListReverse(SeqList_t *plist);//顺序表逆置
int SeqListFind_Binary(SeqList_t *plist, ELEM_TYPE x);//二分查找数据


#endif /*_SEQLIST_H_*/