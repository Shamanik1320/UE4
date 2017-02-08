//
//  main.cpp
//  BullsAndCows -  This is the main console executable that makes use of the
//                  BullCow class.  It acts as the view part of an MVC pattern
//                  and is responsible for user interaction.  See FBullCowGame
//                  for functionality.
//
//  Created by Tristan McGuire on 07/02/2017.
//  Copyright © 2017 Tristan McGuire. All rights reserved.
//

#include <iostream>
#include "FBullCowGame.hpp"

using FText = std::string;
using int32 = int;

// prototypes
void PrintIntro();
void PlayGame();
FText GetGuess();
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
    std::cout << "Welcome to Bulls and Cows, a fun word game!\n";
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter word I'm thinking of?\n";
    return;
}

// run the game
void PlayGame()
{
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    
    for (int32 count = 0; count < MaxTries; count++)
    {
        FText Guess = GetGuess();  // TODO loop to test for validity of guess
        
        FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
        std::cout << "Bulls = " << BullCowCount.Bulls << " Cows = " << BullCowCount.Cows << std::endl;
    }
    
    // TODO add game summary
    
    return;
}

// get a guess from the user and print to screen
FText GetGuess()
{
    FText Guess;
    
    std::cout << "\nTry " << BCGame.GetCurrentTry() << " Enter your guess: ";
    std::getline(std::cin, Guess);
    
    return Guess;
}

// play again?
bool AskToPlayAgain()
{
    std::cout << "\nPlay Again? (y/n): ";
    FText Answer = "";
    std::getline(std::cin, Answer);
    return Answer[0] == 'y' || Answer[0] == 'Y';
}