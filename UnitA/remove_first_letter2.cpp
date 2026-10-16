#include <iostream>
#include <vector>

void print_string_vector(const std::vector<std::string> &v)
{
  for (const auto &s : v) {
    std::cout << s << " ";
  }
}

// write the without_first_letter function here:
std::vector<std::string> without_first_letter(std::vector<std::string> words) {
    for (std::string &word : words) {
        if (word.size() > 0) {
            word = word.substr(1,word.size()-1);
        }
    }
    return words;
}

int main()
{
  std::vector<std::string> words1 { "write", "some", "vector", "AND", "string", "code" };
  std::vector<std::string> words2 { "a", "", "ccc" };
  std::vector<std::string> words3;
  std::vector<std::string> modified;

  modified = without_first_letter(words1);
  std::cout << "the original vector: |";
  print_string_vector(words1);
  std::cout << "|\nthe words without their first letter: |";
  print_string_vector(modified);
  std::cout << "|\n";
  
  modified = without_first_letter(words2);
  std::cout << "the original vector: |";
  print_string_vector(words2);
  std::cout << "|\nthe words without their first letter: |";
  print_string_vector(modified);
  std::cout << "|\n";

  modified = without_first_letter(words3);
  std::cout << "the original vector: |";
  print_string_vector(words3);
  std::cout << "|\nthe words without their first letter: |";
  print_string_vector(modified);
  std::cout << "|\n";
}