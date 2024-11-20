#include <iostream>
using namespace std;

int sum(int a, int b) {
    return a + b;
}

float sum(float a, float b) {
    return a + b;
}

string sum(string a, string b) {
    return a + b;
}

int minByValue(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}

void minByReference(int a, int b, int &result) {
    result = (a < b) ? a : b;
}

float area(float side) {
    return side * side;
}

float area(float length, float width) {
    return length * width;
}

float areaCircle(float radius) {
    return 3.14 * radius * radius;
}

float areaTriangle(float base, float height) {
    return 0.5 * base * height;
}

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int factorial(int &n) {
    if (n <= 1)
        return 1;
    else {
        int temp = n;
        n--;
        return temp * factorial(n);
    }
}

void drawSquare(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void allFunctions() {
    int sumInt = sum(3, 5);
    float sumFloat = sum(3.5f, 4.5f);
    string sumString = sum("Введення до ", "фаху");

    cout << "Сума цілих чисел: " << sumInt << endl;
    cout << "Сума чисел з плаваючою точкою: " << sumFloat << endl;
    cout << "Сума рядків: " << sumString << endl;

    int min1 = minByValue(3, 5);
    cout << "Мінімальне число за значенням: " << min1 << endl;

    int min2;
    minByReference(10, 20, min2);
    cout << "Мінімальне число за посиланням: " << min2 << endl;

    cout << "Площа квадрата: " << area(5) << endl;
    cout << "Площа прямокутника: " << area(5, 10) << endl;
    cout << "Площа кола: " << areaCircle(7) << endl;
    cout << "Площа трикутника: " << areaTriangle(5, 8) << endl;

    int a = 10, b = 20;
    swapByValue(a, b);
    cout << "Після обміну за значенням, a = " << a << " та b = " << b << endl;

    swapByReference(a, b);
    cout << "Після обміну за посиланням, a = " << a << " та b = " << b << endl;

    int number = 5;
    cout << "Факторіал числа " << number << " дорівнює " << factorial(number) << endl;

    int size = 4;
    cout << "Квадрат розміру " << size << ":\n";
    drawSquare(size);
}

int main() {
    allFunctions();
    return 0;
}

