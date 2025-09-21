#include <bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;

void welcome() {
    cout << "Welcome to Guessing Number Game!" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "Choose Difficulty:" << endl;
    cout << "1 - Easy" << endl;
    cout << "2 - Medium" << endl;
    cout << "3 - Hard" << endl;
    cout << "Choose: ";
}

void easy() {
    cout << "You chose Easy Mode!" << endl;
    this_thread::sleep_for(chrono::milliseconds(200));

    int num = (rand() % 10) + 1;
    int n;

    cout << "Guess a number between 1 and 10: ";
    cin >> n;

    while (n != num) {
        if (n > num) {
            cout << "Too high!" << endl;
        } else {
            cout << "Too low!" << endl;
        }

        if (abs(n - num) <= 3) {
            cout << "You are near!" << endl;
        }

        cout << "Try again: ";
        cin >> n;
    }

    cout << " Yeah! You got it, the number is: " << num << endl;
}

void medium() {
    cout << "You chose Medium Mode!" << endl;

    int num = (rand() % 50) + 1;
    int n;

    cout << "Guess a number between 1 and 50: ";
    cin >> n;

    while (n != num) {
        if (n > num) {
            if (abs(n - num) <= 5) {
                cout << "very close!" << endl;
            } else if (abs(n - num) <= 8) {
                cout << " near!" << endl;
            } else {
                cout << "Too high!" << endl;
            }
        } else {
            if (abs(n - num) <= 5) {
                cout << "very close!" << endl;
            } else if (abs(n - num) <= 8) {
                cout << "near!" << endl;
            } else {
                cout << "Too low!" << endl;
            }
        }

        cout << "Try again: ";
        cin >> n;
    }

    cout << "Yeah! You got it, the number is: " << num << endl;
}

void hard() {
    cout << "You chose Hard Mode!" << endl;

    int num = (rand() % 100) + 1;
    int n;
    int attempts = 7;

    cout << "Guess the number between 1 and 100. You have " << attempts << " attempts!" << endl;

    while (attempts > 0) {
        cout << "Enter your guess: ";
        cin >> n;

        if (n == num) {
            cout << "Amazing! You guessed it, the number is: " << num << endl;
            return;
        } else if (n > num) {
            cout << "Too high!" << endl;
        } else {
            cout << "Too low!" << endl;
        }

        attempts--;
        cout << "Attempts left: " << attempts << endl;

        if (attempts == 0) {
            cout << "Game over! The number was: " << num << endl;
        }
    }
}

int main() {
    srand(time(0));

    welcome();
    int choice;
    cin >> choice;

    if (choice == 1) {
        easy();
    } else if (choice == 2) {
        medium();
    } else if (choice == 3) {
        hard();
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
