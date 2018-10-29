/*
Gauss-Jordan elimination
편의상 계수 행렬 arr 각각의 계수를 aij (ex. a00, a01, a02 ...)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void swap(int arraySize, int row1, int row2);

int main() {
	int arraySize;

	printf("Matirx size: ");
	scanf("%d", &arraySize); // 1. n by n 행렬을 만들 n 입력

	double **arr; //이차원 배열 동적할당
	arr = (double**)malloc(sizeof(int*) * arraySize);
	for (int i = 0; i < arraySize; i++) {
		arr[i] = (double*)malloc(sizeof(double) * (arraySize + 1));
	}

	printf("input elements : \n"); // 2. 행렬의 모든 요소 입력
	for (int i = 0; i < arraySize; i++) {
		for (int j = 0; j < (arraySize + 1); j++) {
			scanf("%lf", &arr[i][j]);
		}
	}

	/*3. Gauss 소거법*/	
	if (arr[0][0] == 0) { // 3-(1) R1의 첫번째 계수가 0이면 R2 행과 교환하고
		for (int j = 0; j < (arraySize+1); j++) {
			swap(arraySize, arr[0][j], arr[1][j]);
		}		
	}
	else if (arr[0][0] != 0) { // 3-(1) 0이 아니면 R1에 첫번째 계수의 역수를 곱한다.	
		double reverseA00 = 1 / arr[0][0];
		for (int j = 0; j < (arraySize + 1); j++) {
			arr[0][j] *= reverseA00; // R1에 역수를 곱해 a00을 1로 만들어준다
		}

		// 3-(2) R1에 R2의 첫번째 계수의 음수값 만큼 곱한 뒤 R2에 더한다. (이때 a10을 0으로 만들어주기 위함)
		double multiplyA10 = arr[1][0]; //R2의 첫번째 계수 
		for (int j = 0; j < (arraySize + 1); j++) {
			arr[1][j] = arr[1][j] + (-multiplyA10) * arr[0][j]; // 새로운 R2 =  기존의 R2 + (-a10) * R1
		}

		// 3-(3) R1에 R3의 첫번째 계수의 음수값 만큼 곱한 뒤 R3에 더한다. (a20을 0으로 만들어주기 위함)
		double multiplyA20 = arr[2][0];
		for (int j = 0; j < (arraySize + 1); j++) {
			arr[2][j] = arr[2][j] + (-multiplyA20) * arr[0][j]; // 새로운 R3 = 기존의 R3 + (-a20) * R1
		}

		// 3-(4) R2의 두번째 계수가 1이 아니므로 R2에 a22역수를 곱한다.
		double reverseA11 = 1 / arr[1][1];
		for (int j = 0; j < (arraySize + 1); j++) {
			arr[1][j] *= reverseA11; // R2에 역수를 곱해 a11을 1로 만들어준다
		}

		// 3-(5) R2에 R3의 두번째 계수의 음수값 만큼 곱한 뒤 R3에 더한다. (a21을 0으로 만들어주기 위함)
		double multiplyA22 = arr[2][1];
		for (int j = 0; j < (arraySize + 1); j++) {
			arr[2][j] = arr[2][j] + (-multiplyA22) * arr[1][j];
		}

		// 3-(6) R3에 세번째 계수의 역수를 곱한다. (a22를 1로 만들어주기 위함)
		double reverseA22 = 1 / arr[2][2];
		for (int j = 0; j < (arraySize + 1); j++) {
			arr[2][j] *= reverseA22; //R3에 역수를 곱해 a22을 1로 만들어준다
		}

		/*여기부턴 Gauss-Jordan 소거법*/

		// 3-(7) R3에 R2의 세번째 계수의 음수만큼 곱해서 R2에 더한다. (a22를 0으로 만들어주기 위함)
		double multiplyA12 = arr[1][2];
		for (int j = 0; j < (arraySize + 1); j++) {
			arr[1][j] = arr[1][j] + (-multiplyA12)* arr[2][j];
		}

		// 3-(8) R3에 R1의 세번째 계수의 음수만큼 곱하여 R1에 더한다
		double multiplyA02 = arr[0][2];
		for (int j = 0; j < (arraySize + 1); j++) {
			arr[0][j] = arr[0][j] + (-multiplyA02) * arr[2][j];
		}

		// 3-(9) R2에 R1의 두번째 계수의 음수만큼 곱하여 R1에 더한다.
		double multiplyA01 = arr[0][1];
		for (int j = 0; j < (arraySize + 1); j++) {
			arr[0][j] = arr[0][j] + (-multiplyA01) * arr[1][j];
		}

	}
	//결과 출력
	printf("Output result : \n");
	for (int i = 0; i < arraySize; i++) {
		for (int j = 0; j < (arraySize + 1); j++) {
			printf("%lf ", arr[i][j]);
		}
		printf("\n");
	}

	free(arr); // 동적 메모리 할당 해제
}
	

/*R1의 첫번째 계수가 0일때 R2와 행 교환하는 함수 */
void swap(int arraySize, int row1, int row2) { 	
		int temp = row1;
		row1 = row2;
		row2 = temp;
}