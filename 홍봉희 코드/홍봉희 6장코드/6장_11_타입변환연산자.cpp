#include <iostream>
#include <cmath>   // std::abs
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    // 기본 생성자
    Complex() : real(0.0f), imag(0.0f) {} // parameter 가 객체가 아니면 벼환 생성자 

    // 비명시적 변환 생성자 (int → Complex)
    Complex(int r) : real(static_cast<float>(r)), imag(0.0f) {
        cout << "비명시적 변환 생성자(int): " << real << " + " << imag << "i" << endl;
    }

    // 명시적 변환 생성자 (float → Complex)
    explicit Complex(float r) : real(std::abs(r)), imag(0.0f) {
        cout << "명시적 변환 생성자(float): " << real << " + " << imag << "i" << endl;
    }

    // 타입 변환 함수: Complex → float // double int 다른것도 가능 하다 
    operator float() const {
        cout << "타입 변환 함수 operator float() 호출됨" << endl;
        return std::abs(real);  // 실수부 절댓값 반환
    }

    void show() const {
        cout << "복소수: " << real << " + " << imag << "i" << endl;
    }
};

// Complex 객체를 매개변수로 받는 함수  // parameter 전달 받아 complex c =19; 와 같이 동작함 complex c(19) 변환생성자가 됨 객체로 만듦
void printComplex(Complex c) {
    cout << "[printComplex] ";
    c.show();
}

int main() {
    // 비명시적 변환 생성자 (int → Complex)
    Complex c1 = -7;    // Complex(int) 호출
    //Complex c1(-7); 위에건 이렇게 됨 변환연산자로 생각해야함 
    Complex c2;

    // 타입 변환 연산자 + std::abs → Complex → float → abs(float)
    Complex c3;
    c3 = std::abs(c1);  // operator float() 호출 → float 반환 → 다시 Complex(int) 생성자 호출 c1은 객첸데 abs에는 실수가 와야함 그래서 객체를 실수로 만들어주는 연산자 자동호출
    //a+b=>a.operator+(b);
    // 출력 확인
    cout << "\n결과 복소수 c3 = abs(c1): ";
    c3.show();

    // 명시적 타입 변환 예제
    Complex c4 = Complex(-3.5f);  // explicit Complex(float) 호출 // 변환생성자 호출 후 복사생성자 생성 

    cout << "\n명시적 타입 변환 c4 = Complex(-3.5f): ";
    c4.show();

    // 함수 호출 시 비명시적 변환
    printComplex(19);  // int → Complex 변환자 자동 호출

    return 0;
}