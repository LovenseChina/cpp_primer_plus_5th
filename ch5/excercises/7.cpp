#include<iostream>
#include<cstring>
using namespace std;
const int StrSize = 200;

int main() {
    cout << "Enter words (to stop, type the word done):" << endl;
    char word[StrSize];
    int count = 0;
    while (strcmp(word, "done")){
        cin >> word;
        //cout << word << endl;
        ++count;
    }
    cout << "You entered a total of " << count - 1 << " words." << endl;
    return 0;
}