#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utils.h"

// Function to handle integer input from the user
int int_input_func(const char *prompt) { // returns int number
    int number;
    char input_buffer[50];
    
    // Display the prompt and read user input
    printf("%s", prompt);
    fgets(input_buffer, sizeof(input_buffer), stdin);

    // Check if the input is a valid integer, if not, ask for input again
    while (sscanf(input_buffer, "%d", &number) != 1) {
        printf("Invalid input, please try again.\n");
        printf("%s", prompt);
        fgets(input_buffer, sizeof(input_buffer), stdin);
    }

    return number;
}

// Function to wait for user input before proceeding
void waitForInput() {
    printf("Press Enter to continue...");
    getchar();
}

// Function to clear the console screen
void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Function to convert a string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Function to handle double (floating-point) input from the user
double double_input_func(const char *prompt) { // returns float number
    double number;
    char input_buffer[50];

    // Display the prompt and read user input
    printf("%s", prompt);
    fgets(input_buffer, sizeof(input_buffer), stdin);

    // Check if the input is a valid double, if not, ask for input again
    while (sscanf(input_buffer, "%lf", &number) != 1) {
        printf("Invalid input, please try again.\n");
        printf("%s", prompt);
        fgets(input_buffer, sizeof(input_buffer), stdin);
    }
    
    return number;
}