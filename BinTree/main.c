#include "BinTree.h"

int main()
{
	BinTree bt;
	BinTreeInit(&bt);

	bt = BinTreeCreate_2();
	int size = BinTreeSize(bt);
	printf("size = %d\n", size);
	BinTreeVLR(bt);
	printf("\n");
	BinTreeLVR(bt);
	printf("\n");
	BinTreeLRV(bt);
	printf("\n");
	BTDataType data;
	//printf("请输入想要查找的节点: \n");
	//scanf("%c", &data);
	data = 'A';
	BinTreeNode *p = BinTreeFind(bt, data);//查找某个节点
	if (p != NULL) {
		printf("%c这个节点存在!\n",data);
	}
	else {
		printf("%c这个节点不存在!\n",data);
	}
	printf("high = %d\n", BinTreeHigh(bt));

	BinTreeDestroy(&bt);
	system("pause");
	return 0;
}

//int main()
//{
//	BinTree bt;
//	BinTreeInit(&bt);
//	//通过前(先)序遍历的数组"ABD##E#H##CF##G##"构建二叉树
//	BTDataType str[] = "ABD##E#H##CF##G##";
//	int i = 0;
//	bt = BinTreeCreate_1(str, &i);
//	int size = BinTreeSize(bt);
//	BTDataType data;
//	scanf("%c", &data);
//	BinTreeNode *p = BinTreeFind(bt, data);//查找某个节点
//	if (p != NULL) {
//		printf("该节点存在!\n");
//	}
//	else {
//		printf("该节点不存在!\n");
//	}
//
//	BinTreeDestroy(&bt);
//	system("pause");
//	return 0;
//}

/*
int main()
{
	BinTree bt;
	BinTreeInit(&bt);
	BinTreeCreate(&bt);

	int size = BinTreeSize(bt);
	BTDataType data;
	scanf("%c", &data);
	BinTreeNode *p = BinTreeFind(bt, data);//查找某个节点

	BinTreeDestroy(&bt);

	system("pause");
	return 0;
}
*/