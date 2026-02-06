#include<iostream>
using namespace std;
const int Max = 10;

int main () {
    double donations[Max];
    cout << "Enter " << Max << " numbers: " << endl;
    cout << "(To end input before " << Max << ", enter a non-numeric value):" << endl;
    int i = 0;
    double sum;
    while ((cin >> donations[i]) && i < Max) {
        sum += donations[i]; 
        i++;
    }
    double average = sum / i;
    cout << "Average is " << average << " and the following values are above average:" << endl;
    for (int j = 0; j < i; ++j)
        if (donations[j] > average)
            cout << "donations[" << j << "] = " << donations[j] << "\t" << endl;
    return 0;
}