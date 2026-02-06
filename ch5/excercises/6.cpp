#include<iostream>
#include<string>
using namespace std;

struct Car {
    string make;
    int year;
};

int main() {
    cout << "Enter number of cars: ";
    int n;
    cin >> n;
    cin.get(); // consume the newline character
    Car *cars = new Car[n];
    for(int i = 0; i < n; ++i) {
        cout << "Car #" << i + 1 << endl;
        cout << "Please enter the make: ";
        getline(cin, cars[i].make);
        cout << "Please enter the year made: ";
        cin >> cars[i].year;
        cin.get(); // consume the newline character
    }
    cout << "\nHere is your collection of cars:\n";
    for(int i = 0; i < n; ++i) 
        cout << cars[i].year << " " << cars[i].make << endl;
    delete [] cars;
    return 0;
}