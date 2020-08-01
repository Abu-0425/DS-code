#ifndef _STACT_H_
#define _STACT_H_

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#pragma warning(disable:4996)

//链栈
typedef int LinkSTDataType;//元素类型

typedef struct LinkStackNode{
	LinkSTDataType data;
	struct LinkStackNode *link;
}LinkStackNode;

typedef  LinkStackNode* LinkStack;

void LinkStackNodeInit(LinkStack *pst);
void LinkStackPush(LinkStack *pst, LinkSTDataType x);
void LinkStackPop(LinkStack *pst);
LinkSTDataType LinkStackTop(LinkStack pst);
void LinkStackDestroy(LinkStack *pst);


//顺序栈
#define STACK_DEFAULT_SIZE 8  //默认容量
typedef int STDataType;   //元素类型

typedef struct Stack
{
	STDataType* _a;  //指向堆空间
	int _top;		 // 栈顶
	int _capacity;   // 容量 
}Stack;

void StackInit(Stack* ps);//初始化栈
void StackPush(Stack* ps, STDataType data);//入栈
void StackPop(Stack* ps);//出栈
STDataType StackTop(Stack* ps);
int StackSize(Stack* ps);//获取元素个数
void StackDestroy(Stack* ps);//摧毁栈

#endif /* _STACT_H_ */