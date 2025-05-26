#include <iostream>
#include <cstring>
using namespace std;

class Vehicle {
protected:
    double engineSize;
    int speed;

public:
    Vehicle(double e = 0.0, int s = 0) : engineSize(e), speed(s) {}
    virtual ~Vehicle() {
        cout << "Vehicle destroyed\n";
    }

    virtual void show() const {
        cout << "Vehicle - Engine: " << engineSize << "L, Speed: " << speed << "km/h" << endl;
    }
};

class Car : public Vehicle {
protected:
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
        cout << "Car destroyed\n";
    }

    void show() const override {
        cout << "Car - Model: " << model << ", Year: " << year << ", ";
        Vehicle::show();
    }
};

class Truck : public Vehicle {
protected:
    double capacity;

public:
    Truck(double e, int s, double c)
        : Vehicle(e, s), capacity(c) {}

    ~Truck() override {
        cout << "Truck destroyed\n";
    }

    void show() const override {
        cout << "Truck - Capacity: " << capacity << " tons, ";
        Vehicle::show();
    }
};

// ==============================
// ✅ 새로운 서브클래스 정의
// ==============================
// Coupes is a Car
class Coupes : public Car {
private:
    int numberSeats;

public:
    Coupes(const char* m, int y, double e, int s, int seats)
        : Car(m, y, e, s), numberSeats(seats) {}

    ~Coupes() override {
        cout << "Coupes destroyed\n";
    }

    void show() const override {
        cout << "🚘 Coupes - Seats: " << numberSeats << ", ";
        Car::show();
    }
};

// Vans is a Truck
class Vans : public Truck {
private:
    int passengers;
    double load;

public:
    Vans(double e, int s, double c, int p, double l)
        : Truck(e, s, c), passengers(p), load(l) {}

    ~Vans() override {
        cout << "Vans destroyed\n";
    }

    void show() const override {
        cout << "🚐 Vans - Passengers: " << passengers << ", Load: " << load << " tons, ";
        Truck::show();
    }
};

// MotorCycles is a Vehicle
class MotorCycles : public Vehicle { //서브클래스에 의한 코드 확장 => 객체지향 기법 
private:
    double displacement;
    int maxSpeed;

public:
    MotorCycles(double e, int s, double d, int max)
        : Vehicle(e, s), displacement(d), maxSpeed(max) {}

    ~MotorCycles() override {
        cout << "MotorCycles destroyed\n";
    }

    void show() const override {
        cout << "🏍️ MotorCycle - Displacement: " << displacement << "cc, Max Speed: "
            << maxSpeed << "km/h, ";
        Vehicle::show();
    }
};


// ==============================
// ✅ 기존 함수 (수정 없음)
// ==============================
void printVehicles(Vehicle* arr[], int size) {
    cout << "[Vehicle 목록 출력: 동적 바인딩]" << endl;
    for (int i = 0; i < size; ++i) {
        if (arr[i]) arr[i]->show();
    }
}

void freeVehicles(Vehicle* arr[], int size) {
    for (int i = 0; i < size; ++i) {
        delete arr[i];
        arr[i] = nullptr;
    }
}

// ==============================
// ✅ 메인 함수 (수정 없음)
// ==============================
int main() {
    Vehicle* table[10] = { nullptr };

    table[0] = new Car("Avante", 2020, 1.6, 180);
    table[1] = new Coupes("Genesis Coupe", 2019, 2.0, 200, 2);  // ✅ Car → Coupes 
    table[2] = new Truck(5.0, 140, 15.0); // ✅ Truck → Vans
    table[3] = new Vans(3.5, 120, 8.0, 7, 1.2);                    
    table[4] = new MotorCycles(0.6, 100, 599, 180);  // ✅ Vehicle → MotorCycles 
    printVehicles(table, 5);  // ✅ 다형성에 따라 적절한 show()가 호출됨
    freeVehicles(table, 5);   // ✅ 가상 소멸자 덕분에 자식 소멸자도 호출됨

    return 0;
}

