#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Vvedit tsile chyslo: ";
    cin >> number;

    cout << "Zalishok vid dilennya na 7: " << number % 7 << endl;

    int num1, num2;
    cout << "Vvedit perhe tsile chyslo: ";
    cin >> num1;
    cout << "Vvedit druhhe tsile chyslo: ";
    cin >> num2;

    if (num1 % num2 == 0) {
        cout << "Perhe chyslo dilitsya na druhhe bez zalishku" << endl;
    } else {
        cout << "Perhe chyslo ne dilitsya na druhhe bez zalishku" << endl;
    }

    if (num1 % 2 == 0) {
        cout << "Perhe chyslo parne" << endl;
    } else {
        cout << "Perhe chyslo neparne" << endl;
    }

    if (num2 % 2 == 0) {
        cout << "Druhhe chyslo parne" << endl;
    } else {
        cout << "Druhhe chyslo neparne" << endl;
    }

    return 0;
}

