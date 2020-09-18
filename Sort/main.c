#include "sort.h"

//int main()
//{
//	//带哨兵位的数组
//	int arr[] = { 0, 9, 2, 6, 3, 7, 5, 1, 4, 8 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//
//	printf("排序前: \n");
//	PrintArray(arr, n);
//	TestSort(arr, n);
//	printf("排序后: \n");
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

	printf("排序前: \n");
	PrintArray(arr, n);
	TestSort(arr, n);
	printf("排序后: \n");
	PrintArray(arr, n);
	TestSortEfficiency();

	system("pause");
	return 0;
}