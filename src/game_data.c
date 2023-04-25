#include <stdio.h>
#include <time.h>
#include "game_data.h"
#include "rock_paper_scissors.h"

GameResult game_result(int user_choice, int computer_choice){
    if (user_choice == computer_choice)
        return DRAW;

    if ((user_choice == 1 && computer_choice == 3) ||
        (user_choice == 2 && computer_choice == 1) ||
        (user_choice == 3 && computer_choice == 2)){
        return WIN;
	}
    
    return LOSE;
}

void save_game_result(GameResult result, int total_games, int wins) {
    // Open the file in append mode
    FILE *file = fopen("game_results.txt", "a");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Get the current time
    time_t raw_time;
    struct tm *time_info;
    time(&raw_time);
    time_info = localtime(&raw_time);

    // Format the time as a string
    char time_str[20];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", time_info);

    // Calculate the average number of wins
    double win_rate = ((double)wins / total_games)*100;

    // Write the game result, date, and win rate to the file
    fprintf(file, "%s | Result: %s | Win rate: %.2lf percent\n", time_str, result == WIN ? "Win" : "Loss", win_rate);

    // Close the file
    fclose(file);
}