#include <iostream>
using namespace std;

// forward ���� (��ȣ ���� ���� �ʿ�)
class ComplexB;

class ComplexA {
private:
    float real, imag;

public:
    ComplexA(float r = 0.0, float i = 0.0) : real(r), imag(i) {}

    // ComplexB �� ComplexA ��ȯ ������
    ComplexA(const ComplexB& b);

    // ComplexB �� ComplexA ���� ������
    ComplexA& operator=(const ComplexB& b);

    float getReal() const { return real; }
    float getImag() const { return imag; }

    void print() const {
        cout << "[A] " << real << " + " << imag << "i\n";
    }
};

class ComplexB {
private:
    float real, imag;

public:
    ComplexB(float r = 0.0, float i = 0.0) : real(r), imag(i) {}

    // ComplexA �� ComplexB ��ȯ ������
    ComplexB(const ComplexA& a) {
        real = a.getReal();
        imag = a.getImag();
        cout << "ComplexB ��ȯ ������ ȣ���\n";
    }

    // ComplexA �� ComplexB ���� ������
    ComplexB& operator=(const ComplexA& a) {
        real = a.getReal();
        imag = a.getImag();
        cout << "ComplexB ��ȯ ������ ȣ���\n";
        return *this;
    }

    float getReal() const { return real; }
    float getImag() const { return imag; }

    void print() const {
        cout << "[B] " << real << " + " << imag << "i\n";
    }
};

// ComplexA ��� �Լ� ���� (ComplexB ���� ���Ŀ�)
ComplexA::ComplexA(const ComplexB& b) {
    real = b.getReal();
    imag = b.getImag();
    cout << "ComplexA ��ȯ ������ ȣ���\n";
}

ComplexA& ComplexA::operator=(const ComplexB& b) {
    real = b.getReal();
    imag = b.getImag();
    cout << "ComplexA ��ȯ ������ ȣ���\n";
    return *this;
}

int main() {
    ComplexA a(1.0, 2.0);
    ComplexB b(3.0, 4.0);

    cout << "\n--- �ʱ� ���� ---\n";
    a.print();
    b.print();

    cout << "\n--- a = b ȣ�� ---\n";
    a = b; // ComplexB �� ComplexA

    cout << "\n--- b = a ȣ�� ---\n";
    b = a; // ComplexA �� ComplexB

    cout << "\n--- ���� ���� ---\n";
    a.print();
    b.print();

    return 0;
}