#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

class Complex {
private:
    float real;
    float imaginary;

    float magnitude() const {
        return sqrt(real * real + imaginary * imaginary);
    }

public:
    Complex(float r = 0.0, float i = 0.0) {
        real = r;
        imaginary = i;
    }

    void print() const {
        cout << fixed << setprecision(2);
        cout << real << " + " << imaginary << " i";
    }

    void printWithMagnitude() const {
        print();
        cout << " (magnitude: " << fixed << setprecision(2) << magnitude() << ")";
    }

    Complex add(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex multiply(const Complex& other) const {
        float r = real * other.real - imaginary * other.imaginary;
        float i = real * other.imaginary + imaginary * other.real;
        return Complex(r, i);
    }

    float getMagnitude() const {
        return magnitude();
    }
};

// 난수 생성 함수
float randomFloat() {
    return static_cast<float>(rand()) / RAND_MAX * 10.0f;
}

// 복소수 배열 생성
void generateComplex(Complex* table[], int size) {
    for (int i = 0; i < size; ++i) {
        float real = randomFloat();
        float imag = randomFloat();
        table[i] = new Complex(real, imag);
    }
}

// 복소수 출력
void showComplex(Complex* table[], int size) {
    for (int i = 0; i < size; ++i) {
        table[i]->print();
        cout << endl;
    }
}

// 크기와 함께 출력
void showComplexWithMagnitude(Complex* table[], int size) {
    for (int i = 0; i < size; ++i) {
        table[i]->printWithMagnitude();
        cout << endl;
    }
}

// 합산
Complex sumComplex(Complex* table[], int size) {
    Complex sum;
    for (int i = 0; i < size; ++i) {
        sum = sum.add(*table[i]);
    }
    return sum;
}

// 곱셈
Complex multiplyComplex(Complex* table[], int size) {
    Complex product(1.0, 0.0);
    for (int i = 0; i < size; ++i) {
        product = product.multiply(*table[i]);
    }
    return product;
}

// 정렬
void sortComplexByMagnitude(Complex* table[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (table[j]->getMagnitude() > table[j + 1]->getMagnitude()) {
                swap(table[j], table[j + 1]);
            }
        }
    }
}

// 메모리 해제
void freeTable(Complex* table[], int size) {
    for (int i = 0; i < size; ++i) {
        delete table[i];
    }
}

enum Menu {
    ShowComplex = 1,
    Sum,
    Product,
    Sort,
    EXIT
};

int main() {
    int seed, command;
    cin >> seed >> command;
    srand(seed);

    const int N = 5;
    Complex* table[N];
    generateComplex(table, N);

    switch (command) {
    case ShowComplex:
        cout << "Complex Numbers:" << endl;
        showComplex(table, N);
        break;

    case Sum: {
        Complex sum = sumComplex(table, N);
        cout << "Sum: ";
        sum.print();
        cout << endl;
        break;
    }

    case Product: {
        Complex product = multiplyComplex(table, N);
        cout << "Product: ";
        product.print();
        cout << endl;
        break;
    }
    case Sort:
        sortComplexByMagnitude(table, N);
        cout << "Sorted by Magnitude: " << endl;
        showComplexWithMagnitude(table, N);
        break;

    case EXIT:
        cout << "Program terminated:" << endl;
        break;

    default:
        cout << "Invalid command: " << endl;
        break;
    }

    freeTable(table, N);
    return 0;
}
