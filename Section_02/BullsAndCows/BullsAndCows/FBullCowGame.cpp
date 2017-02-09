//
//  FBullCowGame.cpp
//  BullsAndCows
//
//  Created by Tristan McGuire on 07/02/2017.
//  Copyright © 2017 Tristan McGuire. All rights reserved.
//

#include "FBullCowGame.hpp"

FBullCowGame::FBullCowGame() { FBullCowGame::Reset(); } // Constructor

// Getters
int32 FBullCowGame::GetMaxTries() const { return 3; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return (int32)MyHiddenWord.length(); }

bool FBullCowGame::GetWinStatus() const { return false; }


void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 3;
    const FString HIDDEN_WORD = "planet";
    
    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;
    
    return;
}

EGuessStatus FBullCowGame::GetGuessValidity(FString Guess) const
{
    if (false) // if guess isn't an isogram
    {
        return EGuessStatus::NotIsogram;
    }
    else if (Guess.length() != GetHiddenWordLength()) // if the guess isn't the right length
    {
        return EGuessStatus::WrongLength;
    }
    else if (false) // if the guess isn't lowercase
    {
        return EGuessStatus::NotLowercase;
    }
    else // otherwise
    {
        return EGuessStatus::OK;
    }
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
    MyCurrentTry++;
    FBullCowCount BullCowCount;
    
    for (int32 i = 0; i < MyHiddenWord.length(); i++)
    {
        for (int32 j = 0; j < MyHiddenWord.length(); j++)
        {
            if (i == j && Guess[i] == MyHiddenWord[i])
            {
                BullCowCount.Bulls++;
            }
            else if (i != j && Guess[i] == MyHiddenWord[j])
            {
                BullCowCount.Cows++;
            }
            else
            {
                // nothing;
            }
        }
    }
    return BullCowCount;
}