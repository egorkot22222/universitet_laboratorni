#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Vvedit tsile chyslo: ";
    cin >> number;

    cout << "Chyslo do inkrementatsiyi: " << number << endl;
    cout << "Chyslo pislya inkrementatsiyi: " << ++number << endl;
    cout << "Chyslo pislya postfiksnogo inkrementu: " << number++ << endl;
    cout << "Chyslo pidchasy dekrementatsiyi: " << --number << endl;
    cout << "Chyslo pislya dekrementatsiyi: " << number << endl;

    return 0;
}

