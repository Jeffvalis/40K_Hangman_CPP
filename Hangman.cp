#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class HangmanGame {
private:
    vector<string> words{"custodian","imperium","spacewolf","chaos", "eldar", "tyranid", "ork", "necron", "mechanicus", "inquisition", "heresy", "bolter", "warp", "khorne", "imperialguard", "wargear"};
    string secretWord;
    string guessedWord;
    int maxAttempts;
    int attemptsLeft;


public:
    HangmanGame() : maxAttempts(6), attemptsLeft(maxAttempts) {
        // Seed for random word selection
        srand(static_cast<unsigned int>(time(nullptr)));

        // Select a random word
        int randomIndex = rand() % words.size();
        secretWord = words[randomIndex];

        // Initialize guessed word with underscores
        guessedWord = string(secretWord.length(), '_');
    }

    void displayGameStatus() const {
        cout << "Secret Word: " << guessedWord << endl;
        cout << "Attempts Left: " << attemptsLeft << endl;
    }

    void guessLetter(char letter) {
        size_t found = secretWord.find(letter);

        if (found != string::npos) {
            // Update guessed word with correctly guessed letter
            while (found != string::npos) {
                guessedWord[found] = letter;
                found = secretWord.find(letter, found + 1);
            }

            cout << "Correct guess!" << endl;
        } else {
            cout << "Incorrect guess. Try again!" << endl;
            attemptsLeft--;
        }
    }

    bool isGameOver() const {
        // Game is over if either the word is guessed or there are no attempts left
        return (secretWord == guessedWord) || (attemptsLeft <= 0);
    }

    void displayResult() const {
        if (secretWord == guessedWord) {
            cout << "Congratulations! You guessed the word: " << secretWord << endl;
        } else {
            cout << "Sorry, you ran out of attempts. The correct word was: " << secretWord << endl;
        }
    }
};

int main() {
    cout << "Welcome to Hangman Game!" << endl;
    cout<<"Go through the brief below to find the word" << endl;
    cout<<"In the vast Imperium, a lone Custodian battled Spacewolf Chaos."<<endl;
    cout<<"Eldar warned of Tyranid swarms, Ork mayhem, and Necron resurgence."<<endl;
    cout<<"Mechanicus toiled to unveil ancient secrets. Inquisitors sought heresy"<<endl;
    cout<<"bolters blazing. Warp rifts widened, Khorne stirred. Imperial Guard defended, clad in wargear."<<endl;
    cout<<"The galaxy trembled in uncertainty."<<endl;


    HangmanGame game;

    while (!game.isGameOver()) {
        cout << "\n";
        game.displayGameStatus();

        char guess;
        cout << "Enter your guess (a letter): ";
        cin >> guess;

        // Convert the guess to lowercase
        guess = tolower(guess);

        game.guessLetter(guess);
    }

    game.displayResult();

    cout << "Thanks for playing 40K Hangman!" << endl;
    cout << "Thanks for playing 40K Hangman!" << endl;
    cout << "Thanks for playing 40K Hangman!" << endl;

    return 0;
}
