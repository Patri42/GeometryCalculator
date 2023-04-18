#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"

void handle_rectangle() {
    double length, width;
    length = double_input_func("Enter the length of the rectangle: "); // Uses double_input_func() from main.c
    width = double_input_func("Enter the width of the rectangle: ");

    double area = rectangle_area(length, width); // Calls the function from shapes.c
    double circumference = rectangle_circumference(length, width);

    print_area_circumference(area, circumference);
}

void handle_parallelogram() {
    double base, height, side;

    base = double_input_func("Enter the base of the parallelogram: ");
    getchar();
    height = double_input_func("Enter the height of the parallelogram: ");
    getchar(); 

    double area = parallelogram_area(base, height); 
    area = double_input_func("Enter the side of the parallelogram: ");
    getchar(); 

    double circumference = parallelogram_circumference(base, side); 

    print_area_circumference(area, circumference);
}

void handle_triangle() {
    double base, height, side1, side2;

    base = double_input_func("Enter the base of the triangle: ");
    getchar(); 
    height = double_input_func("Enter the height of the triangle: ");
    getchar();

    double area = triangle_area(base, height); 

    side1 = double_input_func("Enter the first lateral side: ");
    getchar();
    side2 = double_input_func("Enter the second lateral side: ");
    getchar();

    double circumference = triangle_circumference(base, side1, side2); 

    print_area_circumference(area, circumference);
}

void print_area_circumference(double area, double circumference) {
    printf("Area: %.2lf\n", area);
    printf("Circumference: %.2lf\n", circumference);
}

void handle_circle() {
    double radius;
    radius = double_input_func("Enter the radius of the circle: ");
    getchar(); 

    double area = circle_area(radius); 
    double circumference = circle_circumference(radius); 

    print_area_circumference(area, circumference);
}