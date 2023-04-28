#ifndef GAME_DATA_H
#define GAME_DATA_H

// Header file defines the data structures and functions for handling game data,
// such as saving game results for the rock-paper-scissors game.

typedef enum {
    DRAW,
    WIN,
    LOSE
} GameResult;


// Saves the game result, updating the total number of games played and the number of wins.
// Takes the result of the game (GameResult), the total number of games played so far,
// and the total number of wins.
void save_game_result(GameResult result, int total_games, int wins);

#endif