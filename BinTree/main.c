#include "BinTree.h"

int main()
{
	BinTree bt;
	BinTreeInit(&bt);

	//ͨ��ǰ(��)�����������"ABD##E#H##CF##G##"����������
	BTDataType str[] = "ABD##E#H##CF##G##";
	int i = 0;
	bt = BinTreeCreate(str, &i);
	int size = BinTreeSize(bt);
	BTDataType data;
	scanf("%c", &data);
	BinTreeNode *p = BinTreeFind(bt, data);//����ĳ���ڵ�

	BinTreeDestroy(&bt);

	system("pause");
	return 0;
}