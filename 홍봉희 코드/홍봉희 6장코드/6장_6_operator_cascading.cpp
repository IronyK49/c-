﻿#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    // 생성자
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    Complex(const Complex& b) {
        real = b.real;
        imag = b.imag;
        cout << "복사생성자호출" << endl;
    }
    // 복소수 곱셈 오버로딩
    Complex operator*(const Complex& other) const { //여기서 참조를 쓰면 어뜨케 되는가?(참조변수와 포인터는 항상 추적해야함) 
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);  // ✅ 새 객체를 반환해야 b*c*d 가능
    }

    // 출력
    void print() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex b(2, 3);   // 2 + 3i
    Complex c(1, -4);  // 1 - 4i
    Complex d(0, 2);   // 0 + 2i

    Complex result1 = b * c;      // 2 + 3i * 1 - 4i
    Complex result2 = b * c * d;  // Cascading 연산: (b*c) * d // 구현할 수 있어야 함 알겟제?

    cout << "b * c = ";
    result1.print();

    cout << "b * c * d = ";
    result2.print();

    return 0;
}
