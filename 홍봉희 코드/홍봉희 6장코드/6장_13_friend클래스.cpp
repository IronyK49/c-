#include <iostream> //friend , operator overloading �߿��� 
#include <cstring> 
using namespace std;

// =============================
// Vehicle Ŭ����
// =============================
class Vehicle {
protected:
    double engineSize;
    int speed;

public:
    Vehicle(double e = 0.0, int s = 0) : engineSize(e), speed(s) {}
    void showSpecs() const {
        cout << "Engine: " << engineSize << "L, Speed: " << speed << "km/h";
    }
};

// =============================
// Car Ŭ���� ����
// =============================
class UsedCar;                     // forward ����
bool isExpensive(const class Car&, int, int);  // friend �Լ� ����

class Car : public Vehicle {
private: //encapsolation // design choice 
    char* manufacturer;
    char* model;
    int madeYear;
    int price;

public:
    //insert delete update search show()
    friend class UsedCar;
    friend bool isExpensive(const Car&, int, int);

    Car(const char* m = "", const char* md = "", int y = 0, int p = 0,
        double e = 0.0, int s = 0)
        : Vehicle(e, s), madeYear(y), price(p) {
        manufacturer = new char[strlen(m) + 1];
        strcpy(manufacturer, m);
        model = new char[strlen(md) + 1];
        strcpy(model, md);
    }

    // ���� ������
    Car(const Car& other) : Vehicle(other) {
        madeYear = other.madeYear;
        price = other.price;
        manufacturer = new char[strlen(other.manufacturer) + 1];
        strcpy(manufacturer, other.manufacturer);
        model = new char[strlen(other.model) + 1];
        strcpy(model, other.model);
    }

    ~Car() {
        delete[] manufacturer;
        delete[] model;
    }

    void show() const {
        cout << manufacturer << " " << model << " (" << madeYear << "), "
            << price << "���� | ";
        showSpecs();
        cout << endl;
    }
};

// =============================
// friend �Լ� ����
// =============================
bool isExpensive(const Car& c, int priceThreshold, int currentYear) {
    return (c.price > priceThreshold) && (c.madeYear <= currentYear - 5);
}

// =============================
// UsedCar Ŭ���� ����
// =============================
class UsedCar {
private:
    Car* stock; //��ü���� ����
    int numberCars;

public:
    // �� ������: �ܺο��� Car �迭 ���� �ޱ�
    UsedCar(Car* cars, int n) {
        numberCars = n;
        stock = new Car[numberCars];
        for (int i = 0; i < numberCars; ++i) {
            stock[i] = cars[i];  // ���� ���� ����
        }
    }

    ~UsedCar() {
        delete[] stock;
    }

    void showAllCars() {
        cout << "\n[��ü ���� ���]" << endl;
        for (int i = 0; i < numberCars; ++i) {
            stock[i].show();
        }
    }

    void showExpensiveOldCars(int minPrice, int currentYear) {
        cout << "\n[5�� �̻� ��� & " << minPrice << "���� �ʰ� ����]" << endl;
        for (int i = 0; i < numberCars; ++i) {
            if (isExpensive(stock[i], minPrice, currentYear)) {
                stock[i].show();
            }
        }
    }
};

// =============================
// main �׽�Ʈ �ڵ�
// =============================
int main() {
    // 5�� Car ��ü ����
    Car cars[5] = {
        Car("Hyundai", "Grandeur", 2018, 3200, 2.4, 180),
        Car("Kia", "K5", 2019, 2500, 1.6, 170),
        Car("Renault", "SM6", 2021, 2300, 1.8, 160),
        Car("GM", "Malibu", 2017, 3100, 2.0, 175),
        Car("KGM", "Torres", 2020, 3600, 1.5, 165)
    };

    UsedCar store(cars, 5);  // �迭�� �ʱ�ȭ

    store.showAllCars();
    store.showExpensiveOldCars(3000, 2025);  // 5�� �̻� & �� ���� �˻�

    return 0;
}
