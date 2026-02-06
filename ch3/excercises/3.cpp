#include<iostream>
using namespace std;

int main() {
    const int Con_Val = 60;
    int degrees, minutes, seconds;

    cout << "Enter a latitude in degrees, minutes, and seconds:\n";

    cout << "First, enter the degrees: ";
    cin >> degrees;
    cout << "Next, enter the minutes: ";
    cin >> minutes;
    cout << "Finally, enter the seconds: ";
    cin >> seconds;

    float latitude = (float)degrees + (float)minutes / (float)Con_Val + (float)seconds / (float)Con_Val / (float)Con_Val;
    cout << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = ";
    cout << latitude << " degrees\n";

    return 0;
}