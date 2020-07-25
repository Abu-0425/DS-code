#include "SeqList.h"

static void Swap(ELEM_TYPE *x, ELEM_TYPE *y)
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}

void InitSeqList(SeqList_t *plist)
{
	assert(plist);
	plist->cap = SEQLIST_DEFAULT_SIZE;
	plist->base = (ELEM_TYPE *)malloc(plist->cap * sizeof(ELEM_TYPE));
	plist->size = 0;
}

static bool Inc(SeqList_t *plist, size_t new_cap)
{
	assert(plist);
	assert(new_cap > plist->cap);
	ELEM_TYPE *new_base = (ELEM_TYPE *)realloc(plist->base, sizeof(ELEM_TYPE)* new_cap);
	if (new_base == NULL){
		return false; //����ʧ��
	}
	plist->base = new_base;
	plist->cap = new_cap;
	printf("˳����ѳɹ�����!\n");
	return true; //���ݳɹ�
}

static bool IsFull(SeqList_t *plist)
{
	assert(plist);
	return plist->cap == plist->size;
}

static bool IsEmpty(SeqList_t *plist)
{
	assert(plist);
	return plist->size == 0;
}

void SeqListPushBack(SeqList_t *plist, ELEM_TYPE x)
{
	assert(plist);
	if (IsFull(plist) && !Inc(plist, plist->cap * 2)){//˳�������������ʧ��
		printf("˳����������޷���������!\n");
		return;
	}
	plist->base[plist->size] = x;
	plist->size++;
}

void SeqListPrint(SeqList_t *plist)
{
	assert(plist);
	if (IsEmpty(plist)){
		printf("��ǰ˳���Ϊ��!\n");
		return;
	}
	size_t i = 0;
	for (; i < plist->size; i++){
		printf("%d ", plist->base[i]);
	}
	printf("\n");
}

void SeqListPushFront(SeqList_t *plist, ELEM_TYPE x)
{
	assert(plist);
	if (IsFull(plist) && !Inc(plist, plist->cap * 2)){
		printf("˳����������޷���������!\n");
		return;
	}
	size_t i = plist->size;
	for (; i > 0; i--){
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[0] = x;
	plist->size++;

}

void SeqListPos_Insert(SeqList_t *plist, size_t pos, ELEM_TYPE x)
{
	assert(plist);
	assert(pos >= 0);
	if (IsFull(plist) && !Inc(plist, plist->cap * 2)){
		printf("˳����������޷���������!\n");
		return;
	}
	if (pos < 0 || pos > plist->size){
		printf("��Ҫ�����λ�÷Ƿ�, �޷��ɹ�����!\n");
		return;
	}
	size_t i = plist->size;
	for (; i > pos; i--){
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[pos] = x;
	plist->size++;
	printf("����Ԫ�سɹ�!\n");
}



void SeqListSort(SeqList_t *plist)
{
	assert(plist);
	if (IsEmpty(plist)){
		printf("��ǰ˳���Ϊ��,�޷������������!\n");
		return;
	}
	else if (plist->size == 1){
		printf("��ǰ˳���ֻ��һ��Ԫ�أ��������������!\n");
		return;
	}

	//ð������
	size_t i = 0;
	for (; i < plist->size - 1; i++){
		size_t j = 0;
		for (; j < plist->size - 1 - i; j++){
			if ((plist->base[j]) >(plist->base[j + 1])){
				Swap(&(plist->base[j]), &(plist->base[j + 1]));
			}
		}
	}
	printf("˳�������ɹ�!\n");
}

void SeqListVal_Insert(SeqList_t *plist, ELEM_TYPE x)
{
	assert(plist);
	if (IsFull(plist) && !Inc(plist, plist->cap * 2)){
		printf("˳����������޷���������!\n");
		return;
	}
	SeqListSort(plist);//��ֵ���뼴��˳����룬�����ڲ���֮ǰ˳����������
#if 0 //����һ�������뵽������������򵥵�����
	size_t i = 0;
	while (i < plist->size && x > plist->base[i]){
		i++;//���ҵ��������ݵ�λ��
	}
	size_t j = plist->size;
	for (; j > i; j--){
		plist->base[j] = plist->base[j - 1];//����ƶ�
	}
	plist->base[j] = x;
	plist->size++;
	printf("���ݲ���ɹ�!\n");
#endif
	//������
	size_t end = plist->size - 1;//����һ��ָ��˳���β����"ָ��"
	while (end >= 0 && x < plist->base[end]){
		plist->base[end + 1] = plist->base[end];//����ƶ�
		end--;
	}
	plist->base[end + 1] = x;//��������
	plist->size++;
	printf("���ݲ���ɹ�!\n");
}

void SeqListPopBack(SeqList_t *plist)
{
	assert(plist);
	if (IsEmpty(plist)){
		printf("��ǰ˳���Ϊ�գ��޷�����ɾ��!\n");
		return;
	}
	plist->size--;
	printf("β��ɾ���ɹ�!\n");
}

void SeqListPopFront(SeqList_t *plist)
{
	assert(plist);
	if (IsEmpty(plist)){
		printf("��ǰ˳���Ϊ�գ��޷�����ɾ��!\n");
		return;
	}
	size_t i = 0;
	for (; i < plist->size - 1; i++){
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
	printf("ͷ��ɾ���ɹ�!\n");
}

void SeqListPos_Erase(SeqList_t *plist, size_t pos)
{
	assert(plist);
	assert(pos >= 0);
	if (IsEmpty(plist)){
		printf("��ǰ˳���Ϊ�գ��޷�����ɾ������!\n");
		return;
	}
	if (pos < 0 || pos >= plist->size){
		printf("��Ҫɾ����λ�÷Ƿ�, �޷��ɹ�ɾ��!\n");
		return;
	}
	size_t i = pos;
	for (; i < plist->size; i++){
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
	printf("����ɾ���ɹ�!\n");
}

void SeqListVal_Erase(SeqList_t *plist, ELEM_TYPE x)
{
	assert(plist);
	if (IsEmpty(plist)){
		printf("��ǰ˳���Ϊ��, �޷�����ɾ������!\n");
		return;
	}
	//����ǰ���Ѿ�ʵ�ֵ�һЩ���ܣ�����ֻ�����ĳЩ���ܾͿ���ʵ�ְ�ֵɾ��
	int pos = 0;
	pos = SeqListFind(plist, x);//���ҵ���Ҫɾ�����ݵ�����λ��
	if (pos == -1){
		printf("�Բ���,��Ҫɾ����ֵ[%d]������!\n", x);
		return;
	}
	else{
		SeqListPos_Erase(plist, pos);//�ҵ�����������λ�ú�λ��ɾ������
	}
}

void SeqListEraseAllVal(SeqList_t *plist, ELEM_TYPE x)
{
	assert(plist);
	if (IsEmpty(plist)){
		printf("��ǰ˳���Ϊ�գ��޷�����ɾ������!\n");
		return;
	}
	size_t i = 0;
	int flag = 0;//���ڼ��������Ƿ����
	while (i < plist->size){
		while (x != plist->base[i] && i < plist->size){
			i++;
		}
		if (x == plist->base[i]){
			flag = 1;//���������÷�֧����֤���ҵ������ݣ������ݴ���
			size_t j = i;
			for (; j < plist->size - 1; j++){
				plist->base[j] = plist->base[j + 1];
			}
			plist->size--;
		}
	}
	if (flag == 0){
		printf("�Բ���,��Ҫɾ����ֵ[%d]������!\n", x);
		return;
	}
	printf("����ɾ���ɹ�!\n");
}

int SeqListFind(SeqList_t *plist, ELEM_TYPE x)
{
	assert(plist);
	if (IsEmpty(plist)){//�ձ���Ҳ���������
		return -1;
	}
	size_t pos = 0;
	while (pos < plist->size && plist->base[pos] != x){
		pos++;
	}
	if (pos == plist->size){
		return -2;//��ʾû�ҵ�
	}
	return pos;//�ҵ��ͷ��ظ����ݵ��±�
}

ELEM_TYPE SeqListGetFront(SeqList_t *plist)
{
	assert(plist);
	if (IsEmpty(plist)){
		//���ڲ������ݵĻ��ƣ����е����ݲ�������-1����˴˴��߼����У�������ͬ��Ҳ����һ��С��ȱ�ݰ�
		return -1;
	}
	return plist->base[0];
}

ELEM_TYPE SeqListGetBack(SeqList_t *plist)
{
	assert(plist);
	if (IsEmpty(plist)){
		return -1;
	}
	return plist->base[plist->size - 1];
}

int  SeqListLength(SeqList_t *plist)
{
	assert(plist);
	return plist->size;
}
int  SeqListCapacity(SeqList_t *plist)
{
	assert(plist);
	return plist->cap;
}

void SeqListReverse(SeqList_t *plist)
{
	assert(plist);
	if (IsEmpty(plist)){
		printf("��ǰ˳���Ϊ��,�޷��������ò���!\n");
		return;
	}
	else if (plist->size == 1){
		printf("��ǰ˳�����ֻ��һ��Ԫ��,���ò���������!\n");
		return;
	}
	int start = 0;
	int end = plist->size - 1;
	while (start < end){
		Swap(&(plist->base[start]), &(plist->base[end]));
		start++;
		end--;
	}
	printf("˳������óɹ�!\n");
}

int SeqListFind_Binary(SeqList_t *plist, ELEM_TYPE x)
{
	assert(plist);
	if (IsEmpty(plist)){//�ձ���Ҳ���������
		return -1;
	}
	SeqListSort(plist);//���ֲ��ҵ�ǰ����˳�������
	int start = 0;
	int end = plist->size - 1;
	int mid;
	while (start <= end){
		mid = (start + end) / 2;
		if (x > plist->base[mid]){
			start = mid + 1;
		}
		else if (x < plist->base[mid]){
			end = mid - 1;
		}
		else{
			return mid;
		}
	}
	return -2;
}

void SeqListClear(SeqList_t *plist)
{
	assert(plist);
	plist->size = 0;
	printf("˳����ѳɹ����!\n");
}

void DestorySeqList(SeqList_t *plist)
{
	assert(plist);
	free(plist->base);
	plist->base = NULL;//Ԥ��Ұָ��
	plist->size = plist->cap = 0;
}