#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <cctype>
#include <fstream>
#include <vector>
using std::string;
const int NUM = 26;
const string wordlist[] = {
	"apiary", "beetle", "cereal", "danger", "ensign", "florid", "garage", "health", "insult",
	"jackal", "keeper", "loaner", "manage", "nonce", "conset", "plaid", "quilt", "remote",
	"stolid", "train", "useful", "valid", "whence", "xenon", "yearn", "zippy" };

int main() {
	using std::cout;
	using std::cin;
	using std::tolower;
	using std::endl;
	//the following code writes words down to a file "3.txt"
	std::fstream fio;
	fio.open("3.txt");
	if (!fio.is_open()) {
		cout << "\"3.txt\" open failed! Terminated!\n";
		return 1;
	}
	for (int i = 0; i < NUM; ++i)
		fio << wordlist[i] << ' ';
	fio.close();
	cout << "hangman game data created!\n";
	//the following code uses vector<string> && read words from "3.txt"
	fio.open("3.txt");
	if (!fio.is_open()) {
		cout << "Data file error! Terminated!\n";
		return 1;
	}
	std::vector<string> datas;
	string ftemp;
	while (fio >> ftemp)
		datas.push_back(ftemp);
	cout << "hangman game data loaded!\n";
	const int VDNUM = datas.size();
	//the following code uses 16.3's code with a few modification
	std::srand(std::time(0));
	char play;
	cout << "Will you play a word game? <y/n> ";
	cin >> play;
	play = tolower(play);
	while (play == 'y') { 
		string target = datas[std::rand() % VDNUM];
		int length = target.length();
		string attempt(length, '-');
		string badchars;
		int guesses = 6;
		cout << "Guess my secret word. It has " << length
			<< " letters, and you guess\n"
			<< "one letter at a time. You get " << guesses
			<< " wrong guesses.\n";
		cout << "Your word: " << attempt << endl;
		while (guesses  > 0 &&  attempt != target) {
			char letter;
			cout << "Guess a letter: ";
			cin >> letter;
			if (badchars.find( letter) != string::npos || attempt.find(letter) != string::npos) {
				cout << "You already guessed that. Try again.\n";
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos) { 
				cout << "Oh, bad guess!\n";
				--guesses;
				badchars += letter;
			} else {
				cout << "Good guess!\n";
				attempt[loc] = letter;
				loc = target.find(letter, loc + 1);
				while (loc != string::npos) {
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				} 
			}
			cout << "Your word: " << attempt << endl;
			if (attempt != target) {
				if (badchars.length() > 0)
					cout << "Bad choices: " << badchars << endl;
				cout << guesses << " bad guesses left\n";
			} 
		}
		if (guesses > 0)
			cout << "That's right!\n";
		else
			cout << "Sorry, the word is " << target << ".\n";

		cout << "Will you play another? <y/n> ";
		cin >> play;
		play = tolower(play);
	}

	cout << "Bye\n";

	return 0;
}
