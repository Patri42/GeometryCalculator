#ifndef ROCK_PAPER_SCISSORS_H
#define ROCK_PAPER_SCISSORS_H

#include <time.h>
#include "game_data.h"

void rock_paper_scissors();
GameResult game_result(int user_choice, int computer_choice);

#endif