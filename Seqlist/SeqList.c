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
		return false; //扩容失败
	}
	plist->base = new_base;
	plist->cap = new_cap;
	printf("顺序表已成功扩容!\n");
	return true; //扩容成功
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
		printf("顺序表已满，无法继续插入!\n");
		return;
	}
	plist->base[plist->size] = x;
	plist->size++;
}

void SeqListPushFront(SeqList_t *plist, ELEM_TYPE x)
{
	assert(plist);
	if (IsFull(plist) && !Inc(plist, plist->cap * 2)){
		printf("顺序表已满，无法继续插入!\n");
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
		printf("顺序表已满，无法继续插入!\n");
		return;
	}
	if (pos < 0 || pos > plist->size){
		printf("你要插入的位置非法, 无法成功插入!\n");
		return;
	}
	size_t i = plist->size;
	for (; i > pos; i--){
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[pos] = x;
	plist->size++;
	printf("插入元素成功!\n");
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
		printf("当前顺序表为空，无法继续删除!\n");
		return;
	}
	plist->size--;
	printf("尾部删除成功!\n");
}

void SeqListPopFront(SeqList_t *plist)
{
	assert(plist);
	if (IsEmpty(plist)){
		printf("当前顺序表为空，无法继续删除!\n");
		return;
	}
	size_t i = 0;
	for (; i < plist->size - 1; i++){
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
	printf("头部删除成功!\n");
}

void SeqListErase(SeqList_t *plist, size_t pos)
{
	assert(plist);
	assert(pos >= 0);
	if (IsEmpty(plist)){
		printf("当前顺序表为空，无法继续删除!\n");
		return;
	}
	if (pos < 0 || pos >= plist->size){
		printf("你要删除的位置非法, 无法成功删除!\n");
		return;
	}
	size_t i = pos;
	for (; i < plist->size; i++){
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
	printf("数据删除成功!\n");
}

int SeqListFind(SeqList_t *plist, ELEM_TYPE x)
{
	assert(plist);
	size_t pos = 0;
	while (pos < plist->size && plist->base[pos] != x){
		pos++;
	}
	if (pos == plist->size){
		return -1;//表示没找到
	}
	return pos + 1;//找到就返回该数据在顺序表中的位置，比如下标为0，就是顺序表中的第一个数据
}
void DestorySeqList(SeqList_t *plist)
{
	assert(plist);
	free(plist->base);
	plist->base = NULL;
	plist->size = plist->cap = 0;
}