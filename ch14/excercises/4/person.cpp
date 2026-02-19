#include "person.h"

void Gunslinger::Show() const {
	Person::Show();
	std::cout << "Draw gun: " << Draw() << "s\n";
}

void PokerPlayer::Show() const {
	Person::Show();
	std::cout << "Draw card: " << Draw() << '\n';
}

void BadDude::Show() const {
	Gunslinger::Show();
	std::cout << "Draw card: " << PokerPlayer::Draw() << '\n';
}
