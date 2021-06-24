//MysteryNumber.cpp : a game where you must try to find a number.

#include <iostream>
#include <time.h>

int main(void) {
	int playerGuess, mysteryNumber = 20;

	srand((int)time(NULL));
	mysteryNumber = ((rand() % 1000) + 1);

	do {
		std::cout << "Guess a number from 1 to 1000 : ";
		std::cin >> playerGuess;

		if (playerGuess == mysteryNumber) {
			std::cout << "Well done! You found the mystery number!" << std::endl;
		}
		else if ((playerGuess < 1) || (playerGuess > 1000)) {
			std::cout << "You must guess a number between 1 and 1000." << std::endl;
		}
		else if (playerGuess < mysteryNumber) {
			std::cout << "Too small !" << std::endl;
		}
		else {
			std::cout << "Too big !" << std::endl;
		}
	} while (playerGuess != mysteryNumber);

	system("pause");
	return 0;
}