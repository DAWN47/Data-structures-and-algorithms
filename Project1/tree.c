#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct Data {
	char a;
}data;

typedef struct TNode {
	struct TNode* parent;
	struct TNode* Lchild;
	struct TNode* Rchild;
	data a;
}TNode,*Tree;

Tree createTree() {
	Tree t = (Tree)malloc(sizeof(TNode));
	if (!t)
	{
		exit(0);
	}
	t->parent = NULL;
	t->Lchild = NULL;
	t->Rchild = NULL;
	return t;
}
void vist(Tree t) {
	printf("%c\n", t->a);
}
void traverseFirst(Tree t) {
	if (t)
	{
		vist(t);
		traverseFirst(t->Lchild);
		traverseFirst(t->Rchild);
	}
}
void midOrderTraversal(Tree t) {
	if (t)
	{
		midOrderTraversal(t->Lchild);
		vist(t);
		midOrderTraversal(t->Rchild);
	}
}
void postOrderTraversal(Tree t) {
	if (t)
	{
		postOrderTraversal(t->Lchild);
		postOrderTraversal(t->Rchild);
		vist(t);
	}
}

Tree createTNode() {
	Tree t = (Tree)malloc(sizeof(TNode));
	if (!t)
	{
		exit(0);
	}
	t->parent = NULL;
	t->Lchild = NULL;
	t->Rchild = NULL;
	return t;
}
Tree constructTree(Tree t) {
	char input;
	scanf("%c", &input);
	getchar();
	if (input=='#')
	{
		t = NULL;
	}
	else
	{
		t->a.a = input;
		t->Lchild = createTNode();
		if (!constructTree(t->Lchild))
		{
			free(t->Lchild);
			t->Lchild = NULL;
		}
		t->Rchild = createTNode();
		if (!constructTree(t->Rchild))
		{
			free(t->Rchild);
			t->Rchild = NULL;
		}
	}
	return t;
}
int higth(Tree t) {
	int L = 0, R = 0;
	if (t==NULL)
	{
		return 0;
	}
	else
	{
		L = higth(t->Lchild);
		R = higth(t->Rchild);
	}
	return L > R ? L + 1 : R + 1;
}

int getNodeNumber(Tree t) {
	int L = 0, R = 0;
	if (t==NULL)
	{
		return 0;
	}
	else
	{
		L = getNodeNumber(t->Lchild);
		R = getNodeNumber(t->Rchild);
	}
	return L + R + 1;
}
int getLeafNodes(Tree t) {
	static int i = 0;
	if (t==NULL)
	{
		return 0;
	}
	else {
		if (t->Lchild==NULL&&t->Rchild==NULL)
		{
			i++;
		}
		else
		{
			getLeafNodes(t->Lchild);
			getLeafNodes(t->Rchild);
		}
	}
	return i;
}
int getNodeNumber1(Tree t) {
	static int i = 0;
	if (t)
	{
		i++;
		getNodeNumber1(t->Lchild);
		getNodeNumber1(t->Rchild);
	}
	return i;
}
typedef struct a {
	int* a;
}b, * a;

int main() {
	/*Tree t = createTree();
	t->a.a = 1;
	t->Lchild = createTree();
	t->Rchild = createTree();
	t->Lchild->a.a = 2;
	t->Rchild->a.a = 3;
	t->Lchild->Lchild = createTree();
	t->Lchild->Lchild->a.a = 4;
	postOrderTraversal(t);*/

	/*Tree t = createTree();
	constructTree(t);
	traverseFirst(t);
	
	printf(" %d ", getLeafNodes(t));*/
	printf("%ld", ~0x0000);
	return 0;
 }