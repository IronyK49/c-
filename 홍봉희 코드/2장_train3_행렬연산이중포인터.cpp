//array of pointer 사용 

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

int** addMatrix(int a[][ACOLS], int rows_a, int d[][DROWS], int rows_d);
void getMatrix(int a[][ACOLS], int rows, int cols) {

}


int main() {
    srand(time(NULL));

    int a[AROWS][ACOLS], b[BROWS][BCOLS], d[DROWS][DCOLS]; //stack main frame에 배열생성

    getMatrix(a, AROWS, ACOLS);
    //getMatrix2() 중복 코딩이 필요 > 간결한 코딩 안됨
    getMatrix(b, BROWS, BCOLS);
    getMatrix(d, DROWS, DCOLS);

    printf("Matrix A:\n");
    showMatrix((int**)a, AROWS, ACOLS);
    printf("Matrix B:\n");
    showMatrix((int**)b, BROWS, BCOLS);
    printf("Matrix D:\n");
    showMatrix((int**)d, DROWS, DCOLS);

    // Cascading Addition Example
    int** temp = addMatrix(a, AROWS, d, DROWS); // temp = A + D //이거 연습할것 
    //addMatrix2() 중복 코딩이 필요 > 간결한 코딩 안됨
    int** e = addMatrix(temp, AROWS, a, DROWS); // E = (A + D) + A // 이거도 연습할것 cascading operation 

    printf("Matrix E = ((A + D) + A):\n");
    showMatrix(e, DROWS, DCOLS);

    int(*result2)[CCOLS] = multiplyMatrix(a, AROWS, b, BROWS);
    printf("Matrix C = (A * B):\n");
    showMatrix_c(result2, CROWS);

    int** transResult = transposeMatrix(b, BROWS);
    printf("Transpose Matrix E = transpose(B)\n");
    showMatrix_c(transResult, EROWS);

    int** product = multiplyTransposeMatrix(a, AROWS, transResult, EROWS);
    printf("Matrix product = (A * transpose(B)):\n");
    showMatrix_c(product, CROWS);

    // 메모리 해제
    freeMatrix(temp, DROWS); //해야됨 무조건 할당한 메모리 반환 // free(result[i]) for문 돌리고 result까지 반환 
    freeMatrix(e, DROWS);
    freeMatrix(transResult, BROWS);
    freeMatrix(product, AROWS);
    return 0;
}

int** addMatrix(int a[][ACOLS], int rows_a, int d[][DROWS], int rows_d) {
    int** result = (int**)malloc(rows_a * sizeof(int*));

    for (int i = 0; i < rows_a; i++) {
        result[i] = (int*)malloc(ACOLS * sizeof(int));  
    }
    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < rows_d; j++) {
            result[i][j] = a[i][j] + d[i][j];
        }
    }
    return result;
}// 가르쳐줬으니 써라 시험 나올것 int (*a)[] =/= int **result 호환 안되는거 방법 한번 찾을것 