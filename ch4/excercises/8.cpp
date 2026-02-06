#include<iostream>
using namespace std;

struct Pizza{
        char co[40];
        float diameter;
        float weight;
};

int main() {
    Pizza *p = new Pizza;
    cout << "Enter production company of the pizza: ";
    cin.get(p->co, 40).get();
    cout << "Enter diameter of the pizza: ";
    cin >> p->diameter;
    cout << "Enter weight of the pizza: ";
    cin >> p->weight;
    cout << "Information of the pizza below:\n";
    cout << "Production company: " << p->co << endl;
    cout << "Diameter: " << p->diameter << endl;
    cout << "Weight: " << p->weight << endl;
    delete p;
    p = nullptr;
    return 0;
}