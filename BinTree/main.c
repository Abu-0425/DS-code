#include "BinTree.h"

int main()
{
	BinTree bt;
	BinTreeInit(&bt);

	//通过前(先)序遍历的数组"ABD##E#H##CF##G##"构建二叉树
	BTDataType str[] = "ABD##E#H##CF##G##";
	int i = 0;
	bt = BinTreeCreate(str, &i);
	int size = BinTreeSize(bt);
	BTDataType data;
	scanf("%c", &data);
	BinTreeNode *p = BinTreeFind(bt, data);//查找某个节点

	BinTreeDestroy(&bt);

	system("pause");
	return 0;
}