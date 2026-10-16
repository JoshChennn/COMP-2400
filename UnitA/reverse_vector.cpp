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
  
  std::cout << "the original vector: ";
  print_string_vector(words);

  // write code between here ...

  for (int i = 0; i < words.size(); i++) {
    words.insert(words.begin()+i, words.at(words.size()-1));
    words.pop_back();
  }

  // ... and here only
  // for full points, do **not** declare any other vectors or containers
  // (that is, reverse the vector "in-place")
  
  std::cout << "\nthe reversed vector: ";
  print_string_vector(words);
  std::cout << std::endl;
}