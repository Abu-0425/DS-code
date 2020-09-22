#include "sort.h"

// ��������������
void Swap(int *x, int *y)
{
	
	/*
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
	*/

	int temp = *x;
	*x = *y;
	*y = temp;
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
			else { //tmp >= arr[mid]
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
	int *tmp = (int *)malloc(sizeof(int)* n);//�����¿ռ�
	assert(tmp != NULL);

	tmp[0] = arr[0];
	int first = 0, finsh = 0;
	int i = 1;
	for (; i < n; i++) {
		if (arr[i] < tmp[first]) { //�ȵ�һ��Ԫ�ػ�С
			first = (first - 1 + n) % n;
			tmp[first] = arr[i];
		}
		else if (arr[i] > tmp[finsh]) { //�����һ��Ԫ�ػ���
			tmp[++finsh] = arr[i];
		}
		else { //��Ԫ�����м�
			int end = finsh;
			while (arr[i] < tmp[end]) {
				tmp[(end + 1) % n] = tmp[end];
				end = (end - 1 + n) % n;
			}
			tmp[(end + 1) % n] = arr[i];
			finsh++;
		}
	}

	//��ֵ��ԭ����
	int k = 0;
	int j = first;
	for (; k < n; k++) {
		arr[k] = tmp[j];
		j = (j + 1 ) % n;
	}

	free(tmp); //�ͷ�����Ŀռ�
	tmp = NULL; //Ԥ��Ұָ��
}

//ϣ������
void ShellSort(int *arr, int n)
{
	int dk = n;
	while (dk > 1) {
		dk = dk / 3 + 1;
		int i = dk;
		for (; i < n; i++) {
			if (arr[i] < arr[i - dk]) {
				int tmp = arr[i];
				int end = i - dk;
				while (end >= 0 && tmp < arr[end]) {
					arr[end + dk] = arr[end];
					end -= dk;
				}
				arr[end + dk] = tmp;
			}
		}
	}
}

//��ȡ��Сֵ���±�(ֱ��ѡ������)
int GetMinIndex(int *arr, int left, int right)
{
	int min_val = arr[left];
	int index = left;

	int i = left + 1;
	for (; i < right; i++) {
		if (arr[i] < min_val) {
			min_val = arr[i];
			index = i;
		}
	}
	return index;
}

//ֱ��ѡ������
void SelectSort(int *arr, int n)
{
	int i = 0;
	for (; i < n - 1; i++) {
		int index = GetMinIndex(arr, i, n);
		if (i != index) {
			Swap(&arr[i], &arr[index]);
		}
	}
}

//���µ����㷨
void AdjustDwon(int *arr, int n, int curpos)
{
	int i = curpos;
	int j = 2 * i + 1; //������

	while (j < n) { //����������
		if (j + 1 < n && arr[j] < arr[j + 1]) {
			j++;//���������ڲ��Ҵ�����������ָ��������
		}
		if (arr[i] < arr[j]) { 
			// ���µ���
			Swap(&arr[i], &arr[j]);
			//ָ����һ����֧�������ж��Ƿ���Ҫ����
			i = j;
			j = 2 * i + 1;
		}
		else {
			break;
		}
	}
}

//����
void HeapSort(int *arr, int n)
{
	//�������
	int cur = n / 2 - 1; //��ָ�����һ����֧
	while (cur >= 0) {
		AdjustDwon(arr, n, cur);
		cur--;
	}

	//����
	int end = n - 1;//���һ��Ԫ��
	while (end > 0) {
		Swap(&arr[0], &arr[end]);
		AdjustDwon(arr, end, 0);
		end--;
	}
}

//ð������
void BubbleSort(int *arr, int n)
{
	int i = 0;
	for (; i < n - 1; i++) {
		int j = 0;
		for (; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

//ð������ĸĽ�
void BubbleSort_1(int *arr, int n)
{
	bool is_swap = false;//���ڱ�־���������Ƿ��н������������˵����������δ������
						  //��û����˵�������Ѿ�����ֱ���˳�
	int i = 0;
	for (; i < n - 1; i++) {
		int j = 0;
		for (; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				Swap(&arr[j], &arr[j + 1]);
				is_swap = true; //��ʾ������
			}
		}
		if (!is_swap) { //û�н�������ֱ������ѭ��
			break;
		}
		else {
			is_swap = false;
		}
	}
}

//����ȡ��
int GetMidValIndex(int *arr, int left, int right)
{
	int mid = (left + right) / 2;
	if (arr[left] > arr[mid] && arr[left] < arr[right]) {
		return left;
	}
	else if (arr[mid] > arr[left] && arr[mid] < arr[right]) {
		return mid;
	}
	else {
		return right;
	}
}

//hoare�汾
int Partition_1(int *arr, int left, int right)
{
	int index = GetMidValIndex(arr, left, right);
	if (index != left) {
		Swap(&arr[left], &arr[index]);
	}
	int key = arr[left];//��׼ֵ

	while (left < right) {
		while (left < right && arr[right] >= key) {
			right--;
		}
		Swap(&arr[left], &arr[right]);
		while (left < right && arr[left] < key) {
			left++;
		}
		Swap(&arr[left], &arr[right]);
	}
	return left;//rightͬ��
}

//�ڿӷ�
int Partition_2(int *arr, int left, int right)
{
	int index = GetMidValIndex(arr, left, right);
	if (index != left) {
		Swap(&arr[left], &arr[index]);
	}
	int key = arr[left];//��׼ֵ,�����䱣��,�൱�ڰ���"����"
	while (left < right) {
		while (left < right && arr[right] >= key) {
			right--;
		}
		arr[left] = arr[right];
		while (left < right && arr[left] < key) {
			left++;
		}
		arr[right] = arr[left];
	}
	arr[left] = key;
	return left;
}

//ǰ��ָ�뷨
int Partition_3(int *arr, int left, int right)
{
	int index = GetMidValIndex(arr, left, right);
	if (index != left) {
		Swap(&arr[left], &arr[index]);
	}
	int key = arr[left];//��׼ֵ

	int pos = left;
	int i = left + 1;
	for (; i <= right; i++) {
		if (arr[i] < key) {
			pos++;
			if (i != pos) {
				Swap(&arr[i], &arr[pos]);
			}
		}
	}
	Swap(&arr[left], &arr[pos]);
	return pos;
}

//��������(���ְ汾)
void QuickSort(int *arr, int left, int right)
{
	if (left >= right - 1) {
		return;
	}
	//int pos = Partition_1(arr, left, right - 1);
	//int pos = Partition_2(arr, left, right - 1);
	int pos = Partition_3(arr, left, right - 1);
	QuickSort(arr, left, pos);
	QuickSort(arr, pos + 1, right);
}

//�鲢����Ĺ���
void _MergeSort(int *arr, int left, int right, int *tmp)
{
	//�ȷֽ�
	if (left >= right) {
		return;
	}
	int mid = (left + right) / 2;
	_MergeSort(arr, left, mid, tmp);
	_MergeSort(arr, mid + 1, right, tmp);

	//�ٹ鲢
	int begin1, end1, begin2, end2;
	begin1 = left, end1 = mid;
	begin2 = mid + 1, end2 = right;
	int i = 0;
	while (begin1 <= end1 && begin2 <= end2) {
		if (arr[begin1] <= arr[begin2]) {
			tmp[i++] = arr[begin1++];
		}
		else {
			tmp[i++] = arr[begin2++];
		}
	}
	while (begin1 <= end1) {
		tmp[i++] = arr[begin1++];
	}
	while (begin2 <= end2) {
		tmp[i++] = arr[begin2++];
	}
	memcpy(arr + left, tmp, sizeof(int)* (right - left + 1));
}

//�鲢����
void MergeSort(int *arr, int n)
{
	int *tmp = (int *)malloc(sizeof(int) * n);//������ʱ�ռ�
	assert(tmp != NULL);

	//�鲢����Ĺ���
	_MergeSort(arr, 0, n - 1, tmp);

	free(tmp);
	tmp = NULL;
}

//��������
#include "slist.h" //�õ����������еĲ��ַ���
#define RADIX 10
SList list[RADIX];
#define K 1 //�������ݵ����λ��

//��ȡ�ؼ�ֵ
int GetKey(int value, int k)
{
	int key;
	while (k >= 0) {
		key = value % 10;
		value /= 10;
		k--;
	}
	return key;
}

void Distribute(int *arr, int n, int k)
{
	int i = 0;
	for (; i < n; i++) {
		int key = GetKey(arr[i], k);
		SListPushBack(&list[key], arr[i]);
	}
}

void Collect(int *arr)
{
	int k = 0;
	for (int i = 0; i < RADIX; i++) {
		while (!SListEmpty(list[i])) {
			arr[k++] = SListFront(list[i]);
			SListPopFront(&list[i]);
		}
	}
}

void RadixSort(int *arr, int n)
{
	for (int i = 0; i < RADIX; i++) {
		SListInit(&list[i]);
	}

	for (int i = 0; i < K; i++) {
		//�ַ�
		Distribute(arr, n, i);
		//����
		Collect(arr);
	}

	//ʹ�����֮��ݻٵ�����
	for (int i = 0; i < RADIX; i++) {
		SListDestory(&list[i]);
	}
}

//��������
void TestSort(int *arr, int n)
{
	//InsertSort(arr, n);
	//InsertSort_1(arr, n);
	//InsertSort_2(arr, n);
	//BinInsertSort(arr, n);
	//TwoWayInsert(arr, n);
	//ShellSort(arr, n);
	//SelectSort(arr, n);
	//HeapSort(arr, n);
	//BubbleSort(arr, n);
	//BubbleSort_1(arr, n);
	//MergeSort(arr, n);
	RadixSort(arr, n);
}

//���Կ���
void TestQuickSort(int *arr, int left, int right)
{
	QuickSort(arr, left, right);
}

//��������Ч��
void TestSortEfficiency()
{
	int n = 20000;
	int *a1 = (int *)malloc(sizeof(int)* n);
	int *a2 = (int *)malloc(sizeof(int)* n);
	int *a3 = (int *)malloc(sizeof(int)* n);
	int *a4 = (int *)malloc(sizeof(int)* n);
	int *a5 = (int *)malloc(sizeof(int)* n);
	int *a6 = (int *)malloc(sizeof(int)* n);
	int *a7 = (int *)malloc(sizeof(int)* n);
	int *a8 = (int *)malloc(sizeof(int)* n);
	int *a9 = (int *)malloc(sizeof(int)* n);
	int *a10 = (int *)malloc(sizeof(int)* n);
	int *a11 = (int *)malloc(sizeof(int)* n);
	int *a12 = (int *)malloc(sizeof(int)* n);
	int *a13 = (int *)malloc(sizeof(int)* n);

	srand((unsigned int)time(NULL));
	int i = 0;
	for (; i < n; i++) {
		a1[i] = rand();//����n�������
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
		a9[i] = a1[i];
		a10[i] = a1[i];
		a11[i] = a1[i];
		a12[i] = a1[i];
		a13[i] = a1[i];
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

	start = clock();
	TwoWayInsert(a5, n);
	end = clock();
	printf("TwoWayInsertEff: %u\n", end - start);

	start = clock();
	ShellSort(a6, n);
	end = clock();
	printf("ShellSortEff: %u\n", end - start);

	start = clock();
	SelectSort(a7, n);
	end = clock();
	printf("SelectSortEff: %u\n", end - start);

	start = clock();
	HeapSort(a8, n);
	end = clock();
	printf("HeapSortEff: %u\n", end - start);

	start = clock();
	BubbleSort(a9, n);
	end = clock();
	printf("BubbleSortEff: %u\n", end - start);

	start = clock();
	BubbleSort_1(a10, n);
	end = clock();
	printf("BubbleSort_1Eff: %u\n", end - start);

	start = clock();
	QuickSort(a11, 0, n);
	end = clock();
	printf("QuickSortEff: %u\n", end - start);

	start = clock();
	MergeSort(a12, n);
	end = clock();
	printf("MergeSortEff: %u\n", end - start);

	start = clock();
	RadixSort(a13, n);
	end = clock();
	printf("RadixSortEff: %u\n", end - start);

}