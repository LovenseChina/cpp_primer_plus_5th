#include<iostream>
#include<string>
using namespace std;
struct Donation {
    string name;
    double amount;
};
int main() {
    cout << "Recording donations for the following individuals:\n";
    int numDonors;
    cout << "Enter number of donors: ";
    cin >> numDonors;
    cin.get();
    Donation* donors = new Donation[numDonors];
    for (int i = 0; i < numDonors; ++i) {
        cout << "Enter name of donor " << (i + 1) << ": ";
        getline(cin, donors[i].name);
        cout << "Enter donation amount for " << donors[i].name << ": ";
        cin >> donors[i].amount;
        cin.get();
    }
    int highCount = 0, lowCount = 0;
    cout << "\nDonation Summary:\n";
    for (int i = 0; i < numDonors; ++i)
        if (donors[i].amount >= 10000) {
            cout << "Grand Patron: " << donors[i].name << " donated $" << donors[i].amount << endl;
            ++highCount;
        }
        else {
            cout << "Patron: " << donors[i].name << " donated $" << donors[i].amount << endl;
            ++lowCount;
        }
    if (highCount == 0)
        cout << "Grand Patrons: None\n";
    if (lowCount == 0)
        cout << "Patrons: None\n";
    delete[] donors;
    return 0;
}