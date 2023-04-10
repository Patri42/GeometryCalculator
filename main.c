#include <stdio.h>
#include <stdlib.h>
#include "shape_handlers.h"
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
    double value1, value2, result;

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

        if (choice == 6) {
            return;
        }

        printf("Enter two numbers: ");
        scanf("%lf %lf", &value1, &value2);

        switch (choice) {
            case 1:
                result = add(value1, value2);
                break;
            case 2:
                result = subtract(value1, value2);
                break;
            case 3:
                result = multiply(value1, value2);
                break;
            case 4:
                if (value2 == 0) {
                    printf("Error: Division by zero.\n");
                    continue;
                }
                result = divide(value1, value2);
                break;
            case 5:
                if (value2 == 0) {
                    printf("Error: Division by zero.\n");
                    continue;
                }
                result = modulus(value1, value2);
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
                continue;
        }

        printf("Result: %.2lf\n", result);
    }
}

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}



void print_area_circumference(double area, double circumference) {
    printf("Area: %.2lf\n", area);
    printf("Circumference: %.2lf\n", circumference);
}

// Adjust void calculator_menu()

/*To make input validation more robust, consider using fgets() and sscanf() instead of scanf(). 
This will help you prevent buffer overflows and provide better error handling. 
However, this would require more significant changes to your input handling functions. 
If you're interested in this approach, I can provide more guidance.*/