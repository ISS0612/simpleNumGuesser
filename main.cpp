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

bool exitProgram = false;

int diffSelector() {
        bool debounce = false;
        int retries = 0;

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
                exitProgram = true;
        }

        return 0;
}

int roundsSelector() {
        bool debounce = false;
        int retries = 0;

        for (int i = RETRY_MAX; i > 0 && debounce != true; i--) {
                debounce = true;

                cout << "How many rounds would you like to play?" << endl
                        << "(MAX = " << ROUNDS_MAX << ")" << endl
                        << "(MIN = " << ROUNDS_MIN << ")" << endl;
                cin >> rounds;
                
                if (rounds <= ROUNDS_MAX && rounds >= ROUNDS_MIN) {
                        cout << "You will play " << rounds << " rounds." << endl;
                } else if (rounds < ROUNDS_MIN) {
                        cout << "You want to play too few rounds. Try again." << endl;
                        debounce = false;
                        retries += 1;
                        cin.clear();
                } else if (rounds > ROUNDS_MAX) {
                        cout << "You want to play too many rounds. Try again." << endl;
                        debounce = false;
                        retries += 1;
                        cin.clear();
                } else {
                        cout << "You did not enter a valid number. Try again" << endl;
                        debounce = false;
                        retries += 1;
                        cin.clear();
                }
        }

        if (retries == RETRY_MAX) {
                cout << "Too many attempts. Exiting program." << endl;
                exitProgram = true;
        }

        return 0;
}

int genAnswer() {
        srand(time(NULL));

        if (difficulty == 1) {
                answer = rand() % 50 + 1;
        } else if (difficulty == 2) {
                answer = rand() % 100 + 1;
        } else if (difficulty == 3) {
                answer = rand() % 150 + 1;
        } else {
                cout << "Invalid difficulty: " << difficulty << endl;
        }

        return 0;
}

int getGuess() {
        int guess;

        cin.clear();

        cout << "Type your answer: " << endl;

        cin >> guess;

        return guess;
}

int main() {
        bool hasWon = false;

        diffSelector();
        if (exitProgram == true) {
                cout << "Missing critical values. Exiting program." << endl;

                return 0;
        }
        roundsSelector();
        if (exitProgram == true) {
                cout << "Missing critical values. Exiting program." << endl;

                return 0;
        }

        for (rounds; rounds > 0; rounds--) {
                genAnswer();

                if (lives < 0) {
                        break;
                }

                for (lives; lives > 0 || rounds > 0; lives--) {
                        if (lives < 0) {
                                break;
                        }
                        
                        // cout << "DEBUG: The answer is " << answer << endl;
                        
                        int guess = getGuess();
                        
                        if (guess == answer) {
                                cout << "You got it right!" << endl;
                                hasWon = true;

                                break;
                        } else if (guess > answer) {
                                cout << "Sorry! That answer was too high!" << endl;
                                hasWon = false;
                        } else if (guess < answer) {
                                cout << "Sorry! That answer was too low!" << endl;
                                hasWon = false;
                        } else {
                                cout << "You have not entered a valid number.";
                                lives += 1;
                        }

                        if (lives > 0) {
                                cout << "You have " << lives << " live left!" << endl;
                        } else {
                                cout << "No lives left! Game over!" << endl;
                        }
                }
        }

        return 0;
}