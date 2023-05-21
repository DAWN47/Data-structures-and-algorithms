#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct String {
	char s[51];
	int lenth;
}*String,s;
int bf(String a,String b) {
	int i = 1, j = 1;
	while(i<=a->lenth&&j<=b->lenth)
	{
		if (a->s[i]==b->s[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j>b->lenth)
	{
		return i - b->lenth;
	}
	else
	{
		return 0;
	}
}

int* getNext(String s) {
	int i = 1;
	int j = 0;
	int* next = (int*)malloc((s->lenth+1) * sizeof(int));
	next[1] = 0;
	printf(" %d : %d\n", i, j);
	while (i<s->lenth)
	{
		if (j==0||s->s[i]==s->s[j])
		{	i++;
			j++;
			next[i] = j;
			printf(" %d : %d\n", i, j);
		}
		else
		{
			j = next[j];
		}
	}
	return next;
}
int* getNextVal(String s) {
	int i = 1;
	int j = 0;
	int* nextVal = (int*)malloc((s->lenth + 1) * sizeof(int));
	nextVal[1] = 0;
	printf(" %d : %d\n", i, j);
	while (i < s->lenth)
	{
		if (j == 0 || s->s[i] == s->s[j])
		{
			i++;
			j++;
			if (s->s[i]!=s->s[j])
			{
				nextVal[i] = j;
				printf(" %d : %d\n", i, j);
			}
			else
			{
				nextVal[i] = nextVal[j];
				printf(" %d : %d\n", i, nextVal[j]);
			}
			
			
		}
		else
		{
			j = nextVal[j];
		}
	}
	return nextVal;
}    
int KMP(String a, String b) {
	int* next = getNext(b);
	int i = 1, j = 1;
	while (i <= a->lenth && j <= b->lenth)
	{
		if (j==0||a->s[i] == b->s[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j > b->lenth)
	{
		printf("w %d ", i - b->lenth);
		return i - b->lenth;
	}
	else
	{
		return 0;
	}
}
int KMPNextVal(String a, String b) {
	int* next = getNextVal(b);
	int i = 1, j = 1;
	while (i <= a->lenth && j <= b->lenth)
	{
		if (j == 0 || a->s[i] == b->s[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j > b->lenth)
	{
		printf("w %d ", i - b->lenth);
		return i - b->lenth;
	}
	else
	{
		return 0;
	}
}
//int main() {
//	String a = (String)malloc(sizeof(s));
//	scanf("%s", a->s + 1);
//	a->lenth = strlen(a->s + 1);
//	String b = (String)malloc(sizeof(s));
//	scanf("%s", b->s + 1);
//	b->lenth = strlen(b->s + 1);
//	KMP(a, b);
//	printf("\n--------------------\n");
//	KMPNextVal(a, b);
//	
//	return 0;
//}