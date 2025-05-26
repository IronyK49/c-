#include <iostream>
#include <cstring>
using namespace std;

// =========================
// Vehicle �߻� Ŭ����
// =========================
class Vehicle {
protected:
    double engineSize;
    int speed;

public:
    Vehicle(double e = 0.0, int s = 0) : engineSize(e), speed(s) {}
    virtual ~Vehicle() {}

    virtual void show() const = 0; //  ���� ���ε�
    void print() const { //  ���� ���ε�
        cout << "[Vehicle] Engine: " << engineSize << "L, Speed: " << speed << "km/h\n";
    }
    //table[i] -> show, print ������ Ȯ�� 
};

// =========================
// Car Ŭ����
// =========================
class Car : public Vehicle {
private:
    char* model;
    int year;

public:
    Car(const char* m, int y, double e, int s)
        : Vehicle(e, s), year(y) {
        model = new char[strlen(m) + 1];
        strcpy(model, m);
    }

    ~Car() override {
        delete[] model;
    }

    void show() const override { //  ���� ���ε� ���� Ŭ�������� virtual ���� �Ǿ��־ car���� ���� ���ص��� 
        cout << " Car - Model: " << model << ", Year: " << year
            << ", Engine: " << engineSize << "L, Speed: " << speed << "km/h\n";
    }

    void print() const { //  ���� ���ε�
        cout << "[Car] Model: " << model << ", Year: " << year << '\n';
    }
};

// =========================
// Truck Ŭ����
// =========================
class Truck : public Vehicle {
private:
    double capacity;

public:
    Truck(double e, int s, double c)
        : Vehicle(e, s), capacity(c) {}

    void show() const override { //  ���� ���ε�
        cout << " Truck - Capacity: " << capacity << " tons, Engine: "
            << engineSize << "L, Speed: " << speed << "km/h\n";
    }

    void print() const { // ���� ���ε�
        cout << "[Truck] Capacity: " << capacity << " tons\n";
    }
};

// =========================
// ���� ����� Ŭ����
// =========================
class UsedVehicleStore {
private:
    Vehicle* table[10];
    int count;

public:
    UsedVehicleStore() : count(0) {
        for (int i = 0; i < 10; ++i)
            table[i] = nullptr;
    }

    ~UsedVehicleStore() {
        for (int i = 0; i < count; ++i)
            delete table[i];
    }

    void add(Vehicle* v) {
        if (count < 10) {
            table[count++] = v;
        }
        else {
            cout << "����Ұ� ���� á���ϴ�.\n";
        }
    }

    void showAll() const {
        cout << "\n [���� ���ε�: show() ȣ�� ���]\n";
        for (int i = 0; i < count; ++i)
            table[i]->show();  // ���� ���ε�
    }

    void printAll() const {
        cout << "\n [���� ���ε�: print() ȣ�� ���]\n";
        for (int i = 0; i < count; ++i)
            table[i]->print();  // ���� ���ε� (Vehicle::print ȣ���!)
    }
};

// =========================
// ���� �Լ�
// =========================
int main() {
    UsedVehicleStore store;

    store.add(new Car("Avante", 2020, 1.6, 180));
    store.add(new Car("K5", 2018, 2.0, 170));
    store.add(new Truck(5.0, 140, 12.0));
    store.add(new Truck(3.5, 130, 8.5));

    store.showAll();   //  ���� ���ε����� Car::show(), Truck::show()
    store.printAll();  //  ���� ���ε����� Vehicle::print()�� ȣ���

    return 0;
}