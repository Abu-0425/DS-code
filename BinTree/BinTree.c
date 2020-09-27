#include "BinTree.h"

void BinTreeInit(BinTree *t)//初始化二叉树
{
	*t = NULL;
}

BinTree BinTreeCreate(BTDataType *a, int *i)//二叉树的字符串创建
{
	if (a[*i] == '#' || a[*i] == '\0'){
		return NULL;
	}
	BinTreeNode *t = (BinTreeNode *)malloc(sizeof(BinTreeNode));//申请节点
	assert(t != NULL);

	t->val = a[*i];
	(*i)++;

	t->left_tree = BinTreeCreate(a, i);//递归创建左树
	(*i)++;
	t->right_tree = BinTreeCreate(a, i);//递归创建右树

	return t;//返回创建好的二叉树
}

int BinTreeSize(BinTree t)//节点个数
{
	if (t == NULL){
		return 0;
	}
	return 1 + BinTreeSize(t->left_tree) + BinTreeSize(t->right_tree);
}

BinTreeNode* BinTreeFind(BinTree t, BTDataType data)//二叉树查找
{
	if (t == NULL || t->val == data){
		return t;
	}

	BinTreeNode *pt = BinTreeFind(t->left_tree, data);//在左树中查找
	if (pt != NULL){
		return pt;
	}
	return BinTreeFind(t->right_tree, data);//在右树中查找
}

void BinTreeDestroy(BinTree *t)//二叉树的摧毁
{
	if (*t != NULL){
		BinTreeDestroy(&(*t)->left_tree);
		BinTreeDestroy(&(*t)->right_tree);
		free(*t);
		(*t) = NULL;
	}
}
