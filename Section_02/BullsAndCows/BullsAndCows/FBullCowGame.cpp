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

bool FBullCowGame::GetWinStatus() const { return bIsGameWon; }


void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 3;
    const FString HIDDEN_WORD = "planet";
    
    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;
    bIsGameWon = false;
    
    return;
}

EGuessStatus FBullCowGame::GetGuessValidity(FString Guess) const
{
    if (false) // if guess isn't an isogram
    {
        return EGuessStatus::NotIsogram; // TODO write code to check if isogram
    }
    else if (Guess.length() != GetHiddenWordLength())
    {
        return EGuessStatus::WrongLength;
    }
    else if (false) // if the guess isn't lowercase
    {
        return EGuessStatus::NotLowercase; // TODO write code to check case
    }
    else
    {
        return EGuessStatus::OK;
    }
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
    MyCurrentTry++;
    FBullCowCount BullCowCount;
    int32 WordLength = (int32)MyHiddenWord.length(); // valid Guess is same length.
    
    for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
    {
        for (int32 GChar = 0; GChar < WordLength; GChar++)
        {
            if (Guess[GChar] == MyHiddenWord[MHWChar])
            {
                if (GChar == MHWChar)
                {
                    BullCowCount.Bulls++;
                    if (BullCowCount.Bulls == GetHiddenWordLength()) {
                        bIsGameWon = true;
                    }
                }
                else
                {
                    BullCowCount.Cows++;
                }
                
            }
        }
    }
    return BullCowCount;
}
