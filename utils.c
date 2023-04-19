#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utils.h"

int int_input_func(const char *prompt) { // returns int number
    int number;
    char input_buffer[50];

    printf("%s", prompt);
    fgets(input_buffer, sizeof(input_buffer), stdin);

    while (sscanf(input_buffer, "%d", &number) != 1) {
        printf("Invalid input, please try again.\n");
        printf("%s", prompt);
        fgets(input_buffer, sizeof(input_buffer), stdin);
    }

    return number;
}

void waitForInput() {
    printf("Press Enter to continue...");
    getchar();
}

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

double double_input_func(const char *prompt) { // returns float number
    double number;
    char input_buffer[50];

    printf("%s", prompt);
    fgets(input_buffer, sizeof(input_buffer), stdin);

    while (sscanf(input_buffer, "%lf", &number) != 1) {
        printf("Invalid input, please try again.\n");
        printf("%s", prompt);
        fgets(input_buffer, sizeof(input_buffer), stdin);
    }
    
    return number;
}