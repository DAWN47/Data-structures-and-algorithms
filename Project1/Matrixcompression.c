#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//对称矩阵压缩
int* SymmetricMatrixCompression(int* p, int n) {
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (i>=j)
			{
				if (p[n*i+j]!=p[n*j+i])
				{
					return NULL;
				}
			}
			
		}
	}
	int* arr = (int*)malloc(((n + 1) * n / 2) * sizeof(int));
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (i>=j)
			{
				arr[((i + 1) * i / 2) + j] = p[n*i+j];
			}
		}
	}
	for (size_t i = 0; i < (n + 1) * n / 2; i++)
	{
		printf(" %d ", arr[i]);
	}
	return arr;
}
//三角矩阵压缩
int* TriangularMatrixCompression(int* arr,int n) {
	//略，与对称矩阵相同，再加个元素为另一半的重复元素
}

//int main() {
//	int arr[5][5] = { 0 };
//	for (size_t i = 0; i < 5; i++)
//	{
//		for (size_t j = 0; j < 5; j++)
//		{
//			if (i>=j)
//			{
//				arr[i][j] = i+1 * j+1;
//				arr[j][i] = arr[i][j];
//			}
//			if ()
//			{
//
//			}
//		}
//	}
//	for (size_t i = 0; i < 5; i++)
//	{
//		for (size_t j = 0; j < 5; j++)
//		{
//			printf(" %d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	SymmetricMatrixCompression(arr, 5);
//	return 0;
//}