#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//Gauss-Jordan elimination �����ϱ�
int main() {
	int arraySize; 

	printf("Matirx size: ");
	scanf("%d", &arraySize); // n ���� ���

	int **arr; //������ �迭 �����Ҵ�
	arr = (int**)malloc(sizeof(int*) * arraySize);
	for (int i = 0; i < arraySize; i++) {
		arr[i] = (int*)malloc(sizeof(int) * (arraySize + 1));
	}

	printf("input elements : \n"); //����� ��� ��� �Է�
	for (int i = 0; i < arraySize; i++) {
		for (int j = 0; j < (arraySize + 1); j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	
}