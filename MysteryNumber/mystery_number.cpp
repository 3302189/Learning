//mystery_number.cpp : a game where you must try to find a random number.

#include <iostream>
#include <limits>
#include <random>

int main(void) {
	uint16_t player_guess = 0, mystery_number = 0; // initialization 

	std::uniform_int_distribution<int> dist(1, 1000);
	std::random_device rd;

	mystery_number = dist(rd);

	do {
		std::cout <<mystery_number<< "Guess a number from 1 to 1000 : ";
		if (std::cin >> player_guess) {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (player_guess == mystery_number) {
				std::cout << "Well done! You found the mystery number!" << std::endl;
			}
			else if ((player_guess < 1) || (player_guess > 1000)) {
				std::cout << "You must guess a number from 1 to 1000." << std::endl;
			}
			else if (player_guess < mystery_number) {
				std::cout << "Too small !" << std::endl;
			}
			else {
				std::cout << "Too big !" << std::endl;
			}
		}
		else if (std::cin.fail()) {
			std::cerr << "An error occured. Make sure you entered an integer from 1 to 1000." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else {
			return 2;
		}
	} while (player_guess != mystery_number);

	system("pause");
	return 0;
}