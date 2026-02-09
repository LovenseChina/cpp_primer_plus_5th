#include<iostream>
const int MAXSIZE = 5;

template<typename T>
T max5(T *);

int main() {
	using namespace std;
	int int_num5[MAXSIZE] = {23, 17, 89, 22, 0};
	double double_num5[MAXSIZE] = {1.2, 3.3, 2.5, 9.1, 7.2};
	cout << "max5(int_num5) = " << max5(int_num5) << endl;
	cout << "max5(double_num5) = " << max5(double_num5) << endl;
	return 0;
}

template<typename T>
T max5(T * nums) {
	T max = nums[0];
	for (int i = 1; i < MAXSIZE; ++i)
		max = max > nums[i] ? max : nums[i];
	return max;
}
