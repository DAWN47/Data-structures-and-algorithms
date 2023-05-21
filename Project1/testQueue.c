#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define max 3
typedef struct Data {
	int a;
}data;

typedef struct Queue {
	data* queue;
	int rear;
	int front;
}qNode,*queue;

queue createQueue() {
	queue q = (queue)malloc(sizeof(qNode));
	if (!q)
	{
		exit(0);
	}
	q->queue = (queue)malloc((max+1) * sizeof(data));
	if (!q->queue)
	{
		exit(0);
	}
	q->rear = q->front = 0;
}
int queueIsEmtpy(queue q){
	if (q->front==q->rear)
	{
		printf("队列是空哒\n");
		return 1;
	}
	return 0;
}
void entryQueue(queue q) {
	if ((q->rear+1)%(max+1)==q->front)
	{
		printf("队列满了\n");
		return;
	}
	q->queue[q->rear].a = 56;
	q->rear = (q->rear + 1) % (max+1);
}
void outQueue(queue q) {
	if (queueIsEmtpy(q)==1)
	{
		return;
	}
	data d = q->queue[q->front];
	q->front = (q->front + 1) % (max+1);
	printf(" %d ", d.a);
}
//int main() {
//	queue q = createQueue();
//	outQueue(q);
//	queueIsEmtpy(q);
//	entryQueue(q);
//	entryQueue(q);
//	entryQueue(q);
//	entryQueue(q);
//	outQueue(q);
//	outQueue(q);
//	outQueue(q);
//	entryQueue(q);
//	entryQueue(q);
//	entryQueue(q);
//	outQueue(q);
//	return 0;
//}