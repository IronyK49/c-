#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 10;
//������ 10 ~ 60 ���̿� ���� (ù��° ��������) (�Լ��� ���� �迭 ����)
void inputData(int data[], int size) {
    srand(time(0));
    
    //rand() % 50;
}



void swap(int arr[], int ind1, int ind2) {
 
}

void sortData(int *data, int SIZE) {//�迭�� �����ͷ� �޴´�.
    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (*(data+i) > data[j]) {
                swap(data, i, j);
            }
        }
    }
}

// c��� �޸� ���� 1. code 2.data 3.stack(local) 4.heap(�޸��Ҵ�)
// c���� parameter passing call by value �⺻

/*
 * ���̵��� �ſ� ���� �˰��� ����
 * ���ĵ� ���� �迭�� ���� ���� �߰��ϴ� �˰��� > �� �迭�� ũ��� ���� �迭���� +1�� ����� ���� �迭�� copy�� ��
 * ���Ե� ���� �߰��� ���� �˰��� �����ϱ�
 * O(n) �˰������� ����
 */
int* insertData(int data[], int size, int value) {
    int* newData = new int[size + 1];// �Լ� �����Ŀ��� ���� �־� delete[] �ʿ�

    return newData;
}
int* insertData(char/Student *data[], int size, int value) {
    int* newData = new int[size + 1];// �Լ� �����Ŀ��� ���� �־� delete[] �ʿ�

    return newData;
}


int arr[10] = { 1,2,3,4, };
int main() {
    int data[SIZE]; //data[]�� ���ú��� >> localize �Ѵ� 
    inputData(data, SIZE);
    showData("���� �Է�", data, SIZE);

    swap(data, i, j); //data[i], data[j]�� �¹ٲٶ�
    sortData(data, SIZE);//data��� �ּ� ����� ���� - ������ 
    showData("������", data, SIZE);

    reverse(data, SIZE);
    showData("\n���� ���ġ", data, SIZE);

    maxSort(data, SIZE);

    sortData(data, SIZE);
    showData("\n ������", data, SIZE);

    int realData[] = { 5, 15, 99 };
    for (int newData : realData) {
        int* result = insertData(data, SIZE, newData);
        cout << "\n\n" << newData << " : ";
        showData("�Ǽ� ������", result, SIZE + 1);
        delete[] result;
    }
    system("pause");
    return 0;
}
