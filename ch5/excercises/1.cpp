#include<iostream>
using namespace std;
int main() {
    cout << "Enter two numbers to calculate the sum of the digits between them:" << endl;
    cout << "First number: ";
    int num1;
    cin >> num1;
    cout << "Second number: ";
    int num2;
    cin >> num2;
    int sum = 0;
    for (int i = num1; i <= num2; ++i)
        sum += i;
    cout << "The sum of the digits between " << num1 << " and " << " " << num2 << " is " << sum << endl;
    return 0;
}