#include <iostream>

std::string string_seq(int start, int end, const std::string &sep) {
  std::string result = std::to_string(start);
  if (start <= end) {
    for (int i = start+1; i <= end; i+=1) {
      result += (sep + std::to_string(i));
    }
  }
  else if (start >= end) {
    for (int i = start-1; i >= end; i-=1) {
      result += (sep + std::to_string(i));
    }
  }
  return result;
}

int main() {
  std::string sep = "...";
  
  // the function string_seq returns a string containing the integers
  // between the first and second parameter (inclusive), separated by
  // the string given as the third parameter
  // to earn full marks, use an appropriate reference parameter type

  std::cout << string_seq(1, 10, ",") << std::endl;
  std::cout << string_seq(-2, 2, " <-> ") << std::endl;
  std::cout << string_seq(10, 0, ", ") << std::endl;
  std::cout << string_seq(100, 95, sep) << std::endl;
  std::cout << string_seq(1, 1, "this never appears") << std::endl;
}