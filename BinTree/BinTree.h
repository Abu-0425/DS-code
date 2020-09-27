#ifndef _BINTREE_H_
#define _BINTREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <windows.h>

#pragma warning(disable:4996)

typedef char BTDataType;//二叉树的元素类型

//二叉树的节点
typedef struct BinTreeNode{
	BTDataType val; //值域
	struct BinTreeNode *left_tree; //左子树
	struct BinTreeNode *right_tree; //右子树
}BinTreeNode;

typedef BinTreeNode* BinTree;

void BinTreeInit(BinTree *t);//初始化二叉树
BinTree BinTreeCreate(BTDataType *a, int *i);//二叉树的字符串创建
void BinTreeDestroy(BinTree *t);//摧毁二叉树
int BinTreeSize(BinTree t);//节点个数
BinTreeNode* BinTreeFind(BinTree t, BTDataType data);//二叉树查找



#endif