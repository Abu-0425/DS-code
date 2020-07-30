#include "DCList.h"

//#include <stdbool.h>
//
//void bit_set(unsigned char *p_data, int position, bool flag)
//{
//	unsigned char x = *p_data;
//	if (flag){
//		
//	}
//}
//int main()
//{
//	unsigned char data = 0;
//	scanf("%d", &data);
//	bit_set(&data, 3, true);
//	system("pause");
//	return 0;
//}

static void Menu()
{
	printf("**************************************************\n");
	printf("**************************************************\n");
	printf("---------- Please enter your choice:   -----------\n");
	printf("---------- 0.Quit          1.Show      -----------\n");
	printf("---------- 2.PushBack      3.PushFront -----------\n");
	printf("---------- 4.PopBack       5.PopFront  -----------\n");
	printf("---------- 6.Find          7.Clear     -----------\n");
	printf("---------- 8.InsertByVal   9.EraseByVal-----------\n");
	printf("----------10.EraseAllVal  11.Sort      -----------\n");
	printf("**************************************************\n");
	printf("**************************************************\n");
}

int main()
{
	DCList list;
	list = DCListCreate();
	ELEM_TYPE item = 0;
	size_t pos = 0;
	DCListNode *p = NULL;
	int select = 1;
	while (select){
		Menu();
		scanf("%d", &select);
		if (0 == select){
			printf("�˳��ɹ�!\n");
			break;
		}
		switch (select){
		case 1:
			DCListShow(list);
			break;
		case 2:
			printf("��������Ҫ���������<��-1��β>: ");
			while (scanf("%d", &item), item != -1){
				DCListPushBack(&list, item);
			}
			printf("β��ɹ�!\n");
			break;
		case 3:
			printf("��������Ҫ���������<��-1��β>: ");
			while (scanf("%d", &item), item != -1){
				DCListPushFront(&list, item);
			}
			printf("ͷ��ɹ�!\n");
			break;
		case 4:
			DCListPopBack(&list);
			break;
		case 5:
			DCListPopFront(&list);
			break;
		case 6:
			printf("��������Ҫ���ҵ�����: ");
			scanf("%d", &item);
			p = DCListFind(list, item);
			if (p == NULL){
				printf("��������ʧ��!\n");
			}
			else{
				printf("�������ݳɹ��������ݵĵ�ַΪ%x!\n", p);
			}
			break;
		case 7:
			DCListClear(&list);//���˫ѭ������
			printf("������ճɹ�!\n");
			break;
		case 8:
			printf("��������Ҫ���������: ");
			scanf("%d", &item);
			DCListInsertByVal(&list, item);
			break;
		case 9:
			printf("��������Ҫɾ��������: ");
			scanf("%d", &item);
			DCListEraseByVal(&list, item);
			break;
		case 10:
			printf("��������Ҫɾ��������: ");
			scanf("%d", &item);
			//EraseAllVal(&list, item);
			break;
		case 11:
			DCListSort(list);
			break;
		default:
			printf("��������, ����������!\n");
			break;
		}
		system("pause");
		system("cls");

	}
	DCListDestroy(&list);//�ݻ�˫ѭ������

	system("pause");
	return 0;
}