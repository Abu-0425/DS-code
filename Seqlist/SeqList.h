#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

#pragma warning(disable:4996)

#define ELEM_TYPE int //Ԫ������
#define SEQLIST_DEFAULT_SIZE 8  //˳���Ĭ�ϴ�С


typedef struct SeqList{
	ELEM_TYPE *base;//ָ������ѿռ䣬����Ԫ��
	size_t size;//��ǰԪ�ظ���
	size_t cap;//����
}SeqList_t;

void InitSeqList(SeqList_t *plist);//��ʼ��˳���
void DestorySeqList(SeqList_t *plist);//�ݻ�˳���
void SeqListPrint(SeqList_t *plist);//��ӡ˳���
void SeqListPushBack(SeqList_t *plist, ELEM_TYPE x);//β��
void SeqListPushFront(SeqList_t *plist, ELEM_TYPE x);//ͷ��
void SeqListPopBack(SeqList_t *plist);//βɾ
void SeqListPopFront(SeqList_t *plist);//ͷɾ
int  SeqListFind(SeqList_t *plist, ELEM_TYPE x);//��ֵ����
void SeqListSort(SeqList_t *plist);//����
void SeqListPos_Insert(SeqList_t *plist, size_t pos, ELEM_TYPE x);//��λ�ò���
void SeqListVal_Insert(SeqList_t *plist, ELEM_TYPE x);//��ֵ����
void SeqListPos_Erase(SeqList_t *plist, size_t pos);//��λ��ɾ��
void SeqListVal_Erase(SeqList_t *plist, ELEM_TYPE x);//��ֵɾ��
void SeqListEraseAllVal(SeqList_t *plist, ELEM_TYPE x);//ɾ������ֵΪx������
void SeqListClear(SeqList_t *plist);//���˳���
ELEM_TYPE SeqListGetFront(SeqList_t *plist);//��ȡͷ��Ԫ��
ELEM_TYPE SeqListGetBack(SeqList_t *plist);//��ȡβ��Ԫ��
int  SeqListLength(SeqList_t *plist);//��ȡ����
int  SeqListCapacity(SeqList_t *plist);//��ȡ����
void SeqListReverse(SeqList_t *plist);//˳�������
int SeqListFind_Binary(SeqList_t *plist, ELEM_TYPE x);//���ֲ�������


#endif /*_SEQLIST_H_*/