#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <ctime>
using namespace std;

const int RETRY_MAX = 3;
const int ROUNDS_MAX = 10;
const int ROUNDS_MIN = 1;
int difficulty;
int rounds;
int answer;
int lives;

int diffSelector() {
        bool debounce = false;
        int retries = 0;
        /*
        cout << "Choose a difficulty! Enter the corresponding number:" << endl
                << "Easy = 1" << endl
                << "Medium = 2" << endl
                << "Hard = 3" << endl;
        cin >> difficulty;
        */

        for (int i = RETRY_MAX; i > 0 && debounce != true; i--) {
                debounce = true;

                cout << "Choose a difficulty! Enter the corresponding number:" << endl
                        << "Easy = 1" << endl
                        << "Medium = 2" << endl
                        << "Hard = 3" << endl;
                cin >> difficulty;
                
                if (difficulty == 1) {
                        cout << "Selected 'Easy' mode. You have 10 lives." << endl;
                        lives = 10;
                } else if (difficulty == 2) {
                        cout << "Selected 'Medium' mode. You have 5 lives." << endl;
                        lives = 5;
                } else if (difficulty == 3) {
                        cout << "Selected 'Hard' mode. You have 1 life." << endl;
                        lives = 1;
                } else {
                        cout << "You have not entered a valid difficulty. Try again." << endl;
                        debounce = false;
                        retries += 1;
                        cin.clear();
                }
        }

        if (retries == RETRY_MAX) {
                cout << "Too many attempts. Exiting program." << endl;
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
        srand (time(NULL));

        diffSelector();
        genAnswer();

        return 0;
}