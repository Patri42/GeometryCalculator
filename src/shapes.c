#define _USE_MATH_DEFINES

#include "shapes.h"
#include <math.h>

double rectangle_area(double length, double width) {
    return length * width;
}

double rectangle_circumference(double length, double width) {
    return 2 * (length + width);
}

double parallelogram_area(double base, double height) {
    return base * height;
}

double parallelogram_circumference(double base, double side) {
    return 2 * (base + side);
}

double triangle_area(double base, double height) {
    return 0.5 * base * height;
}

double triangle_circumference(double side1, double side2, double side3) {
    return side1 + side2 + side3;
}

double circle_area(double radius) {
    return M_PI * pow(radius, 2);
}

double circle_circumference(double radius) {
    return 2 * M_PI * radius;
}