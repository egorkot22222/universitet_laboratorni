#include <iostream>
using namespace std;

void copyValue(int* source, int* destination) {
    *destination = *source;
}

void countEvenOdd(int* a, int* b, int* c, int* evenCount, int* oddCount) {
    *evenCount = 0;
    *oddCount = 0;

    if (*a % 2 == 0) *evenCount += 1; else *oddCount += 1;
    if (*b % 2 == 0) *evenCount += 1; else *oddCount += 1;
    if (*c % 2 == 0) *evenCount += 1; else *oddCount += 1;
}

void multiply(int* a, int* b, int* result) {
    *result = *a * *b;
}

void swapWithoutTemp(int* a, int* b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void findMinMax(int* a, int* b, int* c, int* min, int* max) {
    *min = *a;
    *max = *a;

    if (*b < *min) *min = *b;
    if (*b > *max) *max = *b;

    if (*c < *min) *min = *c;
    if (*c > *max) *max = *c;
}

int main() {
    int x = 5, y = 10, z = 3;
    int evenCount = 0, oddCount = 0, result = 0, min = 0, max = 0;

    copyValue(&x, &y);
    cout << "Після копіювання: x = " << x << ", y = " << y << endl;

    countEvenOdd(&x, &y, &z, &evenCount, &oddCount);
    cout << "Кількість парних: " << evenCount << ", кількість непарних: " << oddCount << endl;

    multiply(&x, &z, &result);
    cout << "Результат множення: " << result << endl;

    swapWithoutTemp(&x, &z);
    cout << "Після обміну: x = " << x << ", z = " << z << endl;

    findMinMax(&x, &y, &z, &min, &max);
    cout << "Мінімальне: " << min << ", максимальне: " << max << endl;

    return 0;
}

