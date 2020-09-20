#include "sort.h"


//int main()
//{
//	int arr[] = { 9, 2, 6, 3, 7, 5, 1, 4, 8 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//
//	printf("����ǰ: \n");
//	PrintArray(arr, n);
//	TestSort(arr, n);
//	printf("�����: \n");
//	PrintArray(arr, n);
//	TestSortEfficiency();
//
//	system("pause");
//	return 0;
//}

//���ڲ��Կ���
int main()
{
	int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("����ǰ: \n");
	PrintArray(arr, n);
	TestQuickSort(arr, 0, n);
	printf("�����: \n");
	PrintArray(arr, n);
	TestSortEfficiency();

	system("pause");
	return 0;
}


/*
//���ڲ��Դ��ڱ�λ������
int main()
{
	//���ڱ�λ������
	int arr[] = { 0, 9, 2, 6, 3, 7, 5, 1, 4, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("����ǰ: \n");
	PrintArray(arr, n);
	TestSort(arr, n);
	printf("�����: \n");
	PrintArray(arr, n);
	TestSortEfficiency();

	system("pause");
	return 0;
}
*/
