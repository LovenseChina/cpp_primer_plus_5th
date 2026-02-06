#include<iostream>
using namespace std;
int factorial(int n);

int main() {
    int number;
    cout << "This program can caculate factorial of a number\n";
    cout << "Enter the first number(Enter q or a negative number to quit): ";
    while(cin >> number && number >= 0) {
        cout << "factorial is " << factorial(number) << endl;
        cout << "Enter next number(Enter q or a negative number to quit): ";
    }
    cout << "Terminate.\n";
    return 0;
}

int factorial(int n) {
    if(n == 1 || n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}