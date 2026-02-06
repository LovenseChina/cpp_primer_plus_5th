#include<iostream>
#include<string>
using namespace std;

int main() {
    cout << "Enter words (to stop, type the word done):\n";
    string word;
    int count = 0;
    while ( word != "done") {
        cin >> word;
        ++count;
    }
    cout << "You entered a total of " << count - 1 << " words." << endl;
    return 0;
}