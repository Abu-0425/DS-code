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
	InitSeqList(&list);//��ʼ��˳���
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
			printf("��������Ҫ�����Ԫ��(��-1��β): ");
			while (scanf("%d", &item), item != -1){
				SeqListPushBack(&list, item);
			}
			printf("β������Ԫ�سɹ�!\n");
			break;
		case 3:
			printf("��������Ҫ�����Ԫ��(��-1��β): ");
			while (scanf("%d", &item), item != -1){
				SeqListPushFront(&list, item);
			}
			printf("ͷ������Ԫ�سɹ�!\n");
			break;
		case 4:
			SeqListPopBack(&list);
			break;
		case 5:
			SeqListPopFront(&list);
			break;
		case 6:
			printf("��������Ҫ���ҵ�����: ");
			scanf("%d", &item);
			int ret = SeqListFind(&list, item);
			if (ret == -1){
				printf("��������ʧ��,˳�����û�и�����!\n");
			}
			else{
				printf("�������ݳɹ���������λ��˳���ĵ�%d��λ��!\n", ret);
			}
			break;
		case 7:
			printf("��������Ҫ��������ݺ�λ��: \n");
			printf("����: ");
			scanf("%d", &item);
			printf("λ��: ");
			scanf("%u", &pos);
			SeqListPos_Insert(&list, pos, item);
			break;
		case 8:
			printf("��������Ҫɾ�������ݵ�λ��: ");
			scanf("%u", &pos);
			SeqListErase(&list, pos);
			break;
		default:
			printf("������������������!\n");
			break;
		}
		system("pause");
		system("cls");
	}

	DestorySeqList(&list);//�ݻ�˳���

	system("pause");
	return 0;
}