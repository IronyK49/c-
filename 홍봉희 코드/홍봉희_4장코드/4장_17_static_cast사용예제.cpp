#include <iostream>

using namespace std;

// ������(enum) Menu ����
enum Menu { ADD = 1, DELETE, SEARCH, PRINT, EXIT };

int main() {
    int choice;

    while (true) {
        // �޴� ���
        cout << "\n===== Menu =====\n";
        cout << "1. Add\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Print\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // ������ enum Ÿ������ ��ȯ
        Menu selectedMenu = static_cast<Menu>(choice); // �̰͵� ���迡 ���´��� ���� ���� ��ų� ������ ��

        // switch ������ �޴� ����
        switch (selectedMenu) {
        case ADD:
            cout << "You selected ADD.\n";
            break;
        case DELETE:
            cout << "You selected DELETE.\n";
            break;
        case SEARCH:
            cout << "You selected SEARCH.\n";
            break;
        case PRINT:
            cout << "You selected PRINT.\n";
            break;
        case EXIT:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 5.\n";
            break;
        }
    }

    return 0;
}
