#include <iostream>
using namespace std;

int main() {
    int age, salary;
    cout << "Vvedit vik: ";
    cin >> age;
    cout << "Vvedit zarplatu: ";
    cin >> salary;

    if (age >= 20 && salary >= 400 && salary <= 1000) {
        cout << "My rozglyanemo vashe posadu" << endl;

        string name, surname, position;
        cout << "Vvedit vashe im'ya: ";
        cin >> name;
        cout << "Vvedit vashe prizvishche: ";
        cin >> surname;
        cout << "Vvedit baganu posadu: ";
        cin >> position;

        cout << "Vashe im'ya: " << name << endl;
        cout << "Vashe prizvishche: " << surname << endl;
        cout << "Bagana posada: " << position << endl;
        cout << "Vik: " << age << endl;
        cout << "Zarplata: " << salary << endl;
    } else {
        cout << "Vy ne pidkhodyte" << endl;
    }

    return 0;
}

