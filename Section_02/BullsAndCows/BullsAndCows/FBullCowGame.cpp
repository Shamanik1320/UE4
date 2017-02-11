//
//  FBullCowGame.cpp - Implements the functionality of the FBullCowGame class.
//  BullsAndCows
//
//  Created by Tristan McGuire on 07/02/2017.
//  Copyright © 2017 Tristan McGuire. All rights reserved.
//

#include "FBullCowGame.hpp"
#include <map>
#define TMap std::map // Substitution to emulate Unreal syntax/types. 

FBullCowGame::FBullCowGame() { FBullCowGame::Reset(); } // Constructor

// Getters
int32 FBullCowGame::GetMaxTries() const
{
    TMap<int32, int32> WordLengthToMaxTries {{3,5},{4,6},{5,7},{6,8},{7,9}};
    return WordLengthToMaxTries[(int32)MyHiddenWord.length()];
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return (int32)MyHiddenWord.length(); }

bool FBullCowGame::GetWinStatus() const { return bIsGameWon; }


void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 3;
    const FString HIDDEN_WORD = "plane";
    
    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;
    bIsGameWon = false;
    
    return;
}

EGuessStatus FBullCowGame::GetGuessValidity(FString Guess) const
{
    if (!IsIsogram(Guess))
    {
        return EGuessStatus::NotIsogram;
    }
    else if (Guess.length() != GetHiddenWordLength())
    {
        return EGuessStatus::WrongLength;
    }
    else if (!IsLowerCase(Guess))
    {
        return EGuessStatus::NotLowercase; 
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

bool FBullCowGame::IsIsogram(FString Guess) const
{
    if (Guess.length() <= 1)
    {
        return true;
    }
    
    TMap <char, bool> LetterSeen;
    
    for (auto Letter : Guess)
    {
        Letter = tolower(Letter); //handle mixed case
        if (LetterSeen[Letter])
        {
            return false;
        }
        else
        {
            LetterSeen[Letter] = true;
        }
    }
    
    return true; // in case of other input eg - /0
}

bool FBullCowGame::IsLowerCase(FString Guess) const
{
    for (auto Letter : Guess)
    {
        if (!islower(Letter)) {
            return false;
        }
    }
    return true;
}





