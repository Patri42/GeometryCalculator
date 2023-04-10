#include <stdio.h>
#include <stdlib.h>
#include "shape_handlers.h"
#include "calculator_handlers.h"
#include "shapes.h"
#include "calculator.h"

void main_menu();
void waitForInput();
void clear_screen();
void shapes_menu();
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

void shapes_menu() {
    int choice;

    while (1) {
        clear_screen();
        printf("\nShapes Menu:\n");
        printf("1. Rectangle\n");
        printf("2. Parallelogram\n");
        printf("3. Triangle\n");
        printf("4. Circle\n");
        printf("5. Return to main menu\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                handle_rectangle();
                break;
            case 2:
                handle_parallelogram();
                break;
            case 3:
                handle_triangle();
                break;
            case 4:
                handle_circle();
                break;
            case 5:
                return;
            default:
                printf("\nInvalid choice, please try again.\n");
                continue;
        }

        waitForInput();
    }
}

void calculator_menu() {
    int choice;

    while (1) {
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
                handle_addition();
                break;
            case 2:
                handle_subtraction();
                break;
            case 3:
                handle_multiplication();
                break;
            case 4:
                handle_division();
                break;
            case 5:
                handle_modulus();
                break;
            case 6:
                return;
            default:
                printf("\nInvalid choice, please try again.\n");
        }
        waitForInput();
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