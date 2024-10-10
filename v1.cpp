#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

const int RETRY_MAX = 3;
const int ROUNDS_MAX = 10;
const int ROUNDS_MIN = 1;
int difficulty;
int rounds;
int answer;
int lives;

int diffChecker(int var) {
        int succeed = 0;

        for (int i = RETRY_MAX; i > 0 && succeed != 1; i--) {
                if (var == 1) {
                        cout << "Selected 'Easy' mode. You have 10 lives." << endl;
                        lives = 10;
                        succeed = 1;
                } else if (var == 2) {
                        cout << "Selected 'Medium' mode. You have 5 lives." << endl;
                        lives = 5;
                        succeed = 1;
                } else if (var == 3) {
                        cout << "Selected 'Hard' mode. You have 1 life." << endl;
                        lives = 1;
                        succeed = 1;
                } else {
                        cout << "You have not entered a valid difficulty. Try again." << endl;
                }
        }

        return 0;
}

int difficultySelector() {
        cout << "Choose a difficulty! Enter the corresponding number:" << endl
                << "Easy = 1" << endl
                << "Medium = 2" << endl
                << "Hard = 3" << endl;
        cin >> difficulty;

        difficulty = diffChecker(difficulty);

        return 0;
}

int roundSelector() {
        cout << "How many rounds would you like to play?" << endl;
        cin >> rounds;

        for (int i = RETRY_MAX; i > 0; i--) {
                if (rounds > ROUNDS_MIN && rounds < ROUNDS_MIN) {
                        cout << "Okay. You will play " << rounds << " rounds." << endl;
                } else if (rounds < ROUNDS_MIN) {
                        cout << "That's not enough rounds. You can play a min of 1." << endl;
                } else if (rounds > ROUNDS_MAX) {
                        cout << "That's too many rounds. You can play a max of 10." << endl;
                } else {
                        cout << "There was an error you you entered a non-integer. Try again." << endl;
                }
        }

        return 0;
}

int genAnswer() {
        if (difficulty == 1) {
                answer = rand() % 50 + 1;
                cout << "DEBUG: The answer is " << answer << endl;
        } else if (difficulty == 2) {
                answer = rand() % 100 + 1;
                cout << "DEBUG: The answer is " << answer << endl;
        } else {
                answer = rand() % 150 + 1;
                cout << "DEBUG: The answer is " << answer << endl;
        }

        return 0;
}

int getGuess() {
        int guess;

        cout << "Type your answer: " << endl;

        cin >> guess;

        return guess;
}

int main() {
        difficultySelector();
        genAnswer();

        for (rounds; rounds > 0; rounds--) {
                int hasWon = 0;

                for (lives; lives > 0 && hasWon != 1; lives--) {
                        int guess = getGuess();

                        if (guess == answer) {
                                cout << "Congratulations! You guess the answer: " << answer << endl;
                                hasWon = 1;
                        } else if (guess > answer) {
                                cout << "Sorry! That answer is too high." << endl;
                                lives -= 1;
                        } else if (guess < answer) {
                                cout << "Sorry! That answer was too low." << endl;
                                lives -= 1;
                        } else {
                                cout << "That answer was not an integer." << endl;
                        }

                        getchar();

                }
        }

        if (lives < 1) {
                cout << "Game over!" << endl;
        }

        return 0;
}