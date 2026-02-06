#include<iostream>
using namespace std;

int main() {
    int input, inch, foot;
    const int F_to_I = 12;
    cout << "Enter your height in inch:___\b\b\b";
    cin >> input;
    foot = input / F_to_I;
    inch = input % F_to_I;
    cout << "Your height is " << foot << " foot(s) and " << inch << " inch(s)";
    return 0;
}