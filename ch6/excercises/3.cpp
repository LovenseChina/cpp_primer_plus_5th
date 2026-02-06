#include<iostream>
using namespace std;

void show_menu();
void report_choice(char);

int main() {
    char choice;
    show_menu();
    cin >> choice;
    while (choice != 'q') {
        report_choice(choice);
        show_menu();
        cin >> choice;
    }
    report_choice(choice); // To handle the 'q' case
    return 0;
}

void show_menu() {
    cout << "Please enter one of the following choices:\n";
    cout << "c) carnivore    p) pianist\n";
    cout << "t) tree         g) game\n";
    cout << "q) quit\n";
}

void report_choice(char choice) {
    switch (choice) {
        case 'c':
            cout << "A carnivore is an animal that eats other animals.\n";
            break;
        case 'p':
            cout << "A pianist is a person who plays the piano.\n";
            break;
        case 't':
            cout << "A tree is a perennial plant with an elongated stem, or trunk.\n";
            break;
        case 'g':
            cout << "A game is a form of play or sport.\n";
            break;
        case 'q':
            cout << "Quitting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a 'c', 'p', 't', 'g', or 'q'.\n";
    }
}