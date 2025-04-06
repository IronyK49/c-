#include <iostream>
#include <cstring>

using namespace std;

// �ڵ��� Ŭ���� (������ ����� private���� ����)
class Car {
private:
    char manufacturer[50]; // ������ char *manufacturer; ������ �� �˾ƾ� �Ѵ�.
    char model[50];        // �𵨸� char *model; ������ �� �˾ƾ� �Ѵ�.
    double weight;         // ���߷� (kg)
    int length;            // ����(mm)
    int width;             // ����(mm)
    int speed;             // �ӵ�

public:
    // ������ ����
    Car(const char* m, const char* mod, double w, int l, int wdt, int s);
    Car();

    // Getter & Setter
    void setManufacturer(const char* m);
    const char* getManufacturer() const;
    void setModel(const char* mod);
    const char* getModel() const;
    void setWeight(double w);
    double getWeight() const;
    void setLength(int l);
    int getLength() const;
    void setWidth(int w);
    int getWidth() const;
    void setSpeed(int s);
    int getSpeed() const;

    // ���� �������� ���� ���׸�Ʈ �з�
    const char* getSegment();

    // ���� ���� �Ǵ� �޼ҵ�
    void checkSpeeding(int speedLimit);
    void checkSpeeding();

    // ��ü ������ ����ϴ� ������ �����ε�
    friend ostream& operator<<(ostream& os, const Car& car);
};

// =============================
// �ڵ��� Ŭ���� ��� �Լ� ����
// =============================

// ������ ����
Car::Car(const char* m, const char* mod, double w, int l, int wdt, int s) {
    //manufacturer = malloc(); ������ �޸� ��ȯ�� �ؾ���
    strncpy(manufacturer, m, sizeof(manufacturer) - 1);
    manufacturer[sizeof(manufacturer) - 1] = '\0';
    strncpy(model, mod, sizeof(model) - 1);
    model[sizeof(model) - 1] = '\0';
    weight = w;
    length = l;
    width = wdt;
    speed = s;
}

Car::Car() {
    manufacturer[0] = '\0';
    model[0] = '\0';
    weight = 0.0;
    length = 0;
    width = 0;
    speed = 0;
}

// Getter & Setter ����
void Car::setManufacturer(const char* m) {
    strncpy(manufacturer, m, sizeof(manufacturer) - 1);
    manufacturer[sizeof(manufacturer) - 1] = '\0';
}
const char* Car::getManufacturer() const {
    return manufacturer;
}
void Car::setModel(const char* mod) {
    strncpy(model, mod, sizeof(model) - 1);
    model[sizeof(model) - 1] = '\0';
}
const char* Car::getModel() const {
    return model;
}
void Car::setWeight(double w) {
    weight = w;
}
double Car::getWeight() const {
    return weight;
}
void Car::setLength(int l) {
    length = l;
}
int Car::getLength() const {
    return length;
}
void Car::setWidth(int w) {
    width = w;
}
int Car::getWidth() const {
    return width;
}
void Car::setSpeed(int s) {
    speed = s;
}
int Car::getSpeed() const {
    return speed;
}

// ���� �������� ���� ���׸�Ʈ �з�
const char* Car::getSegment() {
    if (length < 4200)
        return "B-���׸�Ʈ (������)";
    else if (length < 4600)
        return "C-���׸�Ʈ (������, ���� �йи�ī)";
    else if (length < 4900)
        return "D-���׸�Ʈ (������, �йи� ����)";
    else if (length < 5100)
        return "E-���׸�Ʈ (������, ��� ����)";
    else
        return "F-���׸�Ʈ (�ʴ�����, �÷��׽� ����)";
}

// ���� ���� �Ǵ�
void Car::checkSpeeding(int speedLimit) {
    if (speed > speedLimit)
        cout << "���� ���! (���� �ӵ�: " << speedLimit << " km/h)" << endl;
    else
        cout << "���� ����" << endl;
}
void Car::checkSpeeding() {
    checkSpeeding(60);
}

// ��ü ������ ����ϴ� ������ �����ε�
ostream& operator<<(ostream& os, const Car& car) {
    os << "������ = " << car.manufacturer
        << ", �� = " << car.model
        << ", �߷� = " << car.weight << " kg"
        << ", ���� = " << car.length << " mm"
        << ", ���� = " << car.width << " mm"
        << ", �ӵ� = " << car.speed << " km/h";
    return os;
}

// =============================
// ���� �Լ�
// =============================
int main() {
    // �ڵ��� ��ü ����
    Car car1("Hyundai", "Sonata", 1400, 4600, 1800, 95);
    Car car2("BMW", "M3", 1200, 4500, 1700, 110);

    // ��ü ��� ���� (setter ���)
    car1.setSpeed(80);
    car2.setManufacturer("Mercedes");

    cout << "������ ���� ����:" << endl;
    cout << car1 << endl;
    cout << car2 << endl;

    // �⺻ ������ ���
    Car c1;
    //c1.Manufacturer = ; �ȵȴ��� 
    c1.setManufacturer("Toyota");
    c1.setModel("Camry");
    c1.setSpeed(70);

    cout << "�⺻ �����ڷ� ������ ���� ����:" << endl;
    cout << c1 << endl;

    return 0;
}
