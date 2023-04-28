#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

// Handler functions for calculator operations

void handle_addition(double a, double b) {
    double result = add(a, b);
    printf("Result: %.2lf\n", result);
}

void handle_subtraction(double a, double b) {
    double result = subtract(a, b);
    printf("Result: %.2lf\n", result);
}

void handle_multiplication(double a, double b) {
    double result = multiply(a, b);
    printf("Result: %.2lf\n", result);
}

// Handle division operation and display the result, if valid
void handle_division(double a, double b) {
    double result = divide(a, b);
    if (result != 0 || (a == 0 && b == 0)) {
        printf("Result: %.2lf\n", result);
    }
}

// Handle modulus operation and display the result, if valid
void handle_modulus(double a, double b) {
    double result = modulus(a, b);
    if (result != 0 || (a == 0 && b == 0)) {
        printf("Result: %.2lf\n", result);
    }
}