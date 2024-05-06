/**
 * Unit Tests for the class
 **/

#include <gtest/gtest.h>

#include "Guesser.h"

class GuesserTest : public ::testing::Test {
 protected:
  GuesserTest() {}            // constructor runs before each test
  virtual ~GuesserTest() {}   // destructor cleans up after tests
  virtual void SetUp() {}     // sets up before each test (after constructor)
  virtual void TearDown() {}  // clean up after each test, (before destructor)
};

/* Example test
TEST(GuesserTest, smoke_test)
{
    ASSERT_EQ( 1+1, 2 );
}
*/

TEST(GuesserTest, single_letter_guess) {
  Guesser my_secret("Hello World");
  bool actual = my_secret.match("H");
  ASSERT_EQ(false, actual);
}

TEST(GuesserTest, single_difference_guess) {
  Guesser my_secret("Hello World");
  bool actual = my_secret.match("Hello Wirld");
  ASSERT_EQ(false, actual);
}

TEST(GuesserTest, true_guess) {
  Guesser my_secret("TrueGuess");
  bool actual = my_secret.match("TrueGuess");
  ASSERT_EQ(true, actual);
}

TEST(GuesserTest, one_missing_guess) {
  Guesser my_secret("TrueGuess");
  bool actual = my_secret.match("TueGuess");
  ASSERT_EQ(false, actual);
}

TEST(GuesserTest, char_and_num_guess) {
  Guesser my_secret("abc123");
  bool actual = my_secret.match("Abc 123");
  ASSERT_EQ(false, actual);
}

TEST(GuesserTest, correct_guess) {
  Guesser my_secret("58356ThG");
  bool actual = my_secret.match("58356ThG");
  ASSERT_EQ(true, actual);
}

TEST(GuesserTest, big_int_guess) {
  Guesser my_secret("1000000");
  bool actual = my_secret.match("1000000000000000");
  ASSERT_EQ(false, actual);
}

TEST(GuesserTest, one_char_guess) {
  Guesser my_secret("Aaaaaaaa");
  bool actual = my_secret.match("aaaaaaaa");
  ASSERT_EQ(false, actual);
}

TEST(GuesserTest, single_char_correct_guess) {
  Guesser my_secret("bbbbbbbbbb");
  bool actual = my_secret.match("bbbbbbbbbb");
  ASSERT_EQ(true, actual);
}
