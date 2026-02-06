#include<iostream>
#include<cstring>

int main() {
    using namespace std;

    char fname[20], lname[20], flname[42];
    cout << "Enter your first name: ";
    cin.get(fname, 20).get();
    cout << "Enter your last name: ";
    cin.get(lname, 20).get();
    strcpy(flname, lname);
    strcat(flname, ", ");
    strcat(flname, fname);
    cout << "Here's the information in a single string: " << flname << endl;
    return 0;
}