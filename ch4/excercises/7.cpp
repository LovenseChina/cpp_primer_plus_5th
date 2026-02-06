#include<iostream>
#include<cstring>
using namespace std;

int main() {
    struct {
        char co[40];
        float diameter;
        float weight;
    }pizza;
    cout << "Enter production company of the pizza: ";
    cin.get(pizza.co, 40).get();
    cout << "Enter diameter of the pizza: ";
    cin >> pizza.diameter;
    cout << "Enter weight of the pizza: ";
    cin >> pizza.weight;
    cout << "Information of the pizza below:\n";
    cout << "Production company: " << pizza.co << endl;
    cout << "Diameter: " << pizza.diameter << endl;
    cout << "Weight: " << pizza.weight << endl;
    return 0;
}