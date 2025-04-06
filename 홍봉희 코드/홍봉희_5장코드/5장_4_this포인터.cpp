#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string manufacturer;
    int speed;

public:
    // 생성자에서 this 포인터 사용
    Car(string manufacturer, int speed) {
        this->manufacturer = manufacturer;  // this-> 사용 , 사용하지 않으면 좌우 모두 parameter , parameter 이름을 바꾸면 문제 없긴해 
        this->speed = speed;
    }

    // Setter에서 this 포인터 사용
    Car& setManufacturer(string manufacturer) {
        this->manufacturer = manufacturer;
        return *this;  // this 포인터를 사용하여 객체 자신을 반환 중요하다잉 (return by reference 에 this 포인터) 
    }

    Car& setSpeed(int speed) {
        this->speed = speed;
        return *this;
    }

    // 멤버 함수에서 this 포인터 사용
    void printCarInfo() {
        cout << "제조사: " << this->manufacturer << ", 속도: " << this->speed << " km/h" << endl;
    }
};

int main() {
    Car car1("Hyundai", 80);

    car1.setSpeed(100);
    // this 포인터 활용: Method Chaining
    car1.setManufacturer("Toyota").setSpeed(100).printCarInfo(); // 객체.메소드 car1 receive object 이게 가능하도록 method구현 cascading ㅅㅂ 다 시험문제고 

    return 0;
}
