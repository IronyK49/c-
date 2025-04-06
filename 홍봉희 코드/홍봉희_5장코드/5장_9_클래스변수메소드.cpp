#include <iostream>
#include <cstring>

using namespace std;

class Car {
private:
    char* manufacturer;
    int speed;

    static int count;

public:
    static int getCarCount() {
        return count;
    }

    Car() {
        manufacturer = new char[8];
        strcpy(manufacturer, "Unknown");
        speed = 0;
        ++count;
        cout << "Default Constructor ȣ��" << endl;
    }

    Car(const char* manufacturer, int speed) {
        this->manufacturer = new char[strlen(manufacturer) + 1];
        strcpy(this->manufacturer, manufacturer);
        this->speed = speed;
        ++count;
        cout << "Parameterized Constructor ȣ��" << endl;
    }

    Car(const Car& other) {
        this->manufacturer = new char[strlen(other.manufacturer) + 1];
        strcpy(this->manufacturer, other.manufacturer);
        this->speed = other.speed;
        ++count;
        cout << "Copy Constructor ȣ��" << endl;
    }

    ~Car() {
        cout << "Destructor ȣ��: " << manufacturer << endl;
        delete[] manufacturer;
        --count;
    }

    Car& setManufacturer(const char* manufacturer) {
        delete[] this->manufacturer;
        this->manufacturer = new char[strlen(manufacturer) + 1];
        strcpy(this->manufacturer, manufacturer);
        return *this;
    }

    Car& setSpeed(int speed) {
        this->speed = speed;
        return *this;
    }

    void showCars() const {
        cout << "������: " << manufacturer
            << ", �ӵ�: " << speed << " km/h"
            << ", ���� Car ��ü ��: " << count << endl;
    }
};

int Car::count = 0;

// ===================== main =====================
int main() {
    const int SIZE = 5;

    // Car ��ü �迭�� ������ ������ ���� (heap�� �迭 ����)
    Car* carSet = new Car[SIZE]; // Default Constructor 5�� ȣ���

    // �Ϻ� ��ü ���� ���� �� ���
    carSet[0].setManufacturer("Hyundai").setSpeed(100);
    carSet[1].setManufacturer("Toyota").setSpeed(120);
    carSet[2].setManufacturer("Kia").setSpeed(90);

    cout << "\n=== carSet[i].showCars() ===" << endl;
    for (int i = 0; i < SIZE; ++i) {
        carSet[i].showCars();  // ��ü ���� �� ��ü ��ü �� ���
    }

    cout << "\n���� ��ü Car ��ü ��: " << Car::getCarCount() << endl;

    // �޸� ����
    delete[] carSet;  // ��� ��ü�� �Ҹ��� �ڵ� ȣ���

    cout << "Car ��ü ��� ���� �� ��: " << Car::getCarCount() << endl;

    return 0;
}
