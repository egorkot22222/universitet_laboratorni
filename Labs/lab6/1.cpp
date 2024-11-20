#include <iostream>
#include <string>
using namespace std;

const int MAX_PRODUCTS = 10;

void addProduct(string names[], int quantities[], double prices[], int &productCount) {
    if (productCount < MAX_PRODUCTS) {
        string name;
        int quantity;
        double price;

        cout << "Введіть назву товару: ";
        cin >> name;
        cout << "Введіть кількість товару: ";
        cin >> quantity;
        cout << "Введіть ціну товару: ";
        cin >> price;

        names[productCount] = name;
        quantities[productCount] = quantity;
        prices[productCount] = price;
        productCount++;

        cout << "Товар успішно додано!" << endl;
    } else {
        cout << "Максимальна кількість товарів досягнута!" << endl;
    }
}

void removeProduct(string names[], int quantities[], double prices[], int &productCount) {
    string name;
    cout << "Введіть назву товару для видалення: ";
    cin >> name;

    bool found = false;
    for (int i = 0; i < productCount; i++) {
        if (names[i] == name) {
            found = true;
            for (int j = i; j < productCount - 1; j++) {
                names[j] = names[j + 1];
                quantities[j] = quantities[j + 1];
                prices[j] = prices[j + 1];
            }
            productCount--;
            cout << "Товар успішно видалено!" << endl;
            break;
        }
    }

    if (!found) {
        cout << "Товар з таким ім'ям не знайдено!" << endl;
    }
}

void updateQuantity(string names[], int quantities[], double prices[], int productCount) {
    string name;
    int quantity;
    cout << "Введіть назву товару для оновлення кількості: ";
    cin >> name;
    cout << "Введіть нову кількість товару: ";
    cin >> quantity;

    bool found = false;
    for (int i = 0; i < productCount; i++) {
        if (names[i] == name) {
            quantities[i] = quantity;
            found = true;
            cout << "Кількість товару оновлено!" << endl;
            break;
        }
    }

    if (!found) {
        cout << "Товар з таким ім'ям не знайдено!" << endl;
    }
}

void displayProducts(string names[], int quantities[], double prices[], int productCount) {
    if (productCount == 0) {
        cout << "Склад порожній!" << endl;
    } else {
        cout << "Список товарів на складі:\n";
        for (int i = 0; i < productCount; i++) {
            cout << "Назва: " << names[i] << ", Кількість: " << quantities[i] << ", Ціна: " << prices[i] << " грн" << endl;
        }
    }
}

void calculateTotalValue(int quantities[], double prices[], int productCount) {
    double totalValue = 0.0;
    for (int i = 0; i < productCount; i++) {
        totalValue += quantities[i] * prices[i];
    }
    cout << "Загальна вартість товарів на складі: " << totalValue << " грн" << endl;
}

int main() {
    string names[MAX_PRODUCTS];
    int quantities[MAX_PRODUCTS];
    double prices[MAX_PRODUCTS];
    int productCount = 0;
    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. Додати товар\n";
        cout << "2. Видалити товар\n";
        cout << "3. Оновити кількість товару\n";
        cout << "4. Показати всі товари\n";
        cout << "5. Розрахувати загальну вартість\n";
        cout << "6. Завершити\n";
        cout << "Виберіть опцію: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addProduct(names, quantities, prices, productCount);
                break;
            case 2:
                removeProduct(names, quantities, prices, productCount);
                break;
            case 3:
                updateQuantity(names, quantities, prices, productCount);
                break;
            case 4:
                displayProducts(names, quantities, prices, productCount);
                break;
            case 5:
                calculateTotalValue(quantities, prices, productCount);
                break;
            case 6:
                cout << "Програма завершена." << endl;
                break;
            default:
                cout << "Неправильний вибір. Спробуйте ще раз." << endl;
        }

    } while (choice != 6);

    return 0;
}

