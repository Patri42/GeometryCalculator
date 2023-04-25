#include <gtest/gtest.h>

extern "C" {
    #include "calculator.h"
}

class CalculatorTest : public testing::Test {
protected:
    void SetUp() override {
        // Initialization code, if needed
    }
};

// Addition tests
TEST_F(CalculatorTest, Add_PositiveNumbers) {
    // Arrange
    double a = 5;
    double b = 7;

    // Act
    double result = add(a, b);

    // Assert
    ASSERT_NEAR(result, 12, 1e-2); // Using double variables
}

TEST_F(CalculatorTest, Add_NegativeNumbers) {
    // Arrange
    double a = -3;
    double b = -4;

    // Act
    double result = add(a, b);

    // Assert
    ASSERT_NEAR(result, -7, 1e-2);
}

TEST_F(CalculatorTest, Add_PositiveAndNegativeNumbers) {
    // Arrange
    double a = 6;
    double b = -2;

    // Act
    double result = add(a, b);

    // Assert
    ASSERT_NEAR(result, 4, 1e-2);
}