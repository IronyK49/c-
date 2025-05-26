#include <iostream>
#include <cstring>
using namespace std;

// =========================
// Vehicle 추상 클래스
// =========================
class Vehicle {
protected:
    double engineSize;
    int speed;

public:
    Vehicle(double e = 0.0, int s = 0) : engineSize(e), speed(s) {}
    virtual ~Vehicle() {} //가상 소멸자 
    virtual void show() const = 0;  // 순수 가상 함수(pure virtual 함수  // =0 표기는 가상함수 선언만 하고 함수 body는 이 클래스에서 구현하지 않는다.
    //Vehicle 객체를 생성할 수 없다. => 추상클래스(9장 다시 공부) (abstract class) 
    
};

// =========================
// Car 클래스
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

    virtual void show() const override { //여기서 virtual, const override 은 주석용이다 
        cout << "🚗 Car - Model: " << model << ", Year: " << year
            << ", Engine: " << engineSize << "L, Speed: " << speed << "km/h\n";
    }
    //table[i]->show, print 두개 차이점 확인
};


class Bus : public Vehicle { //subclass 만드는거 공부할것 
private:
    char* company;
    int passengers;

public:
    Bus(const char* m, int y, double e, int s)
        : Vehicle(e, s), passengers(y) {
        //this->company = company;
        //company = company; 둘다 오류
        
        //passengers = y;
        //this->passengers = passengers;
        company = new char[strlen(company) + 1];
        //strcpy(company, m);
    }

    ~Bus() override {
        delete[] company;
    }

    virtual void show() const override { //여기서 virtual, const override 은 주석용이다 
        cout << "🚗 Car - Model: " << company << ", Year: " << passengers
            << ", Engine: " << engineSize << "L, Speed: " << speed << "km/h\n";
    }
};

// =========================
// Truck 클래스
// =========================
class Truck : public Vehicle {
private:
    double capacity;

public:
    Truck(double e, int s, double c)
        : Vehicle(e, s), capacity(c) {}

    void show() const override {
        cout << "🚚 Truck - Capacity: " << capacity << " tons, Engine: "
            << engineSize << "L, Speed: " << speed << "km/h\n";
    }
};

// =========================
// 차량 저장소 클래스 (정적 배열 사용)
// -> 중고차 등록, 삭제, 조회, 출력하는 관리 SW의 개발 : 클래스 구현 
// =========================
class UsedVehicleStore {
private:
    Vehicle* table[10];  // 최대 10대 저장
    int count;

public:
    UsedVehicleStore() : count(0) {
        for (int i = 0; i < 10; ++i)
            table[i] = nullptr;
    }

    ~UsedVehicleStore() {
        for (int i = 0; i < count; ++i)
            delete table[i];  // 객체 메모리 해제
    }

    void add(Vehicle* v) {
        if (count < 10) {
            table[count++] = v;
        }
        else {
            cout << "저장소가 가득 찼습니다.\n";
        }
    }
    bool delete(char* name); // 이름을 가지고 삭제 삭제 하고 true false return하기 
    bool update(char* name, char* change); // 이름을 가지고 새로운걸로 바꿈
    Vehicle& search(char* name); // 이름을 가지고 찾기 
    //sort
    //printall
    // animal - cat dog cow ( 젖소, 황소) - 클래스 계층을 만들어라 //// 추상클래스 , virtual 함수 , 생성자 소멸자 등등 만들어야함 
    // animal *table[10] class Animalset에 add updater delete 등을 구현 


    void showAll() const {
        cout << "\n[전체 차량 목록]\n";
        for (int i = 0; i < count; ++i) {
            table[i]->show();  // 🔥 동적 바인딩
        }
    }
};

enum Menu { ADD = 1, DELETE, UPDATE, SEARCH, EXIT }; // 이제 안준다잉 

// =========================
// 메인 함수
// =========================
int main() {
    UsedVehicleStore store;

    store.add(new Car("Avante", 2020, 1.6, 180)); // 주석을 단다 코드 line을 읽어서 이해할수 있어야 함 (readability) -> 주석을 남기고 코드를 삭제 -> 주석만 보고 내가 직접 코딩 
    store.add(new Car("K5", 2018, 2.0, 170));
    store.add(new Truck(5.0, 140, 12.0));
    store.add(new Truck(3.5, 130, 8.5));
    store.add(new Bus("Kia", 1, 130, 8.5));

    store.showAll(); // vehicle table에 add, delete, update, printall, find, sort 이런거 나올거다 
    //store.delete("현대");
    //store.search("현대");
    return 0;
}