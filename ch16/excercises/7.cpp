#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>

std::vector<int> Lotto(int, int);

int main() {
	std::vector<int> winner = Lotto(51, 6);
	std::ostream_iterator<int, char> out(std::cout, " ");
	std::copy(winner.begin(), winner.end(), out);
	std::cout << std::endl;
	return 0;
}

std::vector<int> Lotto(int total, int choices) {
	std::vector<int> ret;
	for (int i = 1; i <= total; ++i)
		ret.push_back(i);
	std::srand(std::time(0));
	std::random_shuffle(ret.begin(), ret.end());
	ret.resize(choices);
	return ret;
}
