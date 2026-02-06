#include<iostream>
using namespace std;
const int Months = 12;

int main() {
    const char *MonthsName[Months] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    int sales[3][Months];
    
    cout << "Enter sales for 3 years:\n";
    for (int year = 0; year < 3; ++year) {
        cout << "Year " << (year + 1) << ":\n";
        for (int month = 0; month < Months; ++month) {
            cout << "  " << MonthsName[month] << ": ";
            cin >> sales[year][month];
        }
    }

    cout << "\nSales Report:\n";
    cout << "-------------------------\n";
    for (int year = 0; year < 3; ++year) {
        cout << "Year " << (year + 1) << ":\n";
        for (int month = 0; month < Months; ++month) {
            cout << "  " << MonthsName[month] << ": " << sales[year][month] << endl;
        }
        cout << "-------------------------\n";
    }
    cout << "Total sales for 3 years:\n";
    int totalSales = 0;
    for (int year = 0; year < 3; ++year) {
        for (int month = 0; month < Months; ++month) {
            totalSales += sales[year][month];
        }
    }
    cout << "Total sales: " << totalSales << endl;

    cout << "End of report.\n";
    return 0;
}