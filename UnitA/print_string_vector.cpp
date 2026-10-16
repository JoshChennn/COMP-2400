#include <iostream>
#include <vector>

void print_string_vector(const std::vector<std::string> &v)
{
  for (const std::string &s : v) {
    std::cout << s << " ";
  }
}

int main()
{
  std::vector<std::string> words { "here", "is", "a", "simple", "vector", "example" };
  std::vector<std::string> reversed;
  
  // write code between here ...

  for (int i = words.size() - 1; i >= 0; i--) {
    reversed.push_back(words.at(i));
  }
  
  // ... and here only
  
  std::cout << "the original vector: ";
  print_string_vector(words);

  std::cout << "\nthe reversed vector: ";
  print_string_vector(reversed);
  
  std::cout << "\n";
}