#include<iostream>
using namespace std;
double harmonic(double, double);
int main() {
    cout << "This program will caculate the harmonic of two numbers.\n";
    cout << "Enter the first two numbers(enter 0 to quit): ";
    double x, y;
    while (cin >> x >> y) {
        if (x == 0 || y == 0)
            break;
        cout << "The harmonic is " << harmonic(x, y) << endl;
        cout << "Enter next two numbers(enter 0 to quit ): ";
    }
    if(!cin)
        cout << "Invalid input, abort.\n";
    else
        cout << "Normally terminate.\n";
    return 0;
}

double harmonic(double x, double y) {
    return 2.0 * x * y / (x + y);
}