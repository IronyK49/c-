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
        cout << real << "_+_" << imaginary << "_i";
    }

    void printWithMagnitude() const {
        print();
        cout << "_(magnitude:_" << fixed << setprecision(2) << magnitude() << ")";
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

float randomFloat() {
    return static_cast<float>(rand()) / RAND_MAX * 10.0f;
}

void generateComplex(Complex* table[], int size) {
    for (int i = 0; i < size; ++i) {
        float real = randomFloat();
        float imag = randomFloat();
        table[i] = new Complex(real, imag);
    }
}

Complex sumComplex(Complex* table[], int size) {
    Complex sum;
    for (int i = 0; i < size; ++i) {
        sum = sum.add(*table[i]);
    }
    return sum;
}

Complex multiplyComplex(Complex* table[], int size) {
    Complex product(1.0, 0.0);
    for (int i = 0; i < size; ++i) {
        product = product.multiply(*table[i]);
    }
    return product;
}

void sortComplexByMagnitude(Complex* table[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (table[j]->getMagnitude() > table[j + 1]->getMagnitude()) {
                swap(table[j], table[j + 1]);
            }
        }
    }
}

void showComplexWithMagnitude(Complex* table[], int size) {
    for (int i = 0; i < size; ++i) {
        table[i]->printWithMagnitude();
        cout << endl;
    }
}

void freeTable(Complex* table[], int size) {
    for (int i = 0; i < size; ++i) {
        delete table[i];
    }
}

int main() {
    int seed = 41;
    srand(seed);

    const int N = 5;
    Complex* table[N];

    generateComplex(table, N);

    cout << "Complex_Numbers:" << endl;
    for (int i = 0; i < N; ++i) {
        table[i]->print();
        cout << endl;
    }
    cout << "..." << endl << endl;

    Complex sum = sumComplex(table, N);
    cout << "Sum:_";
    sum.print();
    cout << endl;

    Complex product = multiplyComplex(table, N);
    cout << "Product:__";
    product.print();
    cout << endl << endl;

    sortComplexByMagnitude(table, N);
    cout << "Sorted_by_Magnitude:" << endl;
    showComplexWithMagnitude(table, N);
    cout << "..." << endl;

    freeTable(table, N);
    return 0;
}
