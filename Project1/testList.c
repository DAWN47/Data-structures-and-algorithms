#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct data
{
	int a;
	int b;
}data;
typedef struct List
{
	data a;
	struct List* next;
}Node,* List;
List creatList();
void addANode(List head);
void addBNode(List head);
void deleteNode(List head);
void selectAll(List head);
void addNode (List head);
List mergeList(List a, List b);
List newPolynomial();
void selectPolynomial(List head);
List addPolynomial(List a, List b);
List test() {
	List a = (List)malloc(12);
	printf("%d", sizeof(a));
	a->next = NULL;
	free(a);
	return a;
}
//int main() {
//	//List a = newPolynomial();
//	/*List b = newPolynomial();*/
//	/*List c= addPolynomial(a, b);
//	a->next= NULL;
//	free(a);
//	a = NULL;
//	selectPolynomial(c)*/;
//	List a = (List)malloc(sizeof (Node));
//	printf("%d ,%d", sizeof (Node),sizeof(a));
//	return 0;
//}


List newPolynomial() {
	List p = creatList();
	Node* pa = p;
	while (1)
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		if (newNode == NULL)
		{
			printf("申请空间出错");
			exit(0);
		}
		newNode->next = NULL;
		printf("请输入依次输入多项式的系数与指数：\n");
		scanf("%d%d", &(newNode->a.a), &(newNode->a.b));
		pa->next = newNode;
		pa = pa->next;
		printf("若停止输入请按T\n");
		getchar();
		if (getchar() == 'T')
		{
			break;
		}
	}
	return p;
}

void selectPolynomial(List head) {
	List pa = head;
	while (pa = pa->next)
	{
		printf(" %dX的%d次方 ", pa->a.a, pa->a.b);
	}
	printf("\n-----------------------\n");
}

List addPolynomial(List p1, List p2) {

	Node* po = p1->next;
	Node* pt = p2->next;
	List out = creatList();
	Node* o = out;
	while (po&&pt)
	{
		if (po->a.b>po->a.b)
		{
			o->next = po;
			po = po->next;
			o = o->next;
		}
		else if(po->a.b<pt->a.b)
		{
			o->next = po;
			po = po->next;
			o = o->next;
		}
		else
		{
			if (po->a.a+pt->a.a!=0)
			{
				po->a.a = po->a.a + pt->a.a;
				o->next = po;
				po = po->next;
				pt = pt->next;
				o = o->next;
			}
			else
			{
				po = po->next;
				pt = pt->next;
			}
		}
	}
	o->next = po ? po : pt;
	p1->next = NULL;
	p2->next = NULL;
	free(p1);
	free(p2);
	return out;
}



//创建链表
List creatList() {
	List list = (List)malloc(sizeof(Node));
	if (list==NULL)
	{
		printf("申请空间出错");
		exit(0);
	}
	list->next = NULL;
	return list;
}

void addANode(List head) {
	static int i = 1;
	Node* pa = head;
	while (pa->next) {
		pa = pa->next;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode==NULL)
	{
		printf("申请空间出错");
		exit(0);
	}
	newNode->next = NULL;
	newNode->a.a = i++;
	pa->next = newNode;
}
void addNode(List head) {
	Node* pa = head;
	while (pa->next) {
		pa = pa->next;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("申请空间出错");
		exit(0);
	}
	newNode->next = NULL;
	printf("请输入");
	scanf("%d", &(newNode->a.a));
	pa->next = newNode;
}

void addBNode(List head) {
	static int i = 1;
	Node* pa = head;
	while (pa->next) {
		pa = pa->next;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("申请空间出错");
		exit(0);
	}
	newNode->next = NULL;
	newNode->a.a = i++;
	pa->next = newNode;
}

void deleteNode(List head) {

}
void selectAll(List head) {
	List pa = head;
	while (pa=pa->next)
	{
		printf(" %d ", pa->a.a);
	}
	printf("\n-----------------------\n");
}

List mergeList(List a, List b) {
	List c = creatList();
	Node* pa=a->next;
	Node* pb=b->next;
	Node* pc = c;
	while(pa && pb) {
		if (pa->a.a>pb->a.a)
		{
			pc->next = pb;
			pb = pb->next;
			pc = pc->next;

		}
		else
		{
			pc->next = pa;
			pa = pa->next;
			pc = pc->next;

		}
	}
	 pc->next = pa ? pa : pb;
	 return c;

}
