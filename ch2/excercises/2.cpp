#include<iostream>

double furlong_to_yard(double);

int main() {
    using namespace std;

    double furlong, yard;
    cout << "Enter furlong: ";
    cin >> furlong;
    yard = furlong_to_yard(furlong);
    cout << furlong << " furlong is " << yard << " yard" << endl;
    return 0;
}

double furlong_to_yard(double fl) {
    return fl * 220;
}