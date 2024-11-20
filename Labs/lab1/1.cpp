#include <iostream>
using namespace std;

int main() {
    double stor1, stor2;
    cout << "Введіть сторону 1: " << endl;
    cin >> stor1;
    cout << "Введіть сторону 2: " << endl;
    cin >> stor2;

    double P = 2 * (stor1 + stor2);
    cout << "Периметр прямокутника: " << P << endl;

    double S = stor1 * stor2;
    cout << "Площа прямокутника: " << S << endl;

    double suma = S + P;
    cout << "Сума площі та периметра: " << suma << endl;

    double riznycya = S - P;
    cout << "Різниця площі та периметра: " << riznycya << endl;

    double dob = S * P;
    cout << "Добуток площі та периметра: " << dob << endl;

    double chastka = S / P;
    cout << "Частка площі та периметра: " << chastka << endl;

    cout << endl << "Адреси в пам'яті: ";
    cout << endl << &stor1 << endl << &stor2 << endl << &S << endl << &P << endl << &chastka << endl;

    return 0;
}

