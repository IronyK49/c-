#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string manufacturer;
    int speed;

public:
    // �����ڿ��� this ������ ���
    Car(string manufacturer, int speed) {
        this->manufacturer = manufacturer;  // this-> ��� , ������� ������ �¿� ��� parameter , parameter �̸��� �ٲٸ� ���� ������ 
        this->speed = speed;
    }

    // Setter���� this ������ ���
    Car& setManufacturer(string manufacturer) {
        this->manufacturer = manufacturer;
        return *this;  // this �����͸� ����Ͽ� ��ü �ڽ��� ��ȯ �߿��ϴ��� (return by reference �� this ������) 
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
    Car car1("Hyundai", 80);

    car1.setSpeed(100);
    // this ������ Ȱ��: Method Chaining
    car1.setManufacturer("Toyota").setSpeed(100).printCarInfo(); // ��ü.�޼ҵ� car1 receive object �̰� �����ϵ��� method���� cascading ���� �� ���蹮���� 

    return 0;
}
