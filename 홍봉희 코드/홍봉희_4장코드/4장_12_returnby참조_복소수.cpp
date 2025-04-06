#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct complex {
    float real;
    float imaginary;
};

// ������ ����Ͽ� ���Ҽ��� �����ϴ� �Լ� (Pass by Reference�� ��ȯ ���� ����)
void getComplex(complex& c) {
    c.real = (rand() % 100) / 10.0;      // 0.0 ~ 9.9
    c.imaginary = (rand() % 100) / 10.0; // 0.0 ~ 9.9
}

// �� ���� ���Ҽ��� ���ϴ� �Լ� (Pass by Reference & Return by Reference) ���Ҽ� (a+b)+c cascading���� �� �ϰڴ� 
complex& addComplex(const complex& c1, const complex& c2, complex& result) {
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    return result;  // result�� main �Լ����� ����� �����̹Ƿ� ������ ���� ��ȯ ����
}

/*
* complex& addComplex(const complex& c1, const complex& c2) {
*   complex result;
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    return result;  // result�� main �Լ����� ����� �����̹Ƿ� ������ ���� ��ȯ ����
}

*/

// ���Ҽ��� ����ϴ� �Լ� (Pass by Reference)
void showComplex(const complex& c) {
    cout << c.real;
    if (c.imaginary >= 0) cout << " + " << c.imaginary << "i" << endl;
    else cout << " - " << -c.imaginary << "i" << endl;
}

int main() {
    srand(time(0)); // ���� �õ� �ʱ�ȭ

    complex num1, num2, sum; // ���Ҽ� ����ü ����

    // ������ �����Ͽ� ���Ҽ��� ���� (Pass by Reference ���)
    getComplex(num1);
    getComplex(num2);

    // �� ���Ҽ��� ���
    cout << "Complex Number 1: ";
    showComplex(num1);

    cout << "Complex Number 2: ";
    showComplex(num2);

    // �� ���Ҽ��� ���� (Pass by Reference & Return by Reference)
    addComplex(num1, num2, sum);

    // �ջ� ��� ���
    cout << "Sum: ";
    showComplex(sum);

    return 0;
}
