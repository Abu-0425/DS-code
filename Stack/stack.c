#include "stack.h"

void StackInit(Stack* ps)
{
	assert(ps);
	ps->_capacity = STACK_DEFAULT_SIZE;
	ps->_a = (STDataType *)malloc(sizeof(STDataType)* ps->_capacity);
	ps->_top = 0;
}

static bool IncStack(Stack *ps, int new_cap)
{
	assert(ps);
	assert(new_cap > ps->_capacity);
	STDataType *new_a = (STDataType *)realloc(ps->_a, sizeof(STDataType)* new_cap);
	if (new_a == NULL){
		return false; //扩容失败
	}
	ps->_a = new_a;
	ps->_capacity = new_cap;
	printf("链表已成功扩容!\n");
	return true; //扩容成功
}

static bool IsFull(Stack *ps)
{
	assert(ps);
	return ps->_top >= ps->_capacity;
}

static bool IsEmpty(Stack *ps)
{
	assert(ps);
	return ps->_top == 0;
}

void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (IsFull(ps) && !IncStack(ps, ps->_capacity * 2)){
		printf("栈已满!无法继续插入元素!\n");
		return;
	}
	ps->_a[ps->_top] = data;
	ps->_top++;
}

void StackPop(Stack* ps)
{
	assert(ps);
	if (IsEmpty(ps)){
		printf("当前栈已空!无法出栈!\n");
		return;
	}
	ps->_top--;
}

STDataType StackTop(Stack* ps)
{
	assert(ps);
	return (ps->_a[ps->_top -1 ]);
}

int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_top = ps->_capacity = 0;
}

/////////////////////////////////////////////////////////////////////////
//以下为链栈的实现
void LinkStackNodeInit(LinkStack *pst)
{
	assert(pst);
	*pst = NULL;
}

static bool LinkStackEmpty(LinkStack pst)
{
	return pst == NULL;
}


void LinkStackPush(LinkStack *pst, LinkSTDataType x)
{
	assert(pst);
	LinkStackNode *node = (LinkStackNode *)malloc(sizeof(LinkStackNode));
	assert(node != NULL);
	node->data = x;
	node->link = *pst;
	*pst = node;	
}

void LinkStackPop(LinkStack *pst)
{
	assert(pst);
	if (LinkStackEmpty(*pst)){//判空
		return;
	}
	LinkStackNode *p = *pst;
	*pst = p->link;
	free(p);
}

LinkSTDataType LinkStackTop(LinkStack pst)
{
	assert(pst);
	return pst->data;
}

void LinkStackDestroy(LinkStack *pst)
{
	assert(pst);
	while(*pst != NULL){
		LinkStackPop(pst);
	}
}


