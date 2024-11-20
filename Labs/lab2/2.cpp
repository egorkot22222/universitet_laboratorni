#include <iostream>
using namespace std;

int main() {
    int rik1, rik2;
    cout << "Введіть 1 рік: ";
    cin >> rik1;
    cout << "Введіть 2 рік: ";
    cin >> rik2;

    if (rik1 > rik2) {
        cout << "Рік 1 не може бути більшим за Рік 2";
        return 0;
    }

    int riznycya = rik2 - rik1;
    if (riznycya >= 100) {
        cout << "Різниця між двома роками більше за 100" << endl;
        return 0;
    }

    cout << "Різниця між роками: " << riznycya << endl;

    int desetylittya = 0;
    for (int potochniy_rik = rik1 + 10; potochniy_rik <= rik2; potochniy_rik += 10) {
        cout << "Десятиліття: " << potochniy_rik << endl;
        desetylittya++;
    }

    cout << "Загальна кількість десятиліть: " << desetylittya << endl;

    return 0;
}

