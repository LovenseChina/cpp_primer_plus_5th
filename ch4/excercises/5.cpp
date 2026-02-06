#include<iostream>

struct CandyBar {
    char brand[20];
    float weight;
    int calorie;
} snack {
    "Mocha Munch",
    2.3,
    350
};

int main() {
    using namespace std;

    cout << "Brand: " << snack.brand << endl;
    cout << "Weight: " << snack.weight << endl;
    cout << "Calorie: " << snack.calorie << endl;
    
    return 0;
}