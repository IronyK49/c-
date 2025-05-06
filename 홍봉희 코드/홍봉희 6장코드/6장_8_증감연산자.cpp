#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    // ������
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // ������ ++ ������ �����ε� (++a)
    Complex& operator++() {
        ++real;
        ++imag;
        cout << "������ ++ ������ ȣ���" << endl;
        return *this;
    }

    // ������ ++ ������ �����ε� (a++)
    Complex operator++(int) {
        Complex temp = *this;  // ���� ���� ����
        real++;
        imag++;
        cout << "������ ++ ������ ȣ���" << endl;
        return temp;  // ���� �� ���� ��ȯ
    }

    // ��� �Լ�
    void print() const {
        cout << "(" << real << " + " << imag << "i)" << endl;
    }
};

int main() {
    Complex a(1, 2);

    cout << "�ʱⰪ: ";
    a.print();

    cout << "\n������ ++a ����:\n";
    (++a).print();  // ����: ���� ���� �� ���

    cout << "\n������ a++ ����:\n";
    (a++).print();  // ����: ���� ��� �� ����

    cout << "\n������ ���� ����:\n";
    a.print();  // ������ ���� ���� Ȯ��

    return 0;
}
