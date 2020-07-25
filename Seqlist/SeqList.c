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

static bool IsEmpty(SeqList_t *plist)
{
	assert(plist);
	return plist->size == 0;
}

void SeqListPushBack(SeqList_t *plist, ELEM_TYPE x)
{
	assert(plist);
	if (IsFull(plist) && !Inc(plist, plist->cap * 2)){//顺序表已满且扩容失败
		printf("顺序表已满，无法继续插入!\n");
		return;
	}
	plist->base[plist->size] = x;
	plist->size++;
}

void SeqListPrint(SeqList_t *plist)
{
	assert(plist);
	if (IsEmpty(plist)){
		printf("当前顺序表为空!\n");
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



void SeqListSort(SeqList_t *plist)
{
	assert(plist);
	if (IsEmpty(plist)){
		printf("当前顺序表为空,无法进行排序操作!\n");
		return;
	}
	else if (plist->size == 1){
		printf("当前顺序表只有一个元素，排序操作无意义!\n");
		return;
	}

	//冒泡排序
	size_t i = 0;
	for (; i < plist->size - 1; i++){
		size_t j = 0;
		for (; j < plist->size - 1 - i; j++){
			if ((plist->base[j]) >(plist->base[j + 1])){
				Swap(&(plist->base[j]), &(plist->base[j + 1]));
			}
		}
	}
	printf("顺序表排序成功!\n");
}

void SeqListVal_Insert(SeqList_t *plist, ELEM_TYPE x)
{
	assert(plist);
	if (IsFull(plist) && !Inc(plist, plist->cap * 2)){
		printf("顺序表已满，无法继续插入!\n");
		return;
	}
	SeqListSort(plist);//按值插入即按顺序插入，所以在插入之前顺序表必须有序
#if 0 //方法一，容易想到，但并不是最简单的做法
	size_t i = 0;
	while (i < plist->size && x > plist->base[i]){
		i++;//先找到插入数据的位置
	}
	size_t j = plist->size;
	for (; j > i; j--){
		plist->base[j] = plist->base[j - 1];//向后移动
	}
	plist->base[j] = x;
	plist->size++;
	printf("数据插入成功!\n");
#endif
	//方法二
	size_t end = plist->size - 1;//定义一个指向顺序表尾部的"指针"
	while (end >= 0 && x < plist->base[end]){
		plist->base[end + 1] = plist->base[end];//向后移动
		end--;
	}
	plist->base[end + 1] = x;//插入数据
	plist->size++;
	printf("数据插入成功!\n");
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

void SeqListPos_Erase(SeqList_t *plist, size_t pos)
{
	assert(plist);
	assert(pos >= 0);
	if (IsEmpty(plist)){
		printf("当前顺序表为空，无法进行删除操作!\n");
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

void SeqListVal_Erase(SeqList_t *plist, ELEM_TYPE x)
{
	assert(plist);
	if (IsEmpty(plist)){
		printf("当前顺序表为空, 无法进行删除操作!\n");
		return;
	}
	//有了前面已经实现的一些功能，我们只需借助某些功能就可以实现按值删除
	int pos = 0;
	pos = SeqListFind(plist, x);//先找到需要删除数据的所在位置
	if (pos == -1){
		printf("对不起,你要删除的值[%d]不存在!\n", x);
		return;
	}
	else{
		SeqListPos_Erase(plist, pos);//找到该数据所在位置后按位置删除即可
	}
}

void SeqListEraseAllVal(SeqList_t *plist, ELEM_TYPE x)
{
	assert(plist);
	if (IsEmpty(plist)){
		printf("当前顺序表为空，无法进行删除操作!\n");
		return;
	}
	size_t i = 0;
	int flag = 0;//用于检测该数据是否存在
	while (i < plist->size){
		while (x != plist->base[i] && i < plist->size){
			i++;
		}
		if (x == plist->base[i]){
			flag = 1;//如果进入过该分支，则证明找到了数据，即数据存在
			size_t j = i;
			for (; j < plist->size - 1; j++){
				plist->base[j] = plist->base[j + 1];
			}
			plist->size--;
		}
	}
	if (flag == 0){
		printf("对不起,你要删除的值[%d]不存在!\n", x);
		return;
	}
	printf("数据删除成功!\n");
}

int SeqListFind(SeqList_t *plist, ELEM_TYPE x)
{
	assert(plist);
	if (IsEmpty(plist)){//空表查找操作无意义
		return -1;
	}
	size_t pos = 0;
	while (pos < plist->size && plist->base[pos] != x){
		pos++;
	}
	if (pos == plist->size){
		return -2;//表示没找到
	}
	return pos;//找到就返回该数据的下标
}

ELEM_TYPE SeqListGetFront(SeqList_t *plist)
{
	assert(plist);
	if (IsEmpty(plist)){
		//由于插入数据的机制，表中的数据不可能有-1，因此此处逻辑可行，不过这同样也算是一个小的缺陷吧
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
		printf("当前顺序表为空,无法进行逆置操作!\n");
		return;
	}
	else if (plist->size == 1){
		printf("当前顺序表中只有一个元素,逆置操作无意义!\n");
		return;
	}
	int start = 0;
	int end = plist->size - 1;
	while (start < end){
		Swap(&(plist->base[start]), &(plist->base[end]));
		start++;
		end--;
	}
	printf("顺序表逆置成功!\n");
}

int SeqListFind_Binary(SeqList_t *plist, ELEM_TYPE x)
{
	assert(plist);
	if (IsEmpty(plist)){//空表查找操作无意义
		return -1;
	}
	SeqListSort(plist);//二分查找的前提是顺序表有序
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
	printf("顺序表已成功清空!\n");
}

void DestorySeqList(SeqList_t *plist)
{
	assert(plist);
	free(plist->base);
	plist->base = NULL;//预防野指针
	plist->size = plist->cap = 0;
}