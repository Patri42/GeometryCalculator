#ifndef ROCK_PAPER_SCISSORS_H
#define ROCK_PAPER_SCISSORS_H

// Header file defines the functions for the rock-paper-scissors game.
// It includes the main game function (rock_paper_scissors) and a helper function (game_result)
// to determine the result of the game based on the user's and computer's choices.

#include <time.h>
#include "game_data.h"

// Starts a new rock-paper-scissors game and handles user input and game logic.
void rock_paper_scissors();

// Determines the result of a rock-paper-scissors game based on the user's choice and the computer's choice.
// Returns a GameResult value (WIN, LOSE, or DRAW) based on the outcome.
GameResult game_result(int user_choice, int computer_choice);

#endif