#include <iostream>

#include <string>
#include <fstream>
#include <vector>
#include <unordered_set>

using namespace std;

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
    // cout << "vector: " << words_vector << endl;
    print_vector(words_vector);

    return 0;
}

