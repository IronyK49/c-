#include <iostream>

using namespace std;
class Car {
private:
    const char *manufacturer;
    int speed;

public:
    // �⺻ ������ (Default Constructor)
    Car() {
        manufacturer = "Unknown"; // ���� �ִ°� �ƴ� &��  
        speed = 0;
        cout << "Default Constructor ȣ��" << endl;
    }

    // �Ϲ� ������ (Parameterized Constructor)
    Car(const char* manufacturer, int speed) {
        this->manufacturer = manufacturer;
        this->speed = speed;
        cout << "Parameterized Constructor ȣ��" << endl;
    }

    // ���� ������ (Copy Constructor)
    Car(const Car& other) { // ��ü�� ���� 
        this->manufacturer = other.manufacturer;
        this->speed = other.speed;
        cout << "Copy Constructor ȣ��" << endl;
    }

    // �Ҹ��� (Destructor)
    ~Car() {
        cout << "Destructor ȣ��: " << manufacturer << endl;
    }

    // Setter���� this ������ ��� (Method Chaining)
    Car& setManufacturer(const char * manufacturer) {
        this->manufacturer = manufacturer;
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
    Car car3 = car2; // ���� ������ ȣ�� 
    car3.printCarInfo();

    cout << "\n=== Method Chaining �ǽ� ===" << endl;
    car2.setManufacturer("Toyota").setSpeed(100).printCarInfo();

    return 0; // �Ҹ��� �ڵ� ȣ��
}
