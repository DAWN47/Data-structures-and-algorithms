#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MaxLenth 100;
#define bool int
#define true 1
#define false 0
typedef struct Data {
	int a;
}data;

typedef struct Stack
{
	data* top;
	data* base;
	int maxLenth;
}Node,*Stack;
Stack createStack() {
	Stack stack = (Stack)malloc(sizeof(Node));
	if (!stack)
	{
		printf("ÉêÇë¿Õ¼ä³ö´í");
		exit(0);
	}
	stack->maxLenth = MaxLenth;
	stack->base = (data*)malloc(stack->maxLenth * sizeof(data));
	stack->top = stack->base;
	return stack;
	
}
bool StackIsEmtpy(Stack stack){
	return stack->base == stack->top;
}
bool clearStack(Stack stack) {
	stack->top = stack->base;
	return true;
}

Stack destroyStack(Stack stack) {
	free(stack->base);
	stack->base = stack->top = NULL;
	free(stack);
	stack = NULL;
	return NULL;
	
}
bool push(Stack s) {
	if (s->top-s->base==s->maxLenth)
	{
		return false;
	}
	printf("------------");
	scanf("%d", &(s->top->a));
	s->top++;
	return true;
}

data* getTop(Stack s) {
	if (s->top<=s->base)
	{
		return NULL;
	}
	return --s->top;
}
//int main() {
//	Stack stack = createStack();
//	bool b= StackIsEmtpy(stack);
//	printf("%d",b);
//	push(stack);
//	push(stack);
//	printf(" %d ", stack->base->a);
//	bool c = StackIsEmtpy(stack);
//	printf("%d", c);
//	data* d = getTop(stack);
//	printf(" %d ", d->a);
//	 d = getTop(stack);
//	printf(" %d ", d->a);
//	printf(" %d ", StackIsEmtpy(stack));
//	destroyStack(stack);
//	return 0;
//}