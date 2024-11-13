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

int main() {
    cout << "Welcome to Hangman!" << endl;

    // Grabbing words from words.txt and putting them in a vector
    ifstream input("words.txt");
    vector<string> words_vector;
    while (!input.eof()) {
        string word;
        getline(input, word);
        words_vector.push_back(word);
    }

    // randomly select a word from list of words
    srand(static_cast<unsigned>(time(nullptr)));
    string solution_word = words_vector[rand() % words_vector.size()];

    cout << solution_word << endl;

    cout << "The word has " << solution_word.size() << " letters" << endl;
    
    // create solution vector, blank vector, and guess vector
    vector<string> guess_vector;
    vector<string> blank_vector;
    vector<string> solution_vector;
    create_filled_vector(guess_vector, "", solution_word.size());
    create_filled_vector(blank_vector, "_", solution_word.size());
    create_solution_vector(solution_vector, solution_word);

    // main loop that perpetuates the game
    // while (true) {
    //     string guess;
    //     cout << "Guess a letter: ";
    //     getline(cin, guess);
    //     // in case user enters nothing, or 2 or more letters
    //     if (guess.size() > 1 || guess.empty()) {
    //         cout << "Please enter a singular letter" << endl;
    //         continue;
    //     }
    // }

    return 0;
}

