##Notes

###Udemy UE and C++ - Section 2 - Bulls and cows

####Lecture 11, Game Design Document

###### How much planning should we do?
  For this game (Bulls and Cows), not too much.  It's a simple game, maybe an hour.

###### the emotional problem the game solves?
  Games scratch emotional itches.
  - I want a mental challenge
  - I want to feel smart/prove myself
  - I like word puzzles
  - I want to challenge (feel superior to) someone.

###### concept, rules, and requirements?
  - Guess the isogram game.
  - Isogram is a word with no repeating letters.
  - User has a ltd no. of guesses
  - After each guess the game outputs:
      - Bull = right letter in right location
      - Cow = right letter, wrong location
  - Win by guessing the word within the set maximum number of guesses.

###### architecture?

###### copy as much as possible into the code.

###### document now what may change later (not now list)
Not now list:
  - give feedback on every key press.
  - have a large dictionary of words
  - user selectable word length and difficulty.
  - checking the users guess is a dictionary isogram (for adding to dictionary.)
  - time limit for guesses
  - hint system, spend a turn for a hint

###### initial requirements for assets, code, etc.
  - what will the inputs be?
      - text guesses.
  - what will the outputs be?
      - Text/ASCII indicating bulls or cows.
      - text to help user make guesses (all lowercase, etc.)/ plaintext instructions.
  - what tasks will the user be asked to do?
      - type guesses.
  - any performance limits worth mentioning?
      - no.  Simple text game, no modern computer should
        have difficulty running this.
  - What assets are required (art, sound, etc.)?
      - none.
  - Code:
      - code to display instructions and help
      - code to check guesses:
          - how many bulls and cows compared to hidden word
      - Code to keep track of number of valid guesses.


####Lecture 18 - Simplifying with functions
Managing complexity - make it readable.

Abstraction - for managing complexity by considering things at a higher level

Encapsulation - a means of ensuring that abstractions are adhered to.
