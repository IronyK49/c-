#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>
using namespace std;

class Student {
public:
    char* name;
    int age;
    char* city; // string ó���� �߿� 
    Student() {}
    Student(const char* name, int age, const char* city);
    void swap(Student* b);
    void showStudent() const;
    ~Student(); // Destructor �߰�
    int compareStudents(const Student* b);
    void updateStudentCity(const char* city);
};
void Student::updateStudentCity(const char* city) {
    //this->city = city;//const char *�� char*�� ġȯ ���Ѵ� ������? ���ذ� �ʿ� 
    //strcpy(this->city, city);
    this->city = strdup(city);
}
int Student::compareStudents(const Student* b) {
    return strcmp(this->name, b->name);

}
void Student::showStudent() const{
    printf("[%s, %d, %s]\n", name, age, city);
}
// Constructor ����
Student::Student(const char* name, int age, const char* city) {
    /*
    * const char *name = &"hello"; (�߿�) 
    this->name = name;//const�� ����ϴ� ������ �����ϴ� ���� �ʿ� 
    this->age = age;
    this->city = city;//const�� ����ϴ� ������ �����ϴ� ���� �ʿ� 
   */
    //*
    this->name = strdup(name);
    this->age = age;
    this->city = strdup(city);
    //*/
}

// Destructor ����

Student::~Student() {
    if (name != nullptr) {
        free(name);
    }
    if (city != nullptr) {
        free(city);
    }
}
void Student::swap(Student* b) {
    std::swap(name, b->name);
    std::swap(age, b->age);
    std::swap(city, b->city);
} //strcpy����ϸ� ���� , �����͸� �ٲ㼭 ���ư� 

void showStudents(string message, const Student* students[], int numStudents) {
    //void showStudent();�� ����� ��ü ���
    cout << message << ": " << endl;
    for (int i = 0; i < numStudents; ++i) {
        if (students[i] == NULL)
            break;
        students[i]->showStudent();//const Student�� ����ؾ� �Ѵ�.
    }
    cout << endl;
}

void selectionSortStudents(Student* students[], int numStudents) {
    // int compareStudents(const Student* b);�� ����� ����
    for (int i = 0; i < numStudents - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < numStudents; ++j) {
            if (students[j]->compareStudents(students[minIndex]) < 0) {
                minIndex = j;

            }
        }
        if (minIndex != i) {
            students[i]->swap(students[minIndex]);
        }
    }
}
int main() {
    printf("%p", &"hello");
    // �л� ��ü �ʱ�ȭ
    int numStudents = 5;
    Student student1(&"Hong Gildong", 23, "houston");
    Student student2("hello", 22, "newyork");
    Student student3("houston", 13, "houston");
    Student student4("hong", 19, "busan");
    Student student5("kim", 33, "jeju");
    Student* students[5] = { &student1,&student2,&student3,&student4 ,&student5 };
    // �� �л� ���� ���
    showStudents("Before Sort:", students, numStudents);
    student1.updateStudentCity("Busan");
    student1.showStudent();
    selectionSortStudents(students, numStudents);
    showStudents("After Sort", students, numStudents);
    system("pause");
    return 0;
}