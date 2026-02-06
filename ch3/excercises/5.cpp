#include<iostream>
using namespace std;

int main() {
    float mileage, gasl_usage;

    cout << "Enter mileage: ";
    cin >> mileage;
    cout << "Enter gasoline usage: ";
    cin >> gasl_usage;

    cout << gasl_usage / mileage << " per mile\n";

    return 0;
}