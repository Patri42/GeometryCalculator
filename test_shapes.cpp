#define _USE_MATH_DEFINES
#include <cmath>
#include <gtest/gtest.h>

extern "C" {
    #include "shapes.h"
}

class ShapesTest : public testing::Test {
protected:
    void SetUp() override {
        // Initialization code, if needed
    }
};

// Rectangle area test with zero length and width
TEST_F(ShapesTest, RectangleArea_ZeroLengthAndWidth) {
    // Arrange
    double length = 0;
    double width = 0;

    // Act
    double result = rectangle_area(length, width);

    // Assert
    ASSERT_NEAR(result, 0, 1e-9);
}

// Rectangle circumference test
TEST_F(ShapesTest, RectangleCircumference_CorrectValues) {
    // Arrange
    double length = 10;
    double width = 5;

    // Act
    double result = rectangle_circumference(length, width);

    // Assert
    ASSERT_NEAR(result, 30, 1e-9);
}

// Parallelogram area test with a very large base and height
TEST_F(ShapesTest, ParallelogramArea_VeryLargeBaseAndHeight) {
    // Arrange
    double base = 1e9;
    double height = 1e9;

    // Act
    double result = parallelogram_area(base, height);

    // Assert
    ASSERT_NEAR(result, base * height, 1e-9);
}

// Parallelogram circumference test
TEST_F(ShapesTest, ParallelogramCircumference_CorrectValues) {
    // Arrange
    double base = 10;
    double side = 5;

    // Act
    double result = parallelogram_circumference(base, side);

    // Assert
    ASSERT_NEAR(result, 30, 1e-9);
}

// Triangle area test with zero base and height
TEST_F(ShapesTest, TriangleArea_ZeroBaseAndHeight) {
    // Arrange
    double base = 0;
    double height = 0;

    // Act
    double result = triangle_area(base, height);

    // Assert
    ASSERT_NEAR(result, 0, 1e-9);
}

// Triangle circumference test
TEST_F(ShapesTest, TriangleCircumference_CorrectValues) {
    // Arrange
    double side1 = 3;
    double side2 = 4;
    double side3 = 5;

    // Act
    double result = triangle_circumference(side1, side2, side3);

    // Assert
    ASSERT_NEAR(result, 12, 1e-9);
}

// Circle area test with a very small radius
TEST_F(ShapesTest, CircleArea_VerySmallRadius) {
    // Arrange
    double radius = 1e-9;

    // Act
    double result = circle_area(radius);

    // Assert
    ASSERT_NEAR(result, M_PI * pow(radius, 2), 1e-18);
}

// Circle circumference test
TEST_F(ShapesTest, CircleCircumference_CorrectValues) {
    // Arrange
    double radius = 5;

    // Act
    double result = circle_circumference(radius);

    // Assert
    ASSERT_NEAR(result, 2 * M_PI * 5, 1e-9);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}