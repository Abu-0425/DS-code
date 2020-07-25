#include "SeqList.h"

static void Menu()
{
	printf("**************************************************\n");
	printf("**************************************************\n");
	printf("--------  Please enter your choice:       --------\n");
	printf("--------  0.Quit           1.Print        --------\n");
	printf("--------  2.PushBack       3.PushFront    --------\n");
	printf("--------  4.PopBack        5.PopFront     --------\n");
	printf("--------  6.Find           7.Sort         --------\n");
	printf("--------  8.Val_Insert     9.Pos_Insert   --------\n");
	printf("--------  10.Pos_Erase    11.Val_Erase    --------\n");
	printf("--------  12.EraseAllVal  13.Clear        --------\n");
	printf("--------  14.GetFront     15.GetBack      --------\n");
	printf("--------  16.Length       17.Capacity     --------\n");
	printf("--------  18.Reverse      19.Find_Binary  --------\n");
	printf("**************************************************\n");
	printf("**************************************************\n");
}
int main()
{
	SeqList_t list;//定义结构体变量
	InitSeqList(&list);//初始化顺序表
	ELEM_TYPE item = 0;
	size_t pos = 0;
	int select = 1;
	while (select){
		Menu();
		scanf("%d", &select);
		if (0 == select){
			printf("退出成功!\n");
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
				printf("当前顺序表为空，无法进行数据查找!\n");
			}
			else if (ret == -2){
				printf("查找数据失败,顺序表中没有该数据!\n");
			}
			else{
				printf("查找数据成功，该数据在顺序表中的下标为%d!\n", ret);
			}
			break;
		case 7:
			SeqListSort(&list);
			break;
		case 8:
			printf("请输入你要插入的数据: ");
			scanf("%d", &item);
			SeqListVal_Insert(&list, item);
			break;
		case 9:
			printf("请输入你要插入的数据和位置: \n");
			printf("数据: ");
			scanf("%d", &item);
			printf("位置: ");
			scanf("%u", &pos);
			SeqListPos_Insert(&list, pos, item);
			break;
		case 10:
			printf("请输入你要删除的数据的位置: ");
			scanf("%d", &pos);
			SeqListPos_Erase(&list, pos);
			break;
		case 11:
			printf("请输入你要删除的值: ");
			scanf("%d", &item);
			SeqListVal_Erase(&list, item);
			break;
		case 12:
			printf("请输入你要删除的值: ");
			scanf("%d", &item);
			SeqListEraseAllVal(&list, item);
			break;
		case 13:
			SeqListClear(&list);
			break;
		case 14:
			if (SeqListGetFront(&list) == -1){
				printf("当前顺序表为空，无法取表头元素!\n");
			}
			else{
				printf("该顺序表的头部元素为[%d]!\n", SeqListGetFront(&list));
			}
			break;
		case 15:
			if (SeqListGetBack(&list) == -1){
				printf("当前顺序表为空，无法取表尾元素!\n");
			}
			else{
				printf("该顺序表的尾部元素为[%d]!\n", SeqListGetBack(&list));
			}
			break;
		case 16:
			printf("该顺序表的当前长度为[%d]!\n", SeqListLength(&list));
			break;
		case 17:
			printf("该顺序表的当前容量为[%d]!\n", SeqListCapacity(&list));
			break;
		case 18:
			SeqListReverse(&list);
			break;
		case 19:
			printf("请输入你要进行查找的数据: ");
			scanf("%d", &item);
			int bin_ret = SeqListFind_Binary(&list, item);
			if (bin_ret == -1){
				printf("当前顺序表为空，无法进行数据查找!\n");
			}
			else if (bin_ret == -2){
				printf("查找数据失败,顺序表中没有该数据!\n");
			}
			else{
				printf("二分查找数据成功，该数据在顺序表中的下标为%d!\n", bin_ret);
			}
			break;
		default:
			printf("输入有误，请重新输入!\n");
			system("pause");
			system("cls");
			continue;
		}
		system("pause");
		system("cls");
	}

	DestorySeqList(&list);//摧毁顺序表

	system("pause");
	return 0;
}