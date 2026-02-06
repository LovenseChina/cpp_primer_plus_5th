#include<iostream>
const int ArSize = 10;
int Fill_array(double arr[], int n);
void Show_array(const double arr[], int n);
void Reverse_array(double arr[], int n);

int main() {
    double arr[ArSize];
    int size = Fill_array(arr, ArSize);
    Show_array(arr, size);
    Reverse_array(arr, size);
    Show_array(arr, size);
    Reverse_array(arr + 1, size - 2);
    Show_array(arr, size);
}

int Fill_array(double arr[], int n) {
    std::cout << "Enter values no more than " << n << " times(Enter q to quit)\n";
    int i;
    for(i = 0; i < n; ++i) {
        std::cout << "number #" << (i + 1) << " ";
        std::cin >> arr[i];
        if(!std::cin)
            break;
    }
    std::cout << "Enter process terminated.\n";
    return i;
}

void Show_array(const double arr[], int n) {
    const char *str = "------------";
    std::cout << str <<"#arr[]#" << str << std::endl;
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << "  ";
    std::cout << std::endl << str << "-#END#-" << str << std::endl;
}

void Reverse_array(double arr[], int n) {
    double swap;
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        swap = arr[i];
        arr[i] = arr[j];
        arr[j] = swap;
    }
}