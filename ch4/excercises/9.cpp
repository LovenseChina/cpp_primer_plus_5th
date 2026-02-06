#include<iostream>
using namespace std;

struct CandyBar {
    char brand[20];
    float weight;
    int calorie;
};

int main() {
    CandyBar *ps = new CandyBar[3];
    *ps = (CandyBar){"Mocha Munch", 2.3, 350};
    *(ps + 1) = (CandyBar){"Monster", 5.0, 3400};
    ps[2] = (CandyBar){"Pisswa", 9.0, 7300};
    cout << "Three CandyBars\n";
    cout << "ps[0]:\n";
    cout << "Brand: " << ps[0].brand << endl;
    cout << "Weight: " << ps[0].weight << endl;
    cout << "Calorie: " << ps[0].calorie << endl;
    cout << "ps[1]:\n";
    cout << "Brand: " << ps[1].brand << endl;
    cout << "Weight: " << ps[1].weight << endl;
    cout << "Calorie: " << ps[1].calorie << endl;
    cout << "ps[2]:\n";
    cout << "Brand: " << ps[2].brand << endl;
    cout << "Weight: " << ps[2].weight << endl;
    cout << "Calorie: " << ps[2].calorie << endl;
    delete [] ps;
    return 0;
}