#include "SeqList.h"

static void Menu()
{
	printf("**************************************************\n");
	printf("**************************************************\n");
	printf("-----------Please enter your choice:   -----------\n");
	printf("-----------0.Quit          1.Print     -----------\n");
	printf("-----------2.PushBack      3.PushFront -----------\n");
	printf("-----------4.PopBack       5.PopFront  -----------\n");
	printf("-----------6.Find          7.Pos_Insert-----------\n");
	printf("-----------8.Pos_Erase                 -----------\n");
	printf("**************************************************\n");
	printf("**************************************************\n");

}
int main()
{
	SeqList_t list;
	InitSeqList(&list);//初始化顺序表
	ELEM_TYPE item = 0;
	size_t pos = 0;
	int select = 1;
	while (select){
		Menu();
		scanf("%d", &select);
		if (0 == select){
			break;
		}
		switch (select){
		case 1:
			SeqListPrint(&list);
			break;
		case 2:
			printf("请输入你要插入的元素(以-1结尾): ");
			while (scanf("%d", &item), item != -1){
				SeqListPushBack(&list, item);
			}
			printf("尾部插入元素成功!\n");
			break;
		case 3:
			printf("请输入你要插入的元素(以-1结尾): ");
			while (scanf("%d", &item), item != -1){
				SeqListPushFront(&list, item);
			}
			printf("头部插入元素成功!\n");
			break;
		case 4:
			SeqListPopBack(&list);
			break;
		case 5:
			SeqListPopFront(&list);
			break;
		case 6:
			printf("请输入你要查找的数据: ");
			scanf("%d", &item);
			int ret = SeqListFind(&list, item);
			if (ret == -1){
				printf("查找数据失败,顺序表中没有该数据!\n");
			}
			else{
				printf("查找数据成功，该数据位于顺序表的第%d个位置!\n", ret);
			}
			break;
		case 7:
			printf("请输入你要插入的数据和位置: \n");
			printf("数据: ");
			scanf("%d", &item);
			printf("位置: ");
			scanf("%u", &pos);
			SeqListPos_Insert(&list, pos, item);
			break;
		case 8:
			printf("请输入你要删除的数据的位置: ");
			scanf("%u", &pos);
			SeqListErase(&list, pos);
			break;
		default:
			printf("输入有误，请重新输入!\n");
			break;
		}
		system("pause");
		system("cls");
	}

	DestorySeqList(&list);//摧毁顺序表

	system("pause");
	return 0;
}