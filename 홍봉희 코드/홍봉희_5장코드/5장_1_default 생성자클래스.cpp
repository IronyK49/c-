#include <iostream>


using namespace std;

// �ڵ��� Ŭ���� (�ſ� �ܼ��� ����)
class Car {
public:
    const char * manufacturer; // ������
    const char * model;        // �𵨸�
    double weight;       // ���߷� (kg)
    int length;          // ����(mm)
    int width;           // ����(mm)
    int speed;           // �ӵ�
    Car() {} //default ������ (���� �ʱ�ȭ / �����Ϸ��� �ܼ� �����Ҵ� �ʱ�ȭ����) 
    Car() {
        manufacturer = nullptr;
        weight = 0.0L;


    }
    // ���� ���׸�Ʈ �з�
    const char* getSegment() {
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
    void checkSpeeding(int speedLimit) {
        if (speed > speedLimit)
            cout << "���� ���! (���� �ӵ�: " << speedLimit << " km/h)" << endl;
        else
            cout << "���� ����" << endl;
    }
};

int main() {
    Car car1, car2;//�����Ϸ��� ������ �����ڰ� ���� - default �����ڶ� �Ѵ�.
    cout << "���� ��: " << car1.model << endl; // �ʱ�ȭ���� ���� �� (������ ��)
    /*
    * ������ ����� public �̹Ƿ� main()���� ���� ó�� ���� > �ſ� �ٶ������� �ʴ�
    * ������ ������ ������ ��ó���� ����
    * ������ ������ localize�Ǿ�� �Ѵ�.
    */
    car1.manufacturer = "Hyundai";
    car1.model = "Sonata";
    car1.weight = 1400;
    car1.length = 4600;
    car1.width = 1800;
    car1.speed = 95;

    car2.manufacturer = "BMW";
    car2.model = "M3";
    car2.weight = 1200;
    car2.length = 4500;
    car2.width = 1700;
    car2.speed = 110;

    // ���� �ӵ� ����
    int cityLimit = 50;    // ���� ���� �ӵ�
    int highwayLimit = 100; // ��ӵ��� ���� �ӵ�

    // ���� ���� Ȯ��
    cout << "���� ���� �׽�Ʈ:" << endl;
    car1.checkSpeeding(cityLimit);
    car2.checkSpeeding(cityLimit);

    cout << "\n��ӵ��� ���� �׽�Ʈ:" << endl;
    car1.checkSpeeding(highwayLimit);
    car2.checkSpeeding(highwayLimit);

    // ���� ũ�� �з� ���
    cout << "\n���� ũ�� �з�:" << endl;
    cout << car1.getSegment() << endl;
    cout << car2.getSegment() << endl;

    return 0;
}
