#include "kata/fizzbuzz.h"
#include "gtest/gtest.h"

TEST(fizzbuzz_test, test_first)
{
  EXPECT_EQ(FizzBuzz::shout(1), "1");
}

TEST(fizzbuzz_test, test_multiple_of_three)
{
  EXPECT_EQ(FizzBuzz::shout(3), "Fizz");
  EXPECT_EQ(FizzBuzz::shout(6), "Fizz");
  EXPECT_EQ(FizzBuzz::shout(9), "Fizz");
  EXPECT_EQ(FizzBuzz::shout(12), "Fizz");
}

TEST(fizzbuzz_test, test_multiple_of_five)
{
  EXPECT_EQ(FizzBuzz::shout(5), "Buzz");
  EXPECT_EQ(FizzBuzz::shout(10), "Buzz");
}

TEST(fizzbuzz_test, test_multiple_of_five_and_three)
{
  EXPECT_EQ(FizzBuzz::shout(15), "FizzBuzz");
  EXPECT_EQ(FizzBuzz::shout(30), "FizzBuzz");
}

TEST(fizzbuzz_test, test_sequence)
{
  EXPECT_EQ(FizzBuzz::shout(1), "1");
  EXPECT_EQ(FizzBuzz::shout(2), "2");
  EXPECT_EQ(FizzBuzz::shout(3), "Fizz");
  EXPECT_EQ(FizzBuzz::shout(4), "4");
  EXPECT_EQ(FizzBuzz::shout(5), "Buzz");
  EXPECT_EQ(FizzBuzz::shout(6), "Fizz");
  EXPECT_EQ(FizzBuzz::shout(7), "7");
  EXPECT_EQ(FizzBuzz::shout(8), "8");
  EXPECT_EQ(FizzBuzz::shout(9), "Fizz");
  EXPECT_EQ(FizzBuzz::shout(10), "Buzz");
  EXPECT_EQ(FizzBuzz::shout(11), "11");
  EXPECT_EQ(FizzBuzz::shout(12), "Fizz");
  EXPECT_EQ(FizzBuzz::shout(13), "13");
  EXPECT_EQ(FizzBuzz::shout(14), "14");
  EXPECT_EQ(FizzBuzz::shout(15), "FizzBuzz");
  EXPECT_EQ(FizzBuzz::shout(16), "16");
  EXPECT_EQ(FizzBuzz::shout(17), "17");
  EXPECT_EQ(FizzBuzz::shout(18), "Fizz");
  EXPECT_EQ(FizzBuzz::shout(19), "19");
  EXPECT_EQ(FizzBuzz::shout(20), "Buzz");
}
