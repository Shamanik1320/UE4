//
//  main.cpp
//  BullsAndCows
//
//  Created by Tristan McGuire on 07/02/2017.
//  Copyright © 2017 Tristan McGuire. All rights reserved.
//

#include <iostream>
#include "FBullCowGame.hpp"

// prototypes
void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

// global

FBullCowGame BCGame;  // new game instance.

// main
int main(void)
{
    do {
        PrintIntro();
        PlayGame();  
        std::cout << std::endl;
    } while (AskToPlayAgain());

    return 0;
}

// introduce the game
void PrintIntro()
{
    constexpr size_t WORD_LENGTH = 9;
    std::cout << "Welcome to Bulls and Cows, a fun word game!\n";
    std::cout << "Can you guess the " << WORD_LENGTH << " letter word I'm thinking of?\n";
    return;
}

// run the game
void PlayGame()
{
    BCGame.Reset();
    uint8_t MaxTries = BCGame.GetMaxTries();
    
    for (int count = 0; count < MaxTries; count++)
    {
        std::string Guess = GetGuess();
        std::cout << "Your guess was - " << Guess << std::endl;
    }
    return;
}

// get a guess from the user and print to screen
std::string GetGuess()
{
    uint8_t CurrentTry = BCGame.GetCurrentTry();
    std::string Guess;
    
    std::cout << "\nTry " << BCGame.GetCurrentTry() << " Enter your guess: ";
    std::getline(std::cin, Guess);
    
    CurrentTry++;
    BCGame.SetCurrentTry(CurrentTry);
    
    return Guess;
}

// play again?
bool AskToPlayAgain()
{
    std::cout << "\nPlay Again? (y/n): ";
    std::string Answer = "";
    std::getline(std::cin, Answer);
    return Answer[0] == 'y' || Answer[0] == 'Y';
}