#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//Gauss-Jordan elimination 구현하기
int main() {
	int arraySize; 

	printf("Matirx size: ");
	scanf("%d", &arraySize); // n 개의 행렬

	int **arr; //이차원 배열 동적할당
	arr = (int**)malloc(sizeof(int*) * arraySize);
	for (int i = 0; i < arraySize; i++) {
		arr[i] = (int*)malloc(sizeof(int) * (arraySize + 1));
	}

	printf("input elements : \n"); //행렬의 모든 요소 입력
	for (int i = 0; i < arraySize; i++) {
		for (int j = 0; j < (arraySize + 1); j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	
}