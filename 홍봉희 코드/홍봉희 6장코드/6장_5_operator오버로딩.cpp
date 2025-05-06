#include <iostream> 
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // 생성자  시험에 나온다잉 
    Complex(double r = 0.0, double i = 0.0) {
        real = r;
        imag = i;
    }

    // 복소수 × 복소수 연산자 오버로딩
    Complex operator*(const Complex& other) const {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }

    // 복소수 × 실수 (스칼라 곱) 연산자 오버로딩
    Complex operator*(double scalar) const {
        return Complex(real * scalar, imag * scalar);
    }

    // 실수 × 복소수 (friend 함수로 전역 연산자 오버로딩) 
    friend Complex operator*(double scalar, const Complex& c) {
        return Complex(c.real * scalar, c.imag * scalar);
    }


    // 출력 함수
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

    Complex result1 = c1 * c2;     // 복소수 곱
    Complex result2 = c1 * 2.0;    // 복소수 * 실수 // 2개 차이가 많이 남 이거랑 아래거랑 객체에 실수 vs 실수(기본데이터 타입이라 건들수없음)에 객체 
    Complex result3 = 2.0 * c1;    // 실수 * 복소수 이렇게 나와있는걸 구현하는 overloading 구현 시험문제에 나옴 

    cout << "복소수 * 복소수: ";
    result1.print();  // -5 + 10i

    cout << "복소수 * 실수: ";
    result2.print();  // 6 + 8i

    cout << "실수 * 복소수: ";
    result3.print();  // 6 + 8i

    return 0;
}
