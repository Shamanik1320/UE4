//
//  FBullCowGame.hpp
//  BullsAndCows
//
//  Created by Tristan McGuire on 07/02/2017.
//  Copyright © 2017 Tristan McGuire. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <string>
#include <cstdint>

class FBullCowGame
{
public:
    FBullCowGame(); // Constructor
    
    int GetMaxTries() const;
    int GetCurrentTry() const;
    bool IsGameWon() const;
    
    void Reset();                           
    void SetCurrentTry(uint8_t Try);
    bool CheckGuessValidity(std::string);   // TODO: make a richer return value.

    // ^^ Try to ignore this and focus on the interface above ^^
private:
    // see constructor for initialisation.
    uint8_t MyCurrentTry;
    uint8_t MyMaxTries;
};

#endif /* FBullCowGame_hpp */
