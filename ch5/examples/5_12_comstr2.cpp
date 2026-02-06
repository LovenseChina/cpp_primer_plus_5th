#include<iostream>
#include<string>
int main() {
    using namespace std;
    string word = "?ate";

    for(char ch = 'a'; word != "mate"; ch++) {
        word[0] = ch;
        cout << word << endl;
    }
    cout << "After loop ends, word is " << word << endl;
    return 0;
}