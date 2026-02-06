#include<iostream>
using namespace std;
const int Max = 10;
int input_scores(int scores[], int n);
float average(const int scores[], int n);
void show_scores(const int scores[], int n);

int main() {
    cout << "Enter golf scores no more than 10(enter q to quit in advance)\n";
    int scores[Max], size;
    size = input_scores(scores, Max);
    show_scores(scores, size);
    cout << "Average score is " << average(scores, size) << endl;
    return 0;
}

int input_scores(int scores[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        cout << "score #" << (i + 1) << ": ";
        cin >> scores[i];
        if(!cin)
            break;
    }
    return i;
}

float average(const int scores[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += scores[i];
    return (float)sum / (float)n;
}

void show_scores(const int scores[], int n) {
    const char *str = "----------";
    cout << str << "#SCORES#" << str << endl;
    for (int i = 0; i < n; ++i)
        cout << scores[i] << "  ";
    cout << endl << str << "-#END#-" << str << endl;
}