#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Введіть число: ";
    cin >> a;

    float evenSum = 0;
    for (int i = 1; i <= a; i++) {
        if(i % 2 == 0) {
            cout << i << endl;
            evenSum += i;
        }
    }

    cout << endl;
    cout << "Сума всіх цих чисел: " << evenSum << endl;
    cout << "Сума, поділена на 2: " << evenSum / 2.0;

    return 0;
}

