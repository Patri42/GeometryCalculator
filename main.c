#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utils.h"
#include "shape_handlers.h"
#include "calculator_handlers.h"
#include "shapes.h"
#include "calculator.h"
#include "rock_paper_scissors.h"

int int_input_func(const char *prompt);
void main_menu();
void waitForInput();
void clear_screen();
void to_lowercase(char *str);
void shapes_menu();
double double_input_func(const char *prompt);
void calculator_menu();
void rock_paper_scissors();
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
        printf("3. Rock-paper-scissors\n");
        printf("4. Terminate \n");
        choice = int_input_func("Choose an option: ");
        
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
                rock_paper_scissors();
                waitForInput();
                break;
            case 4:
                printf("Goodbye!\n");
                return;
            default:
                printf("\nInvalid choice, please try again.\n");
        }
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

void calculator_menu() {
    int choice;
    char continue_calculation;

    while (1) {
        clear_screen();

        double a = double_input_func("\nEnter the first number: ");
        double b = double_input_func("Enter the second number: ");

        clear_screen();
        printf("\nCalculator Menu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Return to main menu\n");
        choice = int_input_func("Choose an option: ");
        

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