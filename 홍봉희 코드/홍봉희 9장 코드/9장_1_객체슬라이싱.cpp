//8,9�� �������ε�, Ŭ��������,���, mpolymorphism -> ���� ���� : �ڵ� ���� 
//upcasting downcasting ������ ���ð� 
//

#include <iostream>
#include <string>
using namespace std;

// �߻� Ŭ���� Animal
class Animal {
protected:
    double weight;
    string color;

public:
    Animal(double w, const string& c) : weight(w), color(c) {}

    // ���� �Լ�
    virtual void show()const {}

    // ���� �Ҹ���
    virtual ~Animal() {}
};

// Cow Ŭ������ Animal�� ���
class Cow : public Animal {
private:
    int id;
    string owner;
    int age;

public:
    Cow(double weight, const string& color, int i, const string& o, int a)
        : Animal(weight, color), id(i), owner(o), age(a) {}
    //override: �ʼ��� �ƴ�����, �Ǽ��� �����ϰ� �������� ���̱� ���� �׻� ���� ���� ����
    void show()const override{
        cout << "Cow details:\n";
        cout << "Weight: " << weight << " kg\n";
        cout << "Color: " << color << endl;
        cout << "ID: " << id << endl;
        cout << "Owner: " << owner << endl;
        cout << "Age: " << age << " years\n";
    }
};

// MilkCow Ŭ������ Cow�� ���
class MilkCow : public Cow {
private:
    int milkProduct;

public:
    MilkCow(double w, const string& c, int i, const string& o, int a, int m)
        : Cow(w, c, i, o, a), milkProduct(m) {}

    void show()const{
        Cow::show(); //�ڵ� ���� 
        cout << "Milk Production: " << milkProduct << " liters/day\n"; // ��ӹ����� ���� ��� 
    }
};

// Dog Ŭ������ Animal�� ���
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

// slicing �߻� (subclass ���� �߸�)
void printByValue(Animal a) { //��ü ���� �����Ͽ� ����: Animal ��ü �κи� ����ǰ� subclass ������ ����� �߸�
    //parameter passing �⺻�� call by value : ���� �����ؼ� ���� milkcow���� animal �κи� ���޵� (slicing) 
    cout << "\n[SLICED VERSION: Passed by Value]\n";
    a.show();  // always calls Animal's base version (if not abstract)
}

// slicing ���� (���� polymorphism)
//������ �����ϸ� �����̽��� �Ͼ�� �ʴ� ����:
//����(&)�� �����ϸ� ��ü ���� ���� ���� ��ü�� ����Ű�Ƿ�,
//�Ļ� Ŭ���� ������ �����ǰ�,
//�����̽��� �߻����� ������,
//���� ���ε��� ����� �۵�. 
void printByReference(const Animal& a) {
    cout << "\n[POLYMORPHIC VERSION: Passed by Reference]\n";
    a.show();  // virtual dispatch works correctly
}

// Animal �迭 ��� // �����ͷ� ���� ������ � ������ �߻��ϴ��� 
void showAll(Animal* animals[], int size) { //�����ڵ�, ��ü ���簡 �Ͼ�� ���� 
    for (int i = 0; i < size; ++i) {
        animals[i]->show(); //animals[i].show() �������ε� ó���ȵ� 
        cout << endl;
    }
}

int main() {
    const int numAnimals = 10;
    Animal* animals[numAnimals]; // Animal animals[numAnimals] animals[0] = *new Cow -> �̰�� �迭 �����ϴ� �������� �������ε� ���� ���� �߻� 

    // ���� ��ü ����
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

    cout << "\n���� ��� Animal ��� (���� polymorphism)\n";
    showAll(animals, numAnimals);

    cout << "\n���� ���� ��ü ���� ����\n";

    // slicing �߻�
    printByValue(*animals[3]);      // MilkCow �� Animal by value �� slicing �߻�
    printByValue(*animals[6]);      // Dog �� Animal by value �� slicing �߻�

    // slicing ����
    printByReference(*animals[3]);  // MilkCow �� Animal& �� polymorphism ����
    printByReference(*animals[6]);  // Dog �� Animal& �� polymorphism ����

    // �޸� ����
    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
    }
    int choice; 
    cin >> choice;
    return 0;
}
