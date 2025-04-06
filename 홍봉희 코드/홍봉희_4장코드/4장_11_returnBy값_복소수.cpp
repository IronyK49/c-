#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct complex {
    float real;
    float imaginary;
};

// ������ ����Ͽ� ���Ҽ��� �����ϴ� �Լ� (Call by Value ��ȯ)
complex getComplex() {
    complex c;
    c.real = (rand() % 100) / 10.0;      // 0.0 ~ 9.9
    c.imaginary = (rand() % 100) / 10.0; // 0.0 ~ 9.9
    return c;
}

// �� ���� ���Ҽ��� ���ϴ� �Լ� (Call by Value)
complex addComplex(complex c1, complex c2) {
    complex result;
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    return result;
}

// ���Ҽ��� ����ϴ� �Լ�
void showComplex(complex c) {
    cout << c.real;
    if (c.imaginary >= 0) cout << " + " << c.imaginary << "i" << endl;
    else cout << " - " << -c.imaginary << "i" << endl;
}

int main() {
    srand(time(0)); // ���� �õ� �ʱ�ȭ

    // �� ���� ���Ҽ��� ������ ����
    complex num1 = getComplex();
    complex num2 = getComplex();

    // �� ���Ҽ��� ���
    cout << "Complex Number 1: ";
    showComplex(num1);

    cout << "Complex Number 2: ";
    showComplex(num2);

    // �� ���Ҽ��� ����
    complex sum = addComplex(num1, num2);

    // �ջ� ��� ���
    cout << "Sum: ";
    showComplex(sum);

    return 0;
}
