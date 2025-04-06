#include <iostream>


using namespace std;

// �ڵ��� Ŭ���� (��� ����� public���� ����)
class Car {
public:
    char* manufacturer; // ������
    char* model;        // �𵨸�
    double weight;       // ���߷� (kg)
    int length;          // ����(mm)
    int width;           // ����(mm)
    int speed;           // �ӵ�

    // ������ ����
    Car(char* m, char* mod, double w, int l, int wdt, int s);
    Car(char* m, char* mod); 
    Car() // ���� �ϰ� �Լ� ������ Ŭ���� �ܺο��� ���� ���� / �� ������ ������ car c1; �� ���� �����ڸ� ����� ������ �����Ϸ��� ���� �߰��� �ȸ�������  
    {
        manufacturer = nullptr;

    }
    // ���� �������� ���� ���׸�Ʈ �з� (�Լ� ����)
    char* getSegment();

    // ���� ���� �Ǵ� �޼ҵ� (���� �ӵ� �Է¹޴� ����)
    void checkSpeeding(int speedLimit);

    // ���� ���� �Ǵ� �޼ҵ� (�⺻ ���� �ӵ� 60km/h ����, �����ε�)
    void checkSpeeding();

    // ��ü ������ ����ϴ� ������ �����ε� (����)
    friend ostream& operator<<(ostream& os, const Car& car);
};

// =============================
// �ڵ��� Ŭ���� ��� �Լ� ���� (Ŭ���� �ܺο��� ����)
// =============================

Car::Car() { //����ڰ� ���� default ������ 
    manufacturer = nullptr;
}

Car::Car(char* m, char* mod)
    : manufacturer(m), model(mod) {} // ������ manufacurer=m; model = mod;

// ������ ���� parameer�� �ִ� ������ 
Car::Car(char* m, char* mod, double w, int l, int wdt, int s)
    : manufacturer(m), model(mod), weight(w), length(l), width(wdt), speed(s) {}

// ���� �������� ���� ���׸�Ʈ �з� (�Լ� ����)
char* Car::getSegment() {
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

// ���� ���� �Ǵ� (���� �ӵ� �Է¹޴� ����)
void Car::checkSpeeding(int speedLimit) {
    if (speed > speedLimit)
        cout << "���� ���! (���� �ӵ�: " << speedLimit << " km/h)" << endl;
    else
        cout << "���� ����" << endl;
}

// ���� ���� �Ǵ� (�⺻ ���� �ӵ� 60km/h ����, �����ε�)
void Car::checkSpeeding() {
    if (speed > 60)
        cout << "���� ���! (���� �ӵ�: 60 km/h)" << endl;
    else
        cout << "���� ����" << endl;
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

    // ��ü ��� ����
    car1.speed = 80; // �ӵ� ���� ����
    car2.manufacturer = "Mercedes"; // ������ ���� ����

    cout << "������ ���� ����:" << endl;
    cout << car1 << endl;
    cout << car2 << endl;

    // ����ڰ� ���� �����ڰ� ���� �� �⺻ �����ڰ� ���� ��� ���� �߻�
    Car c1; //default �����ڰ� ������ ����

    return 0;
}
