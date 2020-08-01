#include "stack.h"


int main()
{
	//¡¥’ª≤‚ ‘
	LinkStack st;//∂®“ÂΩ·ππÃÂ÷∏’Î
	LinkStackNodeInit(&st);
	LinkStackPush(&st, 1);
	LinkStackPush(&st, 2);
	LinkSTDataType x1 = LinkStackTop(st);
	LinkStackPop(&st);
	LinkStackPush(&st, 3);
	LinkStackPush(&st, 4);
	LinkSTDataType x2 = LinkStackTop(st);
	LinkStackPop(&st);
	LinkSTDataType x3 = LinkStackTop(st);
	LinkStackDestroy(&st);


	//À≥–Ú’ª≤‚ ‘
	//Stack s;
	//StackInit(&s);
	//StackPush(&s, 1);
	//StackPush(&s, 2);
	//StackPush(&s, 3);
	//int a = StackTop(&s);
	//StackPush(&s, 4);
	//StackPop(&s);
	//StackPop(&s);
	//StackPush(&s, 6);
	//StackPush(&s, 8);
	//int b = StackTop(&s);
	//StackPop(&s);
	//int size = StackSize(&s);
	//printf("size = %d\n", size);
	//StackDestroy(&s);

	system("pause");
	return 0;
}