﻿#include <iostream>
#include <cstring>
using namespace std;

enum Menu {
    INPUT = 1,
    INSERT,
    DELETE_STUDENT,
    UPDATE,
    EXIT
};

class Student {
private:
    int id;
    char* name;
    int age;
    static int count;

public:
    Student(int _id, const char* _name, int _age) {
        id = _id;
        age = _age;
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
        count++;
    }

    ~Student() {
        delete[] name;
        count--;
    }

    void print() const {
        cout << "ID: " << id << ", Name: " << name << ", Age: " << age << endl;
    }

    int getId() const {
        return id;
    }

    const char* getName() const {
        return name;
    }

    void increaseAge() {
        age++;
    }

    static int getCount() {
        return count;
    }
};

int Student::count = 0;

// 1. INPUT
void inputStudents(Student* table[], int& count) {
    const char* names[5] = { "강감찬", "이순신", "신사임당", "김유신", "윤봉길" };
    int ids[5] = { 101, 102, 103, 104, 105 };
    int ages[5] = { 20, 21, 22, 23, 24 };

    for (int i = 0; i < 5; ++i) {
        table[i] = new Student(ids[i], names[i], ages[i]);
    }

    count = 5;
    cout << "[5명의 학생이 자동으로 입력되었습니다.]" << endl;
}

// 2. INSERT
void insertStudent(Student* table[], int& count) {
    if (count >= 10) {
        cout << "더 이상 학생을 추가할 수 없습니다." << endl;
        return;
    }

    int id, age;
    char name[100];
    cout << "Enter ID Name Age: ";
    cin >> id >> name >> age;

    table[count++] = new Student(id, name, age);
    cout << "[학생이 추가되었습니다.]" << endl;
}

// 3. DELETE
void deleteStudent(Student* table[], int& count) {
    char name[100];
    cout << "Enter name to delete: ";
    cin >> name;

    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (strcmp(table[i]->getName(), name) == 0) {
            delete table[i];
            for (int j = i; j < count - 1; ++j) {
                table[j] = table[j + 1];
            }
            table[count - 1] = nullptr;
            count--;
            found = true;
            cout << "[" << name << "님의 정보가 삭제되었습니다.]" << endl;
            break;
        }
    }
    if (!found) {
        cout << "[해당 이름의 학생이 없습니다.]" << endl;
    }
}

// 4. UPDATE
void updateStudent(Student* table[], int count) {
    char name[100];
    cout << "Enter name to update: ";
    cin >> name;

    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (strcmp(table[i]->getName(), name) == 0) {
            table[i]->increaseAge();
            cout << "[" << name << "님의 나이가 1 증가했습니다.]" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "[해당 이름의 학생이 없습니다.]" << endl;
    }
}

// 전체 출력
void printAllStudents(Student* table[], int count) {
    cout << "\n[현재 등록된 학생 목록]" << endl;
    for (int i = 0; i < count; ++i) {
        table[i]->print();
    }
}

int main() {
    Student* table[10] = { nullptr };
    int count = 0;
    int choice;

    while (true) {
        cout << "\n1. INPUT" << endl;
        cout << "2. INSERT" << endl;
        cout << "3. DELETE" << endl;
        cout << "4. UPDATE" << endl;
        cout << "5. EXIT" << endl;
        cout << "Select menu: ";
        cin >> choice;

        Menu menu = static_cast<Menu>(choice);
        switch (menu) {
        case INPUT:
            inputStudents(table, count);
            break;
        case INSERT:
            insertStudent(table, count);
            break;
        case DELETE_STUDENT:
            deleteStudent(table, count);
            break;
        case UPDATE:
            updateStudent(table, count);
            break;
        case EXIT:
            for (int i = 0; i < count; ++i) {
                delete table[i];
            }
            cout << "[모든 메모리 해제 완료]" << endl;
            cout << "[프로그램 종료]" << endl;
            return 0;
        default:
            cout << "잘못된 선택입니다." << endl;
        }

        printAllStudents(table, count);
    }

    return 0;
}
