#include "person.h"
#include <ctime>

int main() {
	std::srand(std::time(0));

	Person *p_ptrs[4] {
		new Person("Lucy", "B."),
		new Gunslinger("Hunk", "S.", 0.2),
		new PokerPlayer("Jackson", "Aven"),
		new BadDude("Ruben", "L.", 0.21)
	}; 

	for (int i = 0; i < 4; ++i) {
		p_ptrs[i]->Show();
		std::cout << '\n';
	}

	for (int i = 0; i < 4; ++i)
		if (p_ptrs[i])
			delete p_ptrs[i];
	return 0;
}
