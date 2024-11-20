#include <iostream>
#include <string>
using namespace std;

const int MAX_ACCOUNTS = 10;

void createAccount(string names[], double balances[], int &accountCount) {
    if (accountCount < MAX_ACCOUNTS) {
        string name;
        bool accountExists = false;

        cout << "Введіть ім'я власника: ";
        cin >> name;

        // Перевірка, чи існує вже акаунт з таким ім'ям
        for (int i = 0; i < accountCount; i++) {
            if (names[i] == name) {
                accountExists = true;
                break;
            }
        }

        if (accountExists) {
            cout << "Акаунт з таким ім'ям вже існує!" << endl;
        } else {
            cout << "Введіть початковий баланс: ";
            double balance;
            cin >> balance;
            names[accountCount] = name;
            balances[accountCount] = balance;
            accountCount++;
            cout << "Акаунт успішно створено!" << endl;
        }
    } else {
        cout << "Максимальна кількість рахунків досягнута!" << endl;
    }
}

void depositMoney(string names[], double balances[], int accountCount) {
    string name;
    double amount;
    cout << "Введіть ім'я власника рахунку: ";
    cin >> name;
    cout << "Введіть суму для поповнення: ";
    cin >> amount;

    bool found = false;
    for (int i = 0; i < accountCount; i++) {
        if (names[i] == name) {
            balances[i] += amount;
            found = true;
            cout << "Баланс рахунку оновлено." << endl;
            break;
        }
    }

    if (!found) {
        cout << "Рахунок з таким ім'ям не знайдено!" << endl;
    }
}

void withdrawMoney(string names[], double balances[], int accountCount) {
    string name;
    double amount;
    cout << "Введіть ім'я власника рахунку: ";
    cin >> name;
    cout << "Введіть суму для зняття: ";
    cin >> amount;

    bool found = false;
    for (int i = 0; i < accountCount; i++) {
        if (names[i] == name) {
            if (balances[i] >= amount) {
                balances[i] -= amount;
                found = true;
                cout << "Гроші знято. Поточний баланс: " << balances[i] << " грн." << endl;
            } else {
                cout << "Недостатньо коштів на рахунку!" << endl;
            }
            break;
        }
    }

    if (!found) {
        cout << "Рахунок з таким ім'ям не знайдено!" << endl;
    }
}

void displayAccounts(string names[], double balances[], int accountCount) {
    if (accountCount == 0) {
        cout << "Немає рахунків для відображення." << endl;
    } else {
        cout << "Рахунки:\n";
        for (int i = 0; i < accountCount; i++) {
            cout << "Ім'я: " << names[i] << ", Баланс: " << balances[i] << " грн" << endl;
        }
    }
}

int main() {
    string names[MAX_ACCOUNTS];
    double balances[MAX_ACCOUNTS];
    int accountCount = 0;
    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. Створити рахунок\n";
        cout << "2. Поповнити рахунок\n";
        cout << "3. Зняти гроші\n";
        cout << "4. Відобразити рахунки\n";
        cout << "5. Завершити\n";
        cout << "Виберіть опцію: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount(names, balances, accountCount);
                break;
            case 2:
                depositMoney(names, balances, accountCount);
                break;
            case 3:
                withdrawMoney(names, balances, accountCount);
                break;
            case 4:
                displayAccounts(names, balances, accountCount);
                break;
            case 5:
                cout << "Програма завершена." << endl;
                break;
            default:
                cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }

    } while (choice != 5);

    return 0;
}

