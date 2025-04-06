/*
��Ʈ�� �迭 ���İ� insert ���� �ذ�
*/
#include <iostream>
#include <cstring> // strcmp, strcpy_s

using namespace std;

#define MAX_LEN 20
#define SIZE 8

// �迭 ��� �Լ�
void showData(const char* msg, char* arr[], int size) {
    cout << msg << ": ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ���ڿ� ��ȯ �Լ� (swap)
void swapStrings(char*& a, char*& b) {
    //a,b�� �����͸� �����ϴ� ����
    //a�� �����͸� ����Ű�� ����������� �ǹ�
    char* temp = a;
    a = b;
    b = temp;
    //main �Լ��� �����Ͱ� �����
}

void swapStrings(char* a, char* b) {//a,b ������ ���� �����
    char* temp = a;
    a = b;
    b = temp;
    //main �Լ��� �����Ͱ� ������� ����
}

// ���� ���� �Լ� (��������) - Sort() �Լ� ��� ���� -swap() ���
void sortData(char* arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) { // �������� ���� (A-Z)
                swapStrings(arr[j], arr[j + 1]);
            }
        }
    }
}

// ���ڿ� ���� �� ũ�� ������ ���� �迭 ��ȯ - Sort() ������ O(n) �ð� ���⵵�� �ذ�- while �� 1���� �ذ� 
char** insertData(char* data[], int size, const char* value) {
    char* newValue = new char[MAX_LEN]; // ���� �޸� �Ҵ�
    strcpy_s(newValue, MAX_LEN, value);

    // ���ο� �迭 ���� (size + 1 ũ��)
    char** newData = new char* [size + 1];
    for (int i = 0; i < size + 1; i++) {
        newData[i] = new char[MAX_LEN];
    }

    int i = size - 1;
    bool tag = true;

    // ���� �����͸� �����ϸ鼭 ���ο� ������ ����
    while (i >= 0) {
        if (strcmp(data[i], newValue) > 0) {
            strcpy_s(newData[i + 1], MAX_LEN, data[i]);
            i--;
            if (tag && i < 0) {
                strcpy_s(newData[i + 1], MAX_LEN, newValue);
                break;
            }
        }
        else {
            if (tag) {
                strcpy_s(newData[i + 1], MAX_LEN, newValue);
                tag = false;
                continue;
            }
            else {
                strcpy_s(newData[i], MAX_LEN, data[i]);
                i--;
            }
        }
    }

    delete[] newValue; // ���� �޸� ����
    return newData;
}

int main() {
    // �ʱ� ���ڿ� ������ ���� �Ҵ�
    char* data[] = {
        new char[MAX_LEN] {"avocado"},
        new char[MAX_LEN] {"grape"},
        new char[MAX_LEN] {"persimmon"},
        new char[MAX_LEN] {"pear"},
        new char[MAX_LEN] {"blueberry"},
        new char[MAX_LEN] {"strawberry"},
        new char[MAX_LEN] {"melon"},
        new char[MAX_LEN] {"jujube"}
    };

    showData("���� ��", data, SIZE);

    sortData(data, SIZE);

    showData("���� �� (��������)", data, SIZE);

    // ������ ������
    const char* realData[3] = { "waterMelon", "kiwi", "apple" };

    for (const char* newData : realData) {
        char** result = insertData(data, SIZE, newData);
        cout << "\n\n" << newData << " ���� ��: ";
        showData("���� �� ���ĵ� �迭", result, SIZE + 1);

        // ���� �Ҵ�� �޸� ����
        for (int i = 0; i < SIZE + 1; i++) {
            delete[] result[i];
        }
        delete[] result;
    }

    // ���� �迭�� �޸� ����
    for (int i = 0; i < SIZE; i++) {
        delete[] data[i];
    }
    system("pause");
    return 0;
}
