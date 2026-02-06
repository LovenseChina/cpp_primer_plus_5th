#include<iostream>
using namespace std;

int main() {
    int feet, inches, pounds;
    const int F_to_I = 12;
    const float I_to_M = 0.0254f;
    const float P_to_KG = 2.2f;

    cout << "Enter your height in feet and inches." << endl;
    cout << "Feet: ";
    cin >> feet;
    cout << "Inches: ";
    cin >> inches;
    cout << "Your height is " << feet * F_to_I + inches << " inchese" << endl;
    cout << "Enter your weight in pounds: ";
    cin >> pounds;
    cout << "Your BMI is " << pounds / P_to_KG / (feet * F_to_I + inches) * I_to_M << endl;

    return 0;
}