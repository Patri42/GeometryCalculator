#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"

void print_area_circumference(double area, double circumference) {
    printf("Area: %.2lf\n", area);
    printf("Circumference: %.2lf\n", circumference);
}

void handle_rectangle() {
    double length, width;
    printf("Enter the length of the rectangle: ");
    scanf("%lf", &length);
    getchar();
    printf("Enter the width of the rectangle: ");
    scanf("%lf", &width);
    getchar();

    double area = rectangle_area(length, width); // Calls the function from shapes.c
    double circumference = rectangle_circumference(length, width); 

    print_area_circumference(area, circumference);
}

void handle_parallelogram() {
    double base, height, side;
    printf("Enter the base of the parallelogram: ");
    scanf("%lf", &base);
    getchar(); 
    printf("Enter the height of the parallelogram: ");
    scanf("%lf", &height);
    getchar(); 

    double area = parallelogram_area(base, height); 

    printf("Enter the side of the parallelogram: ");
    scanf("%lf", &side);
    getchar(); 

    double circumference = parallelogram_circumference(base, side); 

    print_area_circumference(area, circumference);
}

void handle_triangle() {
    double base, height, side1, side2;
    printf("Enter the base of the triangle: ");
    scanf("%lf", &base);
    getchar(); 
    printf("Enter the height of the triangle: ");
    scanf("%lf", &height);
    getchar(); 

    double area = triangle_area(base, height); 

    printf("Enter the first lateral side: ");
    scanf("%lf", &side1);
    getchar(); 
    printf("Enter the second lateral side: ");
    scanf("%lf", &side2);
    getchar(); 

    double circumference = triangle_circumference(base, side1, side2); 

    print_area_circumference(area, circumference);
}

void handle_circle() {
    double radius;
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);
    getchar(); 

    double area = circle_area(radius); 
    double circumference = circle_circumference(radius); 

    print_area_circumference(area, circumference);
}