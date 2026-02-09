#include<iostream>
using namespace std;
#include<cstring>

template<typename T>
T maxn(T *, int);

template<> const char *maxn<const char *>(const char **, int);

int main() {
	int nums6[6] = {3, 9, 2, 8, 14, 7};
	double nums4[4] = {2.3, 7.9, 0.5, 3.4};
	const char* strs[5] = {
		{"Jasmine"},
		{"Jasper"},
		{"Jane"},
		{"Samule"},
		{"Sammy"}
	};
	cout << "maxn(nums6, 6) = " << maxn(nums6, 6) << endl;
	cout << "maxn(nums4, 4) = " << maxn(nums4, 4) << endl;
	cout << "maxn(strs, 5) = " << maxn(strs, 5) << endl;
	return 0; 
}

template<typename T>
T maxn(T *nums, int n) {
	T max = nums[0];
	for (int i = 1; i < n; ++i)
		max = max > nums[i] ? max : nums[i];
	return max;
}

template<> const char *maxn<const char *>(const char **ss, int n) {
	const char *s = ss[0];
	for (int i = 1; i < n; ++i)
		if (strlen(s) < strlen(ss[i]))
				s = ss[i];
	return s;
}
