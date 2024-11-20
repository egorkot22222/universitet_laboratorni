#include <iostream>
using namespace std;

int main() {
    int mark;
    cout << "Vvedit otsinku studenta (vid 0 do 100): ";
    cin >> mark;

    if (mark >= 90) {
        cout << "Vidminno" << endl;
    } else if (mark >= 75) {
        cout << "Dobre" << endl;
    } else if (mark >= 50) {
        cout << "Zadovilenno" << endl;
    } else {
        cout << "Nezadovilenno" << endl;
    }

    return 0;
}

