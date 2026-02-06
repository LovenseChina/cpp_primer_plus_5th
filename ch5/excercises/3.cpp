#include<iostream>
using namespace std;
int main() {
    double Daphne = 100.0;
    double Cleo = 100.0;
    int year = 0;
    while (Cleo <= Daphne) {
        Daphne += 10; // Daphne's fixed annual increase
        Cleo *= 1.05; // Cleo's 5% annual increase
        year++;
    }
    cout << "After " << year << " years, Cleo's investment will exceed Daphne's." << endl;
    return 0;
}