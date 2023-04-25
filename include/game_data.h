#ifndef GAME_DATA_H
#define GAME_DATA_H

typedef enum {
    DRAW,
    WIN,
    LOSE
} GameResult;

void save_game_result(GameResult result, int total_games, int wins);

#endif