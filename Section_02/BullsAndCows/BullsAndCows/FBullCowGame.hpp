//
//  FBullCowGame.hpp -  describes the FBullCowGame class and the data structures
//                      used in it.
//  BullsAndCows
//
//  Created by Tristan McGuire on 07/02/2017.
//  Copyright © 2017 Tristan McGuire. All rights reserved.
//

#pragma once

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <string>

// Substitutions to emulate Unreal syntax/types. 
using FString = std::string;
using int32 = int;

struct FBullCowCount {
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EGuessStatus {
    OK,
    NotIsogram,
    WrongLength,
    NotLowercase,
    Invalid
};

class FBullCowGame
{
public:
    FBullCowGame(); // Constructor
    
    void Reset();
    
    // Getters
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    bool GetWinStatus() const;
    EGuessStatus GetGuessValidity(FString Guess) const;
    
    FBullCowCount SubmitValidGuess(FString Guess);
    
private:
    // see constructor for initialisation.
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
    bool bIsGameWon;
    
    bool IsIsogram(FString Guess) const;
    bool IsLowerCase(FString Guess) const;
};

#endif /* FBullCowGame_hpp */
