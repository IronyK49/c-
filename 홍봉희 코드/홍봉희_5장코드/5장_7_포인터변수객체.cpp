#include <iostream>
#include <cstring> // strcpy, strlen ���

using namespace std;

class Car {
private:
    char* manufacturer;
    int speed;

public:
    // �⺻ ������ (Default Constructor)
    Car() {
        manufacturer = new char[8]; // "Unknown"�� ������ ����� ũ��
        strcpy(manufacturer, "Unknown");
        speed = 0;
        cout << "Default Constructor ȣ��" << endl;
    }

    // �Ϲ� ������ (Parameterized Constructor)
    Car(const char* manufacturer, int speed) {
        this->manufacturer = new char[strlen(manufacturer) + 1]; // ���ڿ� ũ�⸸ŭ ���� �Ҵ�
        strcpy(this->manufacturer, manufacturer);
        this->speed = speed;
        cout << "Parameterized Constructor ȣ��" << endl;
    }

    // ���� ������ (���� ����)
    Car(const Car& other) {
        this->manufacturer = new char[strlen(other.manufacturer) + 1]; // �� �޸� �Ҵ�
        strcpy(this->manufacturer, other.manufacturer);
        this->speed = other.speed;
        cout << "Copy Constructor ȣ��" << endl;
    }

    // �Ҹ��� (Destructor)
    ~Car() {
        cout << "Destructor ȣ��: " << manufacturer << endl;
        delete[] manufacturer; // ���� �Ҵ�� �޸� ����
    }

    // Setter���� this ������ ��� (Method Chaining)
    Car& setManufacturer(const char* manufacturer) {
        delete[] this->manufacturer; // ���� �޸� ����
        this->manufacturer = new char[strlen(manufacturer) + 1]; // ���ο� �޸� �Ҵ�
        strcpy(this->manufacturer, manufacturer);
        return *this;  // this �����͸� ����Ͽ� ��ü �ڽ��� ��ȯ
    }

    Car& setSpeed(int speed) {
        this->speed = speed;
        return *this;
    }

    // ��� �Լ����� this ������ ���
    void printCarInfo() {
        cout << "������: " << this->manufacturer << ", �ӵ�: " << this->speed << " km/h" << endl;
    }
};

int main() {
    cout << "=== Default Constructor �ǽ� ===" << endl;
    Car* car1 = new Car(); // �⺻ ������ ȣ��
    car1->printCarInfo();

    cout << "\n=== Parameterized Constructor �ǽ� ===" << endl;
    Car* car2 = new Car("Hyundai", 80); // �Ϲ� ������ ȣ�� ��ü�� heap�� ������ 
    car2->printCarInfo();

    cout << "\n=== Copy Constructor �ǽ� ===" << endl;
    Car* car3 = new Car(*car2); // ���� ������ ȣ��
    car3->printCarInfo();

    cout << "\n=== Method Chaining �ǽ� ===" << endl;
    car2->setManufacturer("Toyota").setSpeed(100).printCarInfo();

    // ���� �Ҵ�� ��ü�� ���� (�Ҹ��� ȣ���)
    delete car1;
    delete car2;
    delete car3;

    //���̵� �� - ��ް���
    Car* carSet = new Car[10]; //10���� ��ü�� ���� - Car()�� ȣ��
    carSet[0].setManufacturer("Toyota");
    carSet[1].setSpeed(120);
    carSet[2].printCarInfo();

    //Car* carSet = new Car[10]("Hyundai", 100); // ����

    Car* carSet2[10];
    for (int i = 0; i < 10; ++i) {
        carSet2[i] = new Car("Hyundai", 100 + i * 10); // ���� ������ ȣ��
    }

    for (int i = 0; i < 10; ++i)
        delete carSet2[i];

    int num;
    cin >> num;

    return 0;
}