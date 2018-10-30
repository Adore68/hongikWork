/*
Gauss-Jordan elimination
�̻���� �ð��� ��� ���콺���� �ҰŹ��� �ǽ��غ��ϴ�

@author : ������(B471008)
@date : 2018.10.31
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void swap(float **arr, int arraySize, int row1, int row2);
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

	if (arraySize >= 2 && arraySize <= 10) { // 3. ����1 : n�� 2<=n<=10 ���̸�	
		for (int i = 0; i < arraySize; i++) { 
			for (int j = i+1; j < arraySize; j++) {
				if (arr[i][0] == 0) {  // 4. ����2 : R1�� ù��° ����� 0�� ��� �ٸ� ��� swap 
					swap(arr, arraySize, i, j);
				}
			}
		}

		gaussElimination(arr, arraySize); // 5. ���콺 elimination
		gaussJordanElimination(arr, arraySize); // 6. ���콺���� elimination
	}
	else {
		printf("n�� 2���� 10 ������ ���ڸ� �����մϴ�. �ٽ� �Է��ϼ���~");
	}

	printf("output result : \n"); // 7. ������
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
	

/*R1�� ù��° ����� 0�϶� �ٸ� �� ��ȯ�ϴ� �Լ� */
void swap(float **arr, int arraySize, int row1, int row2) {
	for (int j = 0; j < (arraySize + 1); j++) {
		int temp = arr[row1][j];
		arr[row1][j] = arr[row2][j];
		arr[row2][j] = temp;

	}
}


/*���콺 elimination
@param float reverse - ����� �밢���� 1�� ������ֱ� ���� ����
@param float elimination - ù��° ����� n��° ����� �밢�� ���� ��� 0���� �Ұ����ִ� ����
*/
void gaussElimination(float **arr, int arraySize) {
	float reverse; 
	float elimination; 

	for (int i = 0; i < arraySize; i++) {	
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

/*���콺���� elimination
���콺 eliminatio�� ������ �ϸ� ���콺���� elmination
*/
void gaussJordanElimination(float **arr, int arraySize) {
	float elimination; // ���콺 �ҰŹ��� ����� �����ѵ� �̹��� ���� �� �� �ؿ��� ����, �����ʿ��� ��������

	for (int i = (arraySize - 1); i > 0; i--) { 
		for (int j = (arraySize - 1); j > 0; j--) { 
			for (int k = i - 1; k >= 0; k--) { 
				elimination = arr[k][j];
				arr[k][j] = arr[k][j] - (arr[i][j] * elimination);
			}
		}
	}
}