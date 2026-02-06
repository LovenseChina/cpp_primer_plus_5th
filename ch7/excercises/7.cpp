#include<iostream>
const int Max = 5;
double *fill_array(double arr[], int limit);
void show_array(const double arr[], const double *end);
void revalue(double r, double arr[], const double *end);

int main() {
    using namespace std;
    double properties[Max];
    double *end = fill_array(properties, Max);
    show_array(properties, end);
    cout << "Enter revaluation factor: ";
    double factor;
    cin >> factor;
    revalue(factor, properties, end);
    show_array(properties, end);
    cout << "Done.\n";
    return 0;
}

double *fill_array(double arr[], int limit) {
    using namespace std;
    double temp;
    int i;
    for (i = 0; i < limit; ++i) {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if(!cin) {
            cin.clear();
            while(cin.get() != '\n')
                ;
            cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (temp < 0)
            break;
        arr[i] = temp;
    }
    return &(arr[i]);
}

void show_array(const double arr[], const double *end) {
    using namespace std;
    int count = 1;
    for (; arr != end; ++arr, ++count)
        cout << "Property #" << count << ": $" << *arr << endl;
}

void revalue(double r, double arr[], const double *end) {
    for (; arr != end; ++arr)
        *arr *= r;
}