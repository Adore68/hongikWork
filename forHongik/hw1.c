/*
Gauss-Jordan elimination
���ǻ� ��� ��� arr ������ ����� aij (ex. a00, a01, a02 ...)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void swap(int arraySize, int row1, int row2);

int main() {
	int arraySize;

	printf("Matirx size: ");
	scanf("%d", &arraySize); // 1. n by n ����� ���� n �Է�

	double **arr; //������ �迭 �����Ҵ�
	arr = (double**)malloc(sizeof(int*) * arraySize);
	for (int i = 0; i < arraySize; i++) {
		arr[i] = (double*)malloc(sizeof(double) * (arraySize + 1));
	}

	printf("input elements : \n"); // 2. ����� ��� ��� �Է�
	for (int i = 0; i < arraySize; i++) {
		for (int j = 0; j < (arraySize + 1); j++) {
			scanf("%lf", &arr[i][j]);
		}
	}

	/*3. Gauss �ҰŹ�*/	
	if (arr[0][0] == 0) { // 3-(1) R1�� ù��° ����� 0�̸� R2 ��� ��ȯ�ϰ�
		for (int j = 0; j < (arraySize+1); j++) {
			swap(arraySize, arr[0][j], arr[1][j]);
		}		
	}
	else if (arr[0][0] != 0) { // 3-(1) 0�� �ƴϸ� R1�� ù��° ����� ������ ���Ѵ�.	
		double reverseA00 = 1 / arr[0][0];
		for (int j = 0; j < (arraySize + 1); j++) {
			arr[0][j] *= reverseA00; // R1�� ������ ���� a00�� 1�� ������ش�
		}

		// 3-(2) R1�� R2�� ù��° ����� ������ ��ŭ ���� �� R2�� ���Ѵ�. (�̶� a10�� 0���� ������ֱ� ����)
		double multiplyA10 = arr[1][0]; //R2�� ù��° ��� 
		for (int j = 0; j < (arraySize + 1); j++) {
			arr[1][j] = arr[1][j] + (-multiplyA10) * arr[0][j]; // ���ο� R2 =  ������ R2 + (-a10) * R1
		}

		// 3-(3) R1�� R3�� ù��° ����� ������ ��ŭ ���� �� R3�� ���Ѵ�. (a20�� 0���� ������ֱ� ����)
		double multiplyA20 = arr[2][0];
		for (int j = 0; j < (arraySize + 1); j++) {
			arr[2][j] = arr[2][j] + (-multiplyA20) * arr[0][j]; // ���ο� R3 = ������ R3 + (-a20) * R1
		}

		// 3-(4) R2�� �ι�° ����� 1�� �ƴϹǷ� R2�� a22������ ���Ѵ�.
		double reverseA11 = 1 / arr[1][1];
		for (int j = 0; j < (arraySize + 1); j++) {
			arr[1][j] *= reverseA11; // R2�� ������ ���� a11�� 1�� ������ش�
		}

		// 3-(5) R2�� R3�� �ι�° ����� ������ ��ŭ ���� �� R3�� ���Ѵ�. (a21�� 0���� ������ֱ� ����)
		double multiplyA22 = arr[2][1];
		for (int j = 0; j < (arraySize + 1); j++) {
			arr[2][j] = arr[2][j] + (-multiplyA22) * arr[1][j];
		}

		// 3-(6) R3�� ����° ����� ������ ���Ѵ�. (a22�� 1�� ������ֱ� ����)
		double reverseA22 = 1 / arr[2][2];
		for (int j = 0; j < (arraySize + 1); j++) {
			arr[2][j] *= reverseA22; //R3�� ������ ���� a22�� 1�� ������ش�
		}

		/*������� Gauss-Jordan �ҰŹ�*/

		// 3-(7) R3�� R2�� ����° ����� ������ŭ ���ؼ� R2�� ���Ѵ�. (a22�� 0���� ������ֱ� ����)
		double multiplyA12 = arr[1][2];
		for (int j = 0; j < (arraySize + 1); j++) {
			arr[1][j] = arr[1][j] + (-multiplyA12)* arr[2][j];
		}

		// 3-(8) R3�� R1�� ����° ����� ������ŭ ���Ͽ� R1�� ���Ѵ�
		double multiplyA02 = arr[0][2];
		for (int j = 0; j < (arraySize + 1); j++) {
			arr[0][j] = arr[0][j] + (-multiplyA02) * arr[2][j];
		}

		// 3-(9) R2�� R1�� �ι�° ����� ������ŭ ���Ͽ� R1�� ���Ѵ�.
		double multiplyA01 = arr[0][1];
		for (int j = 0; j < (arraySize + 1); j++) {
			arr[0][j] = arr[0][j] + (-multiplyA01) * arr[1][j];
		}

	}
	//��� ���
	printf("Output result : \n");
	for (int i = 0; i < arraySize; i++) {
		for (int j = 0; j < (arraySize + 1); j++) {
			printf("%lf ", arr[i][j]);
		}
		printf("\n");
	}

	free(arr); // ���� �޸� �Ҵ� ����
}
	

/*R1�� ù��° ����� 0�϶� R2�� �� ��ȯ�ϴ� �Լ� */
void swap(int arraySize, int row1, int row2) { 	
		int temp = row1;
		row1 = row2;
		row2 = temp;
}