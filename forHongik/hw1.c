/*
Gauss-Jordan elimination
편의상 계수 행렬 arr 각각의 계수를 aij (ex. a00, a01, a02 ...)
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
	scanf("%d", &arraySize); // 1. n by n 행렬을 만들 n 입력

	float **arr; //이차원 배열 동적할당
	arr = (float**)malloc(sizeof(int*) * arraySize);
	for (int i = 0; i < arraySize; i++) {
		arr[i] = (float*)malloc(sizeof(float) * (arraySize + 1));
	}

	printf("input elements : \n"); // 2. 행렬의 모든 요소 입력
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
		printf("n은 2에서 10 사이의 숫자만 입력하세요~");
	}


	///*3. Gauss 소거법*/	
	//
	for (int i = 0; i < arraySize; i++) {
		for (int j = 0; j < (arraySize + 1); j++){
			if (arr[i][0] == 0) { // 3-(1) R1의 첫번째 계수가 0이면 다른 행과 교환
				swap(arraySize, arr, i);
			}
		}
	//
	//	else if (arr[i][0] != 0) { // 3-(1) 0이 아니면 R1에 첫번째 계수의 역수를 곱한다.	
	//		float reverseA00 = 1 / arr[0][0];
	//		for (int j = 0; j < (arraySize + 1); j++) {
	//			arr[0][j] *= reverseA00; // R1에 역수를 곱해 a00을 1로 만들어준다
	//		}

	//		// 3-(2) R1에 R2의 첫번째 계수의 음수값 만큼 곱한 뒤 R2에 더한다. (이때 a10을 0으로 만들어주기 위함)
	//		float multiplyA10 = arr[1][0]; //R2의 첫번째 계수 
	//		for (int j = 0; j < (arraySize + 1); j++) {
	//			arr[1][j] = arr[1][j] + (-multiplyA10) * arr[0][j]; // 새로운 R2 =  기존의 R2 + (-a10) * R1
	//		}

	//		// 3-(3) R1에 R3의 첫번째 계수의 음수값 만큼 곱한 뒤 R3에 더한다. (a20을 0으로 만들어주기 위함)
	//		float multiplyA20 = arr[2][0];
	//		for (int j = 0; j < (arraySize + 1); j++) {
	//			arr[2][j] = arr[2][j] + (-multiplyA20) * arr[0][j]; // 새로운 R3 = 기존의 R3 + (-a20) * R1
	//		}

	//		// 3-(4) R2의 두번째 계수가 1이 아니므로 R2에 a22역수를 곱한다.
	//		float reverseA11 = 1 / arr[1][1];
	//		for (int j = 0; j < (arraySize + 1); j++) {
	//			arr[1][j] *= reverseA11; // R2에 역수를 곱해 a11을 1로 만들어준다
	//		}

	//		// 3-(5) R2에 R3의 두번째 계수의 음수값 만큼 곱한 뒤 R3에 더한다. (a21을 0으로 만들어주기 위함)
	//		float multiplyA22 = arr[2][1];
	//		for (int j = 0; j < (arraySize + 1); j++) {
	//			arr[2][j] = arr[2][j] + (-multiplyA22) * arr[1][j];
	//		}

	//		// 3-(6) R3에 세번째 계수의 역수를 곱한다. (a22를 1로 만들어주기 위함)
	//		float reverseA22 = 1 / arr[2][2];
	//		for (int j = 0; j < (arraySize + 1); j++) {
	//			arr[2][j] *= reverseA22; //R3에 역수를 곱해 a22을 1로 만들어준다
	//		}

	//		/*여기부턴 Gauss-Jordan 소거법*/

	//		// 3-(7) R3에 R2의 세번째 계수의 음수만큼 곱해서 R2에 더한다. (a22를 0으로 만들어주기 위함)
	//		float multiplyA12 = arr[1][2];
	//		for (int j = 0; j < (arraySize + 1); j++) {
	//			arr[1][j] = arr[1][j] + (-multiplyA12)* arr[2][j];
	//		}

	//		// 3-(8) R3에 R1의 세번째 계수의 음수만큼 곱하여 R1에 더한다
	//		float multiplyA02 = arr[0][2];
	//		for (int j = 0; j < (arraySize + 1); j++) {
	//			arr[0][j] = arr[0][j] + (-multiplyA02) * arr[2][j];
	//		}

	//		// 3-(9) R2에 R1의 두번째 계수의 음수만큼 곱하여 R1에 더한다.
	//		float multiplyA01 = arr[0][1];
	//		for (int j = 0; j < (arraySize + 1); j++) {
	//			arr[0][j] = arr[0][j] + (-multiplyA01) * arr[1][j];
	//		}
	//	}

	//}

	
	
	
	//결과 출력 행렬은 0과 1로만, 결과값은 소숫점 여섯째까지
	printf("output result : \n");
	for (int i = 0; i < arraySize; i++) {
		for (int j = 0; j < (arraySize + 1); j++) {
			if (j != arraySize) {
				printf("%d ", (int)arr[i][j]); // output은 0과 1 정수로 나타내기 위해
			} else if (j == arraySize)
			printf("%f ", arr[i][j]); // result은 소숫점 여섯째까지 나타내기 위해
		}
		printf("\n");
	}

	free(arr); // 동적 메모리 할당 해제
}
	

/*R1의 첫번째 계수가 0일때 R2와 행 교환하는 함수 */
void swap(int arraySize, float **arr, int i) { 	
	for (int j = 0; j < (arraySize + 1); j++) {
		float temp = arr[i][j];
		arr[i][j] = arr[i+1][j];
		arr[i + 1][j] = temp;
	}
}


void gaussElimination(float **arr, int arraySize) {
	float reverse; // aii를 1로 만들어주는 변수 (ex. a11, a22, a33... 행렬의 대각선을 1로 만들어준다고 해서 일명 대각선 변수)
	float elimination; // 첫번째 행부터 n-1번째 행까지 대각선 빼고 모두 0으로 소거해주는 변수. 소거하고자 하는 계수값의 음수값을 전 행의 대각선변수에 곱해서 더해줘서 0으로 만들어준다

	for (int i = 0; i < arraySize; i++) {
		if (arr[i][i] != 1) {
			for (int j = 0; j < (arraySize + 1); j++) {
				reverse = 1 / arr[i][i];
				arr[i][j] = arr[i][j] * reverse; //여기까지 aii 1로 만들기
				
				for (int k = i + 1; k < arraySize; k++) {
					elimination = arr[k][j]; //소거해주는 상수는 소거하고자하는 행의 계수에 음수값 곱한걸 바로 전 행에 곱한것
					arr[k][j] = arr[k][j] - (arr[i][j] * elimination);
				}		
			}
		}			
	}
}

void gaussJordanElimination(float **arr, int arraySize) {
	float elimination; // 가우스 소거법과 방법은 동일한데 이번엔 행의 맨 끝 밑에서 위로, 오른쪽에서 왼쪽으로

	for (int i = (arraySize - 1); i > 0; i--) { //2 /1
		for (int j = (arraySize - 1); j > 0; j--) { //2 /1
			for (int k = i - 1; k >= 0; k--) { //1,0 /0
				elimination = arr[k][j];
				arr[k][j] = arr[k][j] - (arr[i][j] * elimination);
			}
		}
	}
}