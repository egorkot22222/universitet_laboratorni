#include <iostream>
using namespace std;

bool isPrime(int a){
    if(a <= 1) return false;

    if(a == 2 || a == 3) return true;

    for (int i = 2; i < a; ++i) {
        if(a % i == 0) return false;
    }

    return true;
}

int main() {
    int finVal;

    cout << "Введіть кінечне число: " << endl;
    cin >> finVal;

    for (int curVal = 0; curVal <= finVal; ++curVal) {
        if(isPrime(curVal)) {
            cout << curVal << endl;
        }
    }

    return 0;
}

