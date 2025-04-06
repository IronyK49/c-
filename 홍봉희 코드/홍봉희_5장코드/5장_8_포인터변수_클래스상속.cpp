#include <iostream>
#include <cstring>

using namespace std;

// ===================== ���� Ŭ���� =====================
class Vehicle {
protected:
    string licensePlateNumber;
    double engineCapacity;

public:
    Vehicle(const string& plate = "Unknown", double capacity = 0.0)
        : licensePlateNumber(plate), engineCapacity(capacity) {
        cout << "Vehicle ������ ȣ��" << endl;
    }

    virtual void show() {
        cout << "[Vehicle] ��ȣ��: " << licensePlateNumber
            << ", ���� �뷮: " << engineCapacity << "L" << endl;
    }

    virtual ~Vehicle() {
        cout << "Vehicle �Ҹ��� ȣ��" << endl;
    }
};

// ===================== ���� Ŭ���� =====================
class Car : public Vehicle {
private:
    char* manufacturer;
    int speed;

public:
    // �⺻ ������
    Car()
        : Vehicle("Unknown", 0.0), speed(0) {
        manufacturer = new char[8];
        strcpy(manufacturer, "Unknown");
        cout << "Car �⺻ ������ ȣ��" << endl;
    }

    // �Ϲ� ������
    Car(const char* manufacturer, int speed, const string& plate, double capacity)
        : Vehicle(plate, capacity), speed(speed) {
        this->manufacturer = new char[strlen(manufacturer) + 1];
        strcpy(this->manufacturer, manufacturer);
        cout << "Car ������ ȣ��" << endl;
    }

    // ���� ������
    Car(const Car& other)
        : Vehicle(other.licensePlateNumber, other.engineCapacity), speed(other.speed) {
        this->manufacturer = new char[strlen(other.manufacturer) + 1];
        strcpy(this->manufacturer, other.manufacturer);
        cout << "Car ���� ������ ȣ��" << endl;
    }

    // �Ҹ���
    ~Car() override {
        cout << "Car �Ҹ��� ȣ��: " << manufacturer << endl;
        delete[] manufacturer;
    }

    // �������̵��� show �Լ�
    void show() override {
        cout << "[Car] ������: " << manufacturer
            << ", �ӵ�: " << speed << " km/h, "
            << "��ȣ��: " << licensePlateNumber
            << ", ���� �뷮: " << engineCapacity << "L" << endl;
    }
};

// ===================== ���� =====================
int main() {
    const int SIZE = 3;
    Vehicle* vehicles[SIZE];

    vehicles[0] = new Car("Hyundai", 120, "123��4567", 1.6);
    vehicles[1] = new Car("Toyota", 140, "456��7890", 2.0);
    vehicles[2] = new Car("Kia", 100, "789��1234", 1.4);

    cout << "\n=== polymorphism �׽�Ʈ: show() ȣ�� ===" << endl;
    for (int i = 0; i < SIZE; ++i) {
        vehicles[i]->show();  // ���� ���ε� (Car::show)
    }

    cout << "\n=== �޸� ���� ===" << endl;
    for (int i = 0; i < SIZE; ++i) {
        delete vehicles[i];
    }

    int num;
    cin >> num;
    return 0;
}
