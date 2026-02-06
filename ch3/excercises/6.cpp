#include<iostream>
using namespace std;

int main() {
    cout << "Enter gasoline usage in L/mm: ";
    float euor_style;
    cin >> euor_style;

    float us_style;
    const float MM_to_M = 62.14;
    const float G_to_L = 3.875;

    us_style = euor_style * MM_to_M / G_to_L / 10; // 计算有问题，略去
    cout << "It's equavialent to " << us_style << " mpg.\n";

    return 0;
}