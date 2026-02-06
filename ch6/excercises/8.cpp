#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main() {
    cout << "Enter file name: ";
    string file_name;
    cin >> file_name;
    ifstream infile;
    infile.open(file_name);
    if(!infile.is_open()) {
        cout << "Could not open the file " << file_name << endl;
        return 1;
    }
    char ch;
    int count = 0;
    while(infile >> ch) // Read character by character, skipping whitespace
        ++count;
    cout << "The file " << file_name << " contains " << count << " characters." << endl;
    infile.close();
    return 0;
}