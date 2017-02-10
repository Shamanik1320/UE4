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


####Lecture 30 - Pseudocode Programming
TODO - note where existing code needs to change.
Other comments for new functionality.

using int32 = int;            substituting unreal programming standard language.
                              int32 rather than int is for cross platform conformity.

using FText = std::string;    FText indicates display string.  Any text that
                              is to be displayed to a user should be in FText
                              format.  Used for localisation etc. (immutable)

using FString = std::string;  FString is a string type that can be manipulated.
                              (mutable)
####Lecture 42 - Big 'O' Notation

Number of comparisons necessary to check the letters of the word 'planet'
  P L A N E T         x = unnecessary to compare letter to itself.
P x . . . . .         o = comparison in one direction
L o x . . . .         . = comparison in other direction
A o o x . . .
N o o o x . .         unnecessary to compare in both directions so
E o o o o x .         number of letters (n) times itself (whole range including
T o o o o o x         unnecessary comparisons) - n (number of letters to remove
                      comparisons to self) divided by 2 (to remove unnecessary
                      duplication of comparisons) gives the number of necessary
                      comparisons, ie: ((n^2)-n)/2

So a word of ten letter would require ((10*10)-10)/2 or 45 comparisons.  This is an
exponential increase in number of operations which is noted as O(n^2).  exponential
increases in operations to solve problems are inefficient solutions.

O(n) would be the theoretical fastest - any comparison would need to look at each
letter in the word at least once.

Using a sorting algorithm can achieve O(n log n), so sorting followed by a check for
repeating letters in the sorted list should be much faster than a simple loop
comparing each letter to each other letter.

Using a hash table to count instances is even better.  You can achieve O(n) this way.
