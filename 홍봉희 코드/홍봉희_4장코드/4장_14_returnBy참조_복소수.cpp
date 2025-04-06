//4��-12. Cascade.cpp   4.4.4 reference�� ���� �Լ� return ��
// return by reference�� �������� ��ʷμ� 6�� ���� �н��� �ֿ� ���
//4�忡���� �ܼ� �����Ͽ� ���� ������ �ǽ��� - 4���� �ǽ� ���� ����� �ƴ� /������ �ڵ��� 
#include <iostream>

using namespace std;

class Complex {
private:
    float real;
    float imaginary;
public:
    Complex() { real = 0.0; imaginary = 0.0; }
    Complex(float r, float i) : real(r), imaginary(i) { }

    void showComplex() const {
        cout << real << " + " << imaginary << "i" << endl;
    }

    // add() �Լ� (Return by Reference)
    Complex& add(const Complex& T);
};

// add() �Լ� ���� (Return by Reference)
Complex& Complex::add(const Complex& T) {
    //Complex result;
    this->imaginary = this->imaginary + T.imaginary;
    this->real = this->real + T.real;
    cout << "add(const Complex&):: ";
    this->showComplex();
    return *this;
    //return result;//���� �߻�
}

int main(void) {
    Complex C1(1.1, 2.2);
    cout << "C1 = "; C1.showComplex();

    Complex C2(3.3, 4.4);
    cout << "C2 = "; C2.showComplex();

    Complex C3(7.7, 9.9);
    cout << "C3 = "; C3.showComplex();

    Complex C4;

    // ������ �����ε� ��� add() �Լ� ���
    C4 = C1.add(C2).add(C3); // �̰� ���迡 ���´��� 

    cout << "C4 = "; C4.showComplex();

    system("pause");
    return 0;
}

