#include<iostream>
using namespace std;

const int SLEN = 30;
struct student {
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student *ps);
void display3(const student pa[], int n);

int main() {
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;
    while(cin.get() != '\n')
        ;
    student * ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i = 0; i < entered; ++i) {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete []ptr_stu;
    cout << "Done.\n";
    return 0;
}

int getinfo(student pa[], int n) {
    cout << "Enter the information\n";
    cout << "You can teminate it only by enter a blank student name in advance\n";
    int i;
    for (i = 0; i < n; ++i) {
        cout << "Info #" << (i + 1) << endl;
        cout << "Full Name: ";
        cin.getline(pa[i].fullname, SLEN);
        if(pa[i].fullname[0] == '\0')
            break;
        cout << "Hobby: ";
        cin.getline(pa[i].hobby, SLEN);
        cout << "OOP Level: ";
        cin >> pa[i].ooplevel;
        while(cin.get() != '\n')
            ;
    }
    return i;
}

void display1(student st) {
    cout << "Full Name: " << st.fullname
        << ", Hobby: " << st.hobby
        << ", OOP Level: " << st.ooplevel << endl;
}

void display2(const student *ps) {
    cout << "Full Name: " << ps->fullname
        << ", Hobby: " << ps->hobby
        << ", OOP Level: " << ps->ooplevel << endl;
}

void display3(const student pa[], int n) {
    const char *str = "------------";
    cout << str << "#pa[]#" << str << endl;
    for (int i = 0; i < n; ++i)
        cout << pa[i].fullname << '\t'
            << pa[i].hobby << '\t'
            << pa[i].ooplevel << endl;
    cout << str << "#END#" << str;
}