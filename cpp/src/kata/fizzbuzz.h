#include <string>

class FizzBuzz
{
 public:
  static std::string shout(int value);

 private:
  static bool multiple_of_three(int value);
  static bool multiple_of_five(int value);
  static bool multiple_of(const int& base, int value);
};
