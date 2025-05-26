#include <iostream>
#include <cstring>
using namespace std;

// =============================
// Vehicle 클래스
// =============================
class Vehicle {
protected:
    char* manufacturer;
    char* model;
    int madeYear;
    int price;

public:
    Vehicle(const char* m, const char* md, int y, int p)
        : madeYear(y), price(p) {
        manufacturer = new char[strlen(m) + 1];
        strcpy(manufacturer, m);
        model = new char[strlen(md) + 1];
        strcpy(model, md);
    }

    Vehicle(const Vehicle& other)
        : madeYear(other.madeYear), price(other.price) {
        manufacturer = new char[strlen(other.manufacturer) + 1];
        strcpy(manufacturer, other.manufacturer);
        model = new char[strlen(other.model) + 1];
        strcpy(model, other.model);
    }

    virtual ~Vehicle() {
        delete[] manufacturer;
        delete[] model;
    }

    // 공통 출력 (파생 클래스에서 호출)
    virtual void show() const {
        cout << manufacturer << " " << model << " (" << madeYear << "), "
            << price << "만원";
    }
};

// =============================
// Battery 클래스
// =============================
class Battery {
protected:
    int capacity;
    string mode;

public:
    Battery(int cap = 0, const string& m = "EV") : capacity(cap), mode(m) {}

    void show() const {
        cout << " | Battery: " << capacity << "kWh, Mode: " << mode;
    }
};

// =============================
// Car 클래스
// =============================
class Car : public Vehicle {
private:
    double engineSize;
    int speed;

public:
    Car(const char* m, const char* md, int y, int p, double e, int s)
        : Vehicle(m, md, y, p), engineSize(e), speed(s) {}

    void show() const override {
        Vehicle::show();
        cout << " | Engine: " << engineSize << "L, Speed: " << speed << "km/h\n";
    }
};

// =============================
// HybridCar 클래스
// =============================
class HybridCar : public Vehicle, private Battery {
private:
    double engineSize;
    int speed;

public:
    HybridCar(const char* m, const char* md, int y, int p,
        double e, int s, int cap)
        : Vehicle(m, md, y, p), Battery(cap, "Hybrid"),
        engineSize(e), speed(s) {}

    void show() const override {
        Vehicle::show();
        cout << " | Engine: " << engineSize << "L, Speed: " << speed << "km/h";
        Battery::show();
        cout << endl;
    }
};

// =============================
// ElectricCar 클래스
// =============================
class ElectricCar : public Vehicle, private Battery {
public:
    ElectricCar(const char* m, const char* md, int y, int p, int cap)
        : Vehicle(m, md, y, p), Battery(cap, "EV") {}

    void show() const override {
        Vehicle::show();
        Battery::show();
        cout << endl;
    }
};

// =============================
// UsedVehicleStore 클래스
// =============================
class UsedVehicleStore {
private:
    Vehicle** vehicles;
    int count;

public:
    UsedVehicleStore(int maxSize = 100) {
        vehicles = new Vehicle * [maxSize];
        count = 0;
    }

    ~UsedVehicleStore() {
        for (int i = 0; i < count; ++i)
            delete vehicles[i];
        delete[] vehicles;
    }

    void addVehicle(Vehicle* v) {
        vehicles[count++] = v;
    }

    void showAll() const {
        cout << "\n[중고 차량 목록 출력]\n";
        for (int i = 0; i < count; ++i)
            vehicles[i]->show();
    }
};

// =============================
// main 함수
// =============================
int main() {
    UsedVehicleStore store;

    store.addVehicle(new Car("Kia", "K5", 2019, 2500, 2.0, 180));
    store.addVehicle(new HybridCar("Toyota", "Prius", 2018, 3500, 1.8, 170, 45));
    store.addVehicle(new ElectricCar("Tesla", "Model 3", 2022, 5500, 75));
    store.addVehicle(new HybridCar("Hyundai", "Ioniq Hybrid", 2021, 3300, 1.6, 165, 42));
    store.addVehicle(new ElectricCar("Hyundai", "Ioniq 6", 2023, 4700, 77));

    store.showAll();

    return 0;
}
