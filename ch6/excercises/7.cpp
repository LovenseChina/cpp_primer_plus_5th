#include<iostream>
#include<cstring>
using namespace std;
const int ArrSize = 40;

int main() {
    char word[ArrSize];
    int vowel = 0, constonant = 0, others = 0;
    cout << "This program reads words until you enter the 'q'.\n";
    while(cin >> word && strcmp(word, "q") != 0) {
        if (isalpha(word[0]))
            switch (word[0]) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    ++vowel;
                    break;
                default:
                    ++constonant;
            }
        else
            ++others;
    }
    cout << vowel << " words beginning with vowels\n";
    cout << constonant << " words beginning with constonants\n";
    cout << others << " others\n";
    return 0;
}