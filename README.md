# OIT Code Challenge

Started working at 3:50pm on Wednesday November 13th

My git commits will demonstrate the progress of my work.

## Notes Before Coding
- Plan
    - I will complete this challenge using c++ as the coding language, and I will use a terminal interface
    - After reading the instructions, I am planning to use a number of arrays in the form of c++ vectors to store the answer and the guesses
    - I also am planning to use a set to keep track of the letters that have been guessed and have not been guessed
    - I plan to have a main loop that perpetuates the game, and possibly a number of helper functions to assist in the intermediate steps of the game.
    - I also plan to include the words in a separate text file, to make it easy to change or add to the list of possible words without changing the code. 

## After Coding

I finished working at 6:26pm on Wednesday November 13th

This GitHub Repository contains:
- `hangman.cpp` (source code)
- `words.txt` (10 random words used for the game)
- `windows_executable.exe` (executable version of the source code for windows)
- `macOS_executable.exe` (ececutable version of the source code for macOS)
- `README.md`

## Explanation (How my implementation works)
- Step 1
    1. The program reads the words from the file 'words.txt' into an array.
- Step 2
    1. The program begins a loop that will repeat if the player decides to play the game again
- Step 3
    1. The program randomly selects a word from the array containing the words to be the solution
- Step 4
    1. The program creates an array containing all spaces that will be filled in as the player makes correct guesses
    2. The program creates an array containing underscores to represent the word the player is trying to guess
    3. The program creates a solution array that contains the letters to the solution word in order
    4. The program creates a set containing the letters in the solution word
    5. The program creates counter variables for the total guesses, the correct guesses, and the incorrect guesses
- Step 5
    1. The program begins a loop that will continuously prompt the player for a guess, and process that guess until the word is guessed
- Step 6 (within the loop from step 5)
    1.  Within this loop, the program checks if the set created earlier is empty, signifying the player guessing the entire word. If it is, the program ends the game and asks the player if they want to play again.
    2. The program then prompts the player to enter a guess
    3. The program ensures that the player entered a single letter, and prompts them again if not.
    4. If the player enters 'quit' at this point they can exit the game before finishing.
    5. The program then checks to see if the letter they guessed is within the solution array
        - If it is, it changes those indicies of the empty guess array to be that letter, increments the correct guess counter, and removes that letter from the solution set.
        - If not, the program adds the letter to the incorrect guess array, and increments the incorrect guess counter.
    7. The program then prints out the specified information for the player to know what they have guessed up to that point
    8. Once the player guesses the word, the program congratulates them, tells them how many guesses it took them, then asks them if they would like to play again.
- Step 7
    1. If the player chooses not to play again, the program thanks them for playing the game and exits.

## Windows Executable
I have a macOS machine, so I am not sure if the windows executable file will work. I followed instructions online to create the windows executable file, so I apoligize if the executable file does not work correctly. Ultimately, I included the source code, which can be used to create a new executable if that one does not work.