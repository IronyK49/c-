//4-4. reference_variable.cpp    4.3 pointer ������ reference ����

#include <iostream>
using namespace std;
#define COLS 5

// �迭�� ������ �޾� �����ϴ� �Լ�
void update(int* const& rfrn) {
    /*
    * int* const&: const&: ������ �����ϸ� ���� ��ü�� ������ �� ����.
    * int* const: ������ p�� ����Ű�� �ּҴ� ������ �� ����.
    * �Լ� �ȿ��� p = �ٸ� �ּ�; ���� �ڵ�� �����Ǿ� ����
    */
    rfrn[0] = 100; // = *rfrn 
    rfrn[1] = 200; // *(rfrn+1)
}

int main() {
    int a[COLS] = { 10, 11, 12, 13, 14 };

    cout << "<<�Լ� ȣ�� �� a �迭>>" << endl;
    for (int i = 0; i < COLS; i++) {
        cout << "a[" << i << "] = " << a[i] << endl;
    }

    // �迭 a�� ������ ����
    update(a);

    cout << endl << "<<�Լ� ȣ�� �� a �迭>>" << endl;
    for (int i = 0; i < COLS; i++) {
        cout << "a[" << i << "] = " << a[i] << endl;
    }

    cout << endl << "<<reference ���� rfrn ���>>" << endl;
    int* const& rfrn = a;  // �迭�� �ּҸ� const pointer reference�� ����
    rfrn[2] = 300;

    for (int i = 0; i < COLS; i++) {
        cout << "a[" << i << "] = " << a[i] << "\t"
            << "rfrn[" << i << "] = " << rfrn[i] << endl;
    }
    system("pause");
    return 0;
}

