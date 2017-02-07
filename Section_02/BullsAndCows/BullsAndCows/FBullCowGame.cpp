//
//  FBullCowGame.cpp
//  BullsAndCows
//
//  Created by Tristan McGuire on 07/02/2017.
//  Copyright © 2017 Tristan McGuire. All rights reserved.
//

#include "FBullCowGame.hpp"

FBullCowGame::FBullCowGame() { FBullCowGame::Reset(); }


int FBullCowGame::GetMaxTries() const { return 3; }

int FBullCowGame::GetCurrentTry() const { return FBullCowGame::MyCurrentTry; }

bool FBullCowGame::IsGameWon() const { return false; }


void FBullCowGame::Reset()
{
    constexpr uint8_t MAX_TRIES = 3;
    FBullCowGame::MyMaxTries = MAX_TRIES;
    FBullCowGame::MyCurrentTry = 1;
    return;
}

void FBullCowGame::SetCurrentTry(uint8_t Try)
{
    FBullCowGame::MyCurrentTry = Try;
    return;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
    return false;
}