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
	//printf("��������Ҫ���ҵĽڵ�: \n");
	//scanf("%c", &data);
	data = 'A';
	BinTreeNode *p = BinTreeFind(bt, data);//����ĳ���ڵ�
	if (p != NULL) {
		printf("%c����ڵ����!\n",data);
	}
	else {
		printf("%c����ڵ㲻����!\n",data);
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
//	//ͨ��ǰ(��)�����������"ABD##E#H##CF##G##"����������
//	BTDataType str[] = "ABD##E#H##CF##G##";
//	int i = 0;
//	bt = BinTreeCreate_1(str, &i);
//	int size = BinTreeSize(bt);
//	BTDataType data;
//	scanf("%c", &data);
//	BinTreeNode *p = BinTreeFind(bt, data);//����ĳ���ڵ�
//	if (p != NULL) {
//		printf("�ýڵ����!\n");
//	}
//	else {
//		printf("�ýڵ㲻����!\n");
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
	BinTreeNode *p = BinTreeFind(bt, data);//����ĳ���ڵ�

	BinTreeDestroy(&bt);

	system("pause");
	return 0;
}
*/