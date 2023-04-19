#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rock_paper_scissors.h"
#include "utils.h"

void rock_paper_scissors() {
    clear_screen();
    srand(time(NULL)); // Random nr generator
    int user_choice, computer_choice;

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

        if (user_choice==computer_choice){
            printf("It's a TIE!\n");
            getchar();
            clear_screen();
        }
        else if ((user_choice == 1 && computer_choice == 3) ||
                (user_choice == 2 && computer_choice == 1) ||
                (user_choice == 3 && computer_choice == 2)){
            printf("You WIN!\n");
            getchar();
            clear_screen();
            }
        else{
            printf("You LOSE!\n");
            getchar();
            clear_screen();
        }
        
    }

}