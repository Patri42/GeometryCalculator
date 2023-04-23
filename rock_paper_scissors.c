#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rock_paper_scissors.h"
#include "game_data.h"
#include "utils.h"

#define RPS_RESULTS_FILE "rps_results.txt"

void rock_paper_scissors() {
    clear_screen();

    srand(time(NULL)); // Random nr generator

    int user_choice, computer_choice;
	int total_games = 0;
	int wins = 0;

    while (1){
        printf("Rock, Paper, Scissors\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("4. Quit\n");
        user_choice = int_input_func("Enter your choice: ");

        if (user_choice == 4)
            break;

        if (user_choice<1 || user_choice>3){
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        computer_choice = (rand() % 3)+ 1; // Generate computer's choice (1, 2, or 3) -- WHY +1?

        printf("Computer chose: ");
        switch (computer_choice) {
            case 1:
                printf("Rock");
                break;
            case 2:
                printf("Paper");
                break;
            case 3:
                printf("Scissors");
                break;
        }

        printf("\n\n");

        GameResult result = game_result(user_choice, computer_choice);

		

		total_games++;

        switch (result) {
            case DRAW:
                printf("It's a draw!\n");
                getchar();
                clear_screen();
                break;
            case WIN:
                printf("You win!\n");
				wins++;
                getchar();
                clear_screen();
                break;
            case LOSE:
                printf("You lose!\n");
                getchar();
                clear_screen();
                break;
        }
		save_game_result(result, total_games, wins);
        printf("\n");        
    }
}