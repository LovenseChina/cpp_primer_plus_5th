#include<iostream>
#include<string>

int main() {
    using namespace std;

    string fname, lname, flname;
    cout << "Enter your first name: ";
    getline(cin, fname);
    cout << "Enter your last name: ";
    getline(cin, lname);
    flname += lname;
    flname += ", ";
    flname += fname;
    cout << "Here's the information in a single string: " << flname << endl;
    return 0;
}