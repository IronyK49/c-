//6��_1_�޼ҵ�����������.cpp

#include <iostream>
#include <cstring>

using namespace std;

class Car {
private:
    char* manufacturer;
    int speed;

    static int count;

    // [1] Private �޼��� �߰�: �ӵ� ��ȿ�� �˻�
    bool isValidSpeed(int speed) const {
        return speed >= 0 && speed <= 300;
    }

public:
    // [3] Getter �޼���
    const char* getManufacturer() const {
        return manufacturer;
    }

    int getSpeed() const {
        return speed;
    }

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

    // [2] Private �޼��� ȣ�� ����
    Car& setSpeed(int speed) {
        if (isValidSpeed(speed)) {
            this->speed = speed;
        }
        else {
            cout << "��ȿ���� ���� �ӵ��Դϴ�. (0~300 km/h)\n";
            this->speed = 0;  // �⺻��
        }
        return *this;
    }

    void showCars() const {
        cout << "������: " << manufacturer
            << ", �ӵ�: " << speed << " km/h"
            << ", ���� Car ��ü ��: " << count << endl;
    }
    void compareSpeed(const Car& other) const;
};
void Car::compareSpeed(const Car& other) const {
    if (this->speed > other.speed)
        cout << manufacturer << "�� " << other.getManufacturer() << "���� �����ϴ�.\n";
    else if (this->speed < other.speed)
        cout << manufacturer << "�� " << other.getManufacturer() << "���� �����ϴ�.\n";
    else
        cout << manufacturer << "�� " << other.getManufacturer() << "�� �ӵ��� �����ϴ�.\n";
}

int Car::count = 0;

int main() {
    const int SIZE = 5;

    Car* carSet = new Car[SIZE]; // Default Constructor 5�� ȣ��

    carSet[0].setManufacturer("����").setSpeed(100);
    carSet[1].setManufacturer("���Ÿ").setSpeed(120);
    carSet[2].setManufacturer("���").setSpeed(-50);  // ��ȿ���� ���� �ӵ� �� ��� ���

    cout << "\n=== carSet[i].showCars() ===" << endl;
    for (int i = 0; i < SIZE; ++i) {
        carSet[i].showCars();
    }

    cout << "\n���� ��ü Car ��ü ��: " << Car::getCarCount() << endl;

    //[�߰�] Getter ��� ����
    cout << "\n--- Getter �޼��� ��� ���� ---\n";
    cout << "carSet[0] ������: " << carSet[0].getManufacturer() << endl;
    cout << "carSet[1] �ӵ�: " << carSet[1].getSpeed() << " km/h" << endl;
    cout << "\n--- compareSpeed() �׽�Ʈ ---\n";
    carSet[0].compareSpeed(carSet[1]);  // ���� vs ���Ÿ
    carSet[1].compareSpeed(carSet[2]);  // ���Ÿ vs ���

    //[�߰�] Setter ��� ����
    cout << "\n--- Setter �޼���� �� ���� ---\n";
    carSet[3].setManufacturer("BMW");
    carSet[3].setSpeed(250);
    carSet[4].setManufacturer("Tesla").setSpeed(280);

    cout << "\n=== ������ carSet[3]~[4] ��� ===" << endl;
    carSet[3].showCars();
    carSet[4].showCars();

    // ��ü �� ��Ȯ��
    cout << "\n���� ��ü Car ��ü ��: " << Car::getCarCount() << endl;

    delete[] carSet;  // �Ҹ��� ȣ��

    cout << "Car ��ü ��� ���� �� ��: " << Car::getCarCount() << endl;
    int choice;
    cin >> choice;
    return 0;
}