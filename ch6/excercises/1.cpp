#include<iostream>
#include<cctype>
using namespace std;

int main() {
    cout << "Echo and terminate by '@': " << endl;
    char ch;

    do {
        cin.get(ch);
        if (ch == '@')
            break;
        else if (islower(ch))
            cout << (char)toupper(ch);
        else if (isupper(ch))
            cout << (char)tolower(ch);
        else
            cout << ch;
    }while(true);
    cout << endl << "Terminated by '@'" << endl;
    return 0;
}