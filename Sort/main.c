#include "sort.h"

//int main()
//{
//	//���ڱ�λ������
//	int arr[] = { 0, 9, 2, 6, 3, 7, 5, 1, 4, 8 };
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

int main()
{
	int arr[] = { 9, 2, 6, 3, 7, 5, 1, 4, 8 };
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