#include<iostream>

double ly_to_au(double);

int main() {
    using namespace std;

    double light_year, astronomical_unit;
    cout << "Please enter the number of light years: ";
    cin >> light_year;
    astronomical_unit = ly_to_au(light_year);
    cout << light_year << " light years = " << astronomical_unit << " astronomical units." << endl;
    return 0;
}

double ly_to_au(double ly) {
    return ly * 63240;
}