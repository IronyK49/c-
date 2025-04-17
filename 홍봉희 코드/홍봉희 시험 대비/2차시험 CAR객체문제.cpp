#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

class Car {
private:
    char* manufacturer;
    char* model;
    double weight;
    int speed;

public:
    Car(const char* mfr, const char* mdl, double w, int s) {
        manufacturer = new char[strlen(mfr) + 1];
        strcpy(manufacturer, mfr);
        model = new char[strlen(mdl) + 1];
        strcpy(model, mdl);
        weight = w;
        speed = s;
    }

    ~Car() {
        delete[] manufacturer;
        delete[] model;
    }

    void print() const {
        cout << endl <<manufacturer << " " << model << ", "
            << weight << "kg, " << speed << "km/h";
    }
		 void print2() const {
        cout << manufacturer << " " << model << ", "
            << weight << "kg, " << speed << "km/h" << endl;
    }

    int getSpeed() const { return speed; }
    double getWeight() const { return weight; }

    const char* getManufacturer() const { return manufacturer; }
    const char* getModel() const { return model; }

    void setManufacturer(const char* newMfr) {
        delete[] manufacturer;
        manufacturer = new char[strlen(newMfr) + 1];
        strcpy(manufacturer, newMfr);
    }

    void setModel(const char* newModel) {
        delete[] model;
        model = new char[strlen(newModel) + 1];
        strcpy(model, newModel);
    }

    string getFullName() const {
        return string(manufacturer) + string(model);
    }
};

// 조건에 맞는 자동차 탐색
Car* findLightestFastCar(Car* cars[], int size) {
    Car* result = nullptr;
    for (int i = 0; i < size; ++i) {
        if (cars[i]->getSpeed() >= 200) {
            if (result == nullptr || cars[i]->getWeight() < result->getWeight()) {
                result = cars[i];
            }
        }
    }
    return result;
}

// 제조사+모델명 기준 정렬
void sortCars(Car* cars[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (cars[j]->getFullName() > cars[j + 1]->getFullName()) {
                swap(cars[j], cars[j + 1]);
            }
        }
    }
}

int main() {
    const int SIZE = 7;
    Car* cars[SIZE];
    cars[0] = new Car("현대", "Avante", 1250.5, 180);
    cars[1] = new Car("기아", "K5", 1300.0, 190);
    cars[2] = new Car("테슬라", "Model3", 1610.3, 250);
    cars[3] = new Car("벤츠", "E300", 1680.2, 240);
    cars[4] = new Car("BMW", "530i", 1655.0, 245);
    cars[5] = new Car("현대", "Sonata", 1430.7, 200);
    cars[6] = new Car("기아", "Sportage", 1500.0, 210);

    // 조건에 맞는 자동차 찾기
    Car* target = findLightestFastCar(cars, SIZE);
    if (target) {

        // 제조사/모델 자동 변경
        target->setManufacturer("차세대");
        target->setModel("혁신");

        target->print2();
    }

    // 정렬 및 출력
    sortCars(cars, SIZE);
    for (int i = 0; i < SIZE; ++i) {
        cars[i]->print();
				
    }

    // 메모리 해제
    for (int i = 0; i < SIZE; ++i) {
        delete cars[i];
    }
    return 0;
}
