#include "fizzbuzz.h"

std::string FizzBuzz::shout(int value)
{
  std::string result = "";
  if (multiple_of_three(value))
  {
    result += "Fizz";
  }
  if (multiple_of_five(value))
  {
    result += "Buzz";
  }
  if (result.empty())
  {
    result = std::to_string(value);
  }
  return result;
}

bool FizzBuzz::multiple_of_three(int value)
{
  return multiple_of(3, value);
}

bool FizzBuzz::multiple_of_five(int value)
{
  return multiple_of(5, value);
}

bool FizzBuzz::multiple_of(const int& base, int value)
{
  return value % base == 0;
}
