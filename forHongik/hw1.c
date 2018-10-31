/*
Gauss-Jordan elimination
이산수학 시간에 배운 가우스조던 소거법을 실습해봅니다

@author : 김지현(B471008)
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

	if (arraySize >= 2 && arraySize <= 10) { // 3. 조건1 : n은 2<=n<=10 사이만	
		ㅜfor (int i = 0; i < arraySize; i++) { 
			for (int j = i+1; j < arraySize; j++) {
				if (arr[i][0] == 0) {  // 4. 조건2 : R1의 첫번째 계수가 0일 경우 다른 행과 swap 
					swap(arr, arraySize, i, j);
				}
			}
		}

		gaussElimination(arr, arraySize); // 5. 가우스 elimination
		gaussJordanElimination(arr, arraySize); // 6. 가우스조던 elimination
	}
	else {
		printf("n은 2에서 10 사이의 숫자만 가능합니다. 다시 입력하세요~");
	}

	printf("output result : \n"); // 7. 결과출력
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
	

/*R1의 첫번째 계수가 0일때 다른 행 교환하는 함수 */
void swap(float **arr, int arraySize, int row1, int row2) {
	for (int j = 0; j < (arraySize + 1); j++) {
		int temp = arr[row1][j];
		arr[row1][j] = arr[row2][j];
		arr[row2][j] = temp;

	}
}


/*가우스 elimination
@param float reverse - 행렬의 대각선을 1로 만들어주기 위한 변수
@param float elimination - 첫번째 행부터 n번째 행까지 대각선 빼고 모두 0으로 소거해주는 변수
*/
void gaussElimination(float **arr, int arraySize) {
	float reverse; 
	float elimination; 

	for (int i = 0; i < arraySize; i++) {	
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

/*가우스조던 elimination
가우스 elimination을 역으로 하면 가우스조던 elmination
*/
void gaussJordanElimination(float **arr, int arraySize) {
	float elimination; // 가우스 소거법과 방법은 동일한데 이번엔 행의 맨 끝 밑에서 위로, 오른쪽에서 왼쪽으로

	for (int i = (arraySize - 1); i > 0; i--) { 
		for (int j = (arraySize - 1); j > 0; j--) { 
			for (int k = i - 1; k >= 0; k--) { 
				elimination = arr[k][j];
				arr[k][j] = arr[k][j] - (arr[i][j] * elimination);
			}
		}
	}
}
