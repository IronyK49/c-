#include <iostream>
#include <cstring>
using namespace std;

const int MAX_SIZE = 100;

// =============================
// Vehicle Ŭ����
// =============================
class Vehicle {
private:
    char* manufacturer;
    char* model;
    int price;

    static char* copyString(const char* src) {
        if (!src) return nullptr;
        char* dest = new char[strlen(src) + 1];
        strcpy(dest, src);
        return dest;
    }

public:
    Vehicle(const char* m = "", const char* md = "", int p = 0)
        : price(p) {
        manufacturer = copyString(m);
        model = copyString(md);
    }

    Vehicle(const Vehicle& other) : price(other.price) {
        manufacturer = copyString(other.manufacturer);
        model = copyString(other.model);
    }

    virtual ~Vehicle() {
        delete[] manufacturer;
        delete[] model;
    }

    virtual void show() const {
        cout << manufacturer << " " << model << ", " << price << "����";
    }
};

// =============================
// Battery Ŭ����
// =============================
class Battery {
private:
    int capacity;
    string mode;

public:
    Battery(int cap = 0, const string& m = "EV") : capacity(cap), mode(m) {}
    virtual ~Battery() {}

    virtual void show() const {
        cout << " | Battery: " << capacity << "kWh, Mode: " << mode;
    }
};

// =============================
// Car Ŭ����
// =============================
class Car : virtual public Vehicle {
private:
    int passengers;
    double engineSize;

public:
    Car(const char* m, const char* md, int p, int people, double e)
        : Vehicle(m, md, p), passengers(people), engineSize(e) {}

    void show() const override {
        Vehicle::show();
        cout << " | Passengers: " << passengers << ", Engine: " << engineSize << "L";
    }
};

// =============================
// Truck Ŭ����
// =============================
class Truck : virtual public Vehicle {
private:
    double loadCapacity;

public:
    Truck(const char* m, const char* md, int p, double load)
        : Vehicle(m, md, p), loadCapacity(load) {}

    void show() const override {
        Vehicle::show();
        cout << " | Load Capacity: " << loadCapacity << " tons";
    }
};

// =============================
// CarTruck Ŭ����
// =============================
class CarTruck : public Car, public Truck {
public:
    CarTruck(const char* m, const char* md, int p, int people, double e, double load)
        : Vehicle(m, md, p),
        Car(m, md, p, people, e),
        Truck(m, md, p, load) {}

    void show() const override {
        Vehicle::show();
        cout << " | Passengers: ";
        Car::show();       // �� �κп��� Vehicle �ߺ� ����
        cout << ", ";
        Truck::show();     // �߰� ����
    }
};

// =============================
// ElectricCar Ŭ����
// =============================
class ElectricCar : public Vehicle, public Battery {
public:
    ElectricCar(const char* m, const char* md, int p, int cap)
        : Vehicle(m, md, p), Battery(cap, "EV") {}

    void show() const override {
        Vehicle::show();
        Battery::show();
    }
};

// =============================
// HybridCar Ŭ����
// =============================
class HybridCar : public Car, public Battery {
public:
    HybridCar(const char* m, const char* md, int p, int people, double e, int cap)
        : Vehicle(m, md, p),
        Car(m, md, p, people, e),
        Battery(cap, "Hybrid") {}

    void show() const override {
        Vehicle::show();
        cout << " | ";
        Car::show();
        Battery::show();
    }
};

// =============================
// UsedVehicleStore Ŭ����
// =============================
class UsedVehicleStore {
private:
    Vehicle** vehicles;
    int count;

public:
    UsedVehicleStore() {
        vehicles = new Vehicle * [MAX_SIZE];
        count = 0;
    }

    ~UsedVehicleStore() {
        for (int i = 0; i < count; ++i)
            delete vehicles[i];
        delete[] vehicles;
    }

    void add(Vehicle* v) {
        if (count < MAX_SIZE) {
            vehicles[count++] = v;
        }
    }

    void show() const {  // �����ε��� show
        cout << "\n[�߰� ���� ��� ���]\n";
        for (int i = 0; i < count; ++i) {
            vehicles[i]->show();
            cout << endl;
        }
    }
};


int main() {
    UsedVehicleStore store;

    store.add(new Car("Hyundai", "Avante", 1800, 5, 1.6));
    store.add(new Truck("Kia", "Bongo", 2300, 1.5));
    store.add(new CarTruck("Hyundai", "Porter 2", 2500, 3, 2.0, 1.2));
    store.add(new ElectricCar("Tesla", "Model 3", 5500, 75));
    store.add(new HybridCar("Toyota", "Prius", 3200, 4, 1.8, 45));

    store.show();  // �����ε��� show ���

    int choice;
    cin >> choice;
    return 0;
}
