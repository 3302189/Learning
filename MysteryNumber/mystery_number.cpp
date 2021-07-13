//mystery_number.cpp : a game where you must try to find a random number.

#include <iostream>
#include <limits>
#include <random>
#include <Windows.h>

#undef max

using namespace std;

constexpr auto GUESS_PROMPT = "Guess a number from 1 to 1000 (Q to quit): ";
constexpr auto CONTINUE_PROMPT = "Do you want to continue playing? (Y/N): ";
constexpr auto QUIT_CHAR = 'Q';
constexpr auto PLAY_AGAIN = 'Y';

bool skip_to_int(void);
bool get_int(int&, const char*);
inline void ignore_cin(void); // alias to cin.ignore(numeric_limits<streamsize>::max(), '\n')

int main(void) {
	const wchar_t* title = L"Mystery Number"; // set window title
	SetConsoleTitle(title);
	int mystery_number = 0;

	{
		uniform_int_distribution<int> dist(1, 1000); // generate random int in range [1:1000]
		random_device rd;
		
		mystery_number = (int)dist(rd);
	}

	int player_guess = 0;
	bool continue_playing = true;
	char continue_choice = 0;

	do {
		do {
			player_guess = 0;

			if (!get_int(player_guess, GUESS_PROMPT)) {
				cerr << "Error while reading player value, quitting.";
				return 1;
			}
			else if (player_guess == mystery_number) {
				cout << "Well done! You found the mystery number!" << endl << endl;
			}
			else if ((player_guess < 1) || (player_guess > 1000)) {
				cout << "You must guess a number from 1 to 1000." << endl << endl;
			}
			else if (player_guess < mystery_number) {
				cout << "Too small !" << endl << endl;
			}
			else {
				cout << "Too big !" << endl << endl;
			}
		} while (player_guess != mystery_number);

		cout << "Do you want to start over? (Y/N): ";
		cin >> continue_choice;
		cin.clear();
		ignore_cin();
		switch (toupper(continue_choice)) {
			case PLAY_AGAIN: {
				continue_playing = true;
				break;
			}
			default: {
				continue_playing = false;
				cout << "Exiting...";
				Sleep(750);
				break;
			}
		}
	} while (continue_playing);
	return 0;
}

bool get_int(int& i, const char* prompt) {
	cout << prompt;
	while (true) {
		if (cin >> i) {
			ignore_cin();
			return true;
		}
		else if (!skip_to_int()) {
			return false;
		}
	}
}

bool skip_to_int() {
	if (cin.fail()) {
		cin.clear();
		char ch;
		while (cin >> ch) {
			if (isdigit(ch)) {
				cin.unget();
				return true;
			} else if (toupper(ch) == QUIT_CHAR) {
				exit(0);
			}
		}
	}
	return false;
}

void ignore_cin(void) {
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}