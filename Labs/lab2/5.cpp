#include <iostream>
using namespace std;

int main() {
    int startV;
    cout << "Введіть початкове значення: ";
    cin >> startV;

    int finalV;
    cout << "Введіть кінцеве значення: ";
    cin >> finalV;

    // Зробив додатним, щоб вивести зі знаком мінус гарантовано
    if(startV < 0) startV = startV * -1;
    if(finalV < 0) finalV = -finalV * -1;

    if(startV > finalV){
        cout << "Початкове значення не може бути більшим за фінальне";
        return 0;
    }

    bool f = false;
    for (int i = startV; i <= finalV ; i++) {
        if (f == false) {
            f = true;
            cout << "Адреси: (початкове) " << &startV << " (кінцеве) " << &finalV << endl;
        }

        cout << -i << endl;
    }

    return 0;
}

