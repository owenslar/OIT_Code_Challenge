#include <iostream>

#include <string>
#include <fstream>
#include <vector>
#include <unordered_set>

// used for generating random number
#include <cstdlib> 
#include <ctime>

using namespace std;

// temporary function to help test
void print_vector(vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
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

    cout << "Word: " << solution_word << endl;

    return 0;
}

