#include "SeqList.h"


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
bool IsEmpty(SeqList_t *plist)
{
	assert(plist);
	return plist->size == 0;
}
void SeqListPushBack(SeqList_t *plist, ELEM_TYPE x)
{
	assert(plist);
	if (IsFull(plist) && !Inc(plist, plist->cap*2)){
		printf("˳����������޷���������!\n");
		return;
	}
	plist->base[plist->size] = x;
	plist->size++;
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

void SeqListPrint(SeqList_t *plist)
{
	assert(plist);
	size_t i = 0;
	for (; i < plist->size; i++){
		printf("%d ", plist->base[i]);
	}
	printf("\n");
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

void SeqListErase(SeqList_t *plist, size_t pos)
{
	assert(plist);
	assert(pos >= 0);
	if (IsEmpty(plist)){
		printf("��ǰ˳���Ϊ�գ��޷�����ɾ��!\n");
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

int SeqListFind(SeqList_t *plist, ELEM_TYPE x)
{
	assert(plist);
	size_t pos = 0;
	while (pos < plist->size && plist->base[pos] != x){
		pos++;
	}
	if (pos == plist->size){
		return -1;//��ʾû�ҵ�
	}
	return pos + 1;//�ҵ��ͷ��ظ�������˳����е�λ�ã������±�Ϊ0������˳����еĵ�һ������
}
void DestorySeqList(SeqList_t *plist)
{
	assert(plist);
	free(plist->base);
	plist->base = NULL;
	plist->size = plist->cap = 0;
}