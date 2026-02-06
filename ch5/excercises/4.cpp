#include<iostream>
using namespace std;
const int Months=12;
int main() {
    const char *MonthsName[Months] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    int Sales[Months];
    cout << "Enter sales for each month:\n";
    for (int i = 0; i < Months; ++i) {
        cout << MonthsName[i] << ": ";
        cin >> Sales[i];
    }
    cout << "\nMonthly Sales Report:\n";
    for (int i = 0; i < Months; ++i) {
        cout << MonthsName[i] << ": " << Sales[i] << endl;
    }
    cout << "Total Sales for the Year: ";
    int totalSales = 0;
    for (int i = 0; i < Months; ++i) {
        totalSales += Sales[i];
    }
    cout << totalSales << endl;
    cout << "End of Report\n";
    return 0;
}