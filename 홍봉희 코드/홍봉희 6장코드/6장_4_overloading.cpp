#include <iostream>//�����ε� ���迡 ���´���
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // ������
    Complex(double r = 0.0, double i = 0.0) {
        real = r;
        imag = i;
    }

    // [1] ���Ҽ� �� ���Ҽ�
    Complex multiply(const Complex& other) const {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }

    // [2] ���Ҽ� �� �Ǽ� (��Į�� ��)
    Complex multiply(double factor) const {
        return Complex(real * factor, imag * factor);
    }

    // ��� ���
    void print() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4);          // 3 + 4i
    Complex c2(1, 2);          // 1 + 2i

    Complex result1 = c1.multiply(c2);   // ���Ҽ� ����
    Complex result2 = c1.multiply(2.0);  // �Ǽ� �� ����

    cout << "���Ҽ� * ���Ҽ� ���: ";
    result1.print(); // (3+4i)*(1+2i) = -5 + 10i

    cout << "���Ҽ� * 2�� ���: ";
    result2.print(); // 6 + 8i

    return 0;
}
