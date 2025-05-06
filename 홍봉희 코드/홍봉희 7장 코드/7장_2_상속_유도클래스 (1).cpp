#include <iostream>
#include <cstring>
using namespace std;

// =============================
// Vehicle Ŭ����
// =============================
class Vehicle {
private:
    double engineSize;
    int speed;

public:
    Vehicle(double e = 0.0, int s = 0) : engineSize(e), speed(s) {}
    virtual ~Vehicle() {}
    virtual void show() const {
        cout << "Engine: " << engineSize << "L, Speed: " << speed << "km/h";
    }
};

// =============================
// Car Ŭ����
// =============================
class Car : public Vehicle {
private:
    char* manufacturer;
    char* model;
    int madeYear;
    int price;
    /*
static char* copyString(const char* src) { // �ڵ� ����ȭ�� ���
    char* dest = new char[strlen(src) + 1];
    strcpy(dest, src);
    return dest;
}
*/
public:
    Car(const char* m = "", const char* md = "", int y = 0, int p = 0,
        double e = 0.0, int s = 0)
        : Vehicle(e, s), madeYear(y), price(p) {
        manufacturer = new char[strlen(m) + 1];
        strcpy(manufacturer, m);
        model = new char[strlen(md) + 1];
        strcpy(model, md);
    }

    Car(const Car& other) : Vehicle(other) {
        madeYear = other.madeYear;
        price = other.price;
        manufacturer = new char[strlen(other.manufacturer) + 1];
        strcpy(manufacturer, other.manufacturer);
        model = new char[strlen(other.model) + 1];
        strcpy(model, other.model);
    }

    virtual ~Car() {
        delete[] manufacturer;
        delete[] model;
    }

    virtual void show() const override {
        Vehicle::show();
        cout << manufacturer << " " << model << " (" << madeYear << "), "
            << price << "���� | ";
        cout << endl;
    }

    int getMadeYear() const { return madeYear; }
    int getPrice() const { return price; }
};

// =============================
// HybridCar Ŭ����
// =============================
class HybridCar : public Car {
private:
    int batteryCapacity;  // kWh
    string mode;          // "EV", "Engine", "Hybrid"

public:
    HybridCar(const char* m, const char* md, int y, int p,
        double e, int s, int battery, const string& driveMode)
        : Car(m, md, y, p, e, s), batteryCapacity(battery), mode(driveMode) {}

    void show() const override {
        Car::show();
        cout << "Battery: " << batteryCapacity << "kWh, Mode: " << mode << endl;
    }
};

// =============================
// UsedVehicleStore Ŭ����
// =============================
class UsedVehicleStore {
private:
    Vehicle* vehicles[5];
    int numberVehicles;

public:
    UsedVehicleStore(Vehicle** vList, int n) {
        numberVehicles = n;
        for (int i = 0; i < n; ++i) {
            vehicles[i] = vList[i];  // ���� ����
        }
    }

    ~UsedVehicleStore() {
       // delete[] vehicles;
    }

    void showAll() const {
        cout << "\n[�߰� ���� ��� ���]\n";
        for (int i = 0; i < numberVehicles; ++i) {
            vehicles[i]->show();
        }
    }
};

// =============================
// main �Լ�
// =============================
int main() {
    // �Ϲ� ���� 2��
    Car* c1 = new Car("Hyundai", "Avante", 2020, 2000, 1.6, 160);
    Car* c2 = new Car("Kia", "K5", 2019, 2500, 2.0, 180);

    // ���̺긮�� ���� 2��
    HybridCar* h1 = new HybridCar("Toyota", "Prius", 2018, 3500, 1.8, 170, 45, "Hybrid");
    HybridCar* h2 = new HybridCar("Hyundai", "Ioniq", 2021, 3300, 1.6, 165, 42, "EV");

    // Vehicle ������ �迭�� ��� ����
    Vehicle* vList[4] = { c1, c2, h1, h2 };

    // �߰��� ���� ��ü ����
    UsedVehicleStore store(vList, 4);
    store.showAll();

    // ���� ��ü ����
    delete c1;
    delete c2;
    delete h1;
    delete h2;
    int choice;
    cin >> choice;
    return 0;
}
