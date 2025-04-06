

#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string manufacturer;
    string licensePlate;
    int speed;

    static int count;

public:
    Car() {
        manufacturer = "Unknown";
        licensePlate = "None";
        speed = 0;
        ++count;
        cout << "Default Constructor ȣ��" << endl;
    }

    Car(string manufacturer, string licensePlate, int speed) {
        this->manufacturer = manufacturer;
        this->licensePlate = licensePlate;
        this->speed = speed;
        ++count;
        cout << "Parameterized Constructor ȣ��" << endl;
    }

    ~Car() {
        cout << "Destructor ȣ��: " << manufacturer << " (" << licensePlate << ")" << endl;
        --count;
    }

    // setters
    Car& setManufacturer(const string& m) {
        manufacturer = m;
        return *this;
    }

    Car& setLicensePlate(const string& l) {
        licensePlate = l;
        return *this;
    }

    Car& setSpeed(int s) {
        speed = s;
        return *this;
    }

    void show() const {
        cout << "������: " << manufacturer
            << ", ��ȣ��: " << licensePlate
            << ", �ӵ�: " << speed << " km/h"
            << ", ��ü ��ü ��: " << count << endl;
    }

    static int getCount() {
        return count;
    }
};

// static ���� ����
int Car::count = 0;

// ===================== main =====================
int main() {
    const int SIZE = 3;
    Car* carSet = new Car[SIZE];  // ���� Car ��ü �迭 ����

    carSet[0].setManufacturer("Hyundai").setLicensePlate("12��3456").setSpeed(100);
    carSet[1].setManufacturer("Toyota").setLicensePlate("78��9012").setSpeed(120);
    carSet[2].setManufacturer("Kia").setLicensePlate("34��5678").setSpeed(90);

    cout << "\n=== Car ��ü ���� ��� ===" << endl;
    for (int i = 0; i < SIZE; ++i) {
        carSet[i].show();
    }

    cout << "\n���� ��ü Car ��ü ��: " << Car::getCount() << endl;

    delete[] carSet;  // �Ҹ��� �ڵ� ȣ��

    cout << "\n��ü ���� �� ��: " << Car::getCount() << endl;

    return 0;
}
