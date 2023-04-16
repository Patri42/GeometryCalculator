#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "shape_handlers.h"
#include "calculator_handlers.h"
#include "shapes.h"
#include "calculator.h"

void main_menu();
void waitForInput();
void clear_screen();
void to_lowercase(char *str);
void shapes_menu();
double py_input_func(const char *prompt);
void calculator_menu();
void handle_rectangle();
void handle_parallelogram();
void handle_triangle();
void handle_circle();
void print_area_circumference(double area, double circumference);

int main() {
    main_menu();
    return 0;
}

void main_menu() {
    int choice;
    while (1) {
        clear_screen();
        printf("\nMain menu:\n");
        printf("1. Shapes\n");
        printf("2. Calculator\n");
        printf("3. Terminate \n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                shapes_menu();
                waitForInput();
                break;
            case 2:
                calculator_menu();
                waitForInput();
                break;
            case 3:
                printf("Goodbye!\n");
                return;
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }
}

void waitForInput() {
    printf("Press Enter to continue...");
    getchar();
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

void shapes_menu() {
    char choice[50];

    while (1) {
        clear_screen();
        printf("\nShapes Menu:\n");
        printf("Type 'rectangle' for Rectangle\n");
        printf("Type 'parallelogram' for Parallelogram\n");
        printf("Type 'triangle' for Triangle\n");
        printf("Type 'circle' for Circle\n");
        printf("Type 'return' to Return to main menu\n");
        printf("Choose an option: ");
        fgets(choice, sizeof(choice), stdin);
        strtok(choice, "\n"); // Remove trailing newline character

        to_lowercase(choice); // Convert user input to lowercase

        if (strcmp(choice, "rectangle") == 0) {
            handle_rectangle();
        } else if (strcmp(choice, "parallelogram") == 0) {
            handle_parallelogram();
        } else if (strcmp(choice, "triangle") == 0) {
            handle_triangle();
        } else if (strcmp(choice, "circle") == 0) {
            handle_circle();
        } else if (strcmp(choice, "return") == 0) {
            return;
        } else {
            printf("\nInvalid choice, please try again.\n");
            continue;
        }

        waitForInput();
    }
}

double py_input_func(const char *prompt) {
    double number;
    printf("%s", prompt);
    scanf("%lf", &number);
    getchar();
    return number;
}

void calculator_menu() {
    int choice;
    char continue_calculation;

    while (1) {
        clear_screen();

        double a = py_input_func("\nEnter the first number: ");
        double b = py_input_func("Enter the second number: ");

        clear_screen();
        printf("\nCalculator Menu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Return to main menu\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                handle_addition(a, b);
                break;
            case 2:
                handle_subtraction(a, b);
                break;
            case 3:
                handle_multiplication(a, b);
                break;
            case 4:
                handle_division(a, b);
                break;
            case 5:
                handle_modulus(a, b);
                break;
            case 6:
                return;
            default:
                printf("\nInvalid choice, please try again.\n");
                waitForInput();
                continue;
        }

        printf("\nDo you want to do another calculation? (Y/N): ");
        scanf("%c", &continue_calculation);
        getchar();

        if (tolower((unsigned char)continue_calculation) != 'y') {
            return;
        }
    }
}

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}





/*To make input validation more robust, consider using fgets() and sscanf() instead of scanf(). 
This will help you prevent buffer overflows and provide better error handling. 
However, this would require more significant changes to your input handling functions. 
If you're interested in this approach, I can provide more guidance.*/