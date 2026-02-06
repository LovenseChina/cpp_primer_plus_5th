#include<iostream>
using namespace std;

double tax(double);

int main() {
    double tvarps;
    cout << "Enter your taxable income: ";
    while((cin >> tvarps) && tvarps >= 0) {
        cout << "Tax owed: " << tax(tvarps) << " tvarps" << endl;
        cout << "Enter your taxable income: ";
    }
    cout << "Done!" << endl;
    return 0;
}

double tax(double tvarps) {
    if (tvarps <= 5000.0)
        return 0.0;
    else if (tvarps <= 15000.0)
        return (tvarps - 5000.0) * 0.10;
    else if (tvarps <= 35000.0)
        return (tvarps - 15000.0) * 0.15 + 1000.0;
    else
        return (tvarps - 35000.0) * 0.20 + 4000.0;
}