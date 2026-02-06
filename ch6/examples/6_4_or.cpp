#include<iostream>
int main() {
    using namespace std;
    cout << "This program may reformat your hard disk.\n"
        "and destroy all your data.\n"
        "Do you wish to continue? (y/n): ";
    char ch;
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
        cout << "Reformatting disk...\n";
    else if(ch == 'n' || ch == 'N')
        cout << "Aborting program.\n";
    else
        cout << "Invalid input. Aborting program.\n";
    return 0;
}