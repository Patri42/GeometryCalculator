#include "gtest/gtest.h"

extern "C" {
    #include "rock_paper_scissors.h"
}

// Definitions for the constants
#define ROCK 1
#define PAPER 2
#define SCISSORS 3

class RockPaperScissorsTest : public ::testing::Test {
protected:
    // Add any necessary setup or teardown code here
};

// Test get_winner function
TEST_F(RockPaperScissorsTest, GameResultDraw) {
    // Arrange
    int userChoice, computerChoice;

    // Act and Assert
    userChoice = ROCK;
    computerChoice = ROCK;
    ASSERT_EQ(game_result(userChoice, computerChoice), DRAW);

    userChoice = PAPER;
    computerChoice = PAPER;
    ASSERT_EQ(game_result(userChoice, computerChoice), DRAW);

    userChoice = SCISSORS;
    computerChoice = SCISSORS;
    ASSERT_EQ(game_result(userChoice, computerChoice), DRAW);
}

TEST_F(RockPaperScissorsTest, GameResultUserWins) {
    // Arrange
    int userChoice, computerChoice;

    // Act and Assert
    userChoice = ROCK;
    computerChoice = SCISSORS;
    ASSERT_EQ(game_result(userChoice, computerChoice), WIN);

    userChoice = PAPER;
    computerChoice = ROCK;
    ASSERT_EQ(game_result(userChoice, computerChoice), WIN);

    userChoice = SCISSORS;
    computerChoice = PAPER;
    ASSERT_EQ(game_result(userChoice, computerChoice), WIN);
}

TEST_F(RockPaperScissorsTest, GameResultUserLoses) {
    // Arrange
    int userChoice, computerChoice;

    // Act and Assert
    userChoice = ROCK;
    computerChoice = PAPER;
    ASSERT_EQ(game_result(userChoice, computerChoice), LOSE);

    userChoice = PAPER;
    computerChoice = SCISSORS;
    ASSERT_EQ(game_result(userChoice, computerChoice), LOSE);

    userChoice = SCISSORS;
    computerChoice = ROCK;
    ASSERT_EQ(game_result(userChoice, computerChoice), LOSE);
}

