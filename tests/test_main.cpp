// Include the Google Test framework header
#include <gtest/gtest.h>

int main(int argc, char **argv) {
    // Initialize Google Test framework with command line arguments
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}