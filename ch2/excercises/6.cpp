#include<iostream>

void ShowTime(int, int);

int main() {
    using namespace std;

    int hours, minutes;
    cout << "Enter the number of hours: ";
    cin >> hours;
    cout << "Enter the number of minutes: ";
    cin >> minutes;
    ShowTime(hours, minutes);
    return 0;
}

void ShowTime(int h, int m) {
    using namespace std;
    cout << "Time: " << h << ":" << m << endl;
}