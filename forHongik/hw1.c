/*
Gauss-Jordan elimination
���ǻ� ��� ��� arr ������ ����� aij (ex. a00, a01, a02 ...)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void swap(int arraySize, float **arr, int i);
void gaussElimination(float **arr, int arraySize);
void gaussJordanElimination(float **arr, int arraySize);

int main() {
	int arraySize;

	printf("Matirx size: ");
	scanf("%d", &arraySize); // 1. n by n ����� ���� n �Է�

	float **arr; //������ �迭 �����Ҵ�
	arr = (float**)malloc(sizeof(int*) * arraySize);
	for (int i = 0; i < arraySize; i++) {
		arr[i] = (float*)malloc(sizeof(float) * (arraySize + 1));
	}

	printf("input elements : \n"); // 2. ����� ��� ��� �Է�
	for (int i = 0; i < arraySize; i++) {
		for (int j = 0; j < (arraySize+1); j++) {
			scanf("%f", &arr[i][j]);
		}
	}

	if (arraySize >= 2 && arraySize <= 10) {


		gaussElimination(arr, arraySize);
		gaussJordanElimination(arr, arraySize);
	}
	else {
		printf("n�� 2���� 10 ������ ���ڸ� �Է��ϼ���~");
	}


	///*3. Gauss �ҰŹ�*/	
	//
	for (int i = 0; i < arraySize; i++) {
		for (int j = 0; j < (arraySize + 1); j++){
			if (arr[i][0] == 0) { // 3-(1) R1�� ù��° ����� 0�̸� �ٸ� ��� ��ȯ
				swap(arraySize, arr, i);
			}
		}
	//
	//	else if (arr[i][0] != 0) { // 3-(1) 0�� �ƴϸ� R1�� ù��° ����� ������ ���Ѵ�.	
	//		float reverseA00 = 1 / arr[0][0];
	//		for (int j = 0; j < (arraySize + 1); j++) {
	//			arr[0][j] *= reverseA00; // R1�� ������ ���� a00�� 1�� ������ش�
	//		}

	//		// 3-(2) R1�� R2�� ù��° ����� ������ ��ŭ ���� �� R2�� ���Ѵ�. (�̶� a10�� 0���� ������ֱ� ����)
	//		float multiplyA10 = arr[1][0]; //R2�� ù��° ��� 
	//		for (int j = 0; j < (arraySize + 1); j++) {
	//			arr[1][j] = arr[1][j] + (-multiplyA10) * arr[0][j]; // ���ο� R2 =  ������ R2 + (-a10) * R1
	//		}

	//		// 3-(3) R1�� R3�� ù��° ����� ������ ��ŭ ���� �� R3�� ���Ѵ�. (a20�� 0���� ������ֱ� ����)
	//		float multiplyA20 = arr[2][0];
	//		for (int j = 0; j < (arraySize + 1); j++) {
	//			arr[2][j] = arr[2][j] + (-multiplyA20) * arr[0][j]; // ���ο� R3 = ������ R3 + (-a20) * R1
	//		}

	//		// 3-(4) R2�� �ι�° ����� 1�� �ƴϹǷ� R2�� a22������ ���Ѵ�.
	//		float reverseA11 = 1 / arr[1][1];
	//		for (int j = 0; j < (arraySize + 1); j++) {
	//			arr[1][j] *= reverseA11; // R2�� ������ ���� a11�� 1�� ������ش�
	//		}

	//		// 3-(5) R2�� R3�� �ι�° ����� ������ ��ŭ ���� �� R3�� ���Ѵ�. (a21�� 0���� ������ֱ� ����)
	//		float multiplyA22 = arr[2][1];
	//		for (int j = 0; j < (arraySize + 1); j++) {
	//			arr[2][j] = arr[2][j] + (-multiplyA22) * arr[1][j];
	//		}

	//		// 3-(6) R3�� ����° ����� ������ ���Ѵ�. (a22�� 1�� ������ֱ� ����)
	//		float reverseA22 = 1 / arr[2][2];
	//		for (int j = 0; j < (arraySize + 1); j++) {
	//			arr[2][j] *= reverseA22; //R3�� ������ ���� a22�� 1�� ������ش�
	//		}

	//		/*������� Gauss-Jordan �ҰŹ�*/

	//		// 3-(7) R3�� R2�� ����° ����� ������ŭ ���ؼ� R2�� ���Ѵ�. (a22�� 0���� ������ֱ� ����)
	//		float multiplyA12 = arr[1][2];
	//		for (int j = 0; j < (arraySize + 1); j++) {
	//			arr[1][j] = arr[1][j] + (-multiplyA12)* arr[2][j];
	//		}

	//		// 3-(8) R3�� R1�� ����° ����� ������ŭ ���Ͽ� R1�� ���Ѵ�
	//		float multiplyA02 = arr[0][2];
	//		for (int j = 0; j < (arraySize + 1); j++) {
	//			arr[0][j] = arr[0][j] + (-multiplyA02) * arr[2][j];
	//		}

	//		// 3-(9) R2�� R1�� �ι�° ����� ������ŭ ���Ͽ� R1�� ���Ѵ�.
	//		float multiplyA01 = arr[0][1];
	//		for (int j = 0; j < (arraySize + 1); j++) {
	//			arr[0][j] = arr[0][j] + (-multiplyA01) * arr[1][j];
	//		}
	//	}

	//}

	
	
	
	//��� ��� ����� 0�� 1�θ�, ������� �Ҽ��� ����°����
	printf("output result : \n");
	for (int i = 0; i < arraySize; i++) {
		for (int j = 0; j < (arraySize + 1); j++) {
			if (j != arraySize) {
				printf("%d ", (int)arr[i][j]); // output�� 0�� 1 ������ ��Ÿ���� ����
			} else if (j == arraySize)
			printf("%f ", arr[i][j]); // result�� �Ҽ��� ����°���� ��Ÿ���� ����
		}
		printf("\n");
	}

	free(arr); // ���� �޸� �Ҵ� ����
}
	

/*R1�� ù��° ����� 0�϶� R2�� �� ��ȯ�ϴ� �Լ� */
void swap(int arraySize, float **arr, int i) { 	
	for (int j = 0; j < (arraySize + 1); j++) {
		float temp = arr[i][j];
		arr[i][j] = arr[i+1][j];
		arr[i + 1][j] = temp;
	}
}


void gaussElimination(float **arr, int arraySize) {
	float reverse; // aii�� 1�� ������ִ� ���� (ex. a11, a22, a33... ����� �밢���� 1�� ������شٰ� �ؼ� �ϸ� �밢�� ����)
	float elimination; // ù��° ����� n-1��° ����� �밢�� ���� ��� 0���� �Ұ����ִ� ����. �Ұ��ϰ��� �ϴ� ������� �������� �� ���� �밢�������� ���ؼ� �����༭ 0���� ������ش�

	for (int i = 0; i < arraySize; i++) {
		if (arr[i][i] != 1) {
			for (int j = 0; j < (arraySize + 1); j++) {
				reverse = 1 / arr[i][i];
				arr[i][j] = arr[i][j] * reverse; //������� aii 1�� �����
				
				for (int k = i + 1; k < arraySize; k++) {
					elimination = arr[k][j]; //�Ұ����ִ� ����� �Ұ��ϰ����ϴ� ���� ����� ������ ���Ѱ� �ٷ� �� �࿡ ���Ѱ�
					arr[k][j] = arr[k][j] - (arr[i][j] * elimination);
				}		
			}
		}			
	}
}

void gaussJordanElimination(float **arr, int arraySize) {
	float elimination; // ���콺 �ҰŹ��� ����� �����ѵ� �̹��� ���� �� �� �ؿ��� ����, �����ʿ��� ��������

	for (int i = (arraySize - 1); i > 0; i--) { //2 /1
		for (int j = (arraySize - 1); j > 0; j--) { //2 /1
			for (int k = i - 1; k >= 0; k--) { //1,0 /0
				elimination = arr[k][j];
				arr[k][j] = arr[k][j] - (arr[i][j] * elimination);
			}
		}
	}
}