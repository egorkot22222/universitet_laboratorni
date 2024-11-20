#include <iostream>
using namespace std;

int main() {
    int height;
    cout << "Введіть висоту трикутника: ";
    cin >> height;

    for (int i = 0; i <= height; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}
