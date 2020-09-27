#include "BinTree.h"

void BinTreeInit(BinTree *t)//��ʼ��������
{
	*t = NULL;
}

BinTree BinTreeCreate(BTDataType *a, int *i)//���������ַ�������
{
	if (a[*i] == '#' || a[*i] == '\0'){
		return NULL;
	}
	BinTreeNode *t = (BinTreeNode *)malloc(sizeof(BinTreeNode));//����ڵ�
	assert(t != NULL);

	t->val = a[*i];
	(*i)++;

	t->left_tree = BinTreeCreate(a, i);//�ݹ鴴������
	(*i)++;
	t->right_tree = BinTreeCreate(a, i);//�ݹ鴴������

	return t;//���ش����õĶ�����
}

int BinTreeSize(BinTree t)//�ڵ����
{
	if (t == NULL){
		return 0;
	}
	return 1 + BinTreeSize(t->left_tree) + BinTreeSize(t->right_tree);
}

BinTreeNode* BinTreeFind(BinTree t, BTDataType data)//����������
{
	if (t == NULL || t->val == data){
		return t;
	}

	BinTreeNode *pt = BinTreeFind(t->left_tree, data);//�������в���
	if (pt != NULL){
		return pt;
	}
	return BinTreeFind(t->right_tree, data);//�������в���
}

void BinTreeDestroy(BinTree *t)//�������Ĵݻ�
{
	if (*t != NULL){
		BinTreeDestroy(&(*t)->left_tree);
		BinTreeDestroy(&(*t)->right_tree);
		free(*t);
		(*t) = NULL;
	}
}
