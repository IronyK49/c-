#include <iostream>
#include <cstring>

using namespace std;
class Car {
private:
    char* manufacturer;
    int speed;

public:
    // �⺻ ������ (Default Constructor)
    Car() { // �̰͵� ���迡 ������ �׳� ���� ������ 
        manufacturer = new char[8];
        strcpy(manufacturer, "Unknown");
        speed = 0;
        cout << "Default Constructor ȣ��" << endl;
    }

    // �Ϲ� ������ (Parameterized Constructor)
    Car(const char* manufacturer, int speed) {
        this->manufacturer = new char[strlen(manufacturer) + 1];
        strcpy(this->manufacturer, manufacturer);
        this->speed = speed;
        cout << "Parameterized Constructor ȣ��" << endl;
    }

    // ���� ������ (Deep Copy Implementation)
    Car(const Car& other) { // �������� �׳� ������ 
        this->manufacturer = new char[strlen(other.manufacturer) + 1];
        strcpy(this->manufacturer, other.manufacturer);
        this->speed = other.speed;
        cout << "Copy Constructor ȣ�� (Deep Copy)" << endl;
    }

    // �Ҹ��� (Destructor)
    ~Car() {
        cout << "Destructor ȣ��: " << manufacturer << endl;
        delete[] manufacturer;
    }

    // Setter���� this ������ ��� (Method Chaining) // �����Ͷ� �̷� 
    Car& setManufacturer(const char* manufacturer) {
        delete[] this->manufacturer; // ���� �޸� ����
        this->manufacturer = new char[strlen(manufacturer) + 1];
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
    Car car1; // �⺻ ������ ȣ��
    car1.printCarInfo();

    cout << "\n=== Parameterized Constructor �ǽ� ===" << endl;
    Car car2("Hyundai", 80); // �Ϲ� ������ ȣ��
    car2.printCarInfo();

    cout << "\n=== Copy Constructor �ǽ� ===" << endl;
    Car car3 = car2; // ���� ������ ȣ�� (Deep Copy)
    car3.printCarInfo();

    cout << "\n=== Method Chaining �ǽ� ===" << endl;
    car2.setManufacturer("Toyota").setSpeed(100).printCarInfo();

    int num;
    cin >> num;
    return 0; // �Ҹ��� �ڵ� ȣ��
}
