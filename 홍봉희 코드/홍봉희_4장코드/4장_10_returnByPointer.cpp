#include <iostream>
using namespace std;

// �迭 �����͸� �޾� ������ ��ȯ
int* value(int* ptr, int n);

int main() {
    int a[] = { 10, 20, 30, 40, 50 };
    // ���� ���������� value(a, 2) = 60; �� ����������,
    // ������ ���������� *value(a, 2) = 60; ���� ����ؾ� ��
    *value(a, 2) = 60;
    *value(a, 4) = 70;

    for (int i = 0; i < 5; i++)
        cout << "a[" << i << "] = " << a[i] << endl;

    system("pause");
    return 0;
}

int* value(int* ptr, int n) {
    return  &ptr[n];  // �Ǵ�ptr + n;
}
