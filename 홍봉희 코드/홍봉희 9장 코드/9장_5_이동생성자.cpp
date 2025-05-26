#include <iostream>
#include <string>
using namespace std;

class Fruit {
private:
    string* data;

public:
    // ������
    Fruit(const string& str) {
        data = new string(str);
        cout << "[������] " << *data << endl;
    }

    // ���� ������
    Fruit(const Fruit& other) {
        data = new string(*other.data);
        cout << "[���� ������] " << *data << endl;
    }

    // �̵� ������
    Fruit(Fruit&& other) noexcept {
        data = other.data;
        other.data = nullptr;
        cout << "[�̵� ������] " << *data << endl;
    }

    // ���� ġȯ ������
    Fruit& operator=(const Fruit& other) {
        if (this != &other) {
            delete data;
            data = new string(*other.data);
            cout << "[���� ġȯ ������] " << *data << endl;
        }
        return *this;
    }

    // �̵� ġȯ ������
    // a = T("temp"); ��ü�� rvalue
    //a = std::move(b); move(b)�� rvalue > move(b)�� b�� rvalue�� casting
    //a = func(); �Լ� ���ϰ��� rvalue
    Fruit& operator=(Fruit&& other) noexcept {
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;//�Ҵ�� �ڿ��� �������� ����
            cout << "[�̵� ġȯ ������] " << *data << endl;
        }
        return *this;
    }

    // �Ҹ���
    ~Fruit() {
        if (data)
            cout << "[�Ҹ���] " << *data << endl;
        else
            cout << "[�Ҹ���] (null)" << endl;
        delete data;
    }
};
int main() {
    cout << "\n=== [1] ���� ������ ȣ�� �׽�Ʈ ===\n";
    Fruit f1("Apple");
    Fruit f2 = f1;  // ���� ������ ȣ��

    cout << "\n=== [2] �̵� ������ ȣ�� �׽�Ʈ ===\n";
    Fruit f3 = Fruit("Banana");  // �̵� ������ ȣ�� // ��ü ���� �ִ°� rvalue�� ���� �̵��� ���� �ְ� ����� 

    cout << "\n=== [3] ���� ġȯ ������ ȣ�� �׽�Ʈ ===\n";
    Fruit f4("Cherry");
    Fruit f5("Durian");
    f4 = f5;  // ���� ġȯ ������ ȣ��

    cout << "\n=== [4] �̵� ġȯ ������ ȣ�� �׽�Ʈ ===\n";
    Fruit f6("Elderberry");
    f6 = Fruit("Fig");  // �̵� ġȯ ������ ȣ��

    cout << "\n=== [5] �ڱ� �ڽſ� ���� ���� ���� �׽�Ʈ ===\n";
    f5 = f5;  // �ڱ� �ڽ� ����

    return 0;
}
