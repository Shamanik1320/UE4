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
void PrintSummary();
void PlayGame();
FText GetValidGuess();
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

void PrintSummary()
{
    if (BCGame.GetWinStatus())
    {
        std::cout << "Well played, you win!\n";
    }
    else
    {
        std::cout << "Better luck next time.\n";
    }
    return;
}

// run the game
void PlayGame()
{
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    
    while (!BCGame.GetWinStatus() && BCGame.GetCurrentTry() <= MaxTries)
    {
        FText Guess = GetValidGuess();
        FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
        
        std::cout   << "Bulls = " << BullCowCount.Bulls
                    << " Cows = " << BullCowCount.Cows
                    << std::endl;
    }
    
    PrintSummary();
    
    return;
}

FText GetValidGuess()
{
    FText Guess;
    EGuessStatus Status = EGuessStatus::Invalid;
    
    do {
        std::cout << "\nTry " << BCGame.GetCurrentTry() << " Enter your guess: ";
        std::getline(std::cin, Guess);
    
        Status = BCGame.GetGuessValidity(Guess);
        
        switch (Status) {
            case EGuessStatus::NotIsogram:
                std::cout << "\nYour guess must not have any repeated letters.\n";
                break;
            case EGuessStatus::WrongLength:
                std::cout << "\nYour guess must be " << BCGame.GetHiddenWordLength() << " letters long.\n";
                break;
            case EGuessStatus::NotLowercase:
                std::cout << "\nYour guess must use only lowercase letters.\n";
                break;
            default:
                std::cout << "\nGood Guess!\n";
                break;
        }
    } while (Status != EGuessStatus::OK);
    
    return Guess;
}

bool AskToPlayAgain()
{
    std::cout << "\nPlay Again with the same hidden word? (y/n): ";
    FText Answer = "";
    std::getline(std::cin, Answer);
    return Answer[0] == 'y' || Answer[0] == 'Y';
}