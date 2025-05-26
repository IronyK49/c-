//8,9장 동적바인딩, 클래스계층,상속, mpolymorphism -> 동적 설계 : 코드 재사용 
//upcasting downcasting 문제가 나올것 
//

#include <iostream>
#include <string>
using namespace std;

// 추상 클래스 Animal
class Animal {
protected:
    double weight;
    string color;

public:
    Animal(double w, const string& c) : weight(w), color(c) {}

    // 가상 함수
    virtual void show()const {}

    // 가상 소멸자
    virtual ~Animal() {}
};

// Cow 클래스는 Animal을 상속
class Cow : public Animal {
private:
    int id;
    string owner;
    int age;

public:
    Cow(double weight, const string& color, int i, const string& o, int a)
        : Animal(weight, color), id(i), owner(o), age(a) {}
    //override: 필수는 아니지만, 실수를 방지하고 가독성을 높이기 위해 항상 쓰는 것이 좋음
    void show()const override{
        cout << "Cow details:\n";
        cout << "Weight: " << weight << " kg\n";
        cout << "Color: " << color << endl;
        cout << "ID: " << id << endl;
        cout << "Owner: " << owner << endl;
        cout << "Age: " << age << " years\n";
    }
};

// MilkCow 클래스는 Cow을 상속
class MilkCow : public Cow {
private:
    int milkProduct;

public:
    MilkCow(double w, const string& c, int i, const string& o, int a, int m)
        : Cow(w, c, i, o, a), milkProduct(m) {}

    void show()const{
        Cow::show(); //코드 재사용 
        cout << "Milk Production: " << milkProduct << " liters/day\n"; // 상속받은거 전부 출력 
    }
};

// Dog 클래스는 Animal을 상속
class Dog : public Animal {
private:
    int id;
    string owner;
    int age;

public:
    Dog(double w, const string& c, int i, const string& o, int a)
        : Animal(w, c), id(i), owner(o), age(a) {}

    void show() const {
        cout << "Dog details:\n";
        cout << "Weight: " << weight << " kg\n";
        cout << "Color: " << color << endl;
        cout << "ID: " << id << endl;
        cout << "Owner: " << owner << endl;
        cout << "Age: " << age << " years\n";
    }
};

// slicing 발생 (subclass 정보 잘림)
void printByValue(Animal a) { //객체 값을 복사하여 전달: Animal 객체 부분만 복사되고 subclass 데이터 멤버는 잘림
    //parameter passing 기본은 call by value : 값을 복사해서 전달 milkcow에서 animal 부분만 전달됨 (slicing) 
    cout << "\n[SLICED VERSION: Passed by Value]\n";
    a.show();  // always calls Animal's base version (if not abstract)
}

// slicing 방지 (정상 polymorphism)
//참조로 전달하면 슬라이싱이 일어나지 않는 이유:
//참조(&)로 전달하면 객체 복사 없이 원래 객체를 가리키므로,
//파생 클래스 정보도 유지되고,
//슬라이싱이 발생하지 않으며,
//동적 바인딩이 제대로 작동. 
void printByReference(const Animal& a) {
    cout << "\n[POLYMORPHIC VERSION: Passed by Reference]\n";
    a.show();  // virtual dispatch works correctly
}

// Animal 배열 출력 // 포인터로 받지 않으면 어떤 문제가 발생하는지 
void showAll(Animal* animals[], int size) { //정답코드, 객체 복사가 일어나지 않음 
    for (int i = 0; i < size; ++i) {
        animals[i]->show(); //animals[i].show() 동적바인딩 처리안됨 
        cout << endl;
    }
}

int main() {
    const int numAnimals = 10;
    Animal* animals[numAnimals]; // Animal animals[numAnimals] animals[0] = *new Cow -> 이경우 배열 전달하는 과정에서 동적바인딩 관련 문제 발생 

    // 동적 객체 생성
    animals[0] = new Cow(500, "Brown", 101, "John Doe", 5);
    animals[1] = new Cow(520, "Black", 102, "Alice Smith", 4);
    animals[2] = new Cow(480, "White", 103, "Bob Johnson", 6);

    animals[3] = new MilkCow(530, "Brown", 104, "Charlie Rose", 3, 20);
    animals[4] = new MilkCow(510, "Spotted", 105, "Diana Ross", 5, 25);
    animals[5] = new MilkCow(495, "White", 106, "Emily Clark", 4, 22);

    animals[6] = new Dog(30, "Black", 201, "Jane Smith", 3);
    animals[7] = new Dog(28, "Brown", 202, "Emily Davis", 2);
    animals[8] = new Dog(35, "White", 203, "Frank White", 4);
    animals[9] = new Dog(32, "Gray", 204, "Grace Lee", 5);

    cout << "\n▶▶ 모든 Animal 출력 (정상 polymorphism)\n";
    showAll(animals, numAnimals);

    cout << "\n▶▶ 개별 객체 전달 실험\n";

    // slicing 발생
    printByValue(*animals[3]);      // MilkCow → Animal by value → slicing 발생
    printByValue(*animals[6]);      // Dog → Animal by value → slicing 발생

    // slicing 방지
    printByReference(*animals[3]);  // MilkCow → Animal& → polymorphism 유지
    printByReference(*animals[6]);  // Dog → Animal& → polymorphism 유지

    // 메모리 해제
    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
    }
    int choice; 
    cin >> choice;
    return 0;
}
