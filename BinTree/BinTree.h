#ifndef _BINTREE_H_
#define _BINTREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <windows.h>

#pragma warning(disable:4996)

typedef char BTDataType;//��������Ԫ������

//�������Ľڵ�
typedef struct BinTreeNode{
	BTDataType val; //ֵ��
	struct BinTreeNode *left_tree; //������
	struct BinTreeNode *right_tree; //������
}BinTreeNode;

typedef BinTreeNode* BinTree;

void BinTreeInit(BinTree *t);//��ʼ��������
void BinTreeCreate(BinTree *t);//����������
BinTree BinTreeCreate_2(); //����һ�Ŷ�����
BinTree BinTreeCreate_1(BTDataType *a, int *i);//���������ַ�������
void BinTreeVLR(BinTree t);
void BinTreeLVR(BinTree t);
void BinTreeLRV(BinTree t);
int BinTreeSize(BinTree t);//�ڵ����
BinTreeNode* BinTreeFind(BinTree t, BTDataType data);//����������
void BinTreeDestroy(BinTree *t);//�ݻٶ�����


#endif