//
//  main.cpp
//  BullsAndCows
//
//  Created by Tristan McGuire on 07/02/2017.
//  Copyright © 2017 Tristan McGuire. All rights reserved.
//

#include <iostream>

using namespace std;

// prototypes
void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

// constants

// main
int main(void)
{
    PrintIntro();
    PlayGame();  // consistent level of abstraction throughout.
    cout << AskToPlayAgain();

    cout << endl;
    return 0;
}

// introduce the game
void PrintIntro()
{
    constexpr size_t WORD_LENGTH = 9;
    cout << "Welcome to Bulls and Cows, a fun word game!\n";
    cout << "Can you guess the " << WORD_LENGTH << " letter word I'm thinking of?\n";
    return;
}

// run the game
void PlayGame()
{
    constexpr size_t NUMBER_OF_TURNS = 3;
    for (int count = 0; count < NUMBER_OF_TURNS; count++)
    {
        string Guess = GetGuess();
        cout << "Your guess was - " << Guess << endl;
    }
    return;
}

// get a guess from the user and print to screen
string GetGuess()
{
    string Guess;
    cout << "\nEnter your guess: ";
    getline(cin, Guess);
    return Guess;
}

// play again?
bool AskToPlayAgain()
{
    cout << "\nPlay Again? (yes or no): ";
    string Answer = "";
    getline(cin, Answer);
    return Answer[0] == 'y' || Answer[0] == 'Y';
}