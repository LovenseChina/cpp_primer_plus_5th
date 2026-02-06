#include<iostream>
using namespace std;

int main() {
    long seconds;
    cout << "Enter the number of seconds: ";
    cin >> seconds;
    
    int days_ = seconds / 60 / 60 / 24;
    int minutes_ = seconds / 60 % 60;
    int seconds_ = seconds % 60;

    cout << seconds << " seconds = "
        << days_ << " days, "
        << minutes_ << " minutes, "
        << seconds_ << " seconds\n";
        
    return 0;
}