#include<iostream>
using namespace std;
double caculate(double, double, double (*pf)(double, double));
double add(double, double);
double sub(double, double);

int main() {
    cout << "Enter pairs to caculate x op y(first value you entered is x and enter 'q' to terminate)\n";
    double x, y;
    double (*funcs[2])(double, double) = { add, sub};
    while(cin >> x >> y) {
        cout << x << " + " << y << " = " << caculate(x, y, funcs[0]) << endl;
        cout << x << " - " << y << " = " << caculate(x, y, funcs[1]) << endl;
    }
    cout << "Done.\n";
    return 0;
}

double caculate(double x, double y, double (*pf)(double, double)) {
    return pf(x, y);
}

double add(double x, double y) {
    return x + y;
}

double sub(double x, double y) {
    return x - y;
}