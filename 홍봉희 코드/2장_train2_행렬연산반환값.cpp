/*
2차원 배열을 함수로 전달하여 함수에서 계산하여 전달하는 방식
int (*data)[](pointer to array) 로 전달하여 함수의 결과를 리턴하는 구현 - static int[][](array of pointer)를 사용하여 구현
메모리 동적 사용 안하고 문제 해결 가능할까?
=> 중복 코딩 발생: 간결한 코딩 개선이 필요
*/

//c++ : cascading operation : add(add(a,b),c) = a와 b 행렬을 더한 행렬에 c를 더함 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define AROWS 3
#define ACOLS 4
#define BROWS 4
#define BCOLS 5
#define CROWS 3
#define CCOLS 5
#define DROWS 3
#define DCOLS 4
#define EROWS 3
#define ECOLS 4

void getMatrix(int matrix[][ACOLS], int rows);
void getMatrix_b(int matrix[][BCOLS], int rows);
void showMatrix(int matrix[][ACOLS], int rows);
void showMatrix_b(int matrix[][BCOLS], int rows);
void showMatrix_c(int matrix[][CCOLS], int rows);
int (*addMatrix(int a1[][ACOLS], int rows1, int a2[][ACOLS], int rows2))[ACOLS]; //pointer to array 

int(*multiplyMatrix(int a[][ACOLS], int rows_a, int b[][BCOLS], int rows_b))[CCOLS];
int(*transposeMatrix(int b[][BCOLS], int rows_b))[ECOLS];
int(*multiplyTransposeMatrix(int a[][ACOLS], int rows_a, int(*e)[ECOLS], int rows_e))[CCOLS];

int main() {
    srand(42);//seed 값이 주어지면 난수 생성 결과가 항상 같게 만들어짐

    int a[AROWS][ACOLS], a2[AROWS][ACOLS], b[BROWS][BCOLS], c[CROWS][CCOLS], d[DROWS][DCOLS], e[DROWS][DCOLS];

    getMatrix(a, AROWS);
    getMatrix(a2, AROWS);

    printf("Matrix A1:\n");
    showMatrix(a, AROWS);

    printf("Matrix A1:\n");
    showMatrix(a2, AROWS);

    int(*result)[ACOLS] = addMatrix(a, AROWS, a2, AROWS);
    printf("Matrix E = A + A2:\n");

    printf("Matrix Result:\n");
    showMatrix(result, AROWS);

    int(*result2)[ACOLS] = addMatrix(result, AROWS, a2, AROWS);
    printf("Matrix Result2:\n");
    showMatrix(result2, AROWS);

    //곱셈
    getMatrix_b(b, BROWS);
    printf("Matrix B:\n");
    showMatrix_b(b, BROWS);
    int(*result2)[CCOLS] = multiplyMatrix(a, AROWS, b, BROWS);
    printf("Matrix C = (A * B):\n");
    showMatrix_c(result2, CROWS);

    int(*transResult)[BROWS] = transposeMatrix(b, BROWS);
    printf("Transpose Matrix E = transpose(B)\n");
    showMatrix_c(transResult, EROWS);

    int(*product)[CCOLS] = multiplyTransposeMatrix(a, AROWS, transResult, EROWS);
    printf("Matrix product = (A * transpose(B)):\n");
    showMatrix_c(product, CROWS);

    system("pause");
    return 0;
}

int(*addMatrix(int a1[][ACOLS], int rows1, int a2[][ACOLS], int rows2))[ACOLS] {//return 값은 (*a)[]
    //함수 반환값이 int(*)[]형태
    int (*result)[ACOLS]; // static int result[AROWS][ACOLS] -> 함수가 끝나면 사라짐(static 사용 : 함수 끝나도 안사라짐) 
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < rows2; j++) {
            result[i][j] = a1[i][j] + a2[i][j];
        }
    }
    return result; 
}