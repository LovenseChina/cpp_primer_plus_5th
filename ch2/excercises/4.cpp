#include<iostream>

double Ce_to_Fa(double);

int main() {
    using namespace std;

    double celsius, fahrenheit;
    cout << "Please enter a Celsius value: ";
    cin >> celsius;
    fahrenheit = Ce_to_Fa(celsius);
    cout << celsius << " degrees Celsius is " << fahrenheit << " degrees Fahrenheit." << endl;
    return 0;
}

double Ce_to_Fa(double c) {
    return 1.8 * c + 32.0;
}