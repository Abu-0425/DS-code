#include "sort.h"


int main()
{
	//int arr[] = { 9, 2, 6, 3, 7, 5, 1, 4, 8 };
	//int arr[] = {49, 38, 65, 97, 76, 13,27, 49};
	int arr[] = { 278, 109, 63, 930, 589, 184, 505, 269, 8, 83 };
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


//用于测试快排
/*
int main()
{
	int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("排序前: \n");
	PrintArray(arr, n);
	TestQuickSort(arr, 0, n);
	printf("排序后: \n");
	PrintArray(arr, n);
	TestSortEfficiency();

	system("pause");
	return 0;
}
*/



/*
//用于测试带哨兵位的排序
int main()
{
	//带哨兵位的数组
	int arr[] = { 0, 9, 2, 6, 3, 7, 5, 1, 4, 8 };
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
*/
