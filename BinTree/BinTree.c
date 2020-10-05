#include "BinTree.h"

void BinTreeInit(BinTree *t)//��ʼ��������
{
	*t = NULL;
}

void BinTreeCreate(BinTree *t)
{
	assert(t);
	BTDataType item;
	scanf("%c", &item);
	if (item == '#') {
		*t = NULL;
	}
	else {
		*t = (BinTreeNode *)malloc(sizeof(BinTreeNode));
		assert(*t);

		(*t)->val = item;
		BinTreeCreate(&(*t)->left_tree);
		BinTreeCreate(&(*t)->right_tree);
	}
}

BinTree BinTreeCreate_2()
{
	BTDataType item;
	scanf("%c", &item);
	if (item == '#') {
		return NULL;
	}
	else {
		BinTreeNode *t = (BinTreeNode *)malloc(sizeof(BinTreeNode));
		assert(t);
		t->val = item;
		t->left_tree = BinTreeCreate_2();
		t->right_tree = BinTreeCreate_2();
		return t;
	}
}

BinTree BinTreeCreate_1(BTDataType *a, int *i)//���������ַ�������
{
	if (a[*i] == '#' || a[*i] == '\0'){
		return NULL;
	}
	else {
		BinTreeNode *t = (BinTreeNode *)malloc(sizeof(BinTreeNode));//����ڵ�
		assert(t != NULL);

		t->val = a[*i];
		(*i)++;

		t->left_tree = BinTreeCreate_1(a, i);//�ݹ鴴������
		(*i)++;
		t->right_tree = BinTreeCreate_1(a, i);//�ݹ鴴������

		return t;//���ش����õĶ�����
	}
}

void BinTreeVLR(BinTree t)
{
	if (t != NULL) {
		printf("%c ", t->val);
		BinTreeVLR(t->left_tree);
		BinTreeVLR(t->right_tree);
	}
}
void BinTreeLVR(BinTree t)
{
	if (t != NULL)
	{
		BinTreeLVR(t->left_tree);
		printf("%c ", t->val);
		BinTreeLVR(t->right_tree);
	}
}

void BinTreeLRV(BinTree t)
{
	if (t != NULL)
	{
		BinTreeLRV(t->left_tree);
		BinTreeLRV(t->right_tree);
		printf("%c ", t->val);
	}
}

int BinTreeSize(BinTree t)//�ڵ����
{
	if (t == NULL){
		return 0;
	}
	return 1 + BinTreeSize(t->left_tree) + BinTreeSize(t->right_tree);
}

int BinTreeHigh(BinTree t)
{
	if (t == NULL) {
		return 0;
	}
	else {
		int high_l = BinTreeHigh(t->left_tree);
		int high_r = BinTreeHigh(t->right_tree);
		return (high_l > high_r ? high_l : high_r) + 1;
	}
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
