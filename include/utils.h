#ifndef UTILS_H
#define UTILS_H

// Utility function prototypes for user input, string manipulation, and screen control.

// Prompt user for an integer input and return the value.
int int_input_func(const char *prompt);

// Wait for the user to press Enter before proceeding.
void waitForInput();

void clear_screen();

// Convert a given string to lowercase.
void to_lowercase(char *str);

// Prompt user for a double input and return the value.
double double_input_func(const char *prompt);

#endif