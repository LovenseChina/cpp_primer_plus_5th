#include<iostream>
using namespace std;

struct CandyBar {
    char brand[20];
    float weight;
    int calorie;
};

int main() {
    CandyBar snacks[3] = {
        {"Mocha Munch", 2.3, 350},
        {"Monster", 5.0, 3400},
        {"Pisswa", 9.0, 7300}
    };

    cout << "Three CandyBars\n";
    cout << "snacks[0]:\n";
    cout << "Brand: " << snacks[0].brand << endl;
    cout << "Weight: " << snacks[0].weight << endl;
    cout << "Calorie: " << snacks[0].calorie << endl;
    cout << "snacks[1]:\n";
    cout << "Brand: " << snacks[1].brand << endl;
    cout << "Weight: " << snacks[1].weight << endl;
    cout << "Calorie: " << snacks[1].calorie << endl;
    cout << "snacks[2]:\n";
    cout << "Brand: " << snacks[2].brand << endl;
    cout << "Weight: " << snacks[2].weight << endl;
    cout << "Calorie: " << snacks[2].calorie << endl;
    return 0;
}