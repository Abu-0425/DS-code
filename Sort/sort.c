#include "sort.h"

void Swap(int *x, int *y)
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}

void PrintArray(int *arr, int n)
{
	int i = 0;
	for (; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//ֱ�Ӳ�������
void InsertSort(int *arr, int n)
{
	int i = 1;
	for (; i < n; i++) {
		int end = i;
		while (end > 0 && arr[end] < arr[end - 1]) {
			Swap(&arr[end], &arr[end - 1]);//������������
			end--;
		}
	}
}

//ֱ�Ӳ�������Ľ�
void InsertSort_1(int *arr, int n)
{
	int i = 1;
	for (; i < n; i++) {
		int tmp = arr[i];
		int end = i;
		while (end > 0 && tmp < arr[end - 1]) {
			arr[end] = arr[end - 1];//����ƶ�����
			end--;
		}
		arr[end] = tmp;
	}
}

//���ڱ�λ��ֱ�Ӳ�������
void InsertSort_2(int *arr, int n)
{
	int tmp = arr[0];
	int i = 1;
	for (; i < n; i++) {
		arr[0] = arr[i];//�ڱ�λ
		int end = i;
		while (arr[0] < arr[end - 1]) {
			arr[end] = arr[end - 1];//����ƶ�����
			end--;
		}
		arr[end] = arr[0];
	}
	arr[0] = tmp;
}

//�۰��������
void BinInsertSort(int *arr, int n)
{
	int i = 1;
	for (; i < n; i++) {
		int tmp = arr[i];
		int low = 0;
		int high = i - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (tmp < arr[mid]) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		int j = i - 1;
		for (; j >= high + 1; j--) {
			arr[j + 1] = arr[j];
		}
		arr[high + 1] = tmp;
	}
}

//��·��������
void TwoWayInsert(int *arr, int n)
{

}

//��������
void TestSort(int *arr, int n)
{
	//InsertSort(arr, n);
	//InsertSort_1(arr, n);
	//InsertSort_2(arr, n);
	BinInsertSort(arr, n);
}

//��������Ч��
void TestSortEfficiency()
{
	int n = 20000;
	int *a1 = (int *)malloc(sizeof(int)* n);
	int *a2 = (int *)malloc(sizeof(int)* n);
	int *a3 = (int *)malloc(sizeof(int)* n);
	int *a4 = (int *)malloc(sizeof(int)* n);

	srand((unsigned int)time(NULL));
	int i = 0;
	for (; i < n; i++) {
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
	}

	time_t start = clock();
	InsertSort(a1, n);
	time_t end = clock();
	printf("InsertSortEff: %u\n", end - start);

	start = clock();
	InsertSort_1(a2, n);
	end = clock();
	printf("InsertSort_1Eff: %u\n", end - start);

	start = clock();
	InsertSort_2(a3, n);
	end = clock();
	printf("InsertSort_2Eff: %u\n", end - start);

	start = clock();
	BinInsertSort(a4, n);
	end = clock();
	printf("BinInsertSortEff: %u\n", end - start);

}