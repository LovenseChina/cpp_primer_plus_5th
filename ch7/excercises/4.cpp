#include<iostream>
long double probability(unsigned numbers, unsigned picks);
int main() {
    using namespace std;
    double ftotal, fchoices, stotal;
    cout << "Enter the field total number of field choices on the game card and\n"
            "Enter a numbers for special number too\n"
            "the number of picks allowed:\n";
    while((cin >> ftotal >> fchoices >> stotal) && fchoices <= ftotal) {
        cout << "You have one chance in ";
        cout << probability(ftotal, fchoices) * probability(stotal, 1);
        cout << " of winning.\n";
        cout << "Next two numbers (q to quit): ";
    }
    cout << "bye\n";
    return 0;
}

long double probability(unsigned numbers, unsigned picks) {
    long double result = 1.0;
    long double n;
    unsigned p;
    for(n = numbers, p = picks; p > 0; n--, p--) {
        result = result * n / p;
    }
    return result;
}