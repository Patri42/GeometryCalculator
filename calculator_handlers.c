#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

void handle_addition() {
    double a, b;
    printf("Enter the first number: ");
    scanf("%lf", &a);
    getchar(); 
    printf("Enter the second number: ");
    scanf("%lf", &b);
    getchar(); 
    double result = add(a, b);
    printf("Result: %.2lf\n", result);
}

void handle_subtraction() {
    double a, b;
    printf("Enter the first number: ");
    scanf("%lf", &a);
    getchar(); 
    printf("Enter the second number: ");
    scanf("%lf", &b);
    getchar(); 
    double result = subtract(a, b);
    printf("Result: %.2lf\n", result);
}

void handle_multiplication() {
    double a, b;
    printf("Enter the first number: ");
    scanf("%lf", &a);
    getchar(); 
    printf("Enter the second number: ");
    scanf("%lf", &b);
    getchar(); 
    double result = multiply(a, b);
    printf("Result: %.2lf\n", result);
}

void handle_division() {
    double a, b;
    printf("Enter the first number: ");
    scanf("%lf", &a);
    getchar(); 
    printf("Enter the second number: ");
    scanf("%lf", &b);
    getchar(); 
    if (b == 0) {
        printf("Error: Division by zero.\n");
        return;
    }
    double result = divide(a, b);
    printf("Result: %.2lf\n", result);
}

void handle_modulus() {
    double a, b;
    printf("Enter the first number: ");
    scanf("%lf", &a);
    getchar(); 
    printf("Enter the second number: ");
    scanf("%lf", &b);
    getchar(); 
    if (b == 0) {
        printf("Error: Division by zero.\n");
        return;
    }
    double result = modulus(a, b);
    printf("Result: %.2lf\n", result);
}