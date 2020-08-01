#ifndef _STACT_H_
#define _STACT_H_

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#pragma warning(disable:4996)

//��ջ
typedef int LinkSTDataType;//Ԫ������

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


//˳��ջ
#define STACK_DEFAULT_SIZE 8  //Ĭ������
typedef int STDataType;   //Ԫ������

typedef struct Stack
{
	STDataType* _a;  //ָ��ѿռ�
	int _top;		 // ջ��
	int _capacity;   // ���� 
}Stack;

void StackInit(Stack* ps);//��ʼ��ջ
void StackPush(Stack* ps, STDataType data);//��ջ
void StackPop(Stack* ps);//��ջ
STDataType StackTop(Stack* ps);
int StackSize(Stack* ps);//��ȡԪ�ظ���
void StackDestroy(Stack* ps);//�ݻ�ջ

#endif /* _STACT_H_ */