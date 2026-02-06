#include<iostream>

using namespace std;

void func_1();
void func_2();

int main() {
    func_1();
    func_1();
    func_2();
    func_2();
    return 0;
}

void func_1() {
    cout << "Three blind mice\n";
}

void func_2() {
    cout << "See how they run" << endl;
}