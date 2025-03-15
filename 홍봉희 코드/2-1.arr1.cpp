//2-1. arr1.cpp �ǽ����� 2.1
/*
C ���� ������ ����Ǵ� �޸� ����.

Stack (����) ����: ���� ���� �� �Լ� ȣ��� ���õ� �����Ͱ� ����
Heap (��) ����: malloc, calloc, realloc ���� ����Ͽ� �������� �Ҵ�� �޸�.
Data (������) ����: ���� ���� �� static ������ ����.
Code (�ڵ�) ����: ���� ���� ���α׷� �ڵ�
*/
#include <stdio.h>
#include <stdlib.h>

// ������ ������ �����ϴ� �Լ�
void operationPointer(int arr[], int size) {
    printf("&arr[0] = %p\n", &arr[0]);
    printf("arr = %p\n", arr);

    //C���� ������ ������ �����Ͱ� ����Ű�� ������ Ÿ���� ũ�⸦ ���(�߿�)
    //arr + 1  ==  (char *)arr + sizeof(int)
    printf("arr+1 = %p\n", arr + 1); // �迭�� �ι�° ������ �ּ�
    printf("arr[0] = %d\n", arr[0]);
    printf("*arr = %d\n", *arr);
    printf("*arr+1 = %d\n", *arr + 1);
    printf("*(arr+1) = %d\n\n", *(arr + 1));
}

int main() {
    int odd[5] = { 3, 5, 7, 9, 11 };
    int size = sizeof(odd) / sizeof(odd[0]);

    // ������ ������ �����ϴ� �Լ� ȣ��
    //�迭�� �̸� (odd Ȥ�� arr)�� �迭�� ù ��° ������ �ּҸ� ����Ű�� ������ ���
    operationPointer(odd, size);//�迭 �̸��� �����ͻ�� 
    //odd = &size;
    system("pause");
    return 0;
}
