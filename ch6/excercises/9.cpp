#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct Donation {
    string name;
    double amount;
};
int main() {
    cout << "Recording donations for the following individuals:\nInput information from .txt.\nEnter file name: ";
    string filename;
    getline(cin, filename);
    ifstream infile;
    infile.open(filename);
    if (!infile.is_open()) {
        cerr << "Error opening file " << filename << endl;
        return 1;
    }
    cout << "\n-----------------------------------------------\n";
    int numDonors;
    infile >> numDonors;
    infile.get();
    Donation* donors = new Donation[numDonors];
    cout << "Data Processing...\n";
    for (int i = 0; i < numDonors; ++i) {
        getline(infile, donors[i].name);
        infile >> donors[i].amount;
        infile.get();
    }
    int highCount = 0, lowCount = 0;
    cout << "Donation Summary:\n";
    for (int i = 0; i < numDonors; ++i)
        if (donors[i].amount >= 10000) {
            cout << "Grand Patron:\t" << donors[i].name << ":\t$" << donors[i].amount << endl;
            ++highCount;
        }
        else {
            cout << "Patron:\t" << donors[i].name << ":\t$" << donors[i].amount << endl;
            ++lowCount;
        }
    if (highCount == 0)
        cout << "Grand Patrons: None\n";
    if (lowCount == 0)
        cout << "Patrons: None\n";
    delete[] donors;
    infile.close();
    return 0;
}