#include <iostream>

#include <string>
#include <fstream>
#include <vector>
#include <unordered_set>

// used for generating random number
#include <cstdlib> 
#include <ctime>

using namespace std;

// function that prints out values in a vector
void print_vector(vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
    }
    cout << endl;
}

// function that creates a vector filled with the specified item
void create_filled_vector(vector<string> &filled_vector, string fill_item, int vector_size) {
    for (int i = 0; i < vector_size; i++) {
        filled_vector.push_back(fill_item);
        filled_vector.push_back(" ");
    }
    return;
}

// function that creates a vector with the letters to the solution word in it
void create_solution_vector(vector<string> &solution_vector, string solution) {
    for (int i = 0; i < solution.size(); i++) {
        string letter = string(1, solution[i]);
        solution_vector.push_back(letter);
    }
    return;
}

// function that creates a set containing the letters in the solution word
void create_set(unordered_set<string> &set, string solution) {
    for (int i = 0; i < solution.size(); i++) {
        string letter = string(1, solution[i]);
        set.insert(letter);
    }
}

// main function that is called when the executable file is ran
int main() {
    cout << "-----Welcome to Owen Larson's Hangman!-----" << endl << endl << endl;

    // Grabbing words from words.txt and putting them in a vector
    ifstream input("words.txt");
    vector<string> words_vector;
    while (!input.eof()) {
        string word;
        getline(input, word);
        words_vector.push_back(word);
    }

    // variable used to determine if the user wants to play again
    string restart;

    // the game will run as long as restart is 'y' or 'Y'
    do {
        
        // randomly select a word from list of words
        srand(static_cast<unsigned>(time(nullptr)));
        string solution_word = words_vector[rand() % words_vector.size()];

        cout << "The mystery word has " << solution_word.size() << " letters" << endl << endl;
        
        // create solution vector, blank vector, incorrect guess vector, and guess vector
        vector<string> guess_vector;
        vector<string> blank_vector;
        vector<string> solution_vector;
        vector<string> incorrect_guesses;
        create_filled_vector(guess_vector, " ", solution_word.size());
        create_filled_vector(blank_vector, "_", solution_word.size());
        create_solution_vector(solution_vector, solution_word);

        // create set that contains all the letters in the word
        unordered_set<string> solution_set;
        create_set(solution_set, solution_word);

        // create counter variables
        int total_guesses = 0;
        int correct_counter = 0;
        int incorrect_counter = 0;

        // main loop that perpetuates the game
        while (true) {


            // check if they have solved the word, exit the loop if so
            if (solution_set.empty()) {
                cout << "You guessed the word! The word was: " << solution_word << "." << endl;
                cout << "It took you " << total_guesses << "guesses." << endl;
                break;
            }

            // get a guess from the player
            string guess;
            cout << "Guess a letter: ";
            getline(cin, guess);

            // in case user enters nothing, or 2 or more letters, prompt them again
            if (guess.size() > 1 || guess.empty()) {
                cout << "Please enter a singular letter" << endl;
                continue;
            }
            total_guesses += 1;

            // print the current guess to help with formatting and to make the game look better in the terminal
            cout << endl << "---Guess " << total_guesses << "---" << endl << endl;
            
            // check if guess is in solution; add it to guess vector if it is, and 
            // remove that letter from the set. If not, 
            // add it to incorrect guesses vector, and increment the guess counters;
            bool contains_guess = false;
            for (int i = 0; i < solution_vector.size(); i++) {
                if (solution_vector[i] == guess) {
                    contains_guess = true;
                    guess_vector[i*2] = guess;
                    solution_set.erase(guess);
                }
            }
            if (contains_guess == false) {
                cout << "The letter: " << guess << " is not in the word" << endl;
                incorrect_guesses.push_back(guess);
                incorrect_guesses.push_back(" ");
                incorrect_counter += 1;
            }
            else {
                cout << "Correct guess!" << endl << endl;
                correct_counter += 1;
            }

            // print out their progress after each guess including thier current progress, the incorrect guess history, and the number of guesses
            print_vector(guess_vector);
            print_vector(blank_vector);
            cout << endl;
            print_vector(incorrect_guesses);
            cout << "You have made " << correct_counter + incorrect_counter << " total guesses, " << correct_counter << " correct and " << incorrect_counter << " incorrect."<< endl << endl;

        }

        // check if they want to play again
        cout << "Would you like to play again? (y/n): ";
        cin >> restart;

    } while (restart == "y" || restart =="Y");  // execute everything in main if their choice is "y"

    // in the event they choose to quit, thank them for playing
    cout << "Thank you for playing Owen Larson's Hangman Game" << endl;

    // program finished
    return 0;
}

