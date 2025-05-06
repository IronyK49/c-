#include <iostream> 
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // ������  ���迡 ���´��� 
    Complex(double r = 0.0, double i = 0.0) {
        real = r;
        imag = i;
    }

    // ���Ҽ� �� ���Ҽ� ������ �����ε�
    Complex operator*(const Complex& other) const {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }

    // ���Ҽ� �� �Ǽ� (��Į�� ��) ������ �����ε�
    Complex operator*(double scalar) const {
        return Complex(real * scalar, imag * scalar);
    }

    // �Ǽ� �� ���Ҽ� (friend �Լ��� ���� ������ �����ε�) 
    friend Complex operator*(double scalar, const Complex& c) {
        return Complex(c.real * scalar, c.imag * scalar);
    }


    // ��� �Լ�
    void print() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

Complex operator*(double scalar, const Complex& c) {
    return Complex(c.real * scalar, c.imag * scalar);
}

int main() {
    Complex c1(3, 4);   // 3 + 4i
    Complex c2(1, 2);   // 1 + 2i

    Complex result1 = c1 * c2;     // ���Ҽ� ��
    Complex result2 = c1 * 2.0;    // ���Ҽ� * �Ǽ� // 2�� ���̰� ���� �� �̰Ŷ� �Ʒ��Ŷ� ��ü�� �Ǽ� vs �Ǽ�(�⺻������ Ÿ���̶� �ǵ������)�� ��ü 
    Complex result3 = 2.0 * c1;    // �Ǽ� * ���Ҽ� �̷��� �����ִ°� �����ϴ� overloading ���� ���蹮���� ���� 

    cout << "���Ҽ� * ���Ҽ�: ";
    result1.print();  // -5 + 10i

    cout << "���Ҽ� * �Ǽ�: ";
    result2.print();  // 6 + 8i

    cout << "�Ǽ� * ���Ҽ�: ";
    result3.print();  // 6 + 8i

    return 0;
}
