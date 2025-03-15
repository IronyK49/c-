#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 10;
//난수를 10 ~ 60 사이에 생성 (첫번째 난수생성) (함수를 만들어서 배열 전달)
void inputData(int data[], int size) {
    srand(time(0));
    
    //rand() % 50;
}



void swap(int arr[], int ind1, int ind2) {
 
}

void sortData(int *data, int SIZE) {//배열을 포인터로 받는다.
    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (*(data+i) > data[j]) {
                swap(data, i, j);
            }
        }
    }
}

// c언어 메모리 영역 1. code 2.data 3.stack(local) 4.heap(메모리할당)
// c에서 parameter passing call by value 기본

/*
 * 난이도가 매우 높은 알고리즘 구현
 * 정렬된 기존 배열에 임의 값을 추가하는 알고리즘 > 새 배열의 크기는 기존 배열보다 +1로 만들고 기존 배열을 copy할 때
 * 삽입된 값이 중간에 들어가는 알고리즘 구현하기
 * O(n) 알고리즘으로 구현
 */
int* insertData(int data[], int size, int value) {
    int* newData = new int[size + 1];// 함수 종료후에도 남아 있어 delete[] 필요

    return newData;
}
int* insertData(char/Student *data[], int size, int value) {
    int* newData = new int[size + 1];// 함수 종료후에도 남아 있어 delete[] 필요

    return newData;
}


int arr[10] = { 1,2,3,4, };
int main() {
    int data[SIZE]; //data[]는 로컬변수 >> localize 한다 
    inputData(data, SIZE);
    showData("난수 입력", data, SIZE);

    swap(data, i, j); //data[i], data[j]을 맞바꾸라
    sortData(data, SIZE);//data라는 주소 상수를 전달 - 값으로 
    showData("정렬후", data, SIZE);

    reverse(data, SIZE);
    showData("\n역순 재배치", data, SIZE);

    maxSort(data, SIZE);

    sortData(data, SIZE);
    showData("\n 정렬후", data, SIZE);

    int realData[] = { 5, 15, 99 };
    for (int newData : realData) {
        int* result = insertData(data, SIZE, newData);
        cout << "\n\n" << newData << " : ";
        showData("실수 삽입후", result, SIZE + 1);
        delete[] result;
    }
    system("pause");
    return 0;
}
