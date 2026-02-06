#include<iostream>
using namespace std;
const int StrSize = 50;
struct bop {
    char fullname[StrSize];
    char title[StrSize];
    char bopname[StrSize];
    int preference; // 0 = fullname, 1 = title, 2 = bopname
};

int main() {
    bop members[3] = {
        {"Wimp Macho", "Junior Programmer", "WMacho", 0},
        {"Raki Rhodes", "Senior Programmer", "RRhodes", 1},
        {"Celia Laiter", "Project Manager", "CLaiter", 2}
    };

    cout << "Benevolent Order of Programmers Report\n";
    cout << "a. display by name\tb. display by title\n";
    cout << "c. display by bopname\td. display by preference\n";
    cout << "q. quit\n";

    char choice;
    cout << "Enter your choice: ";
    while (cin >> choice && choice != 'q') {
        switch (choice) {
            case 'a':
                for (int i = 0; i < 3; i++)
                    cout << members[i].fullname << endl;
                break;
            case 'b':
                for (int i = 0; i < 3; i++)
                    cout << members[i].title << endl;
                break;
            case 'c':
                for (int i = 0; i < 3; i++)
                    cout << members[i].bopname << endl;
                break;
            case 'd':
                for (int i = 0; i < 3; ++i) {
                    switch (members[i].preference) {
                        case 0:
                            cout << members[i].fullname << endl;
                            break;
                        case 1:
                            cout << members[i].title << endl;
                            break;
                        case 2:
                            cout << members[i].bopname << endl;
                            break;
                    }
                }
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
        cout << "Enter next choice: ";
    }
    cout << "Bye!\n";
    return 0;
}