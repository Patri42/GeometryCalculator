#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rock_paper_scissors.h"

void rock_paper_scissors() {
    srand(time(NULL)); // Random nr generator
    int user_choice, computer_choice;
    char input_buffer [10]; // Buffer to avoid overflow issues

    while (1){
        printf("Rock, Paper, Scissors");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        fgets(input_buffer, sizeof(input_buffer), stdin);
        sscanf(input_buffer, "%d, &user_choice");
    }
}