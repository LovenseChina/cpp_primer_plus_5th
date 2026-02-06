#include<iostream>
using namespace std;
int main() {
    cout << "Enter numbers to sum, if you want to stop, enter 0: " << endl;
    int num, sum = 0;
    do {
        cin >> num;
        sum += num;
        cout << "Current sum: " << sum << endl;
    } while (num != 0);
    return 0;
}