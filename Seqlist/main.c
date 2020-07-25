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
	SeqList_t list;//����ṹ�����
	InitSeqList(&list);//��ʼ��˳���
	ELEM_TYPE item = 0;
	size_t pos = 0;
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
				printf("��ǰ˳���Ϊ�գ��޷��������ݲ���!\n");
			}
			else if (ret == -2){
				printf("��������ʧ��,˳�����û�и�����!\n");
			}
			else{
				printf("�������ݳɹ�����������˳����е��±�Ϊ%d!\n", ret);
			}
			break;
		case 7:
			SeqListSort(&list);
			break;
		case 8:
			printf("��������Ҫ���������: ");
			scanf("%d", &item);
			SeqListVal_Insert(&list, item);
			break;
		case 9:
			printf("��������Ҫ��������ݺ�λ��: \n");
			printf("����: ");
			scanf("%d", &item);
			printf("λ��: ");
			scanf("%u", &pos);
			SeqListPos_Insert(&list, pos, item);
			break;
		case 10:
			printf("��������Ҫɾ�������ݵ�λ��: ");
			scanf("%d", &pos);
			SeqListPos_Erase(&list, pos);
			break;
		case 11:
			printf("��������Ҫɾ����ֵ: ");
			scanf("%d", &item);
			SeqListVal_Erase(&list, item);
			break;
		case 12:
			printf("��������Ҫɾ����ֵ: ");
			scanf("%d", &item);
			SeqListEraseAllVal(&list, item);
			break;
		case 13:
			SeqListClear(&list);
			break;
		case 14:
			if (SeqListGetFront(&list) == -1){
				printf("��ǰ˳���Ϊ�գ��޷�ȡ��ͷԪ��!\n");
			}
			else{
				printf("��˳����ͷ��Ԫ��Ϊ[%d]!\n", SeqListGetFront(&list));
			}
			break;
		case 15:
			if (SeqListGetBack(&list) == -1){
				printf("��ǰ˳���Ϊ�գ��޷�ȡ��βԪ��!\n");
			}
			else{
				printf("��˳����β��Ԫ��Ϊ[%d]!\n", SeqListGetBack(&list));
			}
			break;
		case 16:
			printf("��˳���ĵ�ǰ����Ϊ[%d]!\n", SeqListLength(&list));
			break;
		case 17:
			printf("��˳���ĵ�ǰ����Ϊ[%d]!\n", SeqListCapacity(&list));
			break;
		case 18:
			SeqListReverse(&list);
			break;
		case 19:
			printf("��������Ҫ���в��ҵ�����: ");
			scanf("%d", &item);
			int bin_ret = SeqListFind_Binary(&list, item);
			if (bin_ret == -1){
				printf("��ǰ˳���Ϊ�գ��޷��������ݲ���!\n");
			}
			else if (bin_ret == -2){
				printf("��������ʧ��,˳�����û�и�����!\n");
			}
			else{
				printf("���ֲ������ݳɹ�����������˳����е��±�Ϊ%d!\n", bin_ret);
			}
			break;
		default:
			printf("������������������!\n");
			system("pause");
			system("cls");
			continue;
		}
		system("pause");
		system("cls");
	}

	DestorySeqList(&list);//�ݻ�˳���

	system("pause");
	return 0;
}